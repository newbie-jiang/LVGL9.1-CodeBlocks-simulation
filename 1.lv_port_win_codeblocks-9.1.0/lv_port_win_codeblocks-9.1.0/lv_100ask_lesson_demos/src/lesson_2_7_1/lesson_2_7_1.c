/**
 ******************************************************************************
 * @file    lesson_2_7_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-4-25
 * @brief	Lesson 2-7-1 demo
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2024-4-25     zhouyuebiao     First version
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

#if LV_USE_LESSON_DEMO_2_7_1

#include "lesson_2_7_1.h"


/*********************
 *      DEFINES
 *********************/


/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Show how to style a slider.
 */
static void lv_example_slider_2(void)
{
    /*Create a transition*/
    static const lv_style_prop_t props[] = {LV_STYLE_BG_COLOR, 0};
    static lv_style_transition_dsc_t transition_dsc;
    lv_style_transition_dsc_init(&transition_dsc, props, lv_anim_path_linear, 300, 0, NULL);

    static lv_style_t style_main;           // 矩形背景部分
    static lv_style_t style_indicator;      // 指针部分
    static lv_style_t style_knob;           // 旋钮部分
    static lv_style_t style_pressed_color;  // 对象某部分被按下时，该部分样式应用的颜色

    // 矩形背景部分
    lv_style_init(&style_main);
    lv_style_set_bg_opa(&style_main, LV_OPA_COVER);
    lv_style_set_bg_color(&style_main, lv_color_hex3(0xbbb));
    //lv_style_set_outline_width(&style_main, 5);
    //lv_style_set_border_width(&style_main, 2);
    lv_style_set_radius(&style_main, LV_RADIUS_CIRCLE);
    lv_style_set_pad_ver(&style_main, -2); /*Makes the indicator larger*/

    // 指针部分
    lv_style_init(&style_indicator);
    lv_style_set_bg_opa(&style_indicator, LV_OPA_COVER);
    lv_style_set_bg_color(&style_indicator, lv_palette_main(LV_PALETTE_CYAN));
    lv_style_set_radius(&style_indicator, LV_RADIUS_CIRCLE);
    lv_style_set_transition(&style_indicator, &transition_dsc);

    // 旋钮部分
    lv_style_init(&style_knob);
    lv_style_set_bg_opa(&style_knob, LV_OPA_COVER);
    lv_style_set_bg_color(&style_knob, lv_palette_main(LV_PALETTE_CYAN));
    lv_style_set_border_color(&style_knob, lv_palette_darken(LV_PALETTE_CYAN, 3));
    lv_style_set_border_width(&style_knob, 2);
    lv_style_set_radius(&style_knob, LV_RADIUS_CIRCLE);
    lv_style_set_pad_all(&style_knob, 6); /*Makes the knob larger*/
    lv_style_set_transition(&style_knob, &transition_dsc);

    // 对象某部分被按下时，该部分样式应用的颜色
    lv_style_init(&style_pressed_color);
    lv_style_set_bg_color(&style_pressed_color, lv_palette_darken(LV_PALETTE_CYAN, 2));

    /*Create a slider and add the style*/
    lv_obj_t * slider = lv_slider_create(lv_screen_active());

    // 体验流程：先体验 lv_obj_add_style 都被注释时的效果；然后一个个去掉注释
    //lv_obj_remove_style_all(slider);                                                        // 删除对象的所有样式，然后下面再添加我们自定义的样式
    //lv_obj_add_style(slider, &style_main, LV_PART_MAIN);                                    // 矩形背景部分
    //lv_obj_add_style(slider, &style_indicator, LV_PART_INDICATOR);                          // 指针部分
    //lv_obj_add_style(slider, &style_pressed_color, LV_PART_INDICATOR | LV_STATE_PRESSED);   // 当指针部分被按下的时候，指针部分应用该样式
    //lv_obj_add_style(slider, &style_knob, LV_PART_KNOB);                                    // 旋钮部分，像按钮一样可以抓取调整值
    //lv_obj_add_style(slider, &style_pressed_color, LV_PART_KNOB | LV_STATE_PRESSED);        // 当旋钮部分被按下的时候，旋钮部分应用该样式

    lv_obj_center(slider);
}

void lesson_2_7_1(void)
{
#if 0
    // 正常样式
    static lv_style_t style_obj;

	lv_style_init(&style_obj);
    lv_style_set_bg_color(&style_obj, lv_color_hex(0x000000));      // 设置背景色
    lv_style_set_text_color(&style_obj, lv_color_hex(0xc43e1c));    // 设置文字颜色
    //lv_style_set_bg_color(&style_obj, lv_color_hex(0xc43e1c));    // 设置背景色
    //lv_style_set_bg_opa(&style_obj, 30);                          // 设置透明度

    // 创建对象
    lv_obj_t * obj = lv_obj_create(lv_screen_active());

    lv_obj_t * obj2 = lv_obj_create(lv_screen_active());
    lv_obj_align(obj2, LV_ALIGN_CENTER, 0 ,0);

    // 本地样式
    //lv_obj_set_style_bg_color(obj,  lv_color_hex(0xc43e1c), LV_STATE_PRESSED);    // 设置背景色
    //lv_obj_set_style_bg_color(obj2,  lv_color_hex(0xc43e1c), LV_STATE_PRESSED);   // 设置背景色
    //lv_obj_set_style_bg_opa(obj, LV_OPA_50, 0);	                                // 设置背景透明度

    // 添加样式到对象
    lv_obj_add_style(obj, &style_obj, 0);                   // 默认状态: LV_STATE_DEFAULT
    lv_obj_add_style(obj2, &style_obj, 0);                  // 默认状态: LV_STATE_DEFAULT
    //lv_obj_add_style(obj, &style_obj, LV_STATE_PRESSED);  // 按下状态，当对象被按下的时候应用该样式
    //lv_obj_add_style(obj2, &style_obj, LV_STATE_PRESSED); // 按下状态，当对象被按下的时候应用该样式
#endif

    // 滑杆示例(不需要深入研究，体会部件样式的部分和状态即可)，看里面的注释：体验流程
    lv_example_slider_2();
}


#endif /* LV_USE_LESSON_DEMO_2_7_1 */
