/**
 ******************************************************************************
 * @file    lesson_2_8_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-4-25
 * @brief	Lesson 2-8-1 demo
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

#if LV_USE_LESSON_DEMO_2_8_1

#include "lesson_2_8_1.h"


/*********************
 *      DEFINES
 *********************/


/**********************
 *  STATIC VARIABLES
 **********************/

#if 1
static void my_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);        // 获取触发事件的部件(对象)
    lv_event_code_t code = lv_event_get_code(e);    // 获取当前部件(对象)触发的事件代码
    lv_obj_t * label = lv_event_get_user_data(e);   // 获取添加事件时传递的用户数据

    switch(code){
        case LV_EVENT_PRESSED:
            lv_label_set_text(label, "LV_EVENT_PRESSED");
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xc43e1c), 0);  // 通过本地样式(私有样式)设置背景色
            LV_LOG_USER("LV_EVENT_PRESSED\n");
            break;
        case LV_EVENT_LONG_PRESSED:
            lv_label_set_text(label, "LV_EVENT_LONG_PRESSED");
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x4cbe37), 0);  // 通过本地样式(私有样式)设置背景色
            LV_LOG_USER("LV_EVENT_LONG_PRESSED\n");
            break;
        default:
            //LV_LOG_USER("NONE\n");
            break;
    }
}

void lesson_2_8_1(void)
{
    /* 创建基础部件(对象) */
    lv_obj_t * obj = lv_obj_create(lv_screen_active());

    /* 创建label部件(对象) */
    lv_obj_t * label = lv_label_create(lv_screen_active());
    lv_label_set_text(label, "test");   // 设置label展示的文字
    lv_obj_center(label);               // 将对象与其父对象的中心对齐，这里的父对象是屏幕：lv_screen_active()

    // 为obj1添加事件回调函数，所有的事件类型都能触发该回调函数
    lv_obj_add_event_cb(obj, my_event_cb, LV_EVENT_ALL, label);
}
#endif // 0



/* 事件冒泡 */
#if 0
static void my_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);            // 获取触发事件的对象
    lv_obj_t * parent = lv_event_get_current_target(e); // 获取触发事件对象的父对象(事件冒泡才有)
    lv_event_code_t code = lv_event_get_code(e);        // 获取当前部件触发的事件代码
    lv_obj_t * label = lv_event_get_user_data(e);       // 获取添加事件时传递的用户数据

    switch(code){
        case LV_EVENT_PRESSED:
            lv_label_set_text(label, "LV_EVENT_PRESSED");
            lv_obj_set_style_bg_color(parent, lv_color_hex(0xc43e1c), 0);   // 通过本地样式(私有样式)设置背景色
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xc43e1c), 0);      // 通过本地样式(私有样式)设置背景色
            LV_LOG_USER("LV_EVENT_PRESSED\n");
            break;
        case LV_EVENT_CLICKED:
            lv_label_set_text(label, "LV_EVENT_CLICKED");
            lv_obj_remove_local_style_prop(parent, LV_STYLE_BG_COLOR, 0);   // 删除通过本地样式(私有样式)设置的背景色
            lv_obj_remove_local_style_prop(obj, LV_STYLE_BG_COLOR, 0);      // 删除通过本地样式(私有样式)设置的背景色
            LV_LOG_USER("LV_EVENT_CLICKED\n");
            break;
        default:
            //LV_LOG_USER("NONE\n");
            break;
    }
}

void lv_100ask_demo_course_2_2_6(void)
{
    /* 创建一个基础对象 obj1 */
    lv_obj_t * obj1 = lv_obj_create(lv_screen_active());
    lv_obj_set_size(obj1, 450, 250);
    lv_obj_center(obj1);                                // 将对象与其父对象的中心对齐，这里的父对象是屏幕：lv_screen_active()

    /* 以 obj1 创建一个基础对象 obj2 */
    lv_obj_t * obj2 = lv_obj_create(obj1);
    lv_obj_set_size(obj2, 400, 200);
    lv_obj_center(obj2);                                // 将对象与其父对象的中心对齐，这里的父对象是屏幕：obj1
    lv_obj_add_flag(obj2, LV_OBJ_FLAG_EVENT_BUBBLE);    // 启用事件冒泡，将接收到的所有事件传播给父级

    /* 以 obj2 创建一个基础对象 obj3 */
    lv_obj_t * obj3 = lv_obj_create(obj2);
    lv_obj_set_size(obj3, 350, 150);
    lv_obj_center(obj3);                                // 将对象与其父对象的中心对齐，这里的父对象是屏幕：obj2
    lv_obj_add_flag(obj3, LV_OBJ_FLAG_EVENT_BUBBLE);    // 启用事件冒泡，将接收到的所有事件传播给父级

    /* 以 obj3 创建一个基础对象 obj4 */
    lv_obj_t * obj4 = lv_obj_create(obj3);
    lv_obj_set_size(obj4, 300, 100);
    lv_obj_center(obj4);                                // 将对象与其父对象的中心对齐，这里的父对象是屏幕：obj3
    lv_obj_add_flag(obj4, LV_OBJ_FLAG_EVENT_BUBBLE);    // 启用事件冒泡，将接收到的所有事件传播给父级

    /* 以屏幕为父类，创建一个label部件(对象) */
    lv_obj_t * label = lv_label_create(lv_screen_active());
    lv_label_set_text(label, "test");                               // 设置label展示的文字
    lv_obj_align_to(label, obj1, LV_ALIGN_OUT_TOP_MID, 0, 0);       // 将label相对于obj1对齐

    // 将给obj1添加事件回调函数，所有的事件类型都能触发该回调函数
    lv_obj_add_event_cb(obj1, my_event_cb, LV_EVENT_ALL, label);
}
#endif // 1

#endif /* LV_USE_LESSON_DEMO_2_8_1 */
