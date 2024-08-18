/**
 ******************************************************************************
 * @file    lesson_3_20_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-7-19
 * @brief	Lesson 3_20_1 demo
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2024-7-19     zhouyuebiao     First version
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

#if LV_USE_LESSON_DEMO_3_20_1

#include "lesson_3_20_1.h"

/*********************
 *      DEFINES
 *********************/


/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void table_event_handler_3_20_1(lv_event_t * e);

static void table_draw_event_cb_3_20_3(lv_event_t * e);

static void table_update_timer_3_20_4(lv_timer_t * timer);

static void table_draw_event_cb_3_20_5(lv_event_t * e);
static void change_event_cb_3_20_5(lv_event_t * e);

static void ta_event_cb_3_20_6(lv_event_t * e);
/**********************
 *  STATIC VARIABLES
 **********************/
static uint32_t g_col_3_20_5;
static uint32_t g_row_3_20_5;

/**********************
 *      MACROS
 **********************/


/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lesson_3_20_1(void)
{
#if 1 // 3_20_1
    lv_obj_t * table = lv_table_create(lv_screen_active());
    lv_table_set_row_count(table, 10);
    lv_table_set_column_count(table, 1);

    lv_table_set_cell_value(table, 0, 0, "100ask1111111111111111");
    lv_table_set_cell_value(table, 0, 1, "100ask2");
    lv_table_set_cell_value(table, 0, 2, "100ask3");

    lv_table_set_cell_value(table, 1, 0, "100ask4\n100ask5");

    lv_table_set_column_width(table, 0, 300);

    lv_table_add_cell_ctrl(table, 0, 0, LV_TABLE_CELL_CTRL_MERGE_RIGHT);

    lv_obj_set_height(table, 200);

    lv_obj_set_style_bg_color(table, lv_color_hex(0xff0000), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(table, table_event_handler_3_20_1, LV_EVENT_VALUE_CHANGED, NULL);
#elif 0 // 3_20_3
    lv_obj_t * table = lv_table_create(lv_screen_active());

    /*Fill the first column*/
    lv_table_set_cell_value(table, 0, 0, "Name");
    lv_table_set_cell_value(table, 1, 0, "Apple");
    lv_table_set_cell_value(table, 2, 0, "Banana");
    lv_table_set_cell_value(table, 3, 0, "Lemon");
    lv_table_set_cell_value(table, 4, 0, "Grape");
    lv_table_set_cell_value(table, 5, 0, "Melon");
    lv_table_set_cell_value(table, 6, 0, "Peach");
    lv_table_set_cell_value(table, 7, 0, "Nuts");

    /*Fill the second column*/
    lv_table_set_cell_value(table, 0, 1, "Price");
    lv_table_set_cell_value(table, 1, 1, "$7");
    lv_table_set_cell_value(table, 2, 1, "$4");
    lv_table_set_cell_value(table, 3, 1, "$6");
    lv_table_set_cell_value(table, 4, 1, "$2");
    lv_table_set_cell_value(table, 5, 1, "$5");
    lv_table_set_cell_value(table, 6, 1, "$1");
    lv_table_set_cell_value(table, 7, 1, "$9");

    /*Set a smaller height to the table. It'll make it scrollable*/
    lv_obj_set_height(table, 200);
    lv_obj_center(table);

    //lv_obj_set_style_bg_color(table, lv_color_hex(0xff0000), LV_PART_ITEMS | LV_STATE_DEFAULT);

    /*Add an event callback to to apply some custom drawing*/
    lv_obj_add_event_cb(table, table_draw_event_cb_3_20_3, LV_EVENT_DRAW_TASK_ADDED, NULL);
    lv_obj_add_flag(table, LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS);
#elif 0 // 3_20_4
    lv_obj_t * table = lv_table_create(lv_screen_active());

    /*Fill the first column*/
    lv_table_set_cell_value(table, 0, 0, "Name");
    lv_table_set_cell_value(table, 1, 0, "Apple");
    lv_table_set_cell_value(table, 2, 0, "Banana");
    lv_table_set_cell_value(table, 3, 0, "Lemon");
    lv_table_set_cell_value(table, 4, 0, "Grape");
    lv_table_set_cell_value(table, 5, 0, "Melon");
    lv_table_set_cell_value(table, 6, 0, "Peach");
    lv_table_set_cell_value(table, 7, 0, "Nuts");

    /*Fill the second column*/
    lv_table_set_cell_value(table, 0, 1, "Price");
    lv_table_set_cell_value(table, 1, 1, "$7");
    lv_table_set_cell_value(table, 2, 1, "$4");
    lv_table_set_cell_value(table, 3, 1, "$6");
    lv_table_set_cell_value(table, 4, 1, "$2");
    lv_table_set_cell_value(table, 5, 1, "$5");
    lv_table_set_cell_value(table, 6, 1, "$1");
    lv_table_set_cell_value(table, 7, 1, "$9");

    /*Set a smaller height to the table. It'll make it scrollable*/
    lv_obj_set_height(table, 200);
    lv_obj_center(table);

    lv_timer_t * timer = lv_timer_create(table_update_timer_3_20_4, 500, table);

#elif 0 // 3_20_5
    lv_obj_t * table = lv_table_create(lv_screen_active());

    /*Fill the first column*/
    lv_table_set_cell_value(table, 0, 0, "Name");
    lv_table_set_cell_value(table, 1, 0, "Apple");
    lv_table_set_cell_value(table, 2, 0, "Banana");
    lv_table_set_cell_value(table, 3, 0, "Lemon");
    lv_table_set_cell_value(table, 4, 0, "Grape");
    lv_table_set_cell_value(table, 5, 0, "Melon");
    lv_table_set_cell_value(table, 6, 0, "Peach");
    lv_table_set_cell_value(table, 7, 0, "Nuts");

    /*Fill the second column*/
    lv_table_set_cell_value(table, 0, 1, "Price");
    lv_table_set_cell_value(table, 1, 1, "$7");
    lv_table_set_cell_value(table, 2, 1, "$4");
    lv_table_set_cell_value(table, 3, 1, "$6");
    lv_table_set_cell_value(table, 4, 1, "$2");
    lv_table_set_cell_value(table, 5, 1, "$5");
    lv_table_set_cell_value(table, 6, 1, "$1");
    lv_table_set_cell_value(table, 7, 1, "$9");

    lv_obj_center(table);

    lv_obj_add_event_cb(table, table_draw_event_cb_3_20_5, LV_EVENT_DRAW_TASK_ADDED, NULL);
    lv_obj_add_event_cb(table, change_event_cb_3_20_5, LV_EVENT_VALUE_CHANGED, NULL);

    lv_obj_add_flag(table, LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS);

#elif 0 // 3_20_6
    lv_obj_t * table = lv_table_create(lv_screen_active());

    /*Fill the first column*/
    lv_table_set_cell_value(table, 0, 0, "Name");
    lv_table_set_cell_value(table, 1, 0, "Apple");
    lv_table_set_cell_value(table, 2, 0, "Banana");
    lv_table_set_cell_value(table, 3, 0, "Lemon");
    lv_table_set_cell_value(table, 4, 0, "Grape");
    lv_table_set_cell_value(table, 5, 0, "Melon");
    lv_table_set_cell_value(table, 6, 0, "Peach");
    lv_table_set_cell_value(table, 7, 0, "Nuts");

    /*Fill the second column*/
    lv_table_set_cell_value(table, 0, 1, "Price");
    lv_table_set_cell_value(table, 1, 1, "$7");
    lv_table_set_cell_value(table, 2, 1, "$4");
    lv_table_set_cell_value(table, 3, 1, "$6");
    lv_table_set_cell_value(table, 4, 1, "$2");
    lv_table_set_cell_value(table, 5, 1, "$5");
    lv_table_set_cell_value(table, 6, 1, "$1");
    lv_table_set_cell_value(table, 7, 1, "$9");

    lv_obj_set_align(table, LV_ALIGN_TOP_MID);

    lv_obj_add_event_cb(table, table_draw_event_cb_3_20_5, LV_EVENT_DRAW_TASK_ADDED, NULL);


    lv_obj_add_flag(table, LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS);

    lv_obj_t * ta = lv_textarea_create(lv_screen_active());
    lv_obj_t * kb = lv_keyboard_create(lv_screen_active());
    lv_obj_set_size(kb,  LV_HOR_RES, LV_VER_RES / 2);

    lv_keyboard_set_textarea(kb, ta); /*Focus it on one of the text areas to start*/

    lv_obj_add_event_cb(ta, ta_event_cb_3_20_6, LV_EVENT_VALUE_CHANGED, table);

    lv_obj_add_event_cb(table, change_event_cb_3_20_5, LV_EVENT_VALUE_CHANGED, ta);

#endif

}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void table_event_handler_3_20_1(lv_event_t * e)
{
    lv_obj_t * table = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);
    uint32_t row;
    uint32_t col;

    lv_table_get_selected_cell(table, &row, &col);

    LV_LOG_USER("%s", lv_table_get_cell_value(table, row, col));
}


