/**
 ******************************************************************************
 * @file    lesson_3_17_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-7-11
 * @brief	Lesson 3_17_1 demo
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2024-7-11     zhouyuebiao     First version
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

#if LV_USE_LESSON_DEMO_3_17_1

#include "lesson_3_17_1.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void event_handler_3_17_1(lv_event_t * e);
static void textarea_event_handler(lv_event_t * e);

static void event_handler_3_17_4(lv_event_t * e);
static lv_color_t filter_3_17_5(const lv_color_filter_dsc_t * dsc, lv_color_t color, lv_opa_t opa);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lesson_3_17_1(void)
{
#if 1 // 3_17_1
    lv_obj_t * ta = lv_textarea_create(lv_screen_active());

    lv_textarea_add_char(ta, '1');
    lv_textarea_add_text(ta, "www.100ask.net");
    lv_textarea_add_text(ta, "2");

    lv_textarea_set_text(ta, "1\nwww.100ask.net\n2");
    //lv_textarea_set_text(ta, "");  // 清空

    //lv_textarea_set_placeholder_text(ta, "Placeholder text");

    //lv_textarea_delete_char(ta);
    lv_obj_t * btn2 = lv_button_create(lv_screen_active());
    lv_obj_align(btn2, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_event_cb(btn2, event_handler_3_17_1, LV_EVENT_ALL, ta);

    //lv_textarea_set_cursor_click_pos(ta, false);
    //lv_obj_set_style_opa(ta, LV_OPA_TRANSP, LV_PART_CURSOR | LV_STATE_DEFAULT);

    //lv_textarea_set_one_line(ta, true);
    //lv_textarea_set_password_mode(ta, true);   // lv_conf.h LV_TEXTAREA_DEF_PWD_SHOW_TIME
    //lv_textarea_set_accepted_chars(ta, "0123456789.+-");
    //lv_textarea_set_max_length(ta, 20);

    lv_obj_add_event_cb(ta, textarea_event_handler, LV_EVENT_VALUE_CHANGED, ta);

#elif 0 // 3_17_3
    lv_obj_t * ta = lv_textarea_create(lv_screen_active());
    lv_obj_set_style_text_color(ta, lv_color_hex(0x00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_text_color(ta, lv_color_hex(0xff0000), LV_PART_SELECTED | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_color(ta, lv_color_hex(0xff0000), LV_PART_SELECTED | LV_STATE_DEFAULT);
    
    lv_textarea_set_text(ta, "www.100ask.net\n2");
    lv_textarea_set_text_selection(ta, true);

    lv_obj_t * ta_label = lv_textarea_get_label(ta);
    //lv_obj_set_style_text_font(ta, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_color(ta, lv_color_hex(0xff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_text_color(ta_label, lv_color_hex(0xff0000), LV_PART_SELECTED | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_color(ta_label, lv_color_hex(0x0000ff), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_label_set_text_selection_start(ta_label, 1);
    lv_label_set_text_selection_end(ta_label, 6);

#elif 0 // 3_17_4
    lv_obj_t * ta = lv_textarea_create(lv_screen_active());
    lv_textarea_set_text(ta, "1\nwww.100ask.net\n2");

    lv_obj_t * btn2 = lv_button_create(lv_screen_active());
    lv_obj_align(btn2, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_event_cb(btn2, event_handler_3_17_4, LV_EVENT_ALL, ta);

#elif 0 // 3_17_5
    lv_obj_t * ta = lv_textarea_create(lv_screen_active());
    lv_obj_set_style_text_font(ta, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_textarea_set_text(ta, "1\nwww.100ask.net\n2");
    
    // 修改光标闪烁的时间
    lv_obj_t * btn2 = lv_button_create(lv_screen_active());
    //lv_obj_set_style_anim_duration(ta, 2000, LV_PART_CURSOR | LV_STATE_FOCUSED);

    // 修改光标的颜色
    //lv_obj_set_style_bg_color(ta, lv_color_hex(0xff0000), LV_PART_CURSOR | LV_STATE_FOCUSED);
    static lv_color_filter_dsc_t color_filter;
    lv_color_filter_dsc_init(&color_filter, filter_3_17_5);
    lv_obj_set_style_color_filter_dsc(ta, &color_filter, LV_PART_CURSOR);
    lv_obj_set_style_color_filter_opa(ta, LV_OPA_20, LV_PART_CURSOR);

#elif 0 // 3_17_6
    lv_obj_t * ta = lv_textarea_create(lv_screen_active());


    LV_FONT_DECLARE(lv_font_source_han_sans_bold_28);
    lv_obj_set_style_text_font(ta, &lv_font_source_han_sans_bold_28, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    /* 密码明文展示的时间可通过两个方法设置：
     *    1. 通过接口  lv_textarea_set_password_show_time 设置（推荐）
     *    2. 通过修改 lv_conf.h 中的宏 LV_TEXTAREA_DEF_PWD_SHOW_TIME 设置（不推荐）
     */
    lv_textarea_set_password_mode(ta, true);
    lv_textarea_set_password_bullet(ta, "&");
    lv_textarea_set_password_show_time(ta, 2000);

    lv_textarea_set_text(ta, "百问网韦东山温度湿度℃：%");

#endif
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void textarea_event_handler(lv_event_t * e)
{
    lv_obj_t * ta = lv_event_get_target(e);
    LV_UNUSED(ta);
    LV_LOG_USER("%s", lv_textarea_get_text(ta));
}

static void event_handler_3_17_1(lv_event_t * e)
{
    lv_obj_t * ta = lv_event_get_user_data(e);
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED) {
        //lv_textarea_delete_char(ta);
        //lv_textarea_delete_char_forward(ta);

        lv_textarea_add_text(ta, "4");
    }
}

static void event_handler_3_17_4(lv_event_t * e)
{
    lv_obj_t * ta = lv_event_get_user_data(e);
    lv_event_code_t code = lv_event_get_code(e);

    if((code == LV_EVENT_CLICKED) || (code == LV_EVENT_PRESSING)) {
        lv_textarea_delete_char(ta);
    }
    // 修改长按时间： lvgl/src/indev/lv_indev.c 中的宏 LV_INDEV_DEF_LONG_PRESS_TIME
    else if(code == LV_EVENT_LONG_PRESSED) {
        lv_textarea_set_text(ta, "");
    }
}


static lv_color_t filter_3_17_5(const lv_color_filter_dsc_t * dsc, lv_color_t color, lv_opa_t opa)
{
    LV_UNUSED(dsc);
    return lv_color_hex(0xff0000);
}


#endif /* LV_USE_LESSON_DEMO_3_17_1 */
