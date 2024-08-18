/**
 ******************************************************************************
 * @file    lesson_3_18_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-7-12
 * @brief	Lesson 3_18_1 demo
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

#if LV_USE_LESSON_DEMO_3_18_1

#include "lesson_3_18_1.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void my_lv_keyboard_def_event_cb_3_18_2(lv_event_t * e);
static void my_lv_keyboard_def_event_cb_3_18_3(lv_event_t * e);
static void my_keyboard_def_event_cb_3_18_3(lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lesson_3_18_1(void)
{
#if 1 // 3_18_1
    /*Create an AZERTY keyboard map*/
    static const char * kb_map[] = {"A", "Z", "E", "R", "T", "Y", "U", "I", "O", "P", LV_SYMBOL_BACKSPACE, "\n",
                                    "Q", "S", "D", "F", "G", "J", "K", "L", "M",  LV_SYMBOL_NEW_LINE, "\n",
                                    "W", "X", "C", "V", "B", "N", ",", ".", ":", "!", "?", "\n",
                                    LV_SYMBOL_CLOSE, " ",  " ", " ", LV_SYMBOL_OK, NULL
                                    };

    /*Set the relative width of the buttons and other controls*/
    static const lv_buttonmatrix_ctrl_t kb_ctrl[] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 6,
                                                        4, 4, 4, 4, 4, 4, 4, 4, 4, 6,
                                                        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                                                        2, LV_BUTTONMATRIX_CTRL_HIDDEN | 2, 6, LV_BUTTONMATRIX_CTRL_HIDDEN | 2, 2
                                                    };
                                                    
    lv_obj_t * kb = lv_keyboard_create(lv_screen_active());

    //lv_keyboard_set_mode(kb, LV_KEYBOARD_MODE_NUMBER);

    lv_obj_t * ta = lv_textarea_create(lv_screen_active());
    lv_keyboard_set_textarea(kb, ta);

    lv_keyboard_set_popovers(kb, true);


    // LV_KEYBOARD_MODE_USER_1 - LV_KEYBOARD_MODE_USER_4
    lv_keyboard_set_map(kb, LV_KEYBOARD_MODE_USER_1, kb_map, kb_ctrl);
    //lv_keyboard_set_map(kb, LV_KEYBOARD_MODE_USER_2, kb_map, kb_ctrl);
    //lv_keyboard_set_mode(kb, LV_KEYBOARD_MODE_USER_1);

#elif 0 // 3_18_2
    lv_obj_t * kb = lv_keyboard_create(lv_screen_active());

    // 删除默认的事件
    //lv_obj_remove_event(kb, 0);
    lv_obj_remove_event_cb(kb, lv_keyboard_def_event_cb);
    lv_obj_add_event_cb(kb, my_lv_keyboard_def_event_cb_3_18_2, LV_EVENT_VALUE_CHANGED, NULL);

#elif 0 // 3_18_3
    lv_obj_t * kb = lv_keyboard_create(lv_screen_active());
    

    // 删除默认的事件
    //lv_obj_remove_event(kb, 0);
    //lv_obj_remove_event_cb(kb, lv_keyboard_def_event_cb);
    //lv_obj_add_event_cb(kb, my_lv_keyboard_def_event_cb_3_18_3, LV_EVENT_ALL, NULL);

    lv_obj_t * ta = lv_textarea_create(lv_screen_active());
    lv_keyboard_set_textarea(kb, ta);

    lv_obj_add_event_cb(kb, my_keyboard_def_event_cb_3_18_3, LV_EVENT_LONG_PRESSED, ta);