static void table_draw_event_cb_3_20_3(lv_event_t * e)
{
    lv_draw_task_t * draw_task = lv_event_get_draw_task(e);
    //lv_draw_dsc_base_t * base_dsc = draw_task->draw_dsc;
    lv_draw_dsc_base_t * base_dsc = lv_draw_task_get_draw_dsc(draw_task); // 后续版本使用这种写法

    /*If the cells are drawn...*/
    if(base_dsc->part == LV_PART_ITEMS) {
        uint32_t row = base_dsc->id1;
        uint32_t col = base_dsc->id2;

        if(row == 0 && col == 0) {
            lv_draw_label_dsc_t * label_draw_dsc = lv_draw_task_get_label_dsc(draw_task);
            if(label_draw_dsc) {
                label_draw_dsc->align = LV_TEXT_ALIGN_CENTER;
            }
            lv_draw_fill_dsc_t * fill_draw_dsc = lv_draw_task_get_fill_dsc(draw_task);
            if(fill_draw_dsc) {
                fill_draw_dsc->color = lv_color_hex(0xff0000);
                fill_draw_dsc->opa = LV_OPA_COVER;
            }
        }

        if(row == 1 && col == 1) {
            lv_draw_label_dsc_t * label_draw_dsc = lv_draw_task_get_label_dsc(draw_task);
            if(label_draw_dsc) {
                label_draw_dsc->align = LV_TEXT_ALIGN_RIGHT;
                label_draw_dsc->font = &lv_font_montserrat_30;
            }
            lv_draw_fill_dsc_t * fill_draw_dsc = lv_draw_task_get_fill_dsc(draw_task);
            if(fill_draw_dsc) {
                fill_draw_dsc->color = lv_color_hex(0x00ff00);
                fill_draw_dsc->opa = LV_OPA_COVER;
            }
        }
    }
}

