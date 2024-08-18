/**
 ******************************************************************************
 * @file    lesson_3_5_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-5-24
 * @brief	Lesson 3-5-1 demo
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2024-5-24     zhouyuebiao     First version
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

#if LV_USE_LESSON_DEMO_3_5_1

#include "lesson_3_5_1.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void value_changed_event_cb(lv_event_t * e);
static void lv_example_arc_1(void);

static void my_timer_3_5_4(lv_timer_t * timer);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void lesson_3_5_1(void)
{

#if 0 // 3-5-1
    lv_obj_t * arc = lv_arc_create(lv_screen_active());
    lv_obj_set_size(arc, 300, 300);
    lv_arc_set_value(arc, 100);
    //lv_obj_center(arc);
    //lv_obj_set_style_pad_all(arc, 0, 0);
    //lv_obj_set_style_pad_all(arc, -20, LV_PART_INDICATOR);

    lv_arc_set_bg_angles(arc, 0, 270);
    //lv_arc_set_change_rate(arc, 90);
    //lv_arc_set_knob_offset(arc, -20);
    lv_arc_set_angles(arc, 270, 360);
    //lv_arc_set_rotation(arc, 90);
     

    //lv_example_arc_1();


#elif 0 // 3-5-3 (这里就是视频中 3-5-2 部分的代码)
    lv_obj_t * arc = lv_arc_create(lv_screen_active());
    lv_obj_set_size(arc, 300, 300);
    lv_arc_set_value(arc, 100);
    lv_obj_center(arc);
    lv_obj_set_style_arc_width(arc, 60, LV_PART_MAIN);
    lv_obj_set_style_arc_width(arc, 20, LV_PART_INDICATOR);
    //lv_obj_set_style_pad_all(arc, 0, LV_PART_KNOB);
    //lv_obj_set_style_pad_all(arc, 20, LV_PART_INDICATOR);

#elif 1 // 3-5-4 (这里就是视频中 3-5-3 部分的代码)
    lv_obj_t * arc = lv_arc_create(lv_screen_active());
    lv_obj_set_size(arc, 200, 200);
    lv_arc_set_value(arc, 100);
    lv_obj_center(arc);

    lv_obj_set_style_arc_rounded(arc, 0, LV_PART_MAIN);
    lv_obj_set_style_arc_rounded(arc, 0, LV_PART_INDICATOR);
    lv_obj_remove_style(arc, NULL, LV_PART_KNOB);

    //lv_obj_set_style_arc_width(arc, 60, LV_PART_MAIN);
    //lv_obj_set_style_arc_width(arc, 20, LV_PART_INDICATOR);
    //l
    //lv_obj_set_style_pad_all(arc, 20, LV_PART_INDICATOR);

    lv_timer_create(my_timer_3_5_4, 500, arc);
#endif


}

/**********************
 *   STATIC FUNCTIONS
 **********************/
// 直接从文档将代码复制过来使用，要注意 lv_conf.h 中的 LV_BUILD_EXAMPLES 未被打开，否则会报错，
// 定义为static可以避免这个问题，或者直接修改函数名称。
static void lv_example_arc_1(void)
{
    lv_obj_t * label = lv_label_create(lv_screen_active());

    /*Create an Arc*/
    lv_obj_t * arc = lv_arc_create(lv_screen_active());
    lv_obj_set_size(arc, 150, 150);
    lv_arc_set_rotation(arc, 135);
    lv_arc_set_bg_angles(arc, 0, 270);
    lv_arc_set_value(arc, 10);
    lv_obj_center(arc);
    lv_obj_add_event_cb(arc, value_changed_event_cb, LV_EVENT_VALUE_CHANGED, label);

    /*Manually update the label for the first time*/
    lv_obj_send_event(arc, LV_EVENT_VALUE_CHANGED, NULL);
}

static void value_changed_event_cb(lv_event_t * e)
{
    lv_obj_t * arc = lv_event_get_target(e);
    lv_obj_t * label = lv_event_get_user_data(e);

    lv_label_set_text_fmt(label, "%" LV_PRId32 "%%", lv_arc_get_value(arc));

    /*Rotate the label to the current position of the arc*/
    //lv_arc_rotate_obj_to_angle(arc, label, 25);
    lv_arc_align_obj_to_angle(arc, label, 25);
}


static void my_timer_3_5_4(lv_timer_t * timer)
{
    
    lv_obj_t * arc = lv_timer_get_user_data(timer);

#if 0
    int arc_value = 0;
    arc_value = lv_arc_get_value(arc);
    if(arc_value >= lv_arc_get_max_value(arc)) arc_value = 0;
    else arc_value += 1;
    
    lv_arc_set_value(arc, arc_value);
#else
    lv_arc_set_value(arc, lv_rand(23, 30));
    
#endif
}

#endif /* LV_USE_LESSON_DEMO_3_5_1 */
