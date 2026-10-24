# report Lab5-1

I (31) boot: ESP-IDF v5.1.2-dirty 2nd stage bootloader
I (31) boot: compile time Oct 24 2026 15:05:10
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
I (96) esp_image: segment 0: paddr=00010020 vaddr=3f400020 size=1ff5ch (130908) map
I (152) esp_image: segment 1: paddr=0002ff84 vaddr=3ffb0000 size=00094h (   148) load
I (152) esp_image: segment 2: paddr=00030020 vaddr=400d0020 size=810a0h (528544) map
I (349) esp_image: segment 3: paddr=000b10c8 vaddr=3ffb0094 size=039e8h ( 14824) load
I (355) esp_image: segment 4: paddr=000b4ab8 vaddr=40080000 size=15c3ch ( 89148) load
I (403) boot: Loaded app from partition at offset 0x10000
I (403) boot: Disabling RNG early entropy source...
I (415) cpu_start: Multicore app
I (415) cpu_start: Pro cpu up.
I (415) cpu_start: Starting app cpu, entry point is 0x40081390
--- 0x40081390: call_start_cpu1 at /Users/kittikarnkaewnual/esp/esp-idf/components/esp_system/port/cpu_start.c:157
I (0) cpu_start: App cpu up.
I (433) cpu_start: Pro cpu start user code
I (433) cpu_start: cpu freq: 160000000 Hz
I (433) cpu_start: Application information:
I (438) cpu_start: Project name:     wifi_scan_phase
I (443) cpu_start: App version:      e6e557f
I (448) cpu_start: Compile time:     Oct 24 2026 15:05:02
I (454) cpu_start: ELF file SHA256:  3947e4fa2710b06b...
I (460) cpu_start: ESP-IDF:          v5.1.2-dirty
I (466) cpu_start: Min chip rev:     v0.0
I (470) cpu_start: Max chip rev:     v3.99 
I (475) cpu_start: Chip rev:         v3.1
I (480) heap_init: Initializing. RAM available for dynamic allocation:
I (487) heap_init: At 3FFAE6E0 len 00001920 (6 KiB): DRAM
I (493) heap_init: At 3FFB7B18 len 000284E8 (161 KiB): DRAM
I (499) heap_init: At 3FFE0440 len 00003AE0 (14 KiB): D/IRAM
I (506) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
I (512) heap_init: At 40095C3C len 0000A3C4 (40 KiB): IRAM
I (520) spi_flash: detected chip: generic
I (523) spi_flash: flash io: dio
W (527) spi_flash: Detected size(4096k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (541) app_start: Starting scheduler on CPU0
I (545) app_start: Starting scheduler on CPU1
I (545) main_task: Started on CPU0
I (555) main_task: Calling app_main()
I (555) LAB_WIFI_SCAN: [FORENSIC]: Call nvs_flash_init()
I (585) LAB_WIFI_SCAN: [FORENSIC]: nvs_flash_init() returned ESP_OK (0x0)
I (585) LAB_WIFI_SCAN: [FORENSIC]: Call esp_netif_init()
I (595) LAB_WIFI_SCAN: [FORENSIC]: esp_netif_init() returned ESP_OK (0x0)
I (595) LAB_WIFI_SCAN: [FORENSIC]: Call esp_event_loop_create_default()
I (605) LAB_WIFI_SCAN: [FORENSIC]: esp_event_loop_create_default() returned ESP_OK (0x0)
I (615) LAB_WIFI_SCAN: [FORENSIC]: Call esp_netif_create_default_wifi_sta()
I (625) LAB_WIFI_SCAN: [FORENSIC]: esp_netif_create_default_wifi_sta() returned pointer 0x3ffbd598
I (635) LAB_WIFI_SCAN: [FORENSIC]: Call esp_wifi_init(&cfg)
I (645) wifi:wifi driver task: 3ffbfbf0, prio:23, stack:6656, core=0
I (665) wifi:wifi firmware version: 91b9630
I (665) wifi:wifi certification version: v7.0
I (665) wifi:config NVS flash: enabled
I (665) wifi:config nano formating: disabled
I (665) wifi:Init data frame dynamic rx buffer num: 32
I (675) wifi:Init static rx mgmt buffer num: 5
I (675) wifi:Init management short buffer num: 32
I (685) wifi:Init dynamic tx buffer num: 32
I (685) wifi:Init static 

## ตารางสรุปเปรียบเทียบการสแกนทั้ง 4 กรณี

| ข้อการทดลอง | เงื่อนไขการสแกน | สถานะ (Success/Error Code) | จำนวน AP ที่พบ (เครือข่าย) | เวลาที่ใช้ในการสแกน (ms) |
| :---: | :--- | :---: | :---: | :---: |
| **5.1.1** | สแกนทั่วไปทุก Channel |Success|18| |
| **5.1.2** | กำหนดสแกนเฉพาะ Channel 1 |Success|4| |
| **5.1.3** | กำหนดสแกน SSID ที่มีจริง |Success |1| |
| **5.1.4** | กำหนดสแกน SSID ที่ไม่มีจริง |Success|0| |


## คำถามท้ายการทดลอง
    Lab5_1: Wi-Fi Scanning
การกำหนดค่าในโครงสร้าง wifi_scan_config_t สำหรับสแกนเจาะจงเฉพาะช่องความถี่ (ข้อ 5.1.2) ช่วยลดเวลาในการสแกนเมื่อเทียบกับการสแกนทุกช่องความถี่ (ข้อ 5.1.1) อย่างไร และมีข้อจำกัดอย่างไร?
    การช่วยลดเวลา: ช่วยลดเวลาและพลังงานในการประมวลผลอย่างมาก เนื่องจากตัวรับส่งสัญญาณวิทยุ (Radio) ไม่จำเป็นต้องสลับช่องสัญญาณไปมาครบทุกช่อง (เช่น ช่อง 1-13) แต่จะเจาะจงรับฟังเฉพาะช่องที่ระบุไว้เท่านั้น

ข้อจำกัด: หากเครือข่าย Wi-Fi เป้าหมายไม่ได้ตั้งอยู่บนช่องความถี่ที่ระบุไว้ ESP32 จะไม่สามารถค้นหาเครือข่ายนั้นพบเลย
เมื่อสังเกตผล Forensic Log ในข้อ 5.1.4 (สแกนหา SSID ที่ไม่มีอยู่จริง) ฟังก์ชัน esp_wifi_scan_start(), esp_wifi_scan_get_ap_num() และ esp_wifi_scan_get_ap_records() ส่งคืนค่าอย่างไร?
    esp_wifi_scan_start(): ส่งคืนค่า ESP_OK เมื่อคำสั่งเริ่มกระบวนการสแกนทำงานสำเร็จ
    esp_wifi_scan_get_ap_num(): ส่งคืนจำนวน AP ที่พบเป็น 0 เนื่องจากไม่พบสัญญาณที่ตรงกับเงื่อนไข
    esp_wifi_scan_get_ap_records(): ไม่มีรายการข้อมูล AP ถูกบันทึกลงในบัฟเฟอร์ (Buffer) เพราะไม่มีผลลัพธ์จากการสแกน

ค่าระดับความแรงสัญญาณ (RSSI) ที่แสดงเป็นตัวเลขติดลบ (เช่น -45 dBm กับ -80 dBm) ค่าใดแสดงถึงสัญญาณที่มีความแรงและความเสถียรมากกว่ากัน?
    ค่า -45 dBm มีความแรงและเสถียรมากกว่า -80 dBm เนื่องจากค่า RSSI วัดเป็นหน่วยเดซิเบลเมตรบนสเกลลอการิทึม ค่าที่ติดลบน้อยกว่า (เข้าใกล้ 0 มากกว่า) จะหมายถึงพลังงานสัญญาณที่รับได้มีกำลังสูงกว่า

เหตุใดการดึงค่า authmode (wifi_auth_mode_t) จากโครงสร้าง wifi_ap_record_t จึงมีความสำคัญต่อการเตรียมการในเฟสถัดไป (Authentication & Association Phase)?
    เพื่อให้สถานี (ESP32) ทราบประเภทและระดับการรักษาความปลอดภัยของ Access Point (เช่น Open, WPA2-PSK, WPA3) และสามารถกำหนดค่าพารามิเตอร์การเข้ารหัสให้ถูกต้องสอดคล้องกันก่อนเริ่มกระบวนการเชื่อมต่อ