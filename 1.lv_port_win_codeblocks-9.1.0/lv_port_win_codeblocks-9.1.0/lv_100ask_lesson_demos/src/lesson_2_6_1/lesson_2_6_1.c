/**
 ******************************************************************************
 * @file    lesson_2_6_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-4-25
 * @brief	Lesson 2-6-1 demo
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

#if LV_USE_LESSON_DEMO_2_6_1

#include "lesson_2_6_1.h"


/*********************
 *      DEFINES
 *********************/


/**********************
 *  STATIC VARIABLES
 **********************/


void lesson_2_6_1(void)
{
    lv_obj_t * obj1 = lv_obj_create(lv_screen_active());
    lv_obj_align(obj1, LV_ALIGN_CENTER, 0, 0);
    //lv_obj_set_style_border_width(obj1, 10, 0);
    //lv_obj_set_style_outline_width(obj1, 10, 0);
    //lv_obj_set_style_pad_all(obj1, 0, 0);

#if 0
    lv_obj_t * obj2 = lv_obj_create(lv_screen_active());
    lv_obj_t * obj_out_top = lv_obj_create(lv_screen_active());
    lv_obj_t * obj_out_bottom = lv_obj_create(lv_screen_active());
    lv_obj_t * obj_out_left = lv_obj_create(lv_screen_active());
    lv_obj_t * obj_out_right = lv_obj_create(lv_screen_active());
    //lv_obj_set_style_outline_width(obj_out_left, 10, 0);

    lv_obj_align(obj1, LV_ALIGN_CENTER, 0, 0);
    lv_obj_align_to(obj_out_top, obj1, LV_ALIGN_OUT_TOP_MID, 0, 0);
    lv_obj_align_to(obj_out_bottom, obj1, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    lv_obj_align_to(obj_out_left, obj1, LV_ALIGN_OUT_LEFT_MID, 0, 0);
    lv_obj_align_to(obj_out_right, obj1, LV_ALIGN_OUT_RIGHT_MID, 0, 0);
    lv_obj_align_to(obj2, obj_out_right, LV_ALIGN_OUT_TOP_MID, 0, 0);
#endif
}


#endif /* LV_USE_LESSON_DEMO_2_6_1 */
