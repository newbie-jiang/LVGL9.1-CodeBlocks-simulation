/**
 ******************************************************************************
 * @file    lesson_3_14_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-7-9
 * @brief	Lesson 3_14_1 demo
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

#if LV_USE_LESSON_DEMO_3_14_1

#include "lesson_3_14_1.h"

// 3_14_3
#include <stdlib.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void event_handler_3_14_1(lv_event_t * e);
static void event_handler_3_14_3(lv_event_t * e);


/**********************
 *  STATIC VARIABLES
 **********************/

// 3_14_3
static lv_obj_t * g_roller_hours;
static lv_obj_t * g_roller_min;
static lv_obj_t * g_roller_sec;
/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void lesson_3_14_1(void)
{
#if 1 // 3_14_1
    lv_obj_t * roller1 = lv_roller_create(lv_screen_active());
    lv_obj_center(roller1);

    //lv_roller_set_options(roller1, "January\nFebruary\nMarch\nApril\nMay\nJune\nJuly\nAugust\nSeptember\nOctober\nNovember\nDecember",LV_ROLLER_MODE_INFINITE);
    lv_roller_set_options(roller1,
                          "January\n"
                          "February\n"
                          "March\n"
                          "April\n"
                          "May\n"
                          "June\n"
                          "July\n"
                          "August\n"
                          "September\n"
                          "October\n"
                          "November\n"
                          "December",
                          LV_ROLLER_MODE_NORMAL);
    
    lv_roller_set_selected(roller1, 3, LV_ANIM_ON);
    //lv_roller_set_visible_row_count(roller1, 4);
    

    lv_obj_add_event_cb(roller1, event_handler_3_14_1, LV_EVENT_ALL, NULL);
#elif 0 // 3_14_2
    lv_obj_t * roller1 = lv_roller_create(lv_screen_active());
    
    lv_roller_set_options(roller1,
                          "January\n"
                          "February\n"
                          "March\n"
                          "April\n"
                          "May\n"
                          "June\n"
                          "July\n"
                          "August\n"
                          "September\n"
                          "October\n"
                          "November\n"
                          "December",
                          LV_ROLLER_MODE_NORMAL);
    
    lv_obj_center(roller1);

    lv_obj_set_style_text_line_space(roller1, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_roller_set_visible_row_count(roller1, 4);

    lv_obj_set_style_anim_duration(roller1, 1000, LV_PART_MAIN | LV_STATE_DEFAULT);
#elif 0 // 3_14_3


    const char * hours = "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12";
    const char * min_sec = "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n"\
                           "11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n"\
                           "21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n"\
                           "31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n"\
                           "41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n"\
                           "51\n52\n53\n54\n55\n56\n57\n58\n59";
    
    g_roller_hours = lv_roller_create(lv_screen_active());
    lv_roller_set_options(g_roller_hours, hours, LV_ROLLER_MODE_NORMAL);

    g_roller_min = lv_roller_create(lv_screen_active());
    lv_roller_set_options(g_roller_min, min_sec, LV_ROLLER_MODE_NORMAL);

    g_roller_sec = lv_roller_create(lv_screen_active());
    lv_roller_set_options(g_roller_sec, min_sec, LV_ROLLER_MODE_NORMAL);

    //lv_obj_center(g_roller_min);
    //lv_obj_align_to(g_roller_hours, g_roller_min, LV_ALIGN_OUT_LEFT_MID, 0, 0);
    //lv_obj_align_to(g_roller_sec, g_roller_min, LV_ALIGN_OUT_RIGHT_MID, 0, 0);
    lv_obj_align(g_roller_hours, LV_ALIGN_CENTER, -80, 0);
    lv_obj_align(g_roller_min, LV_ALIGN_CENTER, 0, 0);
    lv_obj_align(g_roller_sec, LV_ALIGN_CENTER, 80, 0);

    lv_obj_t * btn = lv_button_create(lv_screen_active());
    lv_obj_add_event_cb(btn, event_handler_3_14_3, LV_EVENT_CLICKED, NULL);
    lv_obj_align_to(btn, g_roller_min, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
#endif
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void event_handler_3_14_1(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_VALUE_CHANGED) {

        char buf[32];
        lv_roller_get_selected_str(obj, buf, sizeof(buf));
        LV_LOG_USER("Selected month: %s\n", buf);
    }
}


static void event_handler_3_14_3(lv_event_t * e)
{
    //lv_obj_t * roller_hours = g_roller_hours;
    //lv_obj_t * roller_min = g_roller_min;
    //lv_obj_t * roller_sec = g_roller_sec;
    lv_obj_t * btn = lv_event_get_target(e);
    lv_obj_t * parent = lv_obj_get_parent(btn);

    lv_obj_t * roller_hours = lv_obj_get_child(parent, 0);
    lv_obj_t * roller_min = lv_obj_get_child(parent, 1);
    lv_obj_t * roller_sec = lv_obj_get_child(parent, 2);
    
    char buf_hours[32];
    char buf_min[32];
    char buf_sec[32];

    int value_hours;
    int value_min;
    int value_sec;

    lv_roller_get_selected_str(roller_hours, buf_hours, sizeof(buf_hours));
    lv_roller_get_selected_str(roller_min, buf_min, sizeof(buf_min));
    lv_roller_get_selected_str(roller_sec, buf_sec, sizeof(buf_sec));
    LV_LOG_USER("%s:%s:%s", buf_hours, buf_min, buf_sec);

    value_hours = atoi(buf_hours);
    value_min = atoi(buf_min);
    value_sec = atoi(buf_sec);
    LV_LOG_USER("%d:%d:%d", value_hours, value_min, value_sec);
}

#endif /* LV_USE_LESSON_DEMO_3_14_1 */
