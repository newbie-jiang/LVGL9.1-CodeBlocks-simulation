/**
 ******************************************************************************
 * @file    lesson_3_2_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-5-20
 * @brief	Lesson 3-2-1 demo
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2024-5-20     zhouyuebiao     First version
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

#if LV_USE_LESSON_DEMO_3_2_1

#include "lesson_3_2_1.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void btn_event_handler(lv_event_t * e);
static void btn_3_2_3_event_handler(lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void lesson_3_2_1(void)
{

#if 0 // 3-2-1
    lv_obj_t * btn;
    lv_obj_t * label;

    btn = lv_button_create(lv_screen_active());
    lv_obj_add_flag(btn, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_size(btn, 400, 200);
    lv_obj_center(btn);

    label = lv_label_create(btn);
    lv_label_set_text(label, "Button");
    lv_obj_center(label);

    lv_obj_add_event_cb(btn, btn_event_handler, LV_EVENT_ALL, NULL);
#elif 0   //3-2-3 （视频演示说这里是3-2-2的代码，其实应该是3-2-3）

    lv_obj_t* obj;
    lv_obj_t *label;
    static lv_style_t style_obj;
    static lv_style_t style_pr;

    obj = lv_obj_create(lv_screen_active());
    lv_obj_set_size(obj, 200, 100);

	lv_style_init(&style_obj);
    lv_style_set_text_color(&style_obj, lv_color_white());
    lv_style_set_bg_color(&style_obj, lv_palette_main(LV_PALETTE_BLUE));
    
    lv_style_set_shadow_width(&style_obj, 8);
    lv_style_set_shadow_offset_y(&style_obj, 8);

    lv_style_set_border_width(&style_obj, 0);

    /////////////////////
	lv_style_init(&style_pr);
    //lv_style_set_size(&style_pr, 210, 110); 400 200
    lv_style_set_transform_width(&style_pr, 10);
    lv_style_set_transform_height(&style_pr, 10);

    lv_obj_add_style(obj, &style_obj, 0);
    lv_obj_add_style(obj, &style_pr, LV_STATE_PRESSED);

    lv_obj_center(obj);

    label = lv_label_create(obj);
    //lv_obj_set_style_text_color(label, lv_color_white(), 0);

#elif 0   // 3-2-4（视频演示说这里是3-2-3的代码，其实应该是3-2-4）
    lv_obj_t * cont;
    lv_obj_t * btn;
    lv_obj_t * label;

    #define BTN_PAD 20
    int w = 0;
    int h = 0;
    int x = 0;
    int y = 0;
    cont = lv_obj_create(lv_screen_active());
    lv_obj_remove_style_all(cont);
    lv_obj_set_size(cont, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_center(cont);
    for(int i = 0; i < 9; i++)
    {
        btn = lv_button_create(cont);
        lv_obj_add_flag(btn, LV_OBJ_FLAG_CHECKABLE);
        lv_obj_set_size(btn, 80, 40);

        label = lv_label_create(btn);
        lv_label_set_text_fmt(label, "Button%d", i);
        lv_obj_center(label);
        
        lv_obj_update_layout(btn);
        w = lv_obj_get_width(btn);
        h = lv_obj_get_height(btn);

        if((i % 3) == 0)
        {
            x = 0;
            y = (i / 3) * (h + BTN_PAD);
        }
        else
        {
            x = (w + BTN_PAD) * (i % 3);
        }
        lv_obj_set_pos(btn, x, y);

        lv_obj_add_event_cb(btn, btn_3_2_3_event_handler, LV_EVENT_ALL, NULL);
    }
#elif 0   // 3-2-6
    lv_obj_t *btn;
    lv_obj_t *label;
    
    btn = lv_button_create(lv_screen_active());
    lv_obj_set_size(btn, 100, 100); // 100/2 = 50
    lv_obj_center(btn);

    lv_obj_set_style_radius(btn, 20, LV_PART_MAIN); // 设置为50就会变成一个圆

    label = lv_label_create(btn);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_40, LV_PART_MAIN);
    lv_label_set_text(label, LV_SYMBOL_BLUETOOTH);
    lv_obj_center(label);
#endif

}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void btn_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED) {
        LV_LOG_USER("Clicked");
    }
    else if(code == LV_EVENT_VALUE_CHANGED) {
        LV_LOG_USER("Toggled");
    }
}

static void btn_3_2_3_event_handler(lv_event_t * e)
{
    lv_obj_t * btn = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * label = lv_obj_get_child(btn, 0);

    if(code == LV_EVENT_CLICKED) {
        LV_LOG_USER("btn: %s", lv_label_get_text(label));
    }
    else if(code == LV_EVENT_VALUE_CHANGED) {
        LV_LOG_USER("Toggled");
    }
}

#endif /* LV_USE_LESSON_DEMO_3_2_1 */
