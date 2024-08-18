/**
 * @file lv_100ask_lesson_demos.h
 *
 */

#ifndef LV_100ASK_LESSON_DEMOS_H
#define LV_100ASK_LESSON_DEMOS_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "../lvgl/lvgl.h"
#endif

#if defined(LV_100ASK_DEMO_CONF_PATH)
#define __LV_TO_STR_AUX(x) #x
#define __LV_TO_STR(x) __LV_TO_STR_AUX(x)
#include __LV_TO_STR(LV_100ASK_DEMO_CONF_PATH)
#undef __LV_TO_STR_AUX
#undef __LV_TO_STR
#elif defined(LV_100ASK_DEMO_CONF_INCLUDE_SIMPLE)
#include "lv_100ask_lesson_demos_conf.h"
#else
#include "../lv_100ask_lesson_demos_conf.h"
#endif

#include "src/lesson_2_3_1/lesson_2_3_1.h"
#include "src/lesson_2_4_1/lesson_2_4_1.h"
#include "src/lesson_2_5_1/lesson_2_5_1.h"
#include "src/lesson_2_6_1/lesson_2_6_1.h"
#include "src/lesson_2_7_1/lesson_2_7_1.h"
#include "src/lesson_2_8_1/lesson_2_8_1.h"
#include "src/lesson_2_9_1/lesson_2_9_1.h"
#include "src/lesson_3_1_1/lesson_3_1_1.h"
#include "src/lesson_3_2_1/lesson_3_2_1.h"
#include "src/lesson_3_3_1/lesson_3_3_1.h"
#include "src/lesson_3_4_1/lesson_3_4_1.h"
#include "src/lesson_3_6_1/lesson_3_6_1.h"
#include "src/lesson_3_7_1/lesson_3_7_1.h"
#include "src/lesson_3_8_1/lesson_3_8_1.h"
#include "src/lesson_3_9_1/lesson_3_9_1.h"
#include "src/lesson_3_10_1/lesson_3_10_1.h"
#include "src/lesson_3_11_1/lesson_3_11_1.h"
#include "src/lesson_3_12_1/lesson_3_12_1.h"
#include "src/lesson_3_13_1/lesson_3_13_1.h"
#include "src/lesson_3_14_1/lesson_3_14_1.h"
#include "src/lesson_3_15_1/lesson_3_15_1.h"
#include "src/lesson_3_16_1/lesson_3_16_1.h"
#include "src/lesson_3_17_1/lesson_3_17_1.h"
#include "src/lesson_3_18_1/lesson_3_18_1.h"
#include "src/lesson_3_19_1/lesson_3_19_1.h"
#include "src/lesson_3_20_1/lesson_3_20_1.h"
#include "src/lesson_3_21_1/lesson_3_21_1.h"
#include "src/lesson_3_22_1/lesson_3_22_1.h"



/*********************
 *      DEFINES
 *********************/
/*Test  lvgl version*/
#if LV_VERSION_CHECK(9, 1, 0) == 0
#warning "lv_100ask_lesson_demos: Wrong lvgl version"
#endif

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/


/**********************
 *      MACROS
 **********************/


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_100ASK_LESSON_DEMOS_H*/
