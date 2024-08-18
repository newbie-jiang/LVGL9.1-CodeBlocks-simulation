/**
 ******************************************************************************
 * @file    lesson_3_7_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-5-30
 * @brief	Lesson 3-7-1 demo
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2024-5-30     zhouyuebiao     First version
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

#if LV_USE_LESSON_DEMO_3_7_1

#include "lesson_3_7_1.h"

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
static void event_cb_3_7_3(lv_event_t * e);

/////////////////////3-7-5
static void btn_timer_cb_3_7_5(lv_timer_t * timer);

static void btnm_timer_cb_3_7_6(lv_timer_t * timer);
static void event_cb_3_7_6(lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

static uint32_t lamp_state_map_3_7_6[9] = {0};
/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lesson_3_7_1(void)
{
#if 0 // 3-7-1
    static const char * btnm_map[] = {"1", "2", "3", "4", "5", "\n",
                                      "6", "7", "8", "9", "0", "\n",
                                      "Action1", "Action2", ""
                                     };
    const lv_buttonmatrix_ctrl_t ctrl_map[] = {LV_BUTTONMATRIX_CTRL_HIDDEN, _LV_BUTTONMATRIX_CTRL_RESERVED_3, LV_BUTTONMATRIX_CTRL_HIDDEN};

    lv_obj_t * btnm = lv_buttonmatrix_create(lv_screen_active());
    lv_obj_set_size(btnm, 400, 200);
    lv_obj_center(btnm);

    lv_buttonmatrix_set_map(btnm, btnm_map);
    lv_buttonmatrix_set_button_width(btnm, 5, 2);

    //lv_buttonmatrix_set_button_ctrl(btnm, 5, LV_BUTTONMATRIX_CTRL_HIDDEN);
    //lv_buttonmatrix_clear_button_ctrl(btnm, 5, LV_BUTTONMATRIX_CTRL_HIDDEN);

    //lv_buttonmatrix_set_button_ctrl_all(btnm, LV_BUTTONMATRIX_CTRL_HIDDEN);
    //lv_buttonmatrix_clear_button_ctrl_all(btnm, LV_BUTTONMATRIX_CTRL_HIDDEN);

    //lv_buttonmatrix_set_ctrl_map(btnm, ctrl_map);

    lv_buttonmatrix_set_button_ctrl_all(btnm, LV_BUTTONMATRIX_CTRL_CHECKABLE);
    lv_buttonmatrix_set_one_checked(btnm, true);

    lv_obj_add_event_cb(btnm, event_handler, LV_EVENT_ALL, NULL);
#elif 0 // 3-7-2
    // 没有代码，对比内存监视器的变化
    // 将lv_conf.h 中的如下宏设置为1
    // #define LV_USE_SYSMON   1
    // #define LV_USE_MEM_MONITOR 1
#elif 0 // 3-7-3
    static const char * btnm_map[] = {"1", "2", "3", "A", "\n",
                                      "4", "5", "6", "B", "\n",
                                      "7", "8", "9", "C", "\n",
                                      "*", "0", "#", "D", ""
                                     };
    lv_obj_t * btnm = lv_buttonmatrix_create(lv_screen_active());
    lv_obj_set_size(btnm, 400, 400);
    lv_obj_center(btnm);

    lv_buttonmatrix_set_map(btnm, btnm_map);
    lv_obj_set_style_bg_color(btnm, lv_palette_main(LV_PALETTE_BLUE), LV_PART_ITEMS);

    lv_obj_add_event_cb(btnm, event_cb_3_7_3, LV_EVENT_DRAW_TASK_ADDED, NULL);
    lv_obj_add_flag(btnm, LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS);

    lv_obj_set_style_text_color(btnm, lv_color_white(), LV_PART_ITEMS);
    lv_obj_set_style_text_font(btnm, &lv_font_montserrat_20, LV_PART_ITEMS);

#elif 0 // 3-7-4
    // 没有代码

#elif 0 // 3-7-5

#if 1  // 使用按钮控件3-7-5

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
    }

    lv_timer_t * timer = lv_timer_create(btn_timer_cb_3_7_5, 1000, cont);

#else  // 使用矩阵按钮控件 3-7-6
    static const char * btnm_map[] = {"Button1", "Button2", "Button3", "\n",
                                      "Button4", "Button5", "Button6", "\n",
                                      "Button7", "Button8", "Button9", ""
                                     };
    lv_obj_t * btnm = lv_buttonmatrix_create(lv_screen_active());
    lv_obj_set_size(btnm, 400, 400);
    lv_obj_center(btnm);
    lv_buttonmatrix_set_map(btnm, btnm_map);

    lv_buttonmatrix_set_button_ctrl_all(btnm, LV_BUTTONMATRIX_CTRL_CHECKABLE);

    lv_obj_add_event_cb(btnm, event_cb_3_7_6, LV_EVENT_DRAW_TASK_ADDED, NULL);
    lv_obj_add_flag(btnm, LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS);

    lv_timer_t * timer = lv_timer_create(btnm_timer_cb_3_7_6, 1000, btnm);

    //lv_obj_set_style_text_color(btnm, lv_color_white(), LV_PART_ITEMS);
    lv_obj_set_style_text_font(btnm, &lv_font_montserrat_20, LV_PART_ITEMS);
#endif

#endif

}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        uint32_t id = lv_buttonmatrix_get_selected_button(obj);
        const char * txt = lv_buttonmatrix_get_button_text(obj, id);
        LV_UNUSED(txt);
        LV_LOG_USER("%s was pressed\n", txt);
    }
}


static void event_cb_3_7_3(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_draw_task_t * draw_task = lv_event_get_draw_task(e);
    //lv_draw_dsc_base_t * base_dsc = draw_task->draw_dsc;
    lv_draw_dsc_base_t * base_dsc = lv_draw_task_get_draw_dsc(draw_task); // 新版本使用这种写法

    /*When the button matrix draws the buttons...*/
    if(base_dsc->part == LV_PART_ITEMS) {
        bool pressed = false;
        if(lv_buttonmatrix_get_selected_button(obj) == base_dsc->id1 && lv_obj_has_state(obj, LV_STATE_PRESSED)) {
            pressed = true;
        }

        //lv_draw_label_dsc_t * label_draw_dsc = lv_draw_task_get_label_dsc(draw_task);
        //if(label_draw_dsc) {
        //    label_draw_dsc->color = lv_color_white();
        //}
        if((base_dsc->id1 == 3) || (base_dsc->id1 == 7) ||\
           (base_dsc->id1 == 11) || (base_dsc->id1 == 12) ||\
           (base_dsc->id1 == 14) || (base_dsc->id1 == 15)){
            lv_draw_fill_dsc_t * fill_draw_dsc = lv_draw_task_get_fill_dsc(draw_task);
            if(fill_draw_dsc) {
                if(pressed) fill_draw_dsc->color = lv_palette_darken(LV_PALETTE_RED, 3);
                else fill_draw_dsc->color = lv_palette_main(LV_PALETTE_RED);
            }
        }
    }
}