/////////////
static void table_update_timer_3_20_4(lv_timer_t * timer)
{
    /*Use the user_data*/
    //lv_obj_t *table = (lv_obj_t *)timer->user_data;
    lv_obj_t *table = (lv_obj_t *)lv_timer_get_user_data(timer); // 后续的新版本使用这种写法

    uint8_t str_buf[32];
    uint32_t value = lv_rand(10, 100);

    lv_snprintf(str_buf, 32, "%d", value);

    lv_table_set_cell_value(table, 1, 1, str_buf);
}

///////////
static void change_event_cb_3_20_5(lv_event_t * e)
{
#if 1
    lv_obj_t * table = lv_event_get_target(e);
    lv_obj_t * ta = lv_event_get_user_data(e);

    lv_table_get_selected_cell(table, &g_row_3_20_5, &g_col_3_20_5);
    bool chk = lv_table_has_cell_ctrl(table, g_row_3_20_5, g_col_3_20_5, LV_TABLE_CELL_CTRL_CUSTOM_1);
    if(chk) lv_table_clear_cell_ctrl(table, g_row_3_20_5, g_col_3_20_5, LV_TABLE_CELL_CTRL_CUSTOM_1);
    else lv_table_add_cell_ctrl(table, g_row_3_20_5, g_col_3_20_5, LV_TABLE_CELL_CTRL_CUSTOM_1);

#else
    // 上面的代码有逻辑问题，这里的代码是优化参考
    static uint32_t last_row = 0;
    static uint32_t last_col = 0;

    lv_obj_t * table = lv_event_get_target(e);
    lv_obj_t * ta = lv_event_get_user_data(e);

    lv_table_get_selected_cell(table, &g_row_3_20_5, &g_col_3_20_5);
    if(g_row_3_20_5 == last_row && g_col_3_20_5 == last_col) return;

    bool chk = lv_table_has_cell_ctrl(table, g_row_3_20_5, g_col_3_20_5, LV_TABLE_CELL_CTRL_CUSTOM_1);
    if(chk) lv_table_clear_cell_ctrl(table, g_row_3_20_5, g_col_3_20_5, LV_TABLE_CELL_CTRL_CUSTOM_1);
    else lv_table_add_cell_ctrl(table, g_row_3_20_5, g_col_3_20_5, LV_TABLE_CELL_CTRL_CUSTOM_1);

    lv_table_clear_cell_ctrl(table, last_row, last_col, LV_TABLE_CELL_CTRL_CUSTOM_1);

    last_row = g_row_3_20_5;
    last_col = g_col_3_20_5;
#endif

    // 此行在 3_20_6 课程中才需要用到，其他情况需要注释掉
    //lv_textarea_set_text(ta, lv_table_get_cell_value(table, g_row_3_20_5, g_col_3_20_5));
}

