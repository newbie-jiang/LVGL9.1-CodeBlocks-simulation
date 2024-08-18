/**
 ******************************************************************************
 * @file    lesson_3_8_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-6-2
 * @brief	Lesson 3-8-1 demo
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2024-6-2     zhouyuebiao     First version
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

#if LV_USE_LESSON_DEMO_3_8_1

#include "lesson_3_8_1.h"

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
static void btn_event_handler_3_8_3(lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/
static char wifi_list_3_8_3[10][32] = {"Wi-Fi1", "Wi-Fi2", "Wi-Fi3", "Wi-Fi4", "Wi-Fi5",\
                                       "Wi-Fi6", "Wi-Fi7", "Wi-Fi8", "Wi-Fi9", "Wi-Fi10"};

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lesson_3_8_1(void)
{
#if 0  // 3-8-1
    lv_obj_t * list;

    list = lv_list_create(lv_screen_active());
    lv_obj_set_width(list, 400);
    lv_obj_center(list);

    lv_obj_t * btn;
    lv_list_add_text(list, "File");
    btn = lv_list_add_button(list, LV_SYMBOL_FILE, "New");
    btn = lv_list_add_button(list, LV_SYMBOL_DIRECTORY, "Open1");
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, list);
    btn = lv_list_add_button(list, LV_SYMBOL_DIRECTORY, "Open2");
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, list);
    btn = lv_list_add_button(list, LV_SYMBOL_DIRECTORY, "Open3");
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, list);
    btn = lv_list_add_button(list, LV_SYMBOL_DIRECTORY, "Open4");
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, list);
    btn = lv_list_add_button(list, LV_SYMBOL_DIRECTORY, "Open5");
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, list);
    lv_list_add_text(list, "Read");
    btn = lv_list_add_button(list, LV_SYMBOL_DIRECTORY, "Open");
    btn = lv_list_add_button(list, LV_SYMBOL_DIRECTORY, "Open");
    btn = lv_list_add_button(list, LV_SYMBOL_DIRECTORY, "Open");
    btn = lv_list_add_button(list, LV_SYMBOL_DIRECTORY, "Open");
    btn = lv_list_add_button(list, LV_SYMBOL_DIRECTORY, "Open");
    btn = lv_list_add_button(list, LV_SYMBOL_DIRECTORY, "Open");
    btn = lv_list_add_button(list, LV_SYMBOL_DIRECTORY, "Open");
    btn = lv_list_add_button(list, LV_SYMBOL_DIRECTORY, "Open");
    btn = lv_list_add_button(list, LV_SYMBOL_DIRECTORY, "Open");
#elif 0 // 3-8-2
    lv_obj_t * list;
    lv_obj_t * btn;

    list = lv_list_create(lv_screen_active());
    lv_obj_set_size(list, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_set_align(list, LV_ALIGN_TOP_MID);
    lv_obj_set_style_base_dir(list, LV_BASE_DIR_RTL, 0);

    btn = lv_list_add_button(list, LV_SYMBOL_WIFI, "Wi-Fi1");

    list = lv_list_create(lv_screen_active());
    lv_obj_set_width(list, LV_PCT(100));
    lv_obj_center(list);
    lv_obj_set_style_base_dir(list, LV_BASE_DIR_RTL, 0);

    lv_list_add_text(list, "File");
    btn = lv_list_add_button(list, LV_SYMBOL_WIFI, "Wi-Fi1");
    btn = lv_list_add_button(list, LV_SYMBOL_WIFI, "Wi-Fi2");
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, list);
    btn = lv_list_add_button(list, LV_SYMBOL_WIFI, "Wi-Fi3");
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, list);
    btn = lv_list_add_button(list, LV_SYMBOL_WIFI, "Wi-Fi4");

#elif 0 // 3-8-3
    lv_obj_t * list1;
    lv_obj_t * list2;
    lv_obj_t * btn;
    lv_obj_t * btn_opt;
    lv_obj_t * label;

    btn_opt = lv_button_create(lv_screen_active());
    label = lv_label_create(btn_opt);
    lv_label_set_text(label, LV_SYMBOL_REFRESH"Refresh");

    list1 = lv_list_create(lv_screen_active());
    lv_obj_set_size(list1, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_align(list1, LV_ALIGN_TOP_MID, 0, 40);
    lv_obj_set_style_base_dir(list1, LV_BASE_DIR_RTL, 0);
    lv_obj_set_style_bg_color(list1, lv_palette_main(LV_PALETTE_GREEN), 0);

    btn = lv_list_add_button(list1, LV_SYMBOL_WIFI, "Wi-Fi1");
    lv_obj_set_style_bg_color(btn, lv_palette_main(LV_PALETTE_GREEN), 0);

    list2 = lv_list_create(lv_screen_active());
    lv_obj_set_size(list2, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_align_to(list2, list1, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    lv_obj_set_style_base_dir(list2, LV_BASE_DIR_RTL, 0);
    lv_obj_set_style_bg_color(list2, lv_palette_main(LV_PALETTE_BLUE_GREY), 0);

    lv_list_add_text(list2, "File");
    btn = lv_list_add_button(list2, LV_SYMBOL_WIFI, "Wi-Fi1");
    lv_obj_set_style_bg_color(btn, lv_palette_main(LV_PALETTE_BLUE_GREY), 0);
    btn = lv_list_add_button(list2, LV_SYMBOL_WIFI, "Wi-Fi2");
    lv_obj_set_style_bg_color(btn, lv_palette_main(LV_PALETTE_BLUE_GREY), 0);
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, list2);
    lv_obj_set_style_bg_color(btn, lv_palette_main(LV_PALETTE_BLUE_GREY), 0);
    btn = lv_list_add_button(list2, LV_SYMBOL_WIFI, "Wi-Fi3");
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, list2);
    lv_obj_set_style_bg_color(btn, lv_palette_main(LV_PALETTE_BLUE_GREY), 0);
    btn = lv_list_add_button(list2, LV_SYMBOL_WIFI, "Wi-Fi4");
    lv_obj_set_style_bg_color(btn, lv_palette_main(LV_PALETTE_BLUE_GREY), 0);

    lv_obj_add_event_cb(btn_opt, btn_event_handler_3_8_3, LV_EVENT_CLICKED, list2);

#elif 1  // 3-8-4

    lv_obj_t * label;
    lv_obj_t * list;
    lv_obj_t * list_btn;

    // label
    label = lv_label_create(lv_screen_active());
    lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL);     /*Circular scroll*/
    lv_obj_set_width(label, 150);
    lv_label_set_text(label, "www.100ask.net!It is a circularly scrolling text. ");
    lv_obj_set_align(label, LV_ALIGN_TOP_MID);
    lv_obj_set_style_anim_duration(label, 20000, 0);

    // list
    list = lv_list_create(lv_screen_active());
    lv_obj_set_width(list, 200);
    lv_obj_center(list);
    
    list_btn = lv_list_add_button(list, LV_SYMBOL_FILE,\
                                        "www.100ask.net!It is a circularly scrolling text.");

    label = lv_obj_get_child(list_btn, 1);                                   
    lv_obj_set_style_anim_duration(label, 20000, 0);
        
#endif
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    lv_obj_t * list = lv_event_get_user_data(e);

    if(code == LV_EVENT_CLICKED) {
        LV_UNUSED(obj);
        LV_LOG_USER("Clicked: %s", lv_list_get_button_text(list, obj));
    }
}


static void btn_event_handler_3_8_3(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    lv_obj_t * list = lv_event_get_user_data(e);

    lv_obj_t * list_btn;
    if(code == LV_EVENT_CLICKED) {
        lv_obj_clean(list);

        int wifi_sum = lv_rand(0, 9);
        lv_list_add_text(list, "File");
        usleep(1000000 * lv_rand(1, 3));
        for(int i = 0; i <= wifi_sum; i++)
        {
            list_btn = lv_list_add_button(list, LV_SYMBOL_WIFI, wifi_list_3_8_3[i]);
            lv_obj_set_style_bg_color(list_btn, lv_palette_main(LV_PALETTE_BLUE_GREY), 0);
        }
    }
}

#endif /* LV_USE_LESSON_DEMO_3_8_1 */
