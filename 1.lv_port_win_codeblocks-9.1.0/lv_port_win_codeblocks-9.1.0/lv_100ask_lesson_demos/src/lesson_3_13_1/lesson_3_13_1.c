/**
 ******************************************************************************
 * @file    lesson_3_13_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-6-28
 * @brief	Lesson 3_13_1 demo
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2024-6-28     zhouyuebiao     First version
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

#if LV_USE_LESSON_DEMO_3_13_1

#include "lesson_3_13_1.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        char buf[32];
        lv_dropdown_get_selected_str(obj, buf, sizeof(buf));
        LV_LOG_USER("Option: %s", buf);
    }
}

void lesson_3_13_1(void)
{
#if 1 // 3_13_1

    lv_obj_t * dd = lv_dropdown_create(lv_screen_active());
    lv_dropdown_set_options(dd, "Apple\n"
                                "Banana\n"
                                "Orange\n"
                                "Cherry\n"
                                "Grape\n"
                                "Raspberry\n"
                                "Melon\n"
                                "Orange\n"
                                "Lemon\n"
                                "Nuts");
    
    //lv_dropdown_add_option(dd, "New option", 0);
    //lv_dropdown_add_option(dd, "New option", LV_DROPDOWN_POS_LAST);
    //lv_dropdown_set_selected(dd, 2);
    //lv_dropdown_set_selected(dd, -1);

    lv_obj_align(dd, LV_ALIGN_CENTER, 0, 0);

    lv_obj_set_style_bg_color(dd, lv_color_hex(0xff3c3b), LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * dd_list = lv_dropdown_get_list(dd);
    lv_obj_set_style_bg_color(dd_list, lv_color_hex(0xff3c3b), LV_PART_MAIN | LV_STATE_DEFAULT);

    //lv_dropdown_set_dir(dd, LV_DIR_LEFT);
    lv_dropdown_set_symbol(dd, LV_SYMBOL_UPLOAD);
    
    //lv_dropdown_set_text(dd, "www.100ask.net");
    //lv_dropdown_open(dd);

    lv_obj_add_event_cb(dd, event_handler, LV_EVENT_ALL, NULL);
    
#elif 0 // 3_13_2
    LV_IMAGE_DECLARE(img_cogwheel_argb);

    lv_obj_t * dd = lv_dropdown_create(lv_screen_active());
    lv_dropdown_set_options(dd, "Apple\n"
                                "Banana\n"
                                "Orange\n"
                                "Cherry\n"
                                "Grape\n"
                                "Raspberry\n"
                                "Melon\n"
                                "Orange\n"
                                "Lemon\n"
                                "Nuts");
    
    lv_dropdown_set_symbol(dd, &img_cogwheel_argb);

    lv_obj_set_style_bg_image_src(dd, &img_cogwheel_argb, LV_PART_MAIN | LV_STATE_DEFAULT);

#elif 0 // 3_13_3
    lv_obj_t * dd = lv_dropdown_create(lv_screen_active());
    lv_dropdown_set_options(dd, "Apple\n"
                                "Banana\n"
                                "Orange\n"
                                "Cherry\n"
                                "Grape\n"
                                "Raspberry\n"
                                "Melon\n"
                                "Orange\n"
                                "Lemon\n"
                                "Nuts");
    lv_obj_align(dd, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t * dd_list = lv_dropdown_get_list(dd);

    //lv_obj_set_style_text_font(dd, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_text_font(dd_list, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    LV_FONT_DECLARE(lv_font_source_han_sans_bold_28);
    lv_dropdown_set_symbol(dd, NULL);
    lv_obj_set_style_text_font(dd, &lv_font_source_han_sans_bold_28, LV_PART_MAIN | LV_STATE_DEFAULT);

#elif 0 // 3_13_4

    LV_IMAGE_DECLARE(img_cogwheel_argb);
    lv_obj_t * dd = lv_dropdown_create(lv_screen_active());
    lv_dropdown_set_options(dd, LV_SYMBOL_OK"Apple\n"
                                LV_SYMBOL_OK"Banana\n"
                                LV_SYMBOL_OK"Orange\n"
                                "Cherry""        "LV_SYMBOL_OK"\n"
                                "Grape""         "LV_SYMBOL_OK"\n"
                                "Raspberry"LV_SYMBOL_OK"\n"
                                "Melon\n"
                                "Orange\n"
                                "Lemon\n"
                                "Nuts");
    lv_obj_align(dd, LV_ALIGN_CENTER, 0, 0);
    lv_dropdown_set_dir(dd, LV_DIR_LEFT);

    lv_obj_t * dd_list = lv_dropdown_get_list(dd);
    lv_obj_set_style_bg_image_src(dd_list, &img_cogwheel_argb, LV_PART_MAIN | LV_STATE_DEFAULT);

    //lv_obj_set_style_max_height(dd_list, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_max_width(dd_list, 100, LV_PART_MAIN | LV_STATE_DEFAULT);

    // 不能这样设置
    //lv_obj_set_height(dd_list, 100);
    //lv_obj_set_width(dd_list, 100);
    
    //lv_obj_set_style_text_font(dd, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_text_font(dd_list, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

#endif
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /* LV_USE_LESSON_DEMO_3_13_1 */
