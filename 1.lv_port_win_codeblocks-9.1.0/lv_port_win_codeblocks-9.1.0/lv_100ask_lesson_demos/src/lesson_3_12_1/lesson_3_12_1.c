/**
 ******************************************************************************
 * @file    lesson_3_12_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-6-14
 * @brief	Lesson 3_12_1 demo
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2024-6-14     zhouyuebiao     First version
 ******************************************************************************
 * @attention
 *
 * Copyright (C) 2008-2024 深圳百问网科技有限公司<https://www.100ask.net/>
 * All rights reserved
 *
 * 代码配套的视频教程：
 *      B站：   https://www.bilibili.com/video/BV1WE421K75k
 *      百问网：https://fnwcn.xetslk.com/s/39njGj
 *      淘宝：  https://detail.tmall.com/item.htm?id=779667445604
 *
 * 本程序遵循MIT协议, 请遵循协议！
 * 免责声明: 百问网编写的文档, 仅供学员学习使用, 可以转发或引用(请保留作者信息),禁止用于商业用途！
 * 免责声明: 百问网编写的程序, 仅供学习参考，假如被用于商业用途, 但百问网不承担任何后果！
 *
 * 百问网学习平台   : https://www.100ask.net
 * 百问网交流社区   : https://forums.100ask.net
 * 百问网LVGL文档   : https://lvgl.100ask.net
 * 百问网官方B站    : https://space.bilibili.com/275908810
 * 百问网官方淘宝   : https://100ask.taobao.com
 * 百问网微信公众号 ：百问科技 或 baiwenkeji
 * 联系我们(E-mail):  support@100ask.net 或 fae_100ask@163.com
 *
 *                             版权所有，盗版必究。
 ******************************************************************************
 */

/*********************
 *      INCLUDES
 *********************/
#include "../../lv_100ask_lesson_demos.h"

#if LV_USE_LESSON_DEMO_3_12_1

#include "lesson_3_12_1.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void event_handler_3_12_2(lv_event_t * e);
static void slider_event_cb_3_12_3(lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lesson_3_12_1(void)
{
#if 1 // 3_12_1
    /*Create a LED and switch it OFF*/
    lv_obj_t * led1  = lv_led_create(lv_screen_active());
    lv_obj_align(led1, LV_ALIGN_CENTER, -80, 0);
    lv_led_off(led1);

    /*Copy the previous LED and set a brightness*/
    lv_obj_t * led2  = lv_led_create(lv_screen_active());
    lv_obj_align(led2, LV_ALIGN_CENTER, 0, 0);
    lv_led_set_brightness(led2, LV_LED_BRIGHT_MAX);
    lv_led_set_color(led2, lv_palette_main(LV_PALETTE_RED));

    /*Copy the previous LED and switch it ON*/
    lv_obj_t * led3  = lv_led_create(lv_screen_active());
    //lv_obj_set_size(led3, 50, 50);
    lv_obj_align(led3, LV_ALIGN_CENTER, 80, 0);
    lv_led_on(led3);

    //lv_obj_set_style_radius(led3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
#elif 0 // 3_12_2
    lv_obj_t * led  = lv_led_create(lv_screen_active());
    lv_obj_set_size(led, 50, 50);
    lv_obj_align(led, LV_ALIGN_CENTER, 80, 0);
    lv_led_on(led);

    lv_obj_t * label;

    lv_obj_t * btn1 = lv_button_create(lv_screen_active());
    lv_obj_add_event_cb(btn1, event_handler_3_12_2, LV_EVENT_CLICKED, led);
    lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -40);
    lv_obj_remove_flag(btn1, LV_OBJ_FLAG_PRESS_LOCK);

    label = lv_label_create(btn1);
    lv_label_set_text(label, "Button");
    lv_obj_center(label);

    lv_obj_t * btn2 = lv_button_create(lv_screen_active());
    lv_obj_add_event_cb(btn2, event_handler_3_12_2, LV_EVENT_VALUE_CHANGED, led);
    lv_obj_align(btn2, LV_ALIGN_CENTER, 0, 40);
    lv_obj_add_flag(btn2, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_height(btn2, LV_SIZE_CONTENT);
    lv_obj_add_state(btn2, LV_STATE_CHECKED);

    label = lv_label_create(btn2);
    lv_label_set_text(label, "Toggle");
    lv_obj_center(label);
#elif 0 // 3_12_3
    lv_obj_t * led  = lv_led_create(lv_screen_active());
    lv_obj_set_size(led, 50, 50);
    lv_obj_align(led, LV_ALIGN_CENTER, 0, 80);
    lv_led_off(led);

    lv_obj_t * slider = lv_slider_create(lv_screen_active());
    lv_slider_set_range(slider, 0, 255);
    lv_obj_center(slider);
    lv_obj_add_event_cb(slider, slider_event_cb_3_12_3, LV_EVENT_VALUE_CHANGED, led);
#elif 0 // 3_12_4
    lv_obj_t * led  = lv_led_create(lv_screen_active());
    lv_obj_set_size(led, 50, 50);
    lv_obj_align(led, LV_ALIGN_CENTER, 0, 80);
    lv_led_off(led);
    //lv_obj_set_style_bg_color(led, lv_color_hex(0xe74032), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_led_set_color(led, lv_palette_main(LV_PALETTE_RED));
    lv_obj_set_style_shadow_spread(led, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * slider = lv_slider_create(lv_screen_active());
    lv_slider_set_range(slider, 0, 255);
    lv_obj_center(slider);
    lv_obj_add_event_cb(slider, slider_event_cb_3_12_3, LV_EVENT_VALUE_CHANGED, led);


#endif
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void event_handler_3_12_2(lv_event_t * e)
{
    lv_obj_t * btn = lv_event_get_target(e);
    lv_obj_t * led = lv_event_get_user_data(e);
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED) {
        lv_led_toggle(led);
        LV_LOG_USER("Clicked");
    }
    else if(code == LV_EVENT_VALUE_CHANGED) {
        LV_LOG_USER("Toggled");
        if(lv_obj_get_state(btn) & LV_STATE_CHECKED)
            lv_led_on(led);
        else 
            lv_led_off(led);
    }
}


static void slider_event_cb_3_12_3(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);
    lv_obj_t * led = lv_event_get_user_data(e);

    uint8_t led_brightness = (uint8_t)lv_slider_get_value(slider);
    lv_led_set_brightness(led, led_brightness);
}

#endif /* LV_USE_LESSON_DEMO_3_12_1 */