static void table_draw_event_cb_3_20_5(lv_event_t * e)
{
    lv_obj_t * table = lv_event_get_target(e);

    lv_draw_task_t * draw_task = lv_event_get_draw_task(e);
    //lv_draw_dsc_base_t * base_dsc = draw_task->draw_dsc;
    lv_draw_dsc_base_t * base_dsc = lv_draw_task_get_draw_dsc(draw_task); // 新版本使用这种写法
    /*If the cells are drawn...*/
    if(base_dsc->part == LV_PART_ITEMS) {
        uint32_t row = base_dsc->id1;
        uint32_t col = base_dsc->id2;

        bool chk = lv_table_has_cell_ctrl(table, row, col, LV_TABLE_CELL_CTRL_CUSTOM_1);

        if(chk && (row == g_row_3_20_5) && (col == g_col_3_20_5)) {
            lv_draw_label_dsc_t * label_draw_dsc = lv_draw_task_get_label_dsc(draw_task);
            if(label_draw_dsc) {
                label_draw_dsc->align = LV_TEXT_ALIGN_CENTER;
            }
            lv_draw_fill_dsc_t * fill_draw_dsc = lv_draw_task_get_fill_dsc(draw_task);
            if(fill_draw_dsc) {
                fill_draw_dsc->color = lv_color_hex(0xff0000);
                fill_draw_dsc->opa = LV_OPA_COVER;
            }
        }
    }
}

///////////
static void ta_event_cb_3_20_6(lv_event_t * e)
{
    lv_obj_t * ta = lv_event_get_target(e);
    lv_obj_t * table = lv_event_get_user_data(e);

    printf("%d, %d, %s\n", g_row_3_20_5, g_col_3_20_5, lv_textarea_get_text(ta));
    lv_table_set_cell_value(table, g_row_3_20_5, g_col_3_20_5, lv_textarea_get_text(ta));
}

#endif /* LV_USE_LESSON_DEMO_3_20_1 */
