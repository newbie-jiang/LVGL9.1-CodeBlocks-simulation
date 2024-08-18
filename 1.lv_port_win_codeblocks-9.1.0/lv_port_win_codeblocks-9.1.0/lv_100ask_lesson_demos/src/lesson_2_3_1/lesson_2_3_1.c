/**
 ******************************************************************************
 * @file    lesson_2_3_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-4-25
 * @brief	Lesson 2-3-1 demo
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

#if LV_USE_LESSON_DEMO_2_3_1

#include "lesson_2_3_1.h"


/*********************
 *      DEFINES
 *********************/


/**********************
 *  STATIC VARIABLES
 **********************/


void lesson_2_3_1(void)
{
//    lv_obj_t * obj;
//    lv_obj_t * label;
//
//    obj = lv_obj_create(lv_screen_active());
//    lv_obj_set_size(obj, LV_PCT(40), LV_PCT(30));
//    lv_obj_align(obj, LV_ALIGN_CENTER, 0, 0);
//
//    label = lv_label_create(obj);
//    lv_label_set_text_fmt(label, "Hello, LVGL!\n LVGL V%d.%d.%d\n https://www.100ask.net", lv_version_major(), lv_version_minor(), lv_version_patch());
//    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

     lv_obj_t * parent = lv_obj_create(lv_scr_act());
     lv_obj_set_size(parent, 240, 240);    // 设置父容器的大小
     lv_obj_center(parent);                // 将父容器居中显示

     // 创建一个3x3的网格布局
     static lv_coord_t col_dsc[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
     static lv_coord_t row_dsc[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};

     lv_obj_set_grid_dsc_array(parent, col_dsc, row_dsc);    // 设置父容器的网格布局

     // 循环创建9个格子
     for (int i = 0; i < 9; i++) {
        lv_obj_t * btn = lv_btn_create(parent);             // 创建按钮对象
        lv_obj_set_grid_cell(btn,
                             LV_GRID_ALIGN_STRETCH, i % 3, 1,
                             LV_GRID_ALIGN_STRETCH, i / 3, 1);  // 将按钮放置到网格的指定位置

        lv_obj_t * label = lv_label_create(btn);            // 在按钮内创建标签
        lv_label_set_text_fmt(label, "%d", i + 1);          // 设置标签文本为对应的数字
        lv_obj_center(label);                               // 将标签居中对齐
    }


#if 0
    //obj = lv_obj_create(lv_screen_active());
    //lv_obj_set_size(obj, LV_PCT(30), LV_PCT(30));
    //lv_obj_align(obj, LV_ALIGN_CENTER, 0, 0);

    obj = lv_obj_create(lv_layer_top());
    lv_obj_set_size(obj, LV_PCT(35), LV_PCT(25));
    lv_obj_align(obj, LV_ALIGN_CENTER, 0, 0);

    obj = lv_obj_create(lv_layer_sys());
    lv_obj_set_size(obj, LV_PCT(30), LV_PCT(20));
    lv_obj_align(obj, LV_ALIGN_CENTER, 0, 0);
#endif
}


#endif /* LV_USE_LESSON_DEMO_2_3_1 */
