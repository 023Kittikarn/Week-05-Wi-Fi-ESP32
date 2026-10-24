# report Lab5-2

I (792) LAB_WIFI_CONN: ------------------------------------------------------------------
I (792) LAB_WIFI_CONN:   Target SSID: "M"
I (802) LAB_WIFI_CONN:   Target Password: "12345678"
I (812) LAB_WIFI_CONN: [FORENSIC]: Call esp_wifi_stop()
I (812) LAB_WIFI_CONN: [FORENSIC]: Call esp_wifi_s�ets Jul 29 2019 12:21:46

rst:0x1 (POWERON_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0xee
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:2
load:0x3fff0030,len:7084
ho 0 tail 12 room 4
load:0x40078000,len:15584
load:0x40080400,len:4
--- 0x40080400: _init at ??:?
load:0x40080404,len:3876
entry 0x4008064c
I (31) boot: ESP-IDF v5.1.2-dirty 2nd stage bootloader
I (31) boot: compile time Oct 24 2026 16:15:21
I (31) boot: Multicore bootloader
I (36) boot: chip revision: v3.1
I (40) boot.esp32: SPI Speed      : 40MHz
I (44) boot.esp32: SPI Mode       : DIO
I (49) boot.esp32: SPI Flash Size : 2MB
I (53) boot: Enabling RNG early entropy source...
I (59) boot: Partition Table:
I (62) boot: ## Label            Usage          Type ST Offset   Length
I (70) boot:  0 nvs              WiFi data        01 02 00009000 00006000
I (77) boot:  1 phy_init         RF data          01 01 0000f000 00001000
I (85) boot:  2 factory          factory app      00 00 00010000 00100000
I (92) boot: End of partition table
I (96) esp_image: segment 0: paddr=00010020 vaddr=3f400020 size=20224h (131620) map
I (152) esp_image: segment 1: paddr=0003024c vaddr=3ffb0000 size=03a7ch (14972) load
I (159) esp_image: segment 2: paddr=00033cd0 vaddr=40080000 size=0c348h (49992) load
I (179) esp_image: segment 3: paddr=00040020 vaddr=400d0020 size=812d0h (529104) map
I (371) esp_image: segment 4: paddr=000c12f8 vaddr=4008c348 size=098f4h (39156) load
I (398) boot: Loaded app from partition at offset 0x10000
I (398) boot: Disabling RNG early entropy source...
I (410) cpu_start: Multicore app
I (410) cpu_start: Pro cpu up.
I (410) cpu_start: Starting app cpu, entry point is 0x40081390
--- 0x40081390: call_start_cpu1 at /Users/kittikarnkaewnual/esp/esp-idf/components/esp_system/port/cpu_start.c:157
I (0) cpu_start: App cpu up.
I (428) cpu_start: Pro cpu start user code
I (428) cpu_start: cpu freq: 160000000 Hz
I (428) cpu_start: Application information:
I (433) cpu_start: Project name:     wifi_connection_phase
I (439) cpu_start: App version:      e6e557f-dirty
I (445) cpu_start: Compile time:     Oct 24 2026 16:15:15
I (451) cpu_start: ELF file SHA256:  ff3493f461ae66b4...
I (457) cpu_start: ESP-IDF:          v5.1.2-dirty
I (462) cpu_start: Min chip rev:     v0.0
I (467) cpu_start: Max chip rev:     v3.99 
I (472) cpu_start: Chip rev:         v3.1
I (476) heap_init: Initializing. RAM available for dynamic allocation:
I (484) heap_init: At 3FFAE6E0 len 00001920 (6 KiB): DRAM
I (490) heap_init: At 3FFB7B18 len 000284E8 (161 KiB): DRAM
I (496) heap_init: At 3FFE0440 len 00003AE0 (14 KiB): D/IRAM
I (502) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
I (509) heap_init: At 40095C3C len 0000A3C4 (40 KiB): IRAM
I (516) spi_flash: detected chip: generic
I (519) spi_flash: flash io: dio
W (523) spi_flash: Detected size(4096k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (537) app_start: Starting scheduler on CPU0
I (542) app_start: Starting scheduler on CPU1
I (542) main_task: Started on CPU0
I (552) main_task: Calling app_main()
I (552) LAB_WIFI_CONN: [FORENSIC]: Call nvs_flash_init()
I (592) LAB_WIFI_CONN: [FORENSIC]: nvs_flash_init() returned ESP_OK (0x0)
I (602) LAB_WIFI_CONN: [FORENSIC]: Call esp_netif_init()
I (602) LAB_WIFI_CONN: [FORENSIC]: Call esp_event_loop_create_default()
I (612) LAB_WIFI_CONN: [FORENSIC]: Call esp_netif_create_default_wifi_sta()
I (612) LAB_WIFI_CONN: [FORENSIC]: esp_netif_create_default_wifi_sta() returned 0x3ffbd5c0
I (622) LAB_WIFI_CONN: [FORENSIC]: Call esp_wifi_init(&cfg)
I (642) wifi:wifi driver task: 3ffbfc18, prio:23, stack:6656, core=0
I (652) wifi:wifi firmware version: 91b9630
I (652) wifi:wifi certification version: v7.0
I (652) wifi:config NVS flash: enabled
I (662) wifi:config nano formating: disabled
I (662) wifi:Init data frame dynamic rx buffer num: 32
I (662) wifi:Init static rx mgmt buffer num: 5
I (672) wifi:Init management short buffer num: 32
I (672) wifi:Init dynamic tx buffer num: 32
I (682) wifi:Init static rx buffer size: 1600
I (682) wifi:Init static rx buffer num: 10
I (682) wifi:Init dynamic rx buffer num: 32
I (692) wifi_init: rx ba win: 6
I (692) wifi_init: tcpip mbox: 32
I (702) wifi_init: udp mbox: 6
I (702) wifi_init: tcp mbox: 6
I (702) wifi_init: tcp tx win: 5744
I (712) wifi_init: tcp rx win: 5744
I (712) wifi_init: tcp mss: 1440
I (722) wifi_init: WiFi IRAM OP enabled
I (722) wifi_init: WiFi RX IRAM OP enabled
I (722) LAB_WIFI_CONN: [FORENSIC]: Call esp_event_handler_instance_register(WIFI_EVENT)
I (732) LAB_WIFI_CONN: [FORENSIC]: Call esp_event_handler_instance_register(IP_EVENT)
I (742) LAB_WIFI_CONN: [FORENSIC]: Call esp_wifi_set_mode(WIFI_MODE_STA)
I (752) LAB_WIFI_CONN: ==================================================================
I (762) LAB_WIFI_CONN:   Lab 5.2: Wi-Fi Connection & IP Assignment (ESP-IDF Forensic)
I (772) LAB_WIFI_CONN: ==================================================================
I (782) LAB_WIFI_CONN: 

I (782) LAB_WIFI_CONN: ------------------------------------------------------------------
I (792) LAB_WIFI_CONN: >>> Experiment 5.2.1: Connection Test - Correct Credentials
I (802) LAB_WIFI_CONN: ------------------------------------------------------------------
I (802) LAB_WIFI_CONN:   Target SSID: "M"
I (812) LAB_WIFI_CONN:   Target Password: "12345678"
I (822) LAB_WIFI_CONN: [FORENSIC]: Call esp_wifi_stop()
I (822) LAB_WIFI_CONN: [FORENSIC]: Call esp_wifi_set_config(WIFI_IF_STA, &wifi_config)
I (872) LAB_WIFI_CONN: [FORENSIC]: esp_wifi_set_config() returned ESP_OK (0x0)
I (872) LAB_WIFI_CONN: [FORENSIC]: Call esp_wifi_start()
I (872) phy_init: phy_version 4780,16b31a7,Sep 22 2023,20:42:16
I (952) wifi:mode : sta (84:1f:e8:39:b4:48)
I (952) wifi:enable tsf
I (952) LAB_WIFI_CONN: [FORENSIC]: esp_wifi_start() returned ESP_OK (0x0)
I (962) LAB_WIFI_CONN: [EVENT FORENSIC]: WIFI_EVENT_STA_START received
I (962) LAB_WIFI_CONN: [FORENSIC]: Call esp_wifi_connect()
I (972) LAB_WIFI_CONN: [FORENSIC]: esp_wifi_connect() returned ESP_OK (0x0)
W (3382) LAB_WIFI_CONN: =======================================================
W (3382) LAB_WIFI_CONN: [EVENT FORENSIC]: WIFI_EVENT_STA_DISCONNECTED received!
W (3392) LAB_WIFI_CONN:   -> Target SSID          : M
W (3392) LAB_WIFI_CONN:   -> Reason Code (Decimal): 201
W (3402) LAB_WIFI_CONN:   -> Reason Code (Hex)    : 0xC9
W (3402) LAB_WIFI_CONN:   -> Reason Description   : WIFI_REASON_NO_AP_FOUND (201)
W (3412) LAB_WIFI_CONN: =======================================================
W (3422) LAB_WIFI_CONN: [RESULT]: TEST FAILED - Disconnected event captured.
I (5432) LAB_WIFI_CONN: 

I (5432) LAB_WIFI_CONN: ------------------------------------------------------------------
I (5432) LAB_WIFI_CONN: >>> Experiment 5.2.2: Connection Test - Wrong SSID (No AP Found)
I (5442) LAB_WIFI_CONN: ------------------------------------------------------------------
I (5442) LAB_WIFI_CONN:   Target SSID: "NON_EXISTENT_SSID_9999"
I (5452) LAB_WIFI_CONN:   Target Password: "12345678"
I (5462) LAB_WIFI_CONN: [FORENSIC]: Call esp_wifi_stop()
E (5462) wifi:NAN WiFi stop
I (5472) LAB_WIFI_CONN: [EVENT FORENSIC]: WIFI_EVENT ID 3 received
I (5472) wifi:flush txq
I (5472) wifi:stop sw txq
I (5482) wifi:lmac stop hw txq
I (5482) LAB_WIFI_CONN: [FORENSIC]: Call esp_wifi_set_config(WIFI_IF_STA,&wifi_config)
I (5512) LAB_WIFI_CONN: [FORENSIC]: esp_wifi_set_config() returned ESP_OK(0x0)
I (5512) LAB_WIFI_CONN: [FORENSIC]: Call esp_wifi_start()
I (5522) wifi:mode : sta (84:1f:e8:39:b4:48)
I (5522) wifi:enable tsf
I (5532) LAB_WIFI_CONN: [EVENT FORENSIC]: WIFI_EVENT_STA_START received
I (5532) LAB_WIFI_CONN: [FORENSIC]: Call esp_wifi_connect()
I (5542) LAB_WIFI_CONN: [FORENSIC]: esp_wifi_connect() returned ESP_OK (0x0)
I (5522) LAB_WIFI_CONN: [FORENSIC]: esp_wifi_start() returned ESP_OK (0x0)
W (7952) LAB_WIFI_CONN: =======================================================
W (7952) LAB_WIFI_CONN: [EVENT FORENSIC]: WIFI_EVENT_STA_DISCONNECTED received!
W (7952) LAB_WIFI_CONN:   -> Target SSID          : NON_EXISTENT_SSID_9999
W (7962) LAB_WIFI_CONN:   -> Reason Code (Decimal): 201
W (7972) LAB_WIFI_CONN:   -> Reason Code (Hex)    : 0xC9
W (7972) LAB_WIFI_CONN:   -> Reason Description   : WIFI_REASON_NO_AP_FOUND (201)
W (7982) LAB_WIFI_CONN: =======================================================
W (7992) LAB_WIFI_CONN: [RESULT]: TEST FAILED - Disconnected event captured.
I (10002) LAB_WIFI_CONN: 

I (10002) LAB_WIFI_CONN: ------------------------------------------------------------------
I (10002) LAB_WIFI_CONN: >>> Experiment 5.2.3: Connection Test - Wrong Password (Auth/Handshake Fail)
I (10012) LAB_WIFI_CONN: ------------------------------------------------------------------
I (10022) LAB_WIFI_CONN:   Target SSID: "M"
I (10022) LAB_WIFI_CONN:   Target Password: "WRONG_PASS_9999"
I (10032) LAB_WIFI_CONN: [FORENSIC]: Call esp_wifi_stop()
E (10032) wifi:NAN WiFi stop
I (10042) LAB_WIFI_CONN: [EVENT FORENSIC]: WIFI_EVENT ID 3 received
I (10042) wifi:flush txq
I (10042) wifi:stop sw txq
I (10052) wifi:lmac stop hw txq
I (10052) LAB_WIFI_CONN: [FORENSIC]: Call esp_wifi_set_config(WIFI_IF_STA, &wifi_config)
I (10102) LAB_WIFI_CONN: [FORENSIC]: esp_wifi_set_config() returned ESP_OK (0x0)
I (10102) LAB_WIFI_CONN: [FORENSIC]: Call esp_wifi_start()
I (10102) wifi:mode : sta (84:1f:e8:39:b4:48)
I (10112) wifi:enable tsf
I (10112) LAB_WIFI_CONN: [EVENT FORENSIC]: WIFI_EVENT_STA_START received
I (10112) LAB_WIFI_CONN: [FORENSIC]: Call esp_wifi_connect()
I (10122) LAB_WIFI_CONN: [FORENSIC]: esp_wifi_connect() returned ESP_OK (0x0)
I (10112) LAB_WIFI_CONN: [FORENSIC]: esp_wifi_start() returned ESP_OK (0x0)
W (12532) LAB_WIFI_CONN: =======================================================
W (12532) LAB_WIFI_CONN: [EVENT FORENSIC]: WIFI_EVENT_STA_DISCONNECTED received!
W (12542) LAB_WIFI_CONN:   -> Target SSID          : M
W (12542) LAB_WIFI_CONN:   -> Reason Code (Decimal): 201
W (12552) LAB_WIFI_CONN:   -> Reason Code (Hex)    : 0xC9
W (12562) LAB_WIFI_CONN:   -> Reason Description   : WIFI_REASON_NO_AP_FOUND (201)
W (12572) LAB_WIFI_CONN: =======================================================
W (12572) LAB_WIFI_CONN: [RESULT]: TEST FAILED - Disconnected event captured.
I (12582) LAB_WIFI_CONN: ==================================================================
I (12592) LAB_WIFI_CONN:   [Phase 2/3/4/5 Completed: Wi-Fi Connection LabFinished]
I (12602) LAB_WIFI_CONN: ==================================================================
I (12612) main_task: Returned from app_main()

Done

## ตารางที่ 1 ผลการทดลอง Lab 5.2

| การทดลอง | ผลที่ได้ | Reason Code | ผลการทดลอง |
|---|---|---|---|
| 5.2.1 ใช้ SSID และรหัสผ่านถูกต้อง | WIFI_EVENT_STA_DISCONNECTED | 201 (0xC9) | ไม่ผ่าน |
| 5.2.2 ใช้ SSID ที่ไม่มีอยู่จริง | WIFI_EVENT_STA_DISCONNECTED | 201 (0xC9) | ไม่ผ่านการเชื่อมต่อ ตามที่คาดหมาย |
| 5.2.3 ใช้รหัสผ่านไม่ถูกต้อง | WIFI_EVENT_STA_DISCONNECTED | 201 (0xC9) | ยังยืนยันผลการทดสอบรหัสผ่านไม่ได้ |

## ตารางที่ 2 ข้อมูลเครือข่ายที่ได้รับ

| รายการ | ผลการทดลอง |
|---|---|
| SSID | M |
| BSSID | ไม่มีข้อมูล |
| Channel | ไม่มีข้อมูล |
| IP Address | ไม่มีข้อมูล |
| Subnet Mask | ไม่มีข้อมูล |
| Gateway | ไม่มีข้อมูล |

## คำถามท้ายการทดลอง
    Lab5_2: Wi-Fi Connection & Events
เหตุใดการระบุ SSID ผิด (ข้อ 5.2.2) จึงส่งผลให้เกิด Disconnect Event ด้วย Reason Code 201 (WIFI_REASON_NO_AP_FOUND) ตั้งแต่เฟส Scan?
    เพราะระบบไม่พบเครือข่าย Wi-Fi ที่มีชื่อ (SSID) ตรงกับที่ระบุในโครงสร้างการเชื่อมต่อ ทำให้กระบวนการค้นหาและจับคู่ล้มเหลวทันที ส่งผลให้เกิด Reason Code 201 แจ้งเตือนว่าไม่พบ Access Point

เหตุใดการพิมพ์ Password ผิด (ข้อ 5.2.3) จึงผ่านเฟส Auth และ Assoc มาได้ แต่มาล้มเหลวในเฟส 4-Way Handshake (Reason Code 15 หรือ 204)?
    เพราะในเฟส Authentication และ Association จะตรวจสอบเพียงสิทธิ์การเข้าถึงระดับลิงก์ (Link-Layer) และความสามารถในการรองรับของ AP เท่านั้น การตรวจสอบความถูกต้องของรหัสผ่าน WPA2-PSK จะเกิดขึ้นในกระบวนการ 4-Way Handshake ภายหลัง เมื่อรหัสผ่านไม่ตรงกัน คีย์ที่สร้างจึงไม่ตรงกันและเกิดข้อผิดพลาดขึ้น

ลำดับการเกิด Event ระหว่าง WIFI_EVENT_STA_CONNECTED กับ IP_EVENT_STA_GOT_IP Event ใดเกิดขึ้นก่อนกัน และมีความหมายทางกายภาพของ Layer Network ต่างกันอย่างไร?
    Event ที่เกิดก่อน: WIFI_EVENT_STA_CONNECTED เกิดขึ้นก่อน
ความแตกต่างทางเลเยอร์:
    WIFI_EVENT_STA_CONNECTED ทำงานอยู่ที่ Data-Link Layer (Layer 2) หมายถึงการเชื่อมต่อคลื่นวิทยุและจับคู่สถานีกับ Access Point สำเร็จแล้ว
    IP_EVENT_STA_GOT_IP ทำงานอยู่ที่ Network Layer (Layer 3) หมายถึงกระบวนการรับค่า IP Address ผ่าน DHCP สำเร็จ และพร้อมสื่อสารบนเครือข่าย IP อย่างสมบูรณ์

สมาชิกตัวแปร reason ในโครงสร้าง wifi_event_sta_disconnected_t มีประโยชน์อย่างไรต่อการออกแบบระบบค้นหาสาเหตุและกู้คืนการเชื่อมต่อ (Auto-Reconnection Mechanism) ในแอปพลิเคชัน IoT?
    ช่วยให้ไมโครคอนโทรลเลอร์ทราบสาเหตุที่แน่ชัดของการตัดการเชื่อมต่อ (เช่น รหัสผ่านผิด, สัญญาณหาย, หรือถูกเตะออกจากเครือข่าย) ทำให้โปรแกรมสามารถเลือกตรรกะในการแก้ไขปัญหาและเชื่อมต่อใหม่ได้อย่างเหมาะสม (เช่น หากรหัสผ่านผิดจะไม่พยายามเชื่อมต่อซ้ำทันที)