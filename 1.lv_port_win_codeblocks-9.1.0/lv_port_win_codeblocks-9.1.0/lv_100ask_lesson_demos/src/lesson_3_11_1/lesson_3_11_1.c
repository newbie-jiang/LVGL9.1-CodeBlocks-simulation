/**
 ******************************************************************************
 * @file    lesson_3_11_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-6-12
 * @brief	Lesson 3_11_1 demo
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2024-6-12     zhouyuebiao     First version
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

#if LV_USE_LESSON_DEMO_3_11_1

#include "lesson_3_11_1.h"

/*********************
 *      DEFINES
 *********************/
/////////////////////////////////3_11_3
#define DISP_VER_RES 800  /* 以屏幕宽度为x轴，每一个像素为一个整数点 */
#define SIN_POINT_MAX 480 /* 以屏幕高度为y轴，每一个像素为一个整数点 */
#define PI 3.1415926

/* 以屏幕宽度为x轴，每一个像素为一个整数点 */
static lv_point_t line_points[DISP_VER_RES] = {0};
/////////////////////////////////

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void event_handler_3_11_2(lv_event_t *e);
static void sin_timer_3_11_3(lv_timer_t *timer);
static void event_handler_3_11_4_test(lv_event_t *e);
static void event_handler_3_11_4(lv_event_t *e);

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_style_t style_line_3_11_4;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lesson_3_11_1(void)
{
#if 1 // 3_11_1
    static lv_point_precise_t line_points[] = { {5, 5}, {70, 70}, {120, 10}, {180, 60}, {240, 10} };

    static lv_style_t style_line;

    lv_style_init(&style_line);
    lv_style_set_bg_opa(&style_line, LV_OPA_COVER);
    lv_style_set_line_width(&style_line, 8);
    lv_style_set_line_color(&style_line, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_line_rounded(&style_line, true);

    lv_obj_t * line;
    line = lv_line_create(lv_scr_act());
    //lv_obj_set_size(line, LV_PCT(100), LV_PCT(100));
    //lv_line_set_points(line, line_points, 5);     /*Set the points*/
    //lv_obj_add_style(line, &style_line, 0);
    //lv_obj_center(line);
    //lv_line_set_y_invert(line, true);

#elif 0 // 3_11_2
    static lv_point_precise_t line_points[] = {{0, 0}, {0, 200}, {200, 200}};

    static lv_style_t style_line;

    lv_style_init(&style_line);
    // lv_style_set_bg_opa(&style_line, LV_OPA_COVER);
    lv_style_set_line_width(&style_line, 5);
    lv_style_set_line_color(&style_line, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_line_rounded(&style_line, true);
    // lv_style_set_line_dash_width(&style_line, 10);
    // lv_style_set_line_dash_gap(&style_line, 10);

    lv_obj_t *line;
    line = lv_line_create(lv_scr_act());
    // lv_obj_set_size(line, LV_PCT(100), LV_PCT(100));
    lv_line_set_points(line, line_points, 3); /*Set the points*/
    lv_obj_center(line);

    lv_obj_add_style(line, &style_line, 0);

    lv_obj_set_style_line_dash_width(line, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_line_dash_gap(line, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_line_dash_width(line, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_dash_gap(line, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_flag(line, LV_OBJ_FLAG_CLICKABLE);
    // lv_obj_add_event_cb(line, event_handler_3_11_2, LV_EVENT_CLICKED, NULL);

#elif 0 // 3_11_3

    static lv_style_t style_line;

    lv_style_init(&style_line);
    // lv_style_set_bg_opa(&style_line, LV_OPA_COVER);
    lv_style_set_line_width(&style_line, 8);
    lv_style_set_line_color(&style_line, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_line_rounded(&style_line, true);

    lv_obj_t *line;
    line = lv_line_create(lv_scr_act());
    lv_obj_add_style(line, &style_line, 0);
    // lv_line_set_y_invert(line, true);

    lv_timer_create(sin_timer_3_11_3, 10, line);
#elif 0 // 3_11_4

    lv_style_init(&style_line_3_11_4);
    lv_style_set_line_width(&style_line_3_11_4, 8);
    lv_style_set_line_color(&style_line_3_11_4, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_line_rounded(&style_line_3_11_4, true);

    lv_obj_add_flag(lv_scr_act(), LV_OBJ_FLAG_CLICKABLE);
    // lv_obj_add_event_cb(lv_scr_act(), event_handler_3_11_4_test, LV_EVENT_PRESSING, NULL);
    lv_obj_add_event_cb(lv_scr_act(), event_handler_3_11_4, LV_EVENT_PRESSING, NULL);
    lv_obj_add_event_cb(lv_scr_act(), event_handler_3_11_4, LV_EVENT_RELEASED, NULL);
#endif
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void event_handler_3_11_2(lv_event_t *e)
{
    lv_obj_t *line = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_CLICKED)
    {
        lv_obj_set_style_line_dash_width(line, 0, LV_PART_MAIN);
        lv_obj_set_style_line_dash_gap(line, 0, LV_PART_MAIN);
        LV_LOG_USER("Clicked");
    }
}

/* 通过sin()函数用角度计算出每个点的值 */
// 参考链接：https://juejin.cn/post/6966760481528905764
static void sin_timer_3_11_3(lv_timer_t * timer)
{
    /*Use the user_data*/
    //lv_obj_t *line = (lv_obj_t *)timer->user_data;
    lv_obj_t *line = (lv_obj_t *)lv_timer_get_user_data(timer); // 后续的新版本使用这种写法
    static uint16_t i = 0;
    uint16_t j = 0;
    float hd = 0.0; // 弧度
    float fz = 0.0; // 峰值

    j = SIN_POINT_MAX / 2;
    hd = PI / j;

    // 超出屏幕宽度？
    if (i >= DISP_VER_RES)
        i = 0;

    fz = j * sin(hd * i) + j;
    line_points[i].y = (uint16_t)fz;
    line_points[i].x = i;

    printf("[%d, %d]\n", line_points[i].x, line_points[i].y);
    lv_line_set_points(line, line_points, i); /*Set the points*/

    i++;
}

static void event_handler_3_11_4_test(lv_event_t *e)
{
    lv_indev_t *indev = lv_indev_active();
    if (indev == NULL)
        return;

    lv_point_t point;
    lv_indev_get_point(indev, &point);
    LV_LOG_USER("[%d, %d]\n", point.x, point.y);
}

#define POINT_SUM_3_11_4 10
static lv_point_t line_points_3_11_4[POINT_SUM_3_11_4][2] = {0};
static void event_handler_3_11_4(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);

    lv_obj_t *line;

    static uint32_t point_count = 0;
    static lv_point_t last_point;
    lv_point_t cur_point;

    if (code == LV_EVENT_PRESSING)
    {
        lv_indev_t *indev = lv_indev_active();
        if (indev == NULL)
            return;

        lv_indev_get_point(indev, &cur_point);
        LV_LOG_USER("[%d, %d]\n", cur_point.x, cur_point.y);
        if (point_count < POINT_SUM_3_11_4)
        {
            if (point_count == 0)
            {
                last_point.x = cur_point.x;
                last_point.y = cur_point.y;
                point_count++;
                return;
            }
            /*
            {{{0, 0}, {0, 1}},
             {{0, 1}, {0, 2}},
             {{0, 2}, {0, 3}},
             .....
            }
            */
            line_points_3_11_4[point_count][0].x = last_point.x;
            line_points_3_11_4[point_count][0].y = last_point.y;
            line_points_3_11_4[point_count][1].x = cur_point.x;
            line_points_3_11_4[point_count][1].y = cur_point.y;

            line = lv_line_create(lv_scr_act());
            lv_obj_add_style(line, &style_line_3_11_4, 0);
            lv_line_set_points(line, line_points_3_11_4[point_count], 2);
            lv_obj_delete_delayed(line, 100);

            last_point.x = cur_point.x;
            last_point.y = cur_point.y;
            point_count++;
        }
        else
        {
            point_count = 0;
        }
    }
    else if(code == LV_EVENT_RELEASED)
    {
        point_count = 0;
    }
}

#endif /* LV_USE_LESSON_DEMO_3_11_1 */
