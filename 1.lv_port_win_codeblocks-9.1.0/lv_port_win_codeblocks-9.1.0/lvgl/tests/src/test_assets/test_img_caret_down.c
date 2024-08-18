#include "../../../lvgl.h"

#if LV_BUILD_TEST

#ifndef LV_ATTRIBUTE_MEM_ALIGN
    #define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMAGE_IMG_CARET_DOWN
    #define LV_ATTRIBUTE_IMAGE_IMG_CARET_DOWN
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMAGE_IMG_CARET_DOWN uint8_t
test_image_caret_down_map[]
= {
    /*Pixel format:  Blue: 8 bit, Green: 8 bit, Red: 8 bit, Alpha: 8 bit*/
    0x46, 0x46, 0x46, 0x00, 0x44, 0x44, 0x44, 0x04, 0x2c, 0x2c, 0x2c, 0x08, 0x2c, 0x2c, 0x2c, 0x08, 0x2c, 0x2c, 0x2c, 0x08, 0x2c, 0x2c, 0x2c, 0x08, 0x2c, 0x2c, 0x2c, 0x08, 0x2c, 0x2c, 0x2c, 0x08, 0x2c, 0x2c, 0x2c, 0x08, 0x2c, 0x2c, 0x2c, 0x08, 0x2c, 0x2c, 0x2c, 0x08, 0x31, 0x31, 0x31, 0x08, 0x82, 0x82, 0x82, 0x00,
    0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0xec, 0x01, 0x01, 0x01, 0xff, 0x01, 0x01, 0x01, 0xff, 0x01, 0x01, 0x01, 0xff, 0x01, 0x01, 0x01, 0xff, 0x01, 0x01, 0x01, 0xff, 0x01, 0x01, 0x01, 0xff, 0x01, 0x01, 0x01, 0xff, 0x01, 0x01, 0x01, 0xff, 0x01, 0x01, 0x01, 0xff, 0x02, 0x02, 0x02, 0xf0, 0x0a, 0x0a, 0x0a, 0x74,
    0x0a, 0x0a, 0x0a, 0x00, 0x0a, 0x0a, 0x0a, 0x83, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x03, 0x03, 0x03, 0xd0, 0x14, 0x14, 0x14, 0x27,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x0a, 0x0a, 0x84, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x03, 0x03, 0x03, 0xd3, 0x13, 0x13, 0x13, 0x27, 0x00, 0x00, 0x00, 0x00,
    0x0a, 0x0a, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x13, 0x13, 0x00, 0x0a, 0x0a, 0x0a, 0x87, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x02, 0x02, 0x02, 0xd4, 0x13, 0x13, 0x13, 0x27, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x0d, 0x0d, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x0a, 0x0a, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x10, 0x03, 0x09, 0x09, 0x09, 0x87, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x03, 0x03, 0x03, 0xd7, 0x13, 0x13, 0x13, 0x28, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x0d, 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x0a, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x0d, 0x0d, 0x03, 0x08, 0x08, 0x08, 0x88, 0x00, 0x00, 0x00, 0xff, 0x02, 0x02, 0x02, 0xd8, 0x12, 0x12, 0x12, 0x28, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x0d, 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x13, 0x13, 0x03, 0x0d, 0x0d, 0x0d, 0x5f, 0x12, 0x12, 0x12, 0x2c, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const lv_image_dsc_t test_image_caret_down = {
    .header.w = 13,
    .header.h = 8,
    .header.stride = 52,
    .header.cf = LV_COLOR_FORMAT_ARGB8888,
    .data = test_image_caret_down_map,
};

#endif /* LV_BUILD_TEST */
