#include <stdio.h>
#include "bsp/esp_bsp_generic.h"
#include "esp_lcd_panel_ops.h"

void app_main(void)
{
    /* 1. Инициализация дисплея и LVGL на основе настроек menuconfig */
    bsp_display_start();
    /* 2. Включение подсветки (если настроен пин в menuconfig) */
    bsp_display_backlight_on();


    /* 3. Работа с LVGL (обязательно под блокировкой для потокобезопасности) */
    bsp_display_lock(0);

    // Здесь ваш код интерфейса LVGL, например:
    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello GC9A01!");
    lv_obj_center(label);

    bsp_display_unlock();
}
