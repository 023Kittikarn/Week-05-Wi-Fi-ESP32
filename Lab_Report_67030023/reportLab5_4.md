# report Lab5-4

I (31) boot: ESP-IDF v5.1.2-dirty 2nd stage bootloader
I (31) boot: compile time Oct 24 2026 17:33:09
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
I (96) esp_image: segment 0: paddr=00010020 vaddr=3f400020 size=20024h (131108) map
I (152) esp_image: segment 1: paddr=0003004c vaddr=3ffb0000 size=03a7ch ( 14972) load
I (158) esp_image: segment 2: paddr=00033ad0 vaddr=40080000 size=0c548h ( 50504) load
I (180) esp_image: segment 3: paddr=00040020 vaddr=400d0020 size=813e4h (529380) map
I (371) esp_image: segment 4: paddr=000c140c vaddr=4008c548 size=096f4h ( 38644) load
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
I (433) cpu_start: Project name:     wifi_handshake_ip_phase
I (439) cpu_start: App version:      e6e557f-dirty
I (445) cpu_start: Compile time:     Oct 24 2026 17:33:03
I (451) cpu_start: ELF file SHA256:  adfdfdb0f5f0ee37...
I (457) cpu_start: ESP-IDF:          v5.1.2-dirty
I (462) cpu_start: Min chip rev:     v0.0
I (467) cpu_start: Max chip rev:     v3.99 
I (472) cpu_start: Chip rev:         v3.1
I (477) heap_init: Initializing. RAM available for dynamic allocation:
I (484) heap_init: At 3FFAE6E0 len 00001920 (6 KiB): DRAM
I (490) heap_init: At 3FFB7B20 len 000284E0 (161 KiB): DRAM
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
I (552) LAB_HANDSHAKE_IP: [INIT] Initializing NVS
I (582) LAB_HANDSHAKE_IP: [INIT] Initializing network interface
I (592) LAB_HANDSHAKE_IP: [INIT] Initializing Wi-Fi driver
I (602) wifi:wifi driver task: 3ffbfc20, prio:23, stack:6656, core=0
I (612) wifi:wifi firmware version: 91b9630
I (612) wifi:wifi certification version: v7.0
I (612) wifi:config NVS flash: enabled
I (622) wifi:config nano formating: disabled
I (622) wifi:Init data frame dynamic rx buffer num: 32
I (622) wifi:Init static rx mgmt buffer num: 5
I (632) wifi:Init management short buffer num: 32
I (632) wifi:Init dynamic tx buffer num: 32
I (642) wifi:Init static rx buffer size: 1600
I (642) wifi:Init static rx buffer num: 10
I (642) wifi:Init dynamic rx buffer num: 32
I (652) wifi_init: rx ba win: 6
I (652) wifi_init: tcpip mbox: 32
I (662) wifi_init: udp mbox: 6
I (662) wifi_init: tcp mbox: 6
I (662) wifi_init: tcp tx win: 5744
I (672) wifi_init: tcp rx win: 5744
I (672) wifi_init: tcp mss: 1440
I (682) wifi_init: WiFi IRAM OP enabled
I (682) wifi_init: WiFi RX IRAM OP enabled
I (692) LAB_HANDSHAKE_IP: [INIT] Registering event handlers
I (692) LAB_HANDSHAKE_IP: [INIT] Setting Wi-Fi station mode
I (702) LAB_HANDSHAKE_IP: ==================================================
I (712) LAB_HANDSHAKE_IP: Lab 5.4: 4-Way Handshake and IP Assignment
I (712) LAB_HANDSHAKE_IP: ==================================================
I (722) LAB_HANDSHAKE_IP: 
I (722) LAB_HANDSHAKE_IP: --------------------------------------------------
I (732) LAB_HANDSHAKE_IP: >>> Experiment 5.4.1: Correct Password
I (742) LAB_HANDSHAKE_IP: --------------------------------------------------
I (752) LAB_HANDSHAKE_IP: Target SSID: "M"
I (752) LAB_HANDSHAKE_IP: Password length: 8
I (762) LAB_HANDSHAKE_IP: [FORENSIC] Calling esp_wifi_stop()
I (762) LAB_HANDSHAKE_IP: [FORENSIC] esp_wifi_stop(): ESP_OK (0x0)
I (972) LAB_HANDSHAKE_IP: [FORENSIC] Calling esp_wifi_set_config()
I (992) LAB_HANDSHAKE_IP: [FORENSIC] esp_wifi_set_config(): ESP_OK (0x0)
I (992) LAB_HANDSHAKE_IP: [FORENSIC] Calling esp_wifi_start()
I (1002) phy_init: phy_version 4780,16b31a7,Sep 22 2023,20:42:16
I (1082) wifi:mode : sta (84:1f:e8:39:b4:48)
I (1082) wifi:enable tsf
I (1082) LAB_HANDSHAKE_IP: [FORENSIC] esp_wifi_start(): ESP_OK (0x0)
I (1082) LAB_HANDSHAKE_IP: [FORENSIC] Waiting for connection result (timeout 15000 ms)
I (1082) LAB_HANDSHAKE_IP: [EVENT] WIFI_EVENT_STA_START received
I (1102) LAB_HANDSHAKE_IP: [FORENSIC] Calling esp_wifi_connect()
I (1112) LAB_HANDSHAKE_IP: [FORENSIC] esp_wifi_connect(): ESP_OK (0x0)
W (3522) LAB_HANDSHAKE_IP: [EVENT] WIFI_EVENT_STA_DISCONNECTED received
W (3522) LAB_HANDSHAKE_IP: Target SSID: M
W (3522) LAB_HANDSHAKE_IP: Reason Code: 201 (0xC9)
W (3522) LAB_HANDSHAKE_IP: Diagnosis: WIFI_REASON_NO_AP_FOUND: SSID not found
W (3532) LAB_HANDSHAKE_IP: [RESULT] TEST FAILED
W (3542) LAB_HANDSHAKE_IP: Disconnected or failed during Wi-Fi connection
I (5542) LAB_HANDSHAKE_IP: 
I (5542) LAB_HANDSHAKE_IP: --------------------------------------------------
I (5542) LAB_HANDSHAKE_IP: >>> Experiment 5.4.2: Incorrect Password
I (5542) LAB_HANDSHAKE_IP: --------------------------------------------------
I (5552) LAB_HANDSHAKE_IP: Target SSID: "M"
I (5552) LAB_HANDSHAKE_IP: Password length: 19
I (5562) LAB_HANDSHAKE_IP: [FORENSIC] Calling esp_wifi_stop()
E (5572) wifi:NAN WiFi stop
I (5572) LAB_HANDSHAKE_IP: [EVENT] Wi-Fi event ID: 3
I (5582) wifi:flush txq
I (5582) wifi:stop sw txq
I (5582) wifi:lmac stop hw txq
I (5582) LAB_HANDSHAKE_IP: [FORENSIC] esp_wifi_stop(): ESP_OK (0x0)
I (5792) LAB_HANDSHAKE_IP: [FORENSIC] Calling esp_wifi_set_config()
I (5812) LAB_HANDSHAKE_IP: [FORENSIC] esp_wifi_set_config(): ESP_OK (0x0)
I (5812) LAB_HANDSHAKE_IP: [FORENSIC] Calling esp_wifi_start()
I (5822) wifi:mode : sta (84:1f:e8:39:b4:48)
I (5822) wifi:enable tsf
I (5822) LAB_HANDSHAKE_IP: [EVENT] WIFI_EVENT_STA_START received
I (5832) LAB_HANDSHAKE_IP: [FORENSIC] Calling esp_wifi_connect()
I (5842) LAB_HANDSHAKE_IP: [FORENSIC] esp_wifi_connect(): ESP_OK (0x0)
I (5822) LAB_HANDSHAKE_IP: [FORENSIC] esp_wifi_start(): ESP_OK (0x0)
I (5852) LAB_HANDSHAKE_IP: [FORENSIC] Waiting for connection result (timeout 15000 ms)
W (8252) LAB_HANDSHAKE_IP: [EVENT] WIFI_EVENT_STA_DISCONNECTED received
W (8252) LAB_HANDSHAKE_IP: Target SSID: M
W (8252) LAB_HANDSHAKE_IP: Reason Code: 201 (0xC9)
W (8252) LAB_HANDSHAKE_IP: Diagnosis: WIFI_REASON_NO_AP_FOUND: SSID not found
W (8262) LAB_HANDSHAKE_IP: [RESULT] TEST FAILED
W (8272) LAB_HANDSHAKE_IP: Disconnected or failed during Wi-Fi connection
I (8272) LAB_HANDSHAKE_IP: ==================================================
I (8282) LAB_HANDSHAKE_IP: Lab 5.4 tests finished
I (8292) LAB_HANDSHAKE_IP: ==================================================
I (8302) main_task: Returned from app_main()

