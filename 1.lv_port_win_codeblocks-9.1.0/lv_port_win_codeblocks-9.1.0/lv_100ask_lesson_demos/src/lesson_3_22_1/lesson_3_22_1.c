/**
 ******************************************************************************
 * @file    lesson_3_22_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-8-2
 * @brief	Lesson 3_22_1 demo
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2024-8-2     zhouyuebiao     First version
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

#if LV_USE_LESSON_DEMO_3_22_1

#include "lesson_3_22_1.h"

/*********************
 *      DEFINES
 *********************/


/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void my_timer_3_22_1(lv_timer_t * timer);
static void value_changed_event_cb_3_22_1(lv_event_t * e);
static void value_changed_event_cb_3_22_3(lv_event_t * e);

static void x_slider_event_cb_3_22_4(lv_event_t * e);
static void y_slider_event_cb_3_22_4(lv_event_t * e);
/**********************
 *  STATIC VARIABLES
 **********************/
static lv_chart_series_t * ser1;
static lv_chart_cursor_t * cursor;

/**********************
 *      MACROS
 **********************/


/**********************
 *   GLOBAL FUNCTIONS
 **********************/
int32_t value_array[] = {1,2,3,4,5,6,7,8,100,200};

void lesson_3_22_1(void)
{
#if 1 // 3_22_1
    lv_obj_t * chart = lv_chart_create(lv_screen_active());
    lv_obj_set_size(chart, 400, 300);
    lv_obj_center(chart);
    //lv_chart_set_type(chart, LV_CHART_TYPE_LINE);
    //lv_chart_set_point_count(chart, 10);
    //lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, 0, 100);

    //lv_chart_set_div_line_count(chart, 0, 0);

    //lv_chart_set_update_mode(chart, LV_CHART_UPDATE_MODE_CIRCULAR);

    //ser1 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_GREEN), LV_CHART_AXIS_PRIMARY_Y);
    ////lv_chart_set_ext_y_array(chart, ser1, value_array);
    //lv_chart_set_x_start_point(chart, ser1, 3);

    //uint32_t i;
    //for(i = 0; i < 10; i++) {
        /*Set the next points on 'ser'*/
    //    lv_chart_set_next_value(chart, ser1, i);
    //}
    //lv_chart_set_value_by_id(chart, ser1, 3, 80);
    //lv_chart_set_value_by_id(chart, ser1, 3, LV_CHART_POINT_NONE);
    //lv_chart_set_all_value(chart, ser1, 0);


    //lv_chart_refresh(chart);

    //lv_timer_t * timer = lv_timer_create(my_timer_3_22_1, 500, chart);


    // Add cursor
    //cursor = lv_chart_add_cursor(chart, lv_palette_main(LV_PALETTE_BLUE), LV_DIR_RIGHT | LV_DIR_TOP);
    //lv_obj_add_event_cb(chart, value_changed_event_cb_3_22_1, LV_EVENT_VALUE_CHANGED, NULL);
    //lv_obj_refresh_ext_draw_size(chart);

#elif 0 // 3_22_3
    lv_obj_t * chart = lv_chart_create(lv_screen_active());
    lv_obj_set_size(chart, 400, 300);
    lv_obj_center(chart);
    lv_chart_set_type(chart, LV_CHART_TYPE_LINE);
    lv_chart_set_point_count(chart, 10);
    lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, 0, 100);

    lv_chart_set_update_mode(chart, LV_CHART_UPDATE_MODE_CIRCULAR);

    ser1 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_GREEN), LV_CHART_AXIS_PRIMARY_Y);


    uint32_t i;
    for(i = 0; i < 10; i++) {
        /*Set the next points on 'ser'*/
        lv_chart_set_next_value(chart, ser1, i);
    }

    lv_chart_refresh(chart);

    lv_timer_t * timer = lv_timer_create(my_timer_3_22_1, 500, chart);


    // Add cursor
    cursor = lv_chart_add_cursor(chart, lv_palette_main(LV_PALETTE_BLUE), LV_DIR_RIGHT | LV_DIR_TOP);
    lv_obj_add_event_cb(chart, value_changed_event_cb_3_22_3, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_refresh_ext_draw_size(chart);

#elif 0 // 3_22_4
    lv_obj_t * chart_parent = lv_obj_create(lv_screen_active());
    lv_obj_set_size(chart_parent, 600, 600);
    lv_obj_center(chart_parent);

    lv_obj_t * chart = lv_chart_create(chart_parent); // use chart_parent
    lv_obj_set_size(chart, LV_PCT(100), LV_PCT(100));
    lv_obj_center(chart);
    lv_chart_set_type(chart, LV_CHART_TYPE_LINE);
    lv_chart_set_point_count(chart, 10);
    lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, 0, 100);

    lv_chart_set_update_mode(chart, LV_CHART_UPDATE_MODE_CIRCULAR);

    ser1 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_GREEN), LV_CHART_AXIS_PRIMARY_Y);


    uint32_t i;
    for(i = 0; i < 10; i++) {
        /*Set the next points on 'ser'*/
        lv_chart_set_next_value(chart, ser1, i);
    }

    lv_chart_refresh(chart);

    lv_timer_t * timer = lv_timer_create(my_timer_3_22_1, 500, chart);


    // Add cursor
    cursor = lv_chart_add_cursor(chart, lv_palette_main(LV_PALETTE_BLUE), LV_DIR_RIGHT | LV_DIR_TOP);
    lv_obj_add_event_cb(chart, value_changed_event_cb_3_22_3, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_refresh_ext_draw_size(chart);

    // zoom
    lv_obj_t * slider_x = lv_slider_create(lv_screen_active());
    lv_obj_set_size(slider_x, 200, 20);
    lv_slider_set_range(slider_x, 0, 400);
    lv_obj_align_to(slider_x, chart_parent, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    lv_obj_add_event_cb(slider_x, x_slider_event_cb_3_22_4, LV_EVENT_VALUE_CHANGED, chart);

    lv_obj_t * slider_y = lv_slider_create(lv_screen_active());
    lv_obj_set_size(slider_y, 20, 200);
    lv_slider_set_range(slider_y, 0, 400);
    lv_obj_align_to(slider_y, chart_parent, LV_ALIGN_OUT_RIGHT_MID, 0, 0);
    lv_obj_add_event_cb(slider_y, y_slider_event_cb_3_22_4, LV_EVENT_VALUE_CHANGED, chart);

#elif 0 // 3_22_5
    /*Create a container*/
    lv_obj_t * main_cont = lv_obj_create(lv_screen_active());
    lv_obj_set_size(main_cont, 500, 400);
    lv_obj_center(main_cont);

    /*Create a transparent wrapper for the chart and the scale.
     *Set a large width, to make it scrollable on the main container*/
    lv_obj_t * wrapper = lv_obj_create(main_cont);
    lv_obj_remove_style_all(wrapper);
    lv_obj_set_size(wrapper, lv_pct(300), lv_pct(100));
    lv_obj_set_flex_flow(wrapper, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_pad_all(wrapper, 6, 0);

    /*Create a scale also with 100% width*/
    lv_obj_t * scale_bottom = lv_scale_create(wrapper);
    lv_scale_set_mode(scale_bottom, LV_SCALE_MODE_VERTICAL_LEFT);
    lv_obj_set_size(scale_bottom, 25, lv_pct(100));
    lv_scale_set_total_tick_count(scale_bottom, 12);
    lv_scale_set_major_tick_every(scale_bottom, 1);
    //lv_obj_set_style_pad_hor(scale_bottom, lv_chart_get_first_point_center_offset(chart), 0);

    static const char * month[] = {"1", "2", "3", "Apr", "May", "Jun", "July", "Aug", "Sept", "Oct", "Nov", "Dec", NULL};
    //lv_scale_set_text_src(scale_bottom, month);

    /*Create a chart on the wrapper
     *Set it's width to 100% to fill the large wrapper*/
    lv_obj_t * chart = lv_chart_create(wrapper);
    lv_obj_set_size(chart, lv_pct(100), lv_pct(100));
    lv_obj_set_flex_grow(chart, 1);
    lv_chart_set_type(chart, LV_CHART_TYPE_BAR);
    lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, 0, 100);
    lv_chart_set_range(chart, LV_CHART_AXIS_SECONDARY_Y, 0, 400);
    lv_chart_set_point_count(chart, 12);
    lv_obj_set_style_radius(chart, 0, 0);

    /*Add two data series*/
    lv_chart_series_t * ser1 = lv_chart_add_series(chart, lv_palette_lighten(LV_PALETTE_GREEN, 2), LV_CHART_AXIS_PRIMARY_Y);
    lv_chart_series_t * ser2 = lv_chart_add_series(chart, lv_palette_darken(LV_PALETTE_GREEN, 2), LV_CHART_AXIS_PRIMARY_Y);

    /*Set the next points on 'ser1'*/
    uint32_t i;
    for(i = 0; i < 12; i++) {
        lv_chart_set_next_value(chart, ser1, lv_rand(10, 60));
        lv_chart_set_next_value(chart, ser2, lv_rand(50, 90));
    }
    lv_chart_refresh(chart); /*Required after direct set*/
#endif

}



/**********************
 *   STATIC FUNCTIONS
 **********************/
static void my_timer_3_22_1(lv_timer_t * timer)
{
  /*Use the user_data*/

  //lv_obj_t *chart = (lv_obj_t *)timer->user_data;
  lv_obj_t *chart = (lv_obj_t *)lv_timer_get_user_data(timer); // 后续的新版本使用这种写法

  lv_chart_set_next_value(chart, ser1, lv_rand(10, 50));
}

static void value_changed_event_cb_3_22_1(lv_event_t * e)
{
    static int32_t last_id = -1;
    lv_obj_t * obj = lv_event_get_target(e);

    last_id = lv_chart_get_pressed_point(obj);
    if(last_id != LV_CHART_POINT_NONE) {
        lv_chart_set_cursor_point(obj, cursor, NULL, last_id);
    }
}


static void value_changed_event_cb_3_22_3(lv_event_t * e)
{
    static int32_t last_id = -1;
    lv_obj_t * chart = lv_event_get_target(e);

    last_id = lv_chart_get_pressed_point(chart);
    if(last_id != LV_CHART_POINT_NONE) {
        lv_chart_set_cursor_point(chart, cursor, NULL, last_id);
        int32_t * y_array = lv_chart_get_y_array(chart, ser1);
        int32_t value = y_array[last_id];

        LV_LOG_USER("%d", value);
    }
}

static void x_slider_event_cb_3_22_4(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);
    lv_obj_t * chart = lv_event_get_user_data(e);

    lv_obj_set_width(chart, LV_PCT(lv_slider_get_value(slider)));
}


static void y_slider_event_cb_3_22_4(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);
    lv_obj_t * chart = lv_event_get_user_data(e);

    lv_obj_set_height(chart, LV_PCT(lv_slider_get_value(slider)));
}

#endif /* LV_USE_LESSON_DEMO_3_22_1 */
