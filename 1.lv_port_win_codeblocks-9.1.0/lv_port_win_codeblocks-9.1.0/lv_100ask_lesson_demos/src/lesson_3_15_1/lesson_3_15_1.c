/**
 ******************************************************************************
 * @file    lesson_3_15_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-7-9
 * @brief	Lesson 3_15_1 demo
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2024-7-9     zhouyuebiao     First version
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

#if LV_USE_LESSON_DEMO_3_15_1

#include "lesson_3_15_1.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void event_cb_3_15_1(lv_event_t * e);
static void event_cb_3_15_3(lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void lesson_3_15_1(void)
{
#if 1 // 3_15_1
    lv_obj_t * mbox1;
    lv_obj_t * btn;

    mbox1 = lv_msgbox_create(NULL);
    lv_msgbox_add_title(mbox1, "100ASK");
    lv_msgbox_add_close_button(mbox1);
    lv_msgbox_add_text(mbox1, "www.100ask.net");
    
    btn = lv_msgbox_add_footer_button(mbox1, "Opt1");
    lv_obj_add_flag(btn, LV_OBJ_FLAG_EVENT_BUBBLE);
    //lv_obj_add_event_cb(btn, event_cb_3_15_1, LV_EVENT_CLICKED, NULL);
    btn = lv_msgbox_add_footer_button(mbox1, "Opt2");
    lv_obj_add_flag(btn, LV_OBJ_FLAG_EVENT_BUBBLE);
    btn = lv_msgbox_add_footer_button(mbox1, "Opt3");
    lv_obj_add_flag(btn, LV_OBJ_FLAG_EVENT_BUBBLE);
    btn = lv_msgbox_add_footer_button(mbox1, "Opt4");
    lv_obj_add_flag(btn, LV_OBJ_FLAG_EVENT_BUBBLE);
    btn = lv_msgbox_add_footer_button(mbox1, "Opt5");
    lv_obj_add_flag(btn, LV_OBJ_FLAG_EVENT_BUBBLE);

    btn = lv_msgbox_get_footer(mbox1);
    lv_obj_add_event_cb(btn, event_cb_3_15_1, LV_EVENT_CLICKED, mbox1);

#elif 0 // 3_15_2
    lv_obj_t * mbox1;
    lv_obj_t * btn;

    mbox1 = lv_msgbox_create(NULL);
    lv_msgbox_add_title(mbox1, "100ASK");
    lv_msgbox_add_close_button(mbox1);
    lv_msgbox_add_text(mbox1, "www.100ask.net");
    lv_msgbox_add_close_button(mbox1);
    lv_msgbox_add_close_button(mbox1);

#elif 0 // 3_15_3
    lv_obj_t * mbox1;
    lv_obj_t * btn_close;

    mbox1 = lv_msgbox_create(NULL);
    lv_msgbox_add_title(mbox1, "100ASK");
    btn_close = lv_msgbox_add_close_button(mbox1);
    lv_msgbox_add_text(mbox1, "www.100ask.net");

    lv_obj_set_style_bg_color(btn_close, lv_color_hex(0x31a528), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_size(btn_close, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_t * img = lv_obj_get_child(btn_close, 0);
    //lv_image_set_src(img, NULL);
    //lv_obj_delete(img);

    lv_obj_t * label = lv_label_create(btn_close);
    lv_label_set_text(label, "100ask");
    lv_obj_center(label);

    lv_obj_remove_event(btn_close, 0);
    lv_obj_add_event_cb(btn_close, event_cb_3_15_3, LV_EVENT_CLICKED, mbox1);

#elif 0 // 3_15_4
    lv_obj_t * mbox1;
    lv_obj_t * footer;

    mbox1 = lv_msgbox_create(NULL);
    lv_msgbox_add_title(mbox1, "100ASK");
    lv_msgbox_add_close_button(mbox1);
    lv_msgbox_add_text(mbox1, "www.100ask.net");

    lv_msgbox_add_footer_button(mbox1, "Opt1");
    lv_msgbox_add_footer_button(mbox1, "Opt2");
    lv_msgbox_add_footer_button(mbox1, "Opt3");
    lv_msgbox_add_footer_button(mbox1, "Opt4");
    lv_msgbox_add_footer_button(mbox1, "Opt5");
    lv_msgbox_add_footer_button(mbox1, "Opt6");

    footer = lv_msgbox_get_footer(mbox1);
    lv_obj_set_height(footer, LV_SIZE_CONTENT);
    lv_obj_set_flex_flow(footer, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_style_pad_all(footer, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    //lv_obj_set_flex_align(footer, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
#endif
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void event_cb_3_15_1(lv_event_t * e)
{
    lv_obj_t * mbox = lv_event_get_user_data(e);
    lv_obj_t * btn = lv_event_get_target(e);
    lv_obj_t * label = lv_obj_get_child(btn, 0);
    LV_UNUSED(label);
    LV_LOG_USER("Button %s clicked", lv_label_get_text(label));
    lv_msgbox_close(mbox);

}


static void event_cb_3_15_3(lv_event_t * e)
{
    lv_obj_t * mbox = lv_event_get_user_data(e);
    lv_msgbox_close(mbox);

    LV_LOG_USER("Clicked Close Btn!");
}


#endif /* LV_USE_LESSON_DEMO_3_15_1 */
