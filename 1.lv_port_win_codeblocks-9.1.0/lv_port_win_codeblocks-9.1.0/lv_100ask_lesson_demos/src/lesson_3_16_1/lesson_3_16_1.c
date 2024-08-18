/**
 ******************************************************************************
 * @file    lesson_3_16_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-7-10
 * @brief	Lesson 3_16_1 demo
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2024-7-10     zhouyuebiao     First version
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

#if LV_USE_LESSON_DEMO_3_16_1

#include "lesson_3_16_1.h"

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

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/


void lesson_3_16_1(void)
{
#if 1 // 3_16_1
    lv_obj_t * spans = lv_spangroup_create(lv_screen_active());
    lv_obj_set_width(spans, 200);
    lv_obj_set_height(spans, 100);
    lv_obj_center(spans);

    lv_span_t * span;
    span = lv_spangroup_new_span(spans);
    lv_span_set_text(span, "111111111111");
    //lv_obj_set_style_text_color(spans, lv_palette_main(LV_PALETTE_RED), 0);
    ////lv_style_set_text_color(&span->style, lv_palette_main(LV_PALETTE_RED));  // 新版本以抛弃这种用法
    lv_style_set_text_color(lv_span_get_style(span), lv_palette_main(LV_PALETTE_RED)); // 后面的新版本使用这个接口获取，而不是上面那行代码直接操作

    span = lv_spangroup_new_span(spans);
    lv_span_set_text(span, "222222222222222222");
    ////lv_style_set_text_font(&span->style, &lv_font_montserrat_30);
    ////lv_style_set_text_font(&span->style, &lv_font_montserrat_30);
    //lv_style_set_text_font(lv_span_get_style(span), &lv_font_montserrat_30);
    lv_style_set_text_font(lv_span_get_style(span), &lv_font_montserrat_30);

    span = lv_spangroup_new_span(spans);
    lv_span_set_text(span, "33333333fdfdsfsdfsdfsdfsdfsdfffffffffsdfsdfsdfsdfdsfsdfsdfsddfsfsd33333");

    span = lv_spangroup_get_child(spans, -1);
    ////lv_style_set_text_font(&span->style, &lv_font_montserrat_20);
    lv_style_set_text_font(lv_span_get_style(span), &lv_font_montserrat_20);

    LV_LOG_USER("span_count: %d", lv_spangroup_get_span_count(spans));

    //lv_spangroup_set_align(spans, LV_TEXT_ALIGN_LEFT);
    //lv_spangroup_set_mode(spans, LV_SPAN_MODE_FIXED);   // 默认状态
    //lv_spangroup_set_mode(spans, LV_SPAN_MODE_EXPAND);  // 忽略宽度限制
    //lv_spangroup_set_mode(spans, LV_SPAN_MODE_BREAK);   // 忽略高度限制

    //lv_spangroup_set_overflow(spans, LV_SPAN_OVERFLOW_ELLIPSIS);

    ///lv_spangroup_set_indent(spans, 60);
    //lv_spangroup_set_max_lines(spans, 4);

    //lv_obj_add_flag(spans, LV_OBJ_FLAG_CLICKABLE);
    //lv_obj_add_event_cb(spans, event_handler, LV_EVENT_CLICKED, NULL);

#elif 0 // 3_16_2
    lv_obj_t * spans = lv_spangroup_create(lv_screen_active());
    lv_obj_set_width(spans, LV_PCT(100));
    lv_obj_set_height(spans, 100);
    lv_obj_center(spans);

    lv_span_t * span;
    span = lv_spangroup_new_span(spans);
    lv_span_set_text(span, "111111111111");
    //lv_obj_set_style_text_color(spans, lv_palette_main(LV_PALETTE_RED), 0);
    ////lv_style_set_text_color(&span->style, lv_palette_main(LV_PALETTE_RED));  // 新版本以抛弃这种用法
    lv_style_set_text_color(lv_span_get_style(span), lv_palette_main(LV_PALETTE_RED)); // 后面的新版本使用这个接口获取，而不是上面那行代码直接操作


    span = lv_spangroup_new_span(spans);
    lv_span_set_text(span, "222222222222222222");
    ////lv_style_set_text_font(&span->style, &lv_font_montserrat_30);
    lv_style_set_text_font(lv_span_get_style(span), &lv_font_montserrat_30);

    span = lv_spangroup_new_span(spans);
    lv_span_set_text(span, "33333333fdfdsfsdfsdfsdfsdfsdfffffffffsdfsdfsdfsdfdsfsdfsdfsddfsfsd33333");

    span = lv_spangroup_get_child(spans, -1);
    ////lv_style_set_text_font(&span->style, &lv_font_montserrat_20);
    lv_style_set_text_font(lv_span_get_style(span), &lv_font_montserrat_20);

    LV_LOG_USER("span_count: %d", lv_spangroup_get_span_count(spans));

    //lv_spangroup_set_align(spans, LV_TEXT_ALIGN_LEFT);
    //lv_spangroup_set_mode(spans, LV_SPAN_MODE_FIXED);   // 默认状态
    //lv_spangroup_set_mode(spans, LV_SPAN_MODE_EXPAND);  // 忽略宽度限制
    //lv_spangroup_set_mode(spans, LV_SPAN_MODE_BREAK);   // 忽略高度限制

    //lv_spangroup_set_overflow(spans, LV_SPAN_OVERFLOW_ELLIPSIS);

    ///lv_spangroup_set_indent(spans, 60);
    //lv_spangroup_set_max_lines(spans, 4);

    lv_obj_add_flag(spans, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(spans, event_handler, LV_EVENT_CLICKED, NULL);

    //lv_spangroup_set_indent(spans, LV_PCT(50));

#endif
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void event_handler(lv_event_t * e)
{
    LV_LOG_USER("LV_EVENT_CLICKED");
}

#endif /* LV_USE_LESSON_DEMO_3_16_1 */