## 6.1 ตารางสรุปเปรียบเทียบผลการทดลองใน Handshake & IP Phase

| ข้อการทดลอง | สถานการณ์ทดสอบ | Event WIFI_EVENT_STA_CONNECTED | Event IP_EVENT_STA_GOT_IP | ผลการทดลอง | Disconnect Reason Code |
| :---: | :--- | :---: | :---: | :--- | :--- |
| 5.4.1 | Password ถูกต้อง | ไม่เกิด | ไม่เกิด | ไม่ผ่าน เนื่องจากไม่พบ Access Point | 201 (WIFI_REASON_NO_AP_FOUND) |
| 5.4.2 | Password ผิด | ไม่เกิด | ไม่เกิด | ยังไม่สามารถทดสอบการตรวจสอบ Password ได้ เนื่องจากไม่พบ Access Point | 201 (WIFI_REASON_NO_AP_FOUND) |

## 6.2 บันทึกข้อมูล IP Network จาก Event IP_EVENT_STA_GOT_IP (ข้อ 5.4.1)

| พารามิเตอร์ Network Layer | ค่าที่จัดสรรได้จริงจาก DHCP Server |
| :--- | :--- |
| IP Address | ไม่มีข้อมูล |
| Subnet Mask | ไม่มีข้อมูล |
| Default Gateway | ไม่มีข้อมูล |


