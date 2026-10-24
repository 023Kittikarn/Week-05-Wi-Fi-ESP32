#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"

#include "esp_event.h"
#include "esp_log.h"
#include "esp_netif.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "nvs_flash.h"

#include "lwip/inet.h"
#include "lwip/ip4_addr.h"

#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT      BIT1

#define TARGET_WIFI_SSID "M"
#define TARGET_WIFI_PASS "12345678"

#define WIFI_TEST_TIMEOUT_MS 15000

static const char *TAG = "LAB_HANDSHAKE_IP";

static EventGroupHandle_t s_wifi_event_group;

/*
 * ใช้ระบุว่ากำลังหยุด Wi-Fi โดยตั้งใจ
 * เพื่อไม่ให้นับ Disconnect Event จากการหยุดรอบก่อน
 * เป็นผลการทดสอบรอบใหม่
 */
static volatile bool s_intentional_disconnect = false;


/* =========================================================
 * แปลความหมาย Disconnect Reason Code
 * ========================================================= */
static const char *get_disconnect_reason_info(int reason)
{
    switch (reason) {
    case 15:
        return "4-Way Handshake Timeout";

    case 200:
        return "WIFI_REASON_BEACON_TIMEOUT";

    case 201:
        return "WIFI_REASON_NO_AP_FOUND: SSID not found";

    case 202:
        return "WIFI_REASON_AUTH_FAIL";

    case 204:
        return "WIFI_REASON_HANDSHAKE_TIMEOUT";

    default:
        return "OTHER_DISCONNECT_REASON";
    }
}


/* =========================================================
 * Wi-Fi และ IP Event Handler
 * ========================================================= */
static void wifi_event_handler(
    void *arg,
    esp_event_base_t event_base,
    int32_t event_id,
    void *event_data)
{
    (void)arg;

    if (event_base == WIFI_EVENT) {

        switch (event_id) {

        case WIFI_EVENT_STA_START: {
            ESP_LOGI(TAG,
                     "[EVENT] WIFI_EVENT_STA_START received");

            ESP_LOGI(TAG,
                     "[FORENSIC] Calling esp_wifi_connect()");

            esp_err_t err = esp_wifi_connect();

            ESP_LOGI(TAG,
                     "[FORENSIC] esp_wifi_connect(): %s (0x%x)",
                     esp_err_to_name(err),
                     (unsigned int)err);

            if (err != ESP_OK) {
                xEventGroupSetBits(
                    s_wifi_event_group,
                    WIFI_FAIL_BIT);
            }

            break;
        }

        case WIFI_EVENT_STA_CONNECTED: {
            wifi_event_sta_connected_t *event =
                (wifi_event_sta_connected_t *)event_data;

            ESP_LOGI(TAG,
                     "================================================");

            ESP_LOGI(TAG,
                     "[EVENT] WIFI_EVENT_STA_CONNECTED received");

            ESP_LOGI(TAG,
                     "[PASS] Authentication and Association completed");

            ESP_LOGI(TAG,
                     "Connected SSID: %.32s",
                     (const char *)event->ssid);

            ESP_LOGI(TAG,
                     "BSSID: %02X:%02X:%02X:%02X:%02X:%02X",
                     event->bssid[0],
                     event->bssid[1],
                     event->bssid[2],
                     event->bssid[3],
                     event->bssid[4],
                     event->bssid[5]);

            ESP_LOGI(TAG,
                     "Channel: %d",
                     event->channel);

            ESP_LOGI(TAG,
                     "Association ID: %d",
                     event->aid);

            ESP_LOGI(TAG,
                     "[PHASE 4] Waiting for handshake completion and IP");

            ESP_LOGI(TAG,
                     "================================================");

            break;
        }

        case WIFI_EVENT_STA_DISCONNECTED: {
            wifi_event_sta_disconnected_t *event =
                (wifi_event_sta_disconnected_t *)event_data;

            ESP_LOGW(TAG,
                     "[EVENT] WIFI_EVENT_STA_DISCONNECTED received");

            ESP_LOGW(TAG,
                     "Target SSID: %.32s",
                     (const char *)event->ssid);

            ESP_LOGW(TAG,
                     "Reason Code: %d (0x%02X)",
                     event->reason,
                     event->reason);

            ESP_LOGW(TAG,
                     "Diagnosis: %s",
                     get_disconnect_reason_info(event->reason));

            if (s_intentional_disconnect) {
                ESP_LOGW(TAG,
                         "[INFO] Ignoring disconnect caused by "
                         "intentional Wi-Fi stop");
            } else {
                xEventGroupSetBits(
                    s_wifi_event_group,
                    WIFI_FAIL_BIT);
            }

            break;
        }

        default:
            ESP_LOGI(TAG,
                     "[EVENT] Wi-Fi event ID: %ld",
                     (long)event_id);
            break;
        }
    }

    else if (event_base == IP_EVENT) {

        if (event_id == IP_EVENT_STA_GOT_IP) {
            ip_event_got_ip_t *event =
                (ip_event_got_ip_t *)event_data;

            ESP_LOGI(TAG,
                     "================================================");

            ESP_LOGI(TAG,
                     "[SUCCESS] IP_EVENT_STA_GOT_IP received");

            ESP_LOGI(TAG,
                     "[PASS] Wi-Fi handshake and DHCP completed");

            ESP_LOGI(TAG,
                     "IP Address: " IPSTR,
                     IP2STR(&event->ip_info.ip));

            ESP_LOGI(TAG,
                     "Subnet Mask: " IPSTR,
                     IP2STR(&event->ip_info.netmask));

            ESP_LOGI(TAG,
                     "Gateway: " IPSTR,
                     IP2STR(&event->ip_info.gw));

            ESP_LOGI(TAG,
                     "================================================");

            xEventGroupSetBits(
                s_wifi_event_group,
                WIFI_CONNECTED_BIT);
        }
    }
}


