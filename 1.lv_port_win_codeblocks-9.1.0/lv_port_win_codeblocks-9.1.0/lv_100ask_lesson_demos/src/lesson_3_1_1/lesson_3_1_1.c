/**
 ******************************************************************************
 * @file    lesson_3_1_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-4-25
 * @brief	Lesson 3-1-1 demo
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2024-5-10     zhouyuebiao     First version
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

#if LV_USE_LESSON_DEMO_3_1_1

#include "lesson_3_1_1.h"


/*********************
 *      DEFINES
 *********************/
extern const lv_font_t lv_font_source_han_sans_bold_28;
LV_FONT_DECLARE(lv_font_source_han_sans_bold_28);

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void my_event_cb(lv_event_t * e);
static void my_timer1(lv_timer_t * timer);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/


void lesson_3_1_1(void)
{
    //char * label_str = "100askkkkkk""11111111""222222222";
    //static char label_str[] = "www.100ask.net\n100ask\n100ask\n100ask";
    lv_obj_t * label = lv_label_create(lv_screen_active());
    //lv_obj_set_size(label, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //lv_obj_set_size(label, 20, LV_SIZE_CONTENT);
    //lv_obj_set_style_bg_opa(label,  LV_OPA_COVER, 0); 
    //lv_obj_set_style_bg_color(label,  lv_color_hex(0x9fce43), 0); 
    //lv_label_set_long_mode(label, LV_LABEL_LONG_DOT);

    //lv_obj_add_flag(label, LV_OBJ_FLAG_CLICKABLE); 
    //lv_obj_add_event_cb(label, my_event_cb, LV_EVENT_CLICKED, label);

    //lv_label_set_text(label, label_str);
    //lv_label_set_text(label, "100askkkkkk""11111111""222222222");
    // lv_label_set_text(label, "100askkkkkk"LV_SYMBOL_WIFI LV_SYMBOL_BACKSPACE LV_SYMBOL_BATTERY_FULL);
    //lv_obj_set_style_text_font(label,  &lv_font_montserrat_40, 0); 
    //lv_obj_set_style_text_font(label,  &lv_font_simsun_16_cjk, 0); 
    //lv_obj_set_style_text_font(label,  &lv_font_source_han_sans_bold_28, 0); 
    
    //lv_obj_set_style_text_color(label, lv_color_hex(0xf1645a), 0);
    //lv_label_set_text_fmt(label, "%s%d%s%s", "www.", 100, "ask", ".net");
    //lv_label_set_text_static(label, label_str);

    //lv_label_set_text_selection_start(label, 4);
    //lv_label_set_text_selection_end(label, 10);
    //lv_obj_set_style_text_color(label, lv_color_hex(0xe84134), LV_PART_SELECTED);
    //lv_obj_set_style_bg_color(label, lv_color_hex(0xf5f5f5), LV_PART_SELECTED);

    //lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_LEFT, 0);

    //lv_timer_t * timer1;

    /* 创建第一个timer */
    //timer1 = lv_timer_create(my_timer1, 100, label);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void my_event_cb(lv_event_t * e)
{
    LV_LOG_USER(">>>>>>>>>>>>LV_EVENT_CLICKED\n");
}

static void my_timer1(lv_timer_t * timer)
{
    lv_obj_t *label = (lv_obj_t *)lv_timer_get_user_data(timer);
    
    //lv_label_set_text(label, "80, 90%");
    //lv_label_set_text_fmt(label, "%d湿度:%d℃, 温度：%d%%", lv_rand(0, 9), lv_rand(20, 30), lv_rand(70, 80));
    //LV_LOG_USER("my_timer1 user_data: %d, idle: %d", *user_data, idle);
}


#endif /* LV_USE_LESSON_DEMO_3_1_1 */
