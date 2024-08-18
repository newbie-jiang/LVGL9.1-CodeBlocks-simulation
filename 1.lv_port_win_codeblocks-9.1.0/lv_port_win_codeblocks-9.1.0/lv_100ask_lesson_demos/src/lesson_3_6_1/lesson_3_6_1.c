/**
 ******************************************************************************
 * @file    lesson_3_6_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-5-28
 * @brief	Lesson 3-6-1 demo
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2024-5-28     zhouyuebiao     First version
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

#if LV_USE_LESSON_DEMO_3_6_1

#include "lesson_3_6_1.h"

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
void lesson_3_6_1(void)
{

#if 1 // 3-6-1
    lv_obj_t * spinner = lv_spinner_create(lv_screen_active());
    lv_obj_set_size(spinner, 300, 300);
    lv_obj_center(spinner);
    lv_spinner_set_anim_params(spinner, 1000, 360);
#else if 0 // 3-6-2
#if 0 // case 1
    lv_obj_t * spinner = lv_spinner_create(lv_screen_active());
    lv_obj_set_size(spinner, 200, 200);
    lv_obj_center(spinner);
    lv_spinner_set_anim_params(spinner, 1000, 270);

    lv_obj_set_style_arc_rounded(spinner, 0, LV_PART_INDICATOR);
    lv_obj_set_style_arc_opa(spinner, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_style_arc_color(spinner, lv_palette_main(LV_PALETTE_GREEN), LV_PART_INDICATOR);
    lv_obj_set_style_arc_width(spinner, 40, LV_PART_INDICATOR);
#endif

#if 0 // case 2、3
    lv_obj_t * spinner = lv_spinner_create(lv_screen_active());
    lv_obj_set_size(spinner, 200, 200);
    lv_obj_center(spinner);
    lv_spinner_set_anim_params(spinner, 1000, 180);

    // case 2
    lv_obj_set_style_pad_all(spinner, 14, LV_PART_INDICATOR);

    // case 3
    //lv_obj_set_style_pad_all(spinner, 14, LV_PART_INDICATOR);
    //lv_obj_set_style_pad_all(spinner, 24, LV_PART_MAIN);
    //lv_obj_set_style_pad_all(spinner, -14, LV_PART_INDICATOR);

    lv_obj_set_style_arc_rounded(spinner, 0, LV_PART_INDICATOR);
    //lv_obj_set_style_arc_opa(spinner, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_style_arc_color(spinner, lv_palette_main(LV_PALETTE_GREEN), LV_PART_INDICATOR);
    //lv_obj_set_style_arc_width(spinner, 40, LV_PART_INDICATOR);
#endif

#endif


}

/**********************
 *   STATIC FUNCTIONS
 **********************/


#endif /* LV_USE_LESSON_DEMO_3_6_1 */
