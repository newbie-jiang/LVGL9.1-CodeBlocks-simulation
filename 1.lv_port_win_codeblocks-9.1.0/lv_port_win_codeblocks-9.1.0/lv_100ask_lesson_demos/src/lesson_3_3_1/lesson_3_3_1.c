/**
 ******************************************************************************
 * @file    lesson_3_3_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-5-22
 * @brief	Lesson 3-3-1 demo
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2024-5-22     zhouyuebiao     First version
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

#if LV_USE_LESSON_DEMO_3_3_1

#include "lesson_3_3_1.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void my_timer_3_3_2(lv_timer_t * timer);

static void event_handler_3_3_4(lv_event_t * e);
static void my_timer_3_3_4(lv_timer_t * timer);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void lesson_3_3_1(void)
{

#if 0 // 3-3-1
    lv_obj_t * bar = lv_bar_create(lv_screen_active());

    //lv_bar_set_range(bar, 0, 100);
    //lv_bar_set_range(bar, 100, 0);
    //lv_bar_set_value(bar, 70, LV_ANIM_OFF);

    lv_bar_set_range(bar, -100, 100);
    //lv_bar_set_mode(bar, LV_BAR_MODE_SYMMETRICAL);
    lv_bar_set_mode(bar, LV_BAR_MODE_RANGE);
    lv_bar_set_start_value(bar, -50, LV_ANIM_ON);
    lv_bar_set_value(bar, 90, LV_ANIM_ON);

    lv_obj_set_style_anim_duration(bar, 2000, 0);

    lv_obj_set_size(bar, 200, 20);
    //lv_obj_set_size(bar, 20, 200);
    lv_obj_center(bar);

    //lv_obj_set_style_pad_all(bar, 10, LV_PART_MAIN);
    lv_obj_set_style_bg_color(bar, lv_color_hex(0xc3494b), LV_PART_MAIN);
    lv_obj_set_style_bg_color(bar, lv_color_hex(0x66d252), LV_PART_INDICATOR);
#elif 0 // 3-3-2
    lv_obj_t * bar = lv_bar_create(lv_screen_active());
    lv_obj_set_size(bar, 200, 20);
    lv_obj_center(bar);
    lv_obj_set_style_anim_duration(bar, 1000, 0);

    lv_bar_set_value(bar, 0, LV_ANIM_ON);

    lv_timer_create(my_timer_3_3_2, 1000, bar);

#elif 0 // 3-3-3
    static lv_style_t style_bg;
    static lv_style_t style_indic;

    lv_style_init(&style_bg);
    lv_style_set_radius(&style_bg, 0);
    lv_style_set_anim_duration(&style_bg, 1000);

    lv_style_init(&style_indic);
    lv_style_set_radius(&style_indic, 0);
    lv_style_set_bg_grad_color(&style_indic, lv_palette_main(LV_PALETTE_RED));
    lv_style_set_bg_grad_dir(&style_indic, LV_GRAD_DIR_HOR);

    lv_obj_t * bar = lv_bar_create(lv_screen_active());
    lv_obj_set_size(bar, 200, 60);
    lv_obj_center(bar);

    lv_bar_set_value(bar, 70, LV_ANIM_ON);

    lv_obj_add_style(bar, &style_bg, LV_PART_MAIN);
    lv_obj_add_style(bar, &style_indic, LV_PART_INDICATOR);

    lv_timer_create(my_timer_3_3_2, 1000, bar);

#elif 0 // 3-3-4
    static lv_style_t style_bg;
    static lv_style_t style_indic;

    lv_style_init(&style_bg);
    lv_style_set_radius(&style_bg, 0);
    lv_style_set_anim_duration(&style_bg, 1000);

    lv_style_init(&style_indic);
    lv_style_set_radius(&style_indic, 0);
    lv_style_set_bg_color(&style_indic, lv_color_hex(0x067fd7));

    lv_obj_t * cont;
    cont = lv_obj_create(lv_screen_active());
    lv_obj_set_size(cont, LV_PCT(100), 200);

    lv_obj_t * bar = lv_bar_create(cont);
    lv_obj_set_size(bar, LV_PCT(90), 40);
    lv_obj_center(bar);

    lv_bar_set_value(bar, 70, LV_ANIM_ON);

    lv_obj_add_style(bar, &style_bg, LV_PART_MAIN);
    lv_obj_add_style(bar, &style_indic, LV_PART_INDICATOR);

    lv_obj_t * btn;
    lv_obj_t * label;
    btn = lv_button_create(cont);
    lv_obj_add_event_cb(btn, event_handler_3_3_4, LV_EVENT_CLICKED, bar);

    label = lv_label_create(btn);
    lv_label_set_text(label, LV_SYMBOL_OK "Upgrade");

    //lv_obj_align_to(btn, bar, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    lv_obj_align(btn, LV_ALIGN_BOTTOM_MID, 0, 0);

    label = lv_label_create(cont);
    
#endif

}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void my_timer_3_3_2(lv_timer_t * timer)
{
    static int bar_value = 0;

    lv_obj_t * bar = lv_timer_get_user_data(timer);

    bar_value += 10;
    if(bar_value >= 100) bar_value = 0;

    lv_bar_set_value(bar, bar_value, LV_ANIM_ON);
}

static void event_handler_3_3_4(lv_event_t * e)
{
    lv_obj_t * btn = lv_event_get_target(e);
    lv_obj_t * bar = lv_event_get_user_data(e);

    lv_obj_set_style_bg_color(bar, lv_color_hex(0x067fd7), LV_PART_INDICATOR);
    lv_timer_create(my_timer_3_3_4, 200, bar);

    lv_obj_add_state(btn, LV_STATE_DISABLED);

}

static void my_timer_3_3_4(lv_timer_t * timer)
{
    static int set_bar_value = 0;
    static int get_bar_value = 0;

    lv_obj_t * parent;
    lv_obj_t * btn;
    lv_obj_t * bar = lv_timer_get_user_data(timer);

    parent = lv_obj_get_parent(bar);
    btn = lv_obj_get_child(parent, 1);

    set_bar_value += 10;
    if(set_bar_value > 100) set_bar_value = 0;

    lv_bar_set_value(bar, set_bar_value, LV_ANIM_ON);

    get_bar_value = lv_bar_get_value(bar);

    if(get_bar_value >= 100)
    {
        LV_LOG_USER("get_bar_value: %d", get_bar_value);
        lv_obj_set_style_bg_color(bar, lv_color_hex(0x3f9f4a), LV_PART_INDICATOR);
        lv_obj_clear_state(btn, LV_STATE_DISABLED);
        lv_timer_del(timer);
    }


}
#endif /* LV_USE_LESSON_DEMO_3_3_1 */
