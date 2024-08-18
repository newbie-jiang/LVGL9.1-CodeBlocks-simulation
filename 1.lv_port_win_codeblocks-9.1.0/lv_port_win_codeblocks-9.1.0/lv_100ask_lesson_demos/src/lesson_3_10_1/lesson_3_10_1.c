/**
 ******************************************************************************
 * @file    lesson_3_10_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-6-5
 * @brief	Lesson 3_10_1 demo
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

#if LV_USE_LESSON_DEMO_3_10_1

#include "lesson_3_10_1.h"

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
static void exercise_3_10_3(lv_obj_t * obj);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lesson_3_10_1(void)
{
#if 0  // 3_10_1
    lv_obj_t * cb;

    cb = lv_checkbox_create(lv_screen_active());
    lv_obj_set_style_text_font(cb, &lv_font_montserrat_20, LV_PART_MAIN);
    lv_checkbox_set_text(cb, "100ASK");

    //lv_obj_set_size(cb, 400, 200); // 一般不需要设置大小
    lv_obj_center(cb);

    lv_obj_add_event_cb(cb, event_handler, LV_EVENT_VALUE_CHANGED, NULL);

#elif 0  // 3_10_2
    lv_obj_t * cb;

    cb = lv_checkbox_create(lv_screen_active());
    lv_checkbox_set_text(cb, "100ASK");
    lv_obj_center(cb);

    //lv_obj_set_style_text_font(cb, &lv_font_montserrat_20, LV_PART_MAIN);
    //lv_obj_set_style_text_font(cb, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_CHECKED);
    
    //lv_obj_set_size(cb, 400, 200); // 一般不需要设置大小
    //lv_obj_set_style_bg_opa(cb, LV_OPA_100, LV_PART_MAIN); // 让part main部分显示出来
    
    //lv_obj_add_event_cb(cb, event_handler, LV_EVENT_VALUE_CHANGED, NULL);

#elif 1  // 3_10_3
    lv_obj_t * cb;

    cb = lv_checkbox_create(lv_screen_active());
    lv_checkbox_set_text(cb, "100ASK");
    lv_obj_center(cb);

    lv_obj_set_style_text_font(cb, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cb, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_CHECKED);
    
    lv_obj_set_style_text_font(cb, &lv_font_montserrat_20, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cb, &lv_font_montserrat_48, LV_PART_INDICATOR | LV_STATE_CHECKED);
    
    lv_obj_set_style_bg_color(cb, lv_color_hex(0x28b139), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cb, lv_color_hex(0xff5c5c), LV_PART_INDICATOR | LV_STATE_CHECKED);
   
    lv_obj_add_event_cb(cb, event_handler, LV_EVENT_VALUE_CHANGED, NULL);

    // 课后练习，请尝试自己练习后再阅读代码
    //exercise_3_10_3(cb);
#elif 0  // 3_10_4
    lv_obj_t * cb;

    cb = lv_checkbox_create(lv_screen_active());
    lv_checkbox_set_text(cb, "100ASK");
    lv_obj_center(cb);

    lv_obj_set_style_text_font(cb, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cb, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_text_font(cb, &lv_font_montserrat_48, LV_PART_INDICATOR | LV_STATE_CHECKED);
    
    lv_obj_set_style_bg_image_src(cb, LV_SYMBOL_CLOSE, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_image_src(cb, NULL, LV_PART_INDICATOR | LV_STATE_CHECKED);

#elif 0  // 3_10_5
    lv_obj_t * cb;

    cb = lv_checkbox_create(lv_screen_active());
    lv_checkbox_set_text(cb, "100ASK");
    lv_obj_center(cb);

    lv_obj_set_style_text_font(cb, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cb, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_text_font(cb, &lv_font_montserrat_48, LV_PART_INDICATOR | LV_STATE_CHECKED);
    
    //lv_obj_set_style_text_decor(cb, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_CHECKED);
    //lv_obj_set_style_text_decor(cb, LV_TEXT_DECOR_STRIKETHROUGH, LV_PART_MAIN | LV_STATE_CHECKED);

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
        const char * txt = lv_checkbox_get_text(obj);
        const char * state = lv_obj_get_state(obj) & LV_STATE_CHECKED ? "Checked" : "Unchecked";
        LV_UNUSED(txt);
        LV_UNUSED(state);
        LV_LOG_USER("%s: %s", txt, state);
    }
}

static void exercise_3_10_3(lv_obj_t * obj)
{
    lv_obj_set_style_border_width(obj, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);

}

#endif /* LV_USE_LESSON_DEMO_3_10_1 */