/* =========================================================
 * ทดสอบการเชื่อมต่อด้วยรหัสผ่านที่กำหนด
 * ========================================================= */
static void test_handshake_ip_phase(
    const char *test_title,
    const char *ssid,
    const char *password)
{
    ESP_LOGI(TAG, "");
    ESP_LOGI(TAG,
             "--------------------------------------------------");

    ESP_LOGI(TAG, ">>> %s", test_title);

    ESP_LOGI(TAG,
             "--------------------------------------------------");

    ESP_LOGI(TAG, "Target SSID: \"%s\"", ssid);

    /*
     * ไม่แสดงรหัสผ่านจริงใน Log
     * เพื่อลดการเปิดเผยข้อมูลการเชื่อมต่อ
     */
    ESP_LOGI(TAG, "Password length: %u",
             (unsigned int)strlen(password));

    /*
     * หยุด Wi-Fi ก่อนเปลี่ยนการตั้งค่า
     */
    s_intentional_disconnect = true;

    ESP_LOGI(TAG, "[FORENSIC] Calling esp_wifi_stop()");

    esp_err_t err_stop = esp_wifi_stop();

    ESP_LOGI(TAG,
             "[FORENSIC] esp_wifi_stop(): %s (0x%x)",
             esp_err_to_name(err_stop),
             (unsigned int)err_stop);

    /*
     * ESP_ERR_WIFI_NOT_STARTED อาจเกิดได้ในการทดสอบครั้งแรก
     * เนื่องจาก Wi-Fi ยังไม่เคยเริ่มทำงาน
     */
    vTaskDelay(pdMS_TO_TICKS(200));

    /*
     * ล้าง Event Bits หลังหยุด Wi-Fi
     * เพื่อไม่ให้ผลจากการทดสอบก่อนหน้าปะปน
     */
    xEventGroupClearBits(
        s_wifi_event_group,
        WIFI_CONNECTED_BIT | WIFI_FAIL_BIT);

    /*
     * ตั้งค่าการเชื่อมต่อ Wi-Fi
     */
    wifi_config_t wifi_config = {0};

    wifi_config.sta.threshold.authmode = WIFI_AUTH_WPA2_PSK;

    snprintf(
        (char *)wifi_config.sta.ssid,
        sizeof(wifi_config.sta.ssid),
        "%s",
        ssid);

    snprintf(
        (char *)wifi_config.sta.password,
        sizeof(wifi_config.sta.password),
        "%s",
        password);

    ESP_LOGI(TAG,
             "[FORENSIC] Calling esp_wifi_set_config()");

    esp_err_t err_config =
        esp_wifi_set_config(WIFI_IF_STA, &wifi_config);

    ESP_LOGI(TAG,
             "[FORENSIC] esp_wifi_set_config(): %s (0x%x)",
             esp_err_to_name(err_config),
             (unsigned int)err_config);

    if (err_config != ESP_OK) {
        ESP_LOGE(TAG,
                 "[RESULT] TEST FAILED: Wi-Fi configuration error");
        s_intentional_disconnect = false;
        return;
    }

    /*
     * เริ่ม Wi-Fi ใหม่
     * WIFI_EVENT_STA_START จะสั่ง esp_wifi_connect()
     * ผ่าน Event Handler ด้านบน
     */
    ESP_LOGI(TAG,
             "[FORENSIC] Calling esp_wifi_start()");

    s_intentional_disconnect = false;

    esp_err_t err_start = esp_wifi_start();

    ESP_LOGI(TAG,
             "[FORENSIC] esp_wifi_start(): %s (0x%x)",
             esp_err_to_name(err_start),
             (unsigned int)err_start);

    if (err_start != ESP_OK) {
        ESP_LOGE(TAG,
                 "[RESULT] TEST FAILED: Wi-Fi start error");
        return;
    }

    /*
     * รอจนได้รับ IP หรือพบการ Disconnect
     */
    ESP_LOGI(TAG,
             "[FORENSIC] Waiting for connection result "
             "(timeout %d ms)",
             WIFI_TEST_TIMEOUT_MS);

    EventBits_t bits = xEventGroupWaitBits(
        s_wifi_event_group,
        WIFI_CONNECTED_BIT | WIFI_FAIL_BIT,
        pdFALSE,
        pdFALSE,
        pdMS_TO_TICKS(WIFI_TEST_TIMEOUT_MS));

    if (bits & WIFI_CONNECTED_BIT) {

        ESP_LOGI(TAG,
                 "[RESULT] TEST PASSED");

        ESP_LOGI(TAG,
                 "4-Way Handshake and DHCP IP Assignment successful");

    } else if (bits & WIFI_FAIL_BIT) {

        ESP_LOGW(TAG,
                 "[RESULT] TEST FAILED");

        ESP_LOGW(TAG,
                 "Disconnected or failed during Wi-Fi connection");

    } else {

        ESP_LOGE(TAG,
                 "[RESULT] TEST TIMEOUT");

        ESP_LOGE(TAG,
                 "No connection result received before timeout");
    }
}


