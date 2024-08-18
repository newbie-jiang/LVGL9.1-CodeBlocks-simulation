/**
 ******************************************************************************
 * @file    lesson_2_9_1.c
 * @author  百问科技
 * @version V1.0
 * @date    2024-4-25
 * @brief	Lesson 2-9-1 demo
 ******************************************************************************
 * Change Logs:
 * Date           Author          Notes
 * 2024-5-10     zhouyuebiao     First version
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

#if LV_USE_LESSON_DEMO_2_9_1

#include "lesson_2_9_1.h"


/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void my_timer1(lv_timer_t * timer);
static void my_timer2(lv_timer_t * timer);
static void my_timer3(lv_timer_t * timer);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lesson_2_9_1(void)
{
    static int user_data = 100;

    lv_timer_t * timer1;
    lv_timer_t * timer2;
    lv_timer_t * timer3;

#if 1
    /* 创建第一个timer */
    timer1 = lv_timer_create(my_timer1, 100, &user_data);
    //lv_timer_set_cb(timer1, my_timer1);
    //lv_timer_set_period(timer1, 10);

    // 设置此timer的运行次数，设置后该timer在执行指定次数后会自动删除
    // 设置为 -1 就是无限重复，默认值就是 -1
    //lv_timer_set_repeat_count(timer1, 3);

    // 让此timer在下一次调用 lv_timer_handler() 时运行
    // 也就是会马上运行，而不是等过了给定的第一个周期过了之后才运行。
    // 与它相反的是：lv_timer_reset(timer) 其会重置定时器的周期，
    // 这样定时器将在我们设置的毫秒时间段过去后再调用。
    //lv_timer_ready(timer1);
    //lv_timer_reset(timer1);
#endif

#if 0
    timer2 = lv_timer_create(my_timer2, 100, timer1);
    lv_timer_set_repeat_count(timer2, 1);

    timer3 = lv_timer_create_basic(); // timer3 = lv_timer_create(NULL, 500, NULL);
    lv_timer_set_cb(timer3, my_timer3);
#endif
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void my_timer1(lv_timer_t * timer)
{
    int *user_data = lv_timer_get_user_data(timer);
    
    uint32_t idle = lv_timer_get_idle();
    LV_LOG_USER("my_timer1 user_data: %d, idle: %d", *user_data, idle);
}


static void my_timer2(lv_timer_t * timer)
{
    static int i = 0;
    //lv_timer_t * timer1 = lv_timer_get_user_data(timer);
    //LV_LOG_USER("my_timer2");

    usleep(1000 * i++);
}

static void my_timer3(lv_timer_t * timer)
{
    LV_LOG_USER("my_timer3");
}

#endif /* LV_USE_LESSON_DEMO_2_9_1 */
