## Окружение
* **ESP-IDF:** v5.5.2
* **Target:** ESP32-S3
* **Основные компоненты:**
  - bsp_generic 3.0.2
  - lvgl v9.5.0
### Создаем новый проект
```bash
idf.py create-project gc9a01_bsp_generic
```
### Указываем целевой контроллер для проекта (классический ESP32 WROOM или VROVER)
```bash
idf.py set-target esp32
```
### Установливаем компонент esp_bsp_generic через менеджер компонентов (IDF Component Manager).
Смотри [Реестр компонентов (ESP Component Registry)](https://components.espressif.com).

Ставим версию 3 позволяя обновляться на минорные версии (например, с 3.0.2 до 3.1.0), но блокирует мажорные обновления (переход на 4.0.0 не произойдет).
```bash
idf.py add-dependency "espressif/esp_bsp_generic^3.0.0"
```
Или ставим строго фиксированную версию 3.0.2
```bash
idf.py add-dependency "espressif/esp_bsp_generic==3.0.2"
```
На момент разработки версия компонента 3.0.2. Он включает в себя еще и следующие компоненты:
```bash
NOTICE: Processing 16 dependencies:
NOTICE: [1/16] espressif/button (4.1.6)
NOTICE: [2/16] espressif/cmake_utilities (0.5.3)
NOTICE: [3/16] espressif/esp_bsp_generic (3.0.2)
NOTICE: [4/16] espressif/esp_lcd_gc9a01 (2.0.4)
NOTICE: [5/16] espressif/esp_lcd_ili9341 (2.0.2)
NOTICE: [6/16] espressif/esp_lcd_touch (1.2.1)
NOTICE: [7/16] espressif/esp_lcd_touch_cst816s (1.1.1)
NOTICE: [8/16] espressif/esp_lcd_touch_ft5x06 (1.1.0)
NOTICE: [9/16] espressif/esp_lcd_touch_gt1151 (1.1.0)
NOTICE: [10/16] espressif/esp_lcd_touch_gt911 (1.2.0~1)
NOTICE: [11/16] espressif/esp_lcd_touch_tt21100 (1.2.0)
NOTICE: [12/16] espressif/esp_lvgl_port (2.7.2)
NOTICE: [13/16] espressif/led_indicator (2.0.2)
NOTICE: [14/16] espressif/led_strip (3.0.3)
NOTICE: [15/16] lvgl/lvgl (9.5.0)
NOTICE: [16/16] idf (5.5.2)
...
ESP_LCD_GC9A01: 2.0.4
ESP_LCD_ILI9341: 2.0.2
```
### Заходим в menuconfig и настрайваем дисплей
```bash
idf.py menuconfig
```
- Component config
  - Board Support Package (generic)
    - Display
      - [x] Enable display
        - Connection
          - (18) Display SPI SCLK GPIO
          - (23) Display SPI MOSI GPIO
          - (-1) Display SPI MISO GPIO
          - (5) Display SPI CS GPIO
          - (2) Display SPI DC GPIO
          - (4) Display reset GPIO
          - (-1) Display backlight GPIO
        - Display driver
          - [x] GC9A01
        - Rotation
          - [x] Mirror X
        - Color space
          - [x] BGR
      - [x] Invert colors
      - (240) Display width

### Подключение пинов.
|**GC9A01**|
|----------|
|RST       |
|CS        |
|DC        |
|SDA       |
|SCL       |
|GND       |
|VCC       |


