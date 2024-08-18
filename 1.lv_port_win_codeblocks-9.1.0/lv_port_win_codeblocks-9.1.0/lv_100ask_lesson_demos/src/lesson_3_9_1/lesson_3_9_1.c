/**
 ******************************************************************************
 * @file    lesson_3_9_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-6-5
 * @brief	Lesson 3-9-1 demo
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2024-6-5     zhouyuebiao     First version
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

#if LV_USE_LESSON_DEMO_3_9_1

#include "lesson_3_9_1.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void event_handler(lv_event_t * e);
static void exercise_3_9_2(lv_obj_t * obj);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lesson_3_9_1(void)
{
#if 1  // 3-9-1
    lv_obj_t * sw;

    sw = lv_switch_create(lv_screen_active());
    //lv_obj_add_event_cb(sw, event_handler, LV_EVENT_ALL, NULL);

    //lv_obj_set_size(sw, 300, 120);
    //lv_obj_center(sw);

    //lv_obj_set_style_radius(sw, 0, LV_PART_MAIN);
    //lv_obj_set_style_bg_color(sw, lv_color_hex(0x54c33d), LV_PART_MAIN);
    //lv_obj_set_style_bg_opa(sw, LV_OPA_COVER, LV_PART_INDICATOR);
    //lv_obj_set_style_bg_color(sw, lv_color_hex(0x54c33d), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_color(sw, lv_color_hex(0xd75249), LV_PART_INDICATOR | LV_STATE_CHECKED);

    //lv_obj_add_state(sw, LV_STATE_CHECKED);
    //lv_obj_remove_state(sw, LV_STATE_CHECKED);

    //lv_obj_add_state(sw, LV_STATE_DISABLED);
    //lv_obj_remove_state(sw, LV_STATE_DISABLED);

    // btn test
    //lv_obj_t * btn2 = lv_button_create(lv_screen_active());
    //lv_obj_add_flag(btn2, LV_OBJ_FLAG_CHECKABLE);
    //lv_obj_add_state(btn2, LV_STATE_CHECKED);
    //lv_obj_remove_state(btn2, LV_STATE_CHECKED);

#elif 0  // 3-9-2
    lv_obj_t * sw;

    sw = lv_switch_create(lv_screen_active());
    lv_obj_set_size(sw, 300, 120);
    lv_obj_center(sw);

    //lv_obj_set_style_pad_all(sw, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_opa(sw, LV_OPA_0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_opa(sw, LV_OPA_100, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_color(sw, lv_color_hex(0x909090), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_color(sw, lv_color_hex(0x91b6b7), LV_PART_INDICATOR | LV_STATE_CHECKED);
    //lv_obj_set_style_bg_color(sw, lv_color_hex(0x3f8586), LV_PART_KNOB| LV_STATE_CHECKED);

    // 课后练习，请尝试自己练习后再阅读代码
    //exercise_3_9_2(sw);

#elif 0  // 3-9-3
    lv_obj_t * sw;

    sw = lv_switch_create(lv_screen_active());
    lv_obj_set_size(sw, 300, 120);
    lv_obj_center(sw);

    //lv_obj_set_style_bg_opa(sw, LV_OPA_100, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_color(sw, lv_color_hex(0xf7eeb4), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_color(sw, lv_color_hex(0x173349), LV_PART_INDICATOR | LV_STATE_CHECKED);
    //lv_obj_set_style_bg_color(sw, lv_color_hex(0x61b3f6), LV_PART_KNOB| LV_STATE_CHECKED);
    //lv_obj_set_style_bg_color(sw, lv_color_hex(0xeacc00), LV_PART_KNOB| LV_STATE_DEFAULT);

    //lv_obj_set_style_text_font(sw, &lv_font_montserrat_48, LV_PART_MAIN);
    //lv_obj_set_style_text_color(sw, lv_color_white(), LV_PART_KNOB);
    //lv_obj_set_style_bg_image_src(sw, LV_SYMBOL_EYE_CLOSE, LV_PART_KNOB| LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_image_src(sw, LV_SYMBOL_EYE_OPEN, LV_PART_KNOB| LV_STATE_CHECKED);

#elif 0  // 3-9-4
    lv_obj_t * sw;

    sw = lv_switch_create(lv_screen_active());
    lv_obj_set_size(sw, 300, 120);
    lv_obj_center(sw);

    //lv_obj_set_style_radius(sw, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_radius(sw, 30, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    //lv_obj_set_style_radius(sw, 30, LV_PART_KNOB | LV_STATE_DEFAULT);

    //lv_obj_set_style_bg_opa(sw, LV_OPA_100, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_color(sw, lv_color_hex(0xe8e8e8), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_color(sw, lv_color_hex(0xe7b800), LV_PART_INDICATOR | LV_STATE_CHECKED);

    //lv_obj_set_style_outline_width(sw, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_border_width(sw, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_outline_color(sw, lv_color_hex(0xe1e1e1), LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_border_color(sw, lv_color_hex(0xd9d9d9), LV_PART_MAIN | LV_STATE_DEFAULT);

    ////lv_obj_set_style_text_font(sw, &lv_font_montserrat_48, LV_PART_MAIN);
    ////lv_obj_set_style_text_color(sw, lv_color_white(), LV_PART_KNOB);
    ////lv_obj_set_style_bg_image_src(sw, LV_SYMBOL_EYE_CLOSE, LV_PART_KNOB| LV_STATE_DEFAULT);
    ////lv_obj_set_style_bg_image_src(sw, LV_SYMBOL_EYE_OPEN, LV_PART_KNOB| LV_STATE_CHECKED);


#endif
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        LV_UNUSED(obj);
        LV_LOG_USER("State: %s\n", lv_obj_has_state(obj, LV_STATE_CHECKED) ? "On" : "Off");
    }
}


static void exercise_3_9_2(lv_obj_t * obj)
{
    lv_obj_set_style_outline_color(obj, lv_color_hex(0x909090), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(obj, lv_color_hex(0x3f8586), LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_outline_width(obj, 40, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(obj, LV_OPA_10, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(obj, LV_OPA_10, LV_PART_KNOB | LV_STATE_CHECKED);
}

#endif /* LV_USE_LESSON_DEMO_3_9_1 */