#endif
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void my_lv_keyboard_def_event_cb_3_18_2(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_current_target(e);

    LV_ASSERT_OBJ(obj, MY_CLASS);
    lv_keyboard_t * keyboard = (lv_keyboard_t *)obj;
    uint32_t btn_id = lv_buttonmatrix_get_selected_button(obj);
    if(btn_id == LV_BUTTONMATRIX_BUTTON_NONE) return;

    const char * txt = lv_buttonmatrix_get_button_text(obj, btn_id);
    if(txt == NULL) return;

    if(lv_strcmp(txt, "abc") == 0) {
        lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_TEXT_LOWER);
        return;
    }

    else if(lv_strcmp(txt, "ABC") == 0) {
        lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_TEXT_UPPER);
        return;
    }
    else if(lv_strcmp(txt, "1#") == 0) {
        lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_SPECIAL);
        return;
    }
    else if(lv_strcmp(txt, LV_SYMBOL_CLOSE) == 0 || lv_strcmp(txt, LV_SYMBOL_KEYBOARD) == 0) {
        lv_result_t res = lv_obj_send_event(obj, LV_EVENT_CANCEL, NULL);
        if(res != LV_RESULT_OK) return;

        if(lv_keyboard_get_textarea(obj)) {
            res = lv_obj_send_event(lv_keyboard_get_textarea(obj), LV_EVENT_CANCEL, NULL);
            if(res != LV_RESULT_OK) return;
        }
        return;
    }
    else if(lv_strcmp(txt, LV_SYMBOL_OK) == 0) {
        lv_result_t res = lv_obj_send_event(obj, LV_EVENT_READY, NULL);
        if(res != LV_RESULT_OK) return;

        if(lv_keyboard_get_textarea(obj)) {
            res = lv_obj_send_event(lv_keyboard_get_textarea(obj), LV_EVENT_READY, NULL);
            if(res != LV_RESULT_OK) return;
        }
        return;
    }

    /*Add the characters to the text area if set*/
    if(lv_keyboard_get_textarea(obj) == NULL) return;

    if(lv_strcmp(txt, "Enter") == 0 || lv_strcmp(txt, LV_SYMBOL_NEW_LINE) == 0) {
        lv_textarea_add_char(lv_keyboard_get_textarea(obj), '\n');
        if(lv_textarea_get_one_line(lv_keyboard_get_textarea(obj))) {
            lv_result_t res = lv_obj_send_event(lv_keyboard_get_textarea(obj), LV_EVENT_READY, NULL);
            if(res != LV_RESULT_OK) return;
        }
    }
    else if(lv_strcmp(txt, LV_SYMBOL_LEFT) == 0) {
        lv_textarea_cursor_left(lv_keyboard_get_textarea(obj));
    }
    else if(lv_strcmp(txt, LV_SYMBOL_RIGHT) == 0) {
        lv_textarea_cursor_right(lv_keyboard_get_textarea(obj));
    }
    else if(lv_strcmp(txt, LV_SYMBOL_BACKSPACE) == 0) {
        lv_textarea_delete_char(lv_keyboard_get_textarea(obj));
    }
    else if(lv_strcmp(txt, "+/-") == 0) {
        uint32_t cur        = lv_textarea_get_cursor_pos(lv_keyboard_get_textarea(obj));
        const char * ta_txt = lv_textarea_get_text(lv_keyboard_get_textarea(obj));
        if(ta_txt[0] == '-') {
            lv_textarea_set_cursor_pos(lv_keyboard_get_textarea(obj), 1);
            lv_textarea_delete_char(lv_keyboard_get_textarea(obj));
            lv_textarea_add_char(lv_keyboard_get_textarea(obj), '+');
            lv_textarea_set_cursor_pos(lv_keyboard_get_textarea(obj), cur);
        }
        else if(ta_txt[0] == '+') {
            lv_textarea_set_cursor_pos(lv_keyboard_get_textarea(obj), 1);
            lv_textarea_delete_char(lv_keyboard_get_textarea(obj));
            lv_textarea_add_char(lv_keyboard_get_textarea(obj), '-');
            lv_textarea_set_cursor_pos(lv_keyboard_get_textarea(obj), cur);
        }
        else {
            lv_textarea_set_cursor_pos(lv_keyboard_get_textarea(obj), 0);
            lv_textarea_add_char(lv_keyboard_get_textarea(obj), '-');
            lv_textarea_set_cursor_pos(lv_keyboard_get_textarea(obj), cur + 1);
        }
    }
    else {
        lv_textarea_add_text(lv_keyboard_get_textarea(obj), txt);
    }
}


