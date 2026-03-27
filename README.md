## Окружение (для себя)
* **ESP-IDF:** v5.1.2 (обязательно укажи свою версию)
* **Target:** ESP32-S3 (или твой чип)
* **Основные компоненты:**
  - led_strip v2.1.0
  - lvgl v8.3.11


### Создаем новый проект
```bash
idf.py create-project gc9a01_bsp_generic
```
### Указываем целевой контроллер для проекта (классический ESP32 WROOM или VROVER)
```bash
idf.py set-target esp32
```
