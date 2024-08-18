/**
 ******************************************************************************
 * @file    lesson_3_19_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-7-12
 * @brief	Lesson 3_19_1 demo
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2024-7-12     zhouyuebiao     First version
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

#if LV_USE_LESSON_DEMO_3_19_1

#include "lesson_3_19_1.h"

#include <stdlib.h>
#include <math.h>

/*********************
 *      DEFINES
 *********************/
#define DIGIT_COUNT 6
#define SEP_COUNT 3

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void lv_spinbox_increment_event_cb(lv_event_t * e);
static void lv_spinbox_decrement_event_cb(lv_event_t * e);
static void spinbox_get_value_event_cb_3_19_3(lv_event_t * e);
static void spinbox_get_value_event_cb_3_19_4(lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/


/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lesson_3_19_1(void)
{
#if 1 // 3_19_1
    lv_obj_t * spinbox = lv_spinbox_create(lv_screen_active());
    lv_spinbox_set_value(spinbox, 1234);
    lv_spinbox_set_range(spinbox, -999, 999);
    lv_spinbox_set_digit_format(spinbox, 3, 1);
    lv_spinbox_set_rollover(spinbox, true);

    lv_obj_set_style_text_font(spinbox, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_center(spinbox);

    //lv_spinbox_set_cursor_pos(spinbox, 3);  // 索引从0开始
    lv_spinbox_step_next(spinbox);
    //lv_spinbox_step_next(spinbox);
    lv_spinbox_set_digit_step_direction(spinbox, LV_DIR_LEFT);
    lv_spinbox_set_digit_step_direction(spinbox, LV_DIR_LEFT);

    lv_spinbox_set_step(spinbox, 10);
    
    lv_spinbox_increment(spinbox);
    //lv_spinbox_increment(spinbox);
    //lv_spinbox_increment(spinbox);
    //lv_spinbox_decrement(spinbox);

#elif 0 // 3_19_3

    lv_obj_t * spinbox = lv_spinbox_create(lv_screen_active());
    lv_spinbox_set_range(spinbox, -1000, 125123);
    lv_spinbox_set_digit_format(spinbox, DIGIT_COUNT, SEP_COUNT);
    lv_spinbox_step_prev(spinbox);
    lv_obj_set_width(spinbox, LV_SIZE_CONTENT);
    lv_obj_center(spinbox);
    lv_obj_set_style_text_font(spinbox, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);

    int32_t h = lv_obj_get_height(spinbox);

    lv_obj_add_event_cb(spinbox, spinbox_get_value_event_cb_3_19_3, LV_EVENT_VALUE_CHANGED, NULL);

    lv_obj_t * btn = lv_button_create(lv_screen_active());
    lv_obj_set_size(btn, h, h);
    lv_obj_align_to(btn, spinbox, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_set_style_bg_image_src(btn, LV_SYMBOL_PLUS, 0);
    lv_obj_add_event_cb(btn, lv_spinbox_increment_event_cb, LV_EVENT_ALL, spinbox);

    btn = lv_button_create(lv_screen_active());
    lv_obj_set_size(btn, h, h);
    lv_obj_align_to(btn, spinbox, LV_ALIGN_OUT_LEFT_MID, -5, 0);
    lv_obj_set_style_bg_image_src(btn, LV_SYMBOL_MINUS, 0);
    lv_obj_add_event_cb(btn, lv_spinbox_decrement_event_cb, LV_EVENT_ALL, spinbox);

#elif 0 // 3_19_4
    lv_obj_t * label = lv_label_create(lv_screen_active());
    lv_obj_set_style_text_font(label, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * spinbox = lv_spinbox_create(lv_screen_active());
    lv_spinbox_set_range(spinbox, -1000, 125123);
    lv_spinbox_set_digit_format(spinbox, DIGIT_COUNT, SEP_COUNT);
    lv_spinbox_step_prev(spinbox);
    lv_obj_set_width(spinbox, LV_SIZE_CONTENT);
    lv_obj_center(spinbox);
    lv_obj_set_style_text_font(spinbox, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);

    int32_t h = lv_obj_get_height(spinbox);

    lv_obj_add_event_cb(spinbox, spinbox_get_value_event_cb_3_19_4, LV_EVENT_VALUE_CHANGED, label);

    lv_obj_t * btn = lv_button_create(lv_screen_active());
    lv_obj_set_size(btn, h, h);
    lv_obj_align_to(btn, spinbox, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_set_style_bg_image_src(btn, LV_SYMBOL_PLUS, 0);
    lv_obj_add_event_cb(btn, lv_spinbox_increment_event_cb, LV_EVENT_ALL, spinbox);

    btn = lv_button_create(lv_screen_active());
    lv_obj_set_size(btn, h, h);
    lv_obj_align_to(btn, spinbox, LV_ALIGN_OUT_LEFT_MID, -5, 0);
    lv_obj_set_style_bg_image_src(btn, LV_SYMBOL_MINUS, 0);
    lv_obj_add_event_cb(btn, lv_spinbox_decrement_event_cb, LV_EVENT_ALL, spinbox);


#endif
    
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void lv_spinbox_increment_event_cb(lv_event_t * e)
{
    lv_obj_t * spinbox = lv_event_get_user_data(e);
    lv_event_code_t code = lv_event_get_code(e);
    
    if(code == LV_EVENT_SHORT_CLICKED || code  == LV_EVENT_LONG_PRESSED_REPEAT) {
        lv_spinbox_increment(spinbox);
    }
}

static void lv_spinbox_decrement_event_cb(lv_event_t * e)
{
    lv_obj_t * spinbox = lv_event_get_user_data(e);
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT) {
        lv_spinbox_decrement(spinbox);
    }
}

static void spinbox_get_value_event_cb_3_19_3(lv_event_t * e)
{
    lv_obj_t * spinbox = lv_event_get_target(e);

    int32_t spinbox_value;
    int32_t spinbox_value_abs;
    int32_t spinbox_value_left;
    int32_t spinbox_value_right;
    double spinbox_value_decimal;
    int32_t right_count;
    
    spinbox_value =  lv_spinbox_get_value(spinbox);
    LV_LOG_USER("%d\n", spinbox_value);

    spinbox_value_abs = abs(spinbox_value);


    right_count = DIGIT_COUNT - SEP_COUNT;
    spinbox_value_left = spinbox_value_abs / pow(10, right_count);
    LV_LOG_USER("%d\n", spinbox_value_left);

    spinbox_value_right = spinbox_value_abs - (spinbox_value_left * pow(10, right_count));
    LV_LOG_USER("%d\n", spinbox_value_right);
    
    spinbox_value_decimal = spinbox_value_left + (spinbox_value_right * (1 / pow(10, right_count)));
    
    if(spinbox_value < 0)
    spinbox_value_decimal = 0.0 - spinbox_value_decimal;
    LV_LOG_USER("%f\n", spinbox_value_decimal);
}


static void spinbox_get_value_event_cb_3_19_4(lv_event_t * e)
{
    lv_obj_t * label =  lv_event_get_user_data(e);
    lv_obj_t * spinbox = lv_event_get_target(e);

    int32_t spinbox_value;
    int32_t spinbox_value_abs;
    int32_t spinbox_value_left;
    int32_t spinbox_value_right;
    double spinbox_value_decimal;
    int32_t right_count;
    
    spinbox_value =  lv_spinbox_get_value(spinbox);
    LV_LOG_USER("%d\n", spinbox_value);

    spinbox_value_abs = abs(spinbox_value);


    right_count = DIGIT_COUNT - SEP_COUNT;
    spinbox_value_left = spinbox_value_abs / pow(10, right_count);
    LV_LOG_USER("%d\n", spinbox_value_left);

    spinbox_value_right = spinbox_value_abs - (spinbox_value_left * pow(10, right_count));
    LV_LOG_USER("%d\n", spinbox_value_right);
    
    spinbox_value_decimal = spinbox_value_left + (spinbox_value_right * (1 / pow(10, right_count)));
    
    if(spinbox_value < 0)
    spinbox_value_decimal = 0.0 - spinbox_value_decimal;
    LV_LOG_USER("%f\n", spinbox_value_decimal);

    // 需要在 lv_conf.h 中打开宏 LV_USE_FLOAT
    lv_label_set_text_fmt(label, "%f", spinbox_value_decimal);  
}

#endif /* LV_USE_LESSON_DEMO_3_19_1 */