//////////////////////////// 3_7_5 -  3-7-6

// 3-7-5
static void btn_timer_cb_3_7_5(lv_timer_t * timer)
{
    /*Use the user_data*/
    //lv_obj_t *cont = (lv_obj_t *)timer->user_data;
    lv_obj_t *cont = (lv_obj_t *)lv_timer_get_user_data(timer); // 后续的新版本使用这种写法

    uint32_t lamp_state = 0;
    lv_obj_t * child = NULL;

    for(int i = 0; i < 9; i++)
    {
        child = lv_obj_get_child(cont, i);

        lamp_state = lv_rand(0, 1);
        if(lamp_state == 0) lv_obj_add_state(child, LV_STATE_CHECKED);
        else lv_obj_clear_state(child, LV_STATE_CHECKED);
    }
}


// 3-7-6
static void btnm_timer_cb_3_7_6(lv_timer_t * timer)
{
    //lv_obj_t *btnm = (lv_obj_t *)timer->user_data;
    lv_obj_t *btnm = (lv_obj_t *)lv_timer_get_user_data(timer); // 后续的新版本使用这种写法

    /*Use the user_data*/
    for(int i = 0; i < 9; i++)
    {
        lamp_state_map_3_7_6[i] = lv_rand(0, 1);
    }

    lv_obj_send_event(btnm, LV_EVENT_STYLE_CHANGED, NULL);
}

static void event_cb_3_7_6(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_draw_task_t * draw_task = lv_event_get_draw_task(e);
    //lv_draw_dsc_base_t * base_dsc = draw_task->draw_dsc;
    lv_draw_dsc_base_t * base_dsc = lv_draw_task_get_draw_dsc(draw_task); // 新版本使用这种写法

    /*When the button matrix draws the buttons...*/
    if(base_dsc->part == LV_PART_ITEMS) {
        lv_draw_fill_dsc_t * fill_draw_dsc = lv_draw_task_get_fill_dsc(draw_task);
        if(fill_draw_dsc) {
            if(lamp_state_map_3_7_6[base_dsc->id1] == 0) fill_draw_dsc->color = lv_palette_main(LV_PALETTE_BLUE);
            else fill_draw_dsc->color = lv_palette_main(LV_PALETTE_RED);
            LV_LOG_USER(": %d", lamp_state_map_3_7_6[base_dsc->id1]);
        }
    }
}
#endif /* LV_USE_LESSON_DEMO_3_7_1 */
