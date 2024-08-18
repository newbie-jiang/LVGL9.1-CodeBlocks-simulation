/**
 ******************************************************************************
 * @file    lesson_3_4_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-5-23
 * @brief	Lesson 3-4-1 demo
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2024-5-23     zhouyuebiao     First version
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

#if LV_USE_LESSON_DEMO_3_4_1

#include "lesson_3_4_1.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void event_handler_3_4_1(lv_event_t * e);
static void event_handler_3_4_2(lv_event_t * e);
static void event_handler_3_4_4(lv_event_t * e);
static void event_handler_3_4_6(lv_event_t * e);

static void style_init_4_4_5(void);

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_style_t style_part_main;
static lv_style_t style_part_knob;
static lv_style_t style_part_knob_pr;
static lv_style_t style_part_indicator;
static lv_style_t style_label;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void lesson_3_4_1(void)
{

#if 1 // 3-4-1
    lv_obj_t * slider = lv_slider_create(lv_screen_active());
    lv_obj_add_flag(slider, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_set_ext_click_area(slider, 10);
    lv_obj_set_style_pad_all(slider, 10, LV_PART_MAIN);
    lv_obj_set_style_pad_all(slider, 0, LV_PART_KNOB);
    //lv_obj_set_size(slider, 40, 200);
    lv_slider_set_value(slider, 90, LV_ANIM_ON);
    lv_obj_center(slider);

    //lv_obj_add_event_cb(slider, event_handler_3_4_1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(slider, event_handler_3_4_1, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(slider, event_handler_3_4_1, LV_EVENT_RELEASED, NULL);

#elif 0 // 3-4-2
    lv_obj_t * slider = lv_slider_create(lv_screen_active());
    lv_slider_set_range(slider, 0, 255);
    //lv_obj_set_size(slider, 40, 200);
    lv_slider_set_value(slider, 255, LV_ANIM_ON);
    lv_obj_center(slider);

    lv_obj_t *obj = lv_obj_create(lv_screen_active());
    lv_obj_set_style_border_width(obj, 0, 0);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0x6edf59), 0);
    lv_obj_align_to(obj, slider, LV_ALIGN_OUT_TOP_MID, 0, -30);

    lv_obj_add_event_cb(slider, event_handler_3_4_2, LV_EVENT_VALUE_CHANGED, obj);

#elif 0 // 3-4-3
    lv_obj_t * slider = lv_slider_create(lv_screen_active());
    lv_obj_set_size(slider, 300, 60);
    lv_obj_center(slider);
    lv_obj_set_style_transform_width(slider, 0, LV_PART_KNOB | LV_STATE_PRESSED);
    lv_obj_set_style_transform_height(slider, 0, LV_PART_KNOB | LV_STATE_PRESSED);

#elif 0 // 3-4-4
    lv_obj_t * slider = lv_slider_create(lv_screen_active());
    lv_obj_set_size(slider, 60, 300);
    lv_obj_center(slider);

    lv_obj_set_style_radius(slider, 15, 0);
    lv_obj_set_style_bg_color(slider, lv_color_hex(0x5a5041), LV_PART_MAIN);
    lv_obj_set_style_radius(slider, 15, LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(slider, lv_color_hex(0xffffff), LV_PART_INDICATOR);
    //lv_obj_set_style_opa(slider, LV_OPA_TRANSP, LV_PART_KNOB);

    //lv_obj_set_style_opa(slider, LV_OPA_TRANSP, LV_PART_KNOB);
    lv_obj_set_style_pad_all(slider, 0, LV_PART_KNOB);
    lv_obj_set_style_pad_top(slider, -30, LV_PART_KNOB);
    lv_obj_set_style_pad_bottom(slider, -18, LV_PART_KNOB);
    lv_obj_set_style_radius(slider, 0, LV_PART_KNOB);
    lv_obj_set_style_bg_color(slider, lv_color_hex(0xffffff), LV_PART_KNOB);
    lv_obj_set_style_transform_width(slider, 0, LV_PART_KNOB | LV_STATE_PRESSED);
    lv_obj_set_style_transform_height(slider, 0, LV_PART_KNOB | LV_STATE_PRESSED);

    lv_obj_add_event_cb(slider, event_handler_3_4_4, LV_EVENT_VALUE_CHANGED, NULL);

    lv_obj_t *label = lv_label_create(lv_screen_active());
    lv_obj_set_style_text_font(label, &lv_font_montserrat_30, 0);
    lv_label_set_text(label, LV_SYMBOL_EYE_OPEN);

    lv_obj_align(label, LV_ALIGN_CENTER, 0, 130);

#elif 0 // 3-4-5

    lv_obj_t * slider;
    lv_obj_t *label;

    style_init_4_4_5();

    for(int i = 0; i < 10; i++)
    {
        slider = lv_slider_create(lv_screen_active());
        lv_obj_set_size(slider, 60, 300);
        lv_slider_set_value(slider, 70, LV_ANIM_OFF);
        lv_obj_align(slider, LV_ALIGN_LEFT_MID, (70 * i) + 30, 0);
        lv_obj_add_event_cb(slider, event_handler_3_4_4, LV_EVENT_VALUE_CHANGED, NULL);

        label = lv_label_create(lv_screen_active());
        lv_label_set_text(label, LV_SYMBOL_EYE_OPEN);
        lv_obj_align_to(label, slider, LV_ALIGN_CENTER, 0, 100);

        lv_obj_add_style(slider, &style_part_main, LV_PART_MAIN);
        lv_obj_add_style(slider, &style_part_indicator, LV_PART_INDICATOR);
        lv_obj_add_style(slider, &style_part_knob, LV_PART_KNOB);
        lv_obj_add_style(slider, &style_part_knob_pr, LV_PART_KNOB | LV_STATE_PRESSED);

        lv_obj_add_style(label, &style_label, LV_PART_MAIN);
    }

#elif 0 // 3-4-6

    lv_obj_t * slider;
    lv_obj_t *label;

    style_init_4_4_5();

    slider = lv_slider_create(lv_screen_active());
    lv_obj_add_flag(slider, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_set_size(slider, 60, 300);
    lv_slider_set_value(slider, 70, LV_ANIM_OFF);
    lv_obj_center(slider);
    lv_obj_add_event_cb(slider, event_handler_3_4_6, LV_EVENT_HIT_TEST, NULL);

    label = lv_label_create(lv_screen_active());
    lv_label_set_text(label, LV_SYMBOL_EYE_OPEN);
    lv_obj_align_to(label, slider, LV_ALIGN_CENTER, -20, 100);

    lv_obj_add_style(slider, &style_part_main, LV_PART_MAIN);
    lv_obj_add_style(slider, &style_part_indicator, LV_PART_INDICATOR);
    lv_obj_add_style(slider, &style_part_knob, LV_PART_KNOB);
    lv_obj_add_style(slider, &style_part_knob_pr, LV_PART_KNOB | LV_STATE_PRESSED);

    lv_obj_add_style(label, &style_label, LV_PART_MAIN);

#endif


}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void event_handler_3_4_1(lv_event_t * e)
{
    int32_t slider_value = 0;
    lv_obj_t * slider = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);

    slider_value = lv_slider_get_value(slider);
    if(code == LV_EVENT_VALUE_CHANGED) {
        LV_LOG_USER("LV_EVENT_VALUE_CHANGED: %d%%", slider_value);

    }
    else if(code == LV_EVENT_RELEASED ) {
        LV_LOG_USER("LV_EVENT_RELEASED ");
    }
}

static void event_handler_3_4_2(lv_event_t * e)
{
    int32_t slider_value = 0;
    lv_obj_t * slider = lv_event_get_target(e);
    lv_obj_t * obj = lv_event_get_user_data(e);

    slider_value = lv_slider_get_value(slider);
    LV_LOG_USER("LV_EVENT_VALUE_CHANGED: %d%%", slider_value);
    //lv_obj_set_style_opa(obj, slider_value, 0);
    lv_obj_set_style_bg_opa(obj, slider_value, 0);
    //lv_obj_set_style_border_opa(obj, slider_value, 0);
}

static void event_handler_3_4_4(lv_event_t * e)
{
    int32_t slider_value = 0;
    lv_obj_t * slider = lv_event_get_target(e);

    slider_value = lv_slider_get_value(slider);
    LV_LOG_USER("LV_EVENT_VALUE_CHANGED: %d%%", slider_value);
    //lv_obj_set_style_opa(obj, slider_value, 0);

    if((slider_value >= 98) || (slider_value <= 4))
    {
        lv_obj_set_style_opa(slider, LV_OPA_TRANSP, LV_PART_KNOB);
    }
    else
    {
        lv_obj_set_style_opa(slider, LV_OPA_COVER, LV_PART_KNOB);
    }
}


static void event_handler_3_4_6(lv_event_t * e)
{
    lv_obj_t *slider = lv_event_get_current_target(e);

    lv_indev_t *indev = lv_indev_get_act();
    if (indev == NULL)
        return;

    LV_LOG_USER("event_handler_3_4_6");
    int16_t sensitive = 3;  // // TODO: You can adjust the sensitivity
    lv_point_t vect;
    lv_indev_get_vect(indev, &vect);
    LV_LOG_USER("vect.x: %d, vect.y: %d\n", vect.x, vect.y);
    if (vect.y < -sensitive)
        lv_slider_set_value(slider, (lv_slider_get_value(slider) + 5), LV_ANIM_ON);
    else if (vect.y > sensitive)
        lv_slider_set_value(slider, (lv_slider_get_value(slider) - 5), LV_ANIM_ON);
}

static void style_init_4_4_5(void)
{
    lv_style_init(&style_part_main);
    lv_style_set_radius(&style_part_main, 15);
    lv_style_set_bg_color(&style_part_main, lv_color_hex(0x5a5041));

    lv_style_init(&style_part_indicator);
    lv_style_set_radius(&style_part_indicator, 15);
    lv_style_set_bg_color(&style_part_indicator, lv_color_hex(0xffffff));

    lv_style_init(&style_part_knob);
    //lv_style_set_opa(&style_part_knob, LV_OPA_TRANSP);
    //lv_style_set_opa(&style_part_knob, LV_OPA_TRANSP);
    lv_style_set_pad_all(&style_part_knob, 0);
    lv_style_set_pad_top(&style_part_knob, -30);
    lv_style_set_pad_bottom(&style_part_knob, -18);
    lv_style_set_radius(&style_part_knob, 0);
    lv_style_set_bg_color(&style_part_knob, lv_color_hex(0xffffff));

    lv_style_init(&style_part_knob_pr);
    lv_style_set_transform_width(&style_part_knob_pr, 0);
    lv_style_set_transform_height(&style_part_knob_pr, 0);

    lv_style_init(&style_label);
    lv_style_set_text_font(&style_label, &lv_font_montserrat_30);
}

#endif /* LV_USE_LESSON_DEMO_3_4_1 */