/* =========================================================
 * Main Application
 * ========================================================= */
void app_main(void)
{
    s_wifi_event_group = xEventGroupCreate();

    if (s_wifi_event_group == NULL) {
        ESP_LOGE(TAG, "Failed to create Event Group");
        return;
    }

    /* 1. Initialize NVS */
    ESP_LOGI(TAG, "[INIT] Initializing NVS");

    esp_err_t ret = nvs_flash_init();

    if (ret == ESP_ERR_NVS_NO_FREE_PAGES ||
        ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {

        ESP_LOGW(TAG,
                 "NVS requires initialization; erasing NVS partition");

        ESP_ERROR_CHECK(nvs_flash_erase());

        ret = nvs_flash_init();
    }

    ESP_ERROR_CHECK(ret);

    /* 2. Initialize network interface */
    ESP_LOGI(TAG, "[INIT] Initializing network interface");

    ESP_ERROR_CHECK(esp_netif_init());

    ESP_ERROR_CHECK(esp_event_loop_create_default());

    esp_netif_t *sta_netif = esp_netif_create_default_wifi_sta();

    if (sta_netif == NULL) {
        ESP_LOGE(TAG, "Failed to create default Wi-Fi STA interface");
        return;
    }

    /* 3. Initialize Wi-Fi driver */
    ESP_LOGI(TAG, "[INIT] Initializing Wi-Fi driver");

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();

    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    /* 4. Register Wi-Fi and IP Event Handlers */
    ESP_LOGI(TAG, "[INIT] Registering event handlers");

    esp_event_handler_instance_t instance_any_id;
    esp_event_handler_instance_t instance_got_ip;

    ESP_ERROR_CHECK(
        esp_event_handler_instance_register(
            WIFI_EVENT,
            ESP_EVENT_ANY_ID,
            &wifi_event_handler,
            NULL,
            &instance_any_id));

    ESP_ERROR_CHECK(
        esp_event_handler_instance_register(
            IP_EVENT,
            IP_EVENT_STA_GOT_IP,
            &wifi_event_handler,
            NULL,
            &instance_got_ip));

    /* 5. Set station mode */
    ESP_LOGI(TAG, "[INIT] Setting Wi-Fi station mode");

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));

    ESP_LOGI(TAG,
             "==================================================");

    ESP_LOGI(TAG,
             "Lab 5.4: 4-Way Handshake and IP Assignment");

    ESP_LOGI(TAG,
             "==================================================");

    /*
     * Experiment 5.4.1
     * รหัสผ่านถูกต้อง
     */
    test_handshake_ip_phase(
        "Experiment 5.4.1: Correct Password",
        TARGET_WIFI_SSID,
        TARGET_WIFI_PASS);

    /* เว้นช่วงระหว่างการทดสอบ */
    vTaskDelay(pdMS_TO_TICKS(2000));

    /*
     * Experiment 5.4.2
     * รหัสผ่านไม่ถูกต้อง
     */
    test_handshake_ip_phase(
        "Experiment 5.4.2: Incorrect Password",
        TARGET_WIFI_SSID,
        "WRONG_PASSWORD_1234");

    ESP_LOGI(TAG,
             "==================================================");

    ESP_LOGI(TAG,
             "Lab 5.4 tests finished");

    ESP_LOGI(TAG,
             "==================================================");
}