static void my_lv_keyboard_def_event_cb_3_18_3(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_current_target(e);

    LV_ASSERT_OBJ(obj, MY_CLASS);
    lv_keyboard_t * keyboard = (lv_keyboard_t *)obj;
    uint32_t btn_id = lv_buttonmatrix_get_selected_button(obj);
    if(btn_id == LV_BUTTONMATRIX_BUTTON_NONE) return;

    const char * txt = lv_buttonmatrix_get_button_text(obj, btn_id);
    if(txt == NULL) return;
    
    if(code == LV_EVENT_VALUE_CHANGED)
    {
        if(lv_strcmp(txt, "abc") == 0) {
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_TEXT_LOWER);
            return;
        }

        else if(lv_strcmp(txt, "ABC") == 0) {
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_TEXT_UPPER);
            return;
        }
        else if(lv_strcmp(txt, "1#") == 0) {
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_SPECIAL);
            return;
        }
        else if(lv_strcmp(txt, LV_SYMBOL_CLOSE) == 0 || lv_strcmp(txt, LV_SYMBOL_KEYBOARD) == 0) {
            lv_result_t res = lv_obj_send_event(obj, LV_EVENT_CANCEL, NULL);
            if(res != LV_RESULT_OK) return;

            if(lv_keyboard_get_textarea(obj)) {
                res = lv_obj_send_event(lv_keyboard_get_textarea(obj), LV_EVENT_CANCEL, NULL);
                if(res != LV_RESULT_OK) return;
            }
            return;
        }
        else if(lv_strcmp(txt, LV_SYMBOL_OK) == 0) {
            lv_result_t res = lv_obj_send_event(obj, LV_EVENT_READY, NULL);
            if(res != LV_RESULT_OK) return;

            if(lv_keyboard_get_textarea(obj)) {
                res = lv_obj_send_event(lv_keyboard_get_textarea(obj), LV_EVENT_READY, NULL);
                if(res != LV_RESULT_OK) return;
            }
            return;
        }

        /*Add the characters to the text area if set*/
        if(lv_keyboard_get_textarea(obj) == NULL) return;

        if(lv_strcmp(txt, "Enter") == 0 || lv_strcmp(txt, LV_SYMBOL_NEW_LINE) == 0) {
            lv_textarea_add_char(lv_keyboard_get_textarea(obj), '\n');
            if(lv_textarea_get_one_line(lv_keyboard_get_textarea(obj))) {
                lv_result_t res = lv_obj_send_event(lv_keyboard_get_textarea(obj), LV_EVENT_READY, NULL);
                if(res != LV_RESULT_OK) return;
            }
        }
        else if(lv_strcmp(txt, LV_SYMBOL_LEFT) == 0) {
            lv_textarea_cursor_left(lv_keyboard_get_textarea(obj));
        }
        else if(lv_strcmp(txt, LV_SYMBOL_RIGHT) == 0) {
            lv_textarea_cursor_right(lv_keyboard_get_textarea(obj));
        }
        else if(lv_strcmp(txt, LV_SYMBOL_BACKSPACE) == 0) {
            lv_textarea_delete_char(lv_keyboard_get_textarea(obj));
        }
        else if(lv_strcmp(txt, "+/-") == 0) {
            uint32_t cur        = lv_textarea_get_cursor_pos(lv_keyboard_get_textarea(obj));
            const char * ta_txt = lv_textarea_get_text(lv_keyboard_get_textarea(obj));
            if(ta_txt[0] == '-') {
                lv_textarea_set_cursor_pos(lv_keyboard_get_textarea(obj), 1);
                lv_textarea_delete_char(lv_keyboard_get_textarea(obj));
                lv_textarea_add_char(lv_keyboard_get_textarea(obj), '+');
                lv_textarea_set_cursor_pos(lv_keyboard_get_textarea(obj), cur);
            }
            else if(ta_txt[0] == '+') {
                lv_textarea_set_cursor_pos(lv_keyboard_get_textarea(obj), 1);
                lv_textarea_delete_char(lv_keyboard_get_textarea(obj));
                lv_textarea_add_char(lv_keyboard_get_textarea(obj), '-');
                lv_textarea_set_cursor_pos(lv_keyboard_get_textarea(obj), cur);
            }
            else {
                lv_textarea_set_cursor_pos(lv_keyboard_get_textarea(obj), 0);
                lv_textarea_add_char(lv_keyboard_get_textarea(obj), '-');
                lv_textarea_set_cursor_pos(lv_keyboard_get_textarea(obj), cur + 1);
            }
        }
        else {
            lv_textarea_add_text(lv_keyboard_get_textarea(obj), txt);
        }
    }
    else if(code == LV_EVENT_LONG_PRESSED)
    {
        if(lv_strcmp(txt, LV_SYMBOL_BACKSPACE) == 0)
            lv_textarea_set_text(lv_keyboard_get_textarea(obj), "");
    }
}

static void my_keyboard_def_event_cb_3_18_3(lv_event_t * e)
{
    lv_obj_t * kb = lv_event_get_current_target(e);
    lv_obj_t * ta = lv_event_get_user_data(e);

    uint32_t btn_id = lv_buttonmatrix_get_selected_button(kb);
    if(btn_id == LV_BUTTONMATRIX_BUTTON_NONE) return;

    const char * txt = lv_buttonmatrix_get_button_text(kb, btn_id);
    
    if(lv_strcmp(txt, LV_SYMBOL_BACKSPACE) == 0)
        lv_textarea_set_text(ta, "");
}

#endif /* LV_USE_LESSON_DEMO_3_18_1 */