## คำถามท้ายการทดลอง
    Lab5_4: 4-Way Handshake & DHCP
เหตุใดกระบวนการ 4-Way Handshake จึงพิสูจน์ทราบรหัสผ่าน Wi-Fi ได้โดยไม่ต้องส่งรหัสผ่าน (Passphrase) ลอยไปในอากาศเลยแม้แต่แพ็กเกจเดียว?
    เพราะระบบใช้หลักการทางคริปโตกราฟี (Cryptographic Challenge-Response) โดยนำรหัสผ่านไปคำนวณร่วมกับข้อมูลเฉพาะ (เช่น Nonce และ MAC Address) เพื่อสร้างคีย์ยืนยันตัวตน ทั้งสองฝ่ายจึงพิสูจน์ได้ว่ามีรหัสผ่านที่ถูกต้องตรงกันโดยไม่ต้องเปิดเผยตัวรหัสผ่านจริงผ่านช่องสัญญาณวิทยุ

อธิบายบทบาทและที่มาของคีย์ PMK (Pairwise Master Key) และ PTK (Pairwise Transient Key) ว่ามีความสัมพันธ์กันอย่างไรในการเข้ารหัสเฟรมข้อมูล?
    PMK (Pairwise Master Key): ได้จากการประมวลผล Passphrase และ SSID ของเครือข่ายด้วยฟังก์ชัน PBKDF2 ทำหน้าที่เป็นคีย์ตั้งต้น
    PTK (Pairwise Transient Key): สร้างขึ้นจากการผสมผสานระหว่าง PMK, MAC Address ของ AP และ STA รวมถึง Nonce ของทั้งสองฝ่ายในกระบวนการ 4-Way Handshake นำมาใช้เข้ารหัสข้อมูลการสื่อสารเฉพาะคู่นั้นๆ (Unicast Traffic)

เหตุใดเมื่อเราพิมพ์ Password ผิด (ข้อ 5.4.2) ESP32 จึงยังคงได้รับ Event WIFI_EVENT_STA_CONNECTED ก่อนที่จะเกิด Event WIFI_EVENT_STA_DISCONNECTED ตามมาในภายหลัง?
    เนื่องจากลำดับการทำงานของระบบ ESP-IDF จะรายงานสถานะการเชื่อมต่อเลเยอร์วิทยุก่อน (WIFI_EVENT_STA_CONNECTED) แต่เมื่อกระบวนการตรวจสอบรหัสผ่านใน 4-Way Handshake ล้มเหลว Access Point จะส่งคำสั่งตัดการเชื่อมต่อ ทำให้เกิด Event WIFI_EVENT_STA_DISCONNECTED ตามมาทันที

หากเครือข่าย Wi-Fi ไม่มี DHCP Server (ไม่มีการแจก IP อัตโนมัติ) ผลการทดลองในข้อ 5.4.1 จะหยุดอยู่ที่ขั้นตอนใด และจะไม่เกิด Event ใดขึ้น?
    จุดที่หยุด: กระบวนการจะเชื่อมต่อ Wi-Fi และผ่าน 4-Way Handshake สำเร็จ แต่จะไม่สามารถรับค่า IP Address ได้
    Event ที่จะไม่เกิดขึ้น: จะไม่เกิด Event IP_EVENT_STA_GOT_IP