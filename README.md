## Окружение
* **ESP-IDF:** v5.5.2
* **Target:** ESP32-S3
* **Основные компоненты:**
  - bsp_generic 3.0.2
  - lvgl v9


### Создаем новый проект
```bash
idf.py create-project gc9a01_bsp_generic
```
### Указываем целевой контроллер для проекта (классический ESP32 WROOM или VROVER)
```bash
idf.py set-target esp32
```
### Установливаем компонент esp_bsp_generic через менеджер компонентов (IDF Component Manager).
```bash
idf.py add-dependency "espressif/esp_bsp_generic^3.0.0"
```
[Реестр компонентов (ESP Component Registry)](https://components.espressif.com)
