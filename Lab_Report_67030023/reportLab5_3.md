# report Lab5-3

I (31) boot: ESP-IDF v5.1.2-dirty 2nd stage bootloader
I (31) boot: compile time Oct 24 2026 17:05:19
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
I (96) esp_image: segment 0: paddr=00010020 vaddr=3f400020 size=2020ch (131596) map
I (152) esp_image: segment 1: paddr=00030234 vaddr=3ffb0000 size=03a7ch (14972) load
I (159) esp_image: segment 2: paddr=00033cb8 vaddr=40080000 size=0c360h (50016) load
I (180) esp_image: segment 3: paddr=00040020 vaddr=400d0020 size=811c4h (528836) map
I (371) esp_image: segment 4: paddr=000c11ec vaddr=4008c360 size=098dch (39132) load
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
I (433) cpu_start: Project name:     wifi_auth_assoc_phase
I (439) cpu_start: App version:      e6e557f-dirty
I (444) cpu_start: Compile time:     Oct 24 2026 17:05:12
I (451) cpu_start: ELF file SHA256:  ad1b349ddc3de442...
I (457) cpu_start: ESP-IDF:          v5.1.2-dirty
I (462) cpu_start: Min chip rev:     v0.0
I (467) cpu_start: Max chip rev:     v3.99 
I (471) cpu_start: Chip rev:         v3.1
I (476) heap_init: Initializing. RAM available for dynamic allocation:
I (484) heap_init: At 3FFAE6E0 len 00001920 (6 KiB): DRAM
I (489) heap_init: At 3FFB7B18 len 000284E8 (161 KiB): DRAM
I (496) heap_init: At 3FFE0440 len 00003AE0 (14 KiB): D/IRAM
I (502) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
I (508) heap_init: At 40095C3C len 0000A3C4 (40 KiB): IRAM
I (516) spi_flash: detected chip: generic
I (519) spi_flash: flash io: dio
W (523) spi_flash: Detected size(4096k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (537) app_start: Starting scheduler on CPU0
I (541) app_start: Starting scheduler on CPU1
I (541) main_task: Started on CPU0
I (551) main_task: Calling app_main()
I (551) LAB_AUTH_ASSOC: [FORENSIC]: Call nvs_flash_init()
I (581) LAB_AUTH_ASSOC: [FORENSIC]: nvs_flash_init() returned ESP_OK (0x0)
I (581) LAB_AUTH_ASSOC: [FORENSIC]: Call esp_netif_init()
I (591) LAB_AUTH_ASSOC: [FORENSIC]: Call esp_event_loop_create_default()
I (591) LAB_AUTH_ASSOC: [FORENSIC]: Call esp_netif_create_default_wifi_sta()
I (601) LAB_AUTH_ASSOC: [FORENSIC]: esp_netif_create_default_wifi_sta() returned 0x3ffbd5c0
I (611) LAB_AUTH_ASSOC: [FORENSIC]: Call esp_wifi_init(&cfg)
I (631) wifi:wifi driver task: 3ffbfc18, prio:23, stack:6656, core=0
I (641) wifi:wifi firmware version: 91b9630
I (641) wifi:wifi certification version: v7.0
I (651) wifi:config NVS flash: enabled
I (651) wifi:config nano formating: disabled
I (651) wifi:Init data frame dynamic rx buffer num: 32
I (651) wifi:Init static rx mgmt buffer num: 5
I (661) wifi:Init management short buffer num: 32
I (661) wifi:Init dynamic tx buffer num: 32
I (671) wifi:Init static rx buffer size: 1600
I (671) wifi:Init static rx buffer num: 10
I (671) wifi:Init dynamic rx buffer num: 32
I (681) wifi_init: rx ba win: 6
I (681) wifi_init: tcpip mbox: 32
I (691) wifi_init: udp mbox: 6
I (691) wifi_init: tcp mbox: 6
I (691) wifi_init: tcp tx win: 5744
I (701) wifi_init: tcp rx win: 5744
I (701) wifi_init: tcp mss: 1440
I (711) wifi_init: WiFi IRAM OP enabled
I (711) wifi_init: WiFi RX IRAM OP enabled
I (721) LAB_AUTH_ASSOC: [FORENSIC]: Call esp_event_handler_instance_register(WIFI_EVENT)
I (721) LAB_AUTH_ASSOC: [FORENSIC]: Call esp_wifi_set_mode(WIFI_MODE_STA)
I (731) LAB_AUTH_ASSOC: ==================================================================
I (741) LAB_AUTH_ASSOC:   Lab 5.3: Wi-Fi Authentication & Association Phase (ESP-IDF Forensic)
I (751) LAB_AUTH_ASSOC: ==================================================================
I (761) LAB_AUTH_ASSOC: 

I (761) LAB_AUTH_ASSOC: ------------------------------------------------------------------
I (771) LAB_AUTH_ASSOC: >>> Experiment 5.3.1: Link-Layer Auth & Assoc Phase Test
I (781) LAB_AUTH_ASSOC: ------------------------------------------------------------------
I (791) LAB_AUTH_ASSOC:   Target SSID    : "M"
I (791) LAB_AUTH_ASSOC:   Target Password: "12345678"
I (801) LAB_AUTH_ASSOC: [FORENSIC]: Call esp_wifi_stop()
I (801) LAB_AUTH_ASSOC: [FORENSIC]: Call esp_wifi_set_config(WIFI_IF_STA,&wifi_config)
I (841) LAB_AUTH_ASSOC: [FORENSIC]: esp_wifi_set_config() returned ESP_OK(0x0)
I (841) LAB_AUTH_ASSOC: [FORENSIC]: Call esp_wifi_start()
I (851) phy_init: phy_version 4780,16b31a7,Sep 22 2023,20:42:16
I (931) wifi:mode : sta (84:1f:e8:39:b4:48)
I (931) wifi:enable tsf
I (931) LAB_AUTH_ASSOC: [FORENSIC]: esp_wifi_start() returned ESP_OK (0x0)
I (931) LAB_AUTH_ASSOC: [EVENT FORENSIC]: WIFI_EVENT_STA_START received
I (941) LAB_AUTH_ASSOC: [FORENSIC]: Initiating 802.11 Link-Layer Connection (Auth & Assoc)...
I (951) LAB_AUTH_ASSOC: [FORENSIC]: Call esp_wifi_connect()
I (961) LAB_AUTH_ASSOC: [FORENSIC]: esp_wifi_connect() returned ESP_OK (0x0)
I (1571) wifi:new:<6,0>, old:<1,0>, ap:<255,255>, sta:<6,0>, prof:1
I (1571) wifi:state: init -> auth (b0)
I (2911) wifi:state: auth -> assoc (0)
I (2921) wifi:state: assoc -> run (10)
I (2971) wifi:connected with M, aid = 2, channel 6, BW20, bssid = 32:8e:22:50:12:95
I (2981) wifi:security: WPA3-SAE, phy: bgn, rssi: -55
I (2991) wifi:pm start, type: 1

I (2991) LAB_AUTH_ASSOC: =======================================================
I (2991) LAB_AUTH_ASSOC: [EVENT FORENSIC]: WIFI_EVENT_STA_CONNECTED received!
I (3001) LAB_AUTH_ASSOC:   [SUCCESS]: Phase 2 (Auth) & Phase 3 (Assoc) COMPLETED!
I (3011) LAB_AUTH_ASSOC:   -> Connected SSID        : M
I (3011) LAB_AUTH_ASSOC:   -> BSSID (MAC Address)   : 32:8E:22:50:12:95
I (3021) LAB_AUTH_ASSOC:   -> Channel               : 6
I (3031) LAB_AUTH_ASSOC:   -> Auth Mode             : 7
I (3031) LAB_AUTH_ASSOC:   -> Association ID (AID)  : 3
I (3041) LAB_AUTH_ASSOC: =======================================================
I (3051) LAB_AUTH_ASSOC: [RESULT]: TEST PASSED - Phase 2 (Auth) & Phase 3(Assoc) Successful!
I (3101) wifi:AP's beacon interval = 102400 us, DTIM period = 1
I (3991) esp_netif_handlers: sta ip: 172.20.10.3, mask: 255.255.255.240, gw: 172.20.10.1
I (5061) LAB_AUTH_ASSOC: 

I (5061) LAB_AUTH_ASSOC: ------------------------------------------------------------------
I (5061) LAB_AUTH_ASSOC: >>> Experiment 5.3.2: Link-Layer Test - Non-Existent AP
I (5061) LAB_AUTH_ASSOC: ------------------------------------------------------------------
I (5071) LAB_AUTH_ASSOC:   Target SSID    : "NON_EXISTENT_AP_9999"
I (5081) LAB_AUTH_ASSOC:   Target Password: "12345678"
I (5091) LAB_AUTH_ASSOC: [FORENSIC]: Call esp_wifi_stop()
I (5091) wifi:state: run -> init (0)
I (5101) wifi:pm stop, total sleep time: 1197623 us / 2107216 us

I (5101) wifi:new:<6,0>, old:<6,0>, ap:<255,255>, sta:<6,0>, prof:1
E (5111) wifi:NAN WiFi stop
W (5111) LAB_AUTH_ASSOC: =======================================================
W (5121) LAB_AUTH_ASSOC: [EVENT FORENSIC]: WIFI_EVENT_STA_DISCONNECTED received!
W (5131) LAB_AUTH_ASSOC:   -> Target SSID          : M
W (5131) LAB_AUTH_ASSOC:   -> Reason Code (Decimal): 8
W (5141) LAB_AUTH_ASSOC:   -> Reason Code (Hex)    : 0x08
W (5141) LAB_AUTH_ASSOC:   -> Reason Diagnosis     : OTHER_DISCONNECT_REASON
W (5151) LAB_AUTH_ASSOC: =======================================================
I (5161) LAB_AUTH_ASSOC: [EVENT FORENSIC]: WIFI_EVENT ID 3 received
I (5191) wifi:flush txq
I (5191) wifi:stop sw txq
I (5191) wifi:lmac stop hw txq
I (5191) LAB_AUTH_ASSOC: [FORENSIC]: Call esp_wifi_set_config(WIFI_IF_STA, &wifi_config)
I (5211) LAB_AUTH_ASSOC: [FORENSIC]: esp_wifi_set_config() returned ESP_OK (0x0)
I (5211) LAB_AUTH_ASSOC: [FORENSIC]: Call esp_wifi_start()
I (5221) wifi:mode : sta (84:1f:e8:39:b4:48)
I (5221) wifi:enable tsf
I (5231) LAB_AUTH_ASSOC: [FORENSIC]: esp_wifi_start() returned ESP_OK (0x0)
I (5231) LAB_AUTH_ASSOC: [EVENT FORENSIC]: WIFI_EVENT_STA_START received
I (5241) LAB_AUTH_ASSOC: [FORENSIC]: Initiating 802.11 Link-Layer Connection (Auth & Assoc)...
I (5251) LAB_AUTH_ASSOC: [FORENSIC]: Call esp_wifi_connect()
I (5261) LAB_AUTH_ASSOC: [FORENSIC]: esp_wifi_connect() returned ESP_OK (0x0)
W (5261) LAB_AUTH_ASSOC: [RESULT]: TEST FAILED - Disconnected event captured in Link-Layer.
I (5271) LAB_AUTH_ASSOC: ==================================================================
I (5281) LAB_AUTH_ASSOC:   [Phase 2 & Phase 3 Completed: Link-Layer Auth & Assoc Finished]
I (5291) LAB_AUTH_ASSOC: ==================================================================
I (5301) main_task: Returned from app_main()
W (7671) LAB_AUTH_ASSOC: =======================================================
W (7671) LAB_AUTH_ASSOC: [EVENT FORENSIC]: WIFI_EVENT_STA_DISCONNECTED received!
W (7671) LAB_AUTH_ASSOC:   -> Target SSID          : NON_EXISTENT_AP_9999
W (7681) LAB_AUTH_ASSOC:   -> Reason Code (Decimal): 201
W (7691) LAB_AUTH_ASSOC:   -> Reason Code (Hex)    : 0xC9
W (7691) LAB_AUTH_ASSOC:   -> Reason Diagnosis     : WIFI_REASON_NO_AP_FOUND (201) [Phase 1: SSID Not Found]
W (7701) LAB_AUTH_ASSOC: =======================================================

## ตารางที่ 1 ผลการทดลอง Lab 5.3

| การทดลอง | Event ที่ได้รับ | Reason Code | AID | ผลการทดลอง |
|---|---|---|---|---|
| 5.3.1 เชื่อมต่อ Access Point ที่มีอยู่จริง | WIFI_EVENT_STA_CONNECTED | - | 3 | ผ่านการทดสอบ Phase 2 และ Phase 3 |
| 5.3.2 เชื่อมต่อ Access Point ที่ไม่มีอยู่จริง | WIFI_EVENT_STA_DISCONNECTED | 201 (0xC9) | - | ไม่สามารถเชื่อมต่อได้ เนื่องจากไม่พบ Access Point |

## ตารางที่ 2 รายละเอียดการเชื่อมต่อ Wi-Fi

| รายการ | ผลการทดลอง |
|---|---|
| SSID | M |
| BSSID (MAC Address) | 32:8E:22:50:12:95 |
| Channel | 6 |
| Auth Mode | 7 (WPA3-SAE) |
| Association ID (AID) | 3 |
| IP Address | 172.20.10.3 |
| Subnet Mask | 255.255.255.240 |
| Gateway | 172.20.10.1 |


## คำถามท้ายการทดลอง
    Lab5_3: Association ID & Handshake Phases
Association ID (AID) คืออะไร มีบทบาทอย่างไรใน Phase 3 และส่งคืนมาในโครงสร้างข้อมูลตัวแปรใด?
    ความหมายและบทบาท: AID คือหมายเลขประจำตัวสถานี (Station ID) ที่ Access Point กำหนดให้เมื่อทำการ Association สำเร็จ เพื่อใช้ระบุตัวตนในการรับส่งเฟรมข้อมูลระหว่างกัน
    ตัวแปรที่เก็บ: ถูกเก็บไว้ในสมาชิกตัวแปร aid ของโครงสร้าง wifi_event_sta_connected_t

เหตุใดการเชื่อมต่อ Wi-Fi ความปลอดภัยแบบ WPA2-PSK จึงสามารถผ่าน Phase 2 (Authentication) และ Phase 3 (Association) จนเกิด Event WIFI_EVENT_STA_CONNECTED ได้สำเร็จ แม้ผู้ใช้จะป้อนรหัสผ่าน (Password) ผิด?
    เนื่องจากโปรโตคอลความปลอดภัย WPA2-PSK ออกแบบให้ขั้นตอน Open System Authentication และ Association ทำหน้าที่แค่ยืนยันตัวตนระดับโครงสร้างและการเชื่อมต่อเครือข่ายไร้สายเบื้องต้นเท่านั้น โดยการตรวจสอบความถูกต้องของรหัสผ่านจะถูกแยกไปทำในขั้นตอน 4-Way Handshake ที่ตามมาหลังจากเกิด Event เชื่อมต่อแล้ว

หาก Router มีการตั้งค่า MAC Address Filtering (อนุญาตเฉพาะ MAC ที่ลงทะเบียน) ESP32 จะล้มเหลวในเฟสใด และจะส่ง Disconnect Reason Code ใดออกมา?
    เฟสที่ล้มเหลว: เฟส Association (Phase 3)
    Reason Code: จะได้รับ Reason Code เช่น WIFI_REASON_ASSOC_NOT_AUTHED (Code 2) หรือโค้ดที่ระบุว่าไม่อนุญาตให้เชื่อมต่อเนื่องจากข้อจำกัดนโยบายของ MAC Address

สรุปความแตกต่างสำคัญระหว่างจุดสิ้นสุดของ Phase 3 (Link-Layer Connected) กับจุดสิ้นสุดของ Phase 5 (IP Address Assigned)
    Phase 3 (Link-Layer): สิ้นสุดเมื่อสถานีจับคู่คลื่นวิทยุและเชื่อมต่อเลเยอร์ 2 กับ Access Point สำเร็จ (ได้สถานะ Connected แต่ยังใช้งานอินเทอร์เน็ตไม่ได้)
    Phase 5 (IP Address): สิ้นสุดเมื่อระบบได้รับ IP Address, Subnet Mask และ Gateway เรียบร้อยแล้ว พร้อมสำหรับการรับส่งแพ็กเกจข้อมูลบนเครือข่ายไอพี