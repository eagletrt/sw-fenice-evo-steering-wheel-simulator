#ifndef UTILS_H
#define UTILS_H

#include "lvgl.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 480

#define NOTCH_HEIGHT 40
#define NOTCH_WIDTH 498

#define NOTCH_BAR_WIDTH_S 35  // smaller items
#define NOTCH_BAR_HEIGHT_S 6
#define NOTCH_BAR_WIDTH_L 90  // large item
#define NOTCH_BAR_HEIGHT_L 10


#define COLOR_PRIMARY_HEX 0x383838 //dark grey backgroud
#define COLOR_SECONDARY_HEX 0X575757 //light grey (borders)
#define COLOR_TERTIARY_HEX 0xF2F3F5 //white
#define COLOR_YELLOW_STATUS_HEX 0xFFFA14
#define COLOR_BLUE_STATUS_HEX 0x466189
#define COLOR_GREEN_STATUS_HEX 0x39D103
#define COLOR_ORANGE_STATUS_HEX 0xE78A00
#define COLOR_RED_STATUS_HEX 0xCE0000


LV_FONT_DECLARE(lv_font_inter_bold_10);
LV_FONT_DECLARE(lv_font_inter_bold_12);
LV_FONT_DECLARE(lv_font_inter_bold_14);
LV_FONT_DECLARE(lv_font_inter_bold_15);
LV_FONT_DECLARE(lv_font_inter_bold_16);
LV_FONT_DECLARE(lv_font_inter_bold_18);
LV_FONT_DECLARE(lv_font_inter_bold_20);
LV_FONT_DECLARE(lv_font_inter_bold_22);
LV_FONT_DECLARE(lv_font_inter_bold_24);
LV_FONT_DECLARE(lv_font_inter_bold_26);
LV_FONT_DECLARE(lv_font_inter_bold_28);
LV_FONT_DECLARE(lv_font_inter_bold_30);
LV_FONT_DECLARE(lv_font_inter_bold_32);
LV_FONT_DECLARE(lv_font_inter_bold_34);
LV_FONT_DECLARE(lv_font_inter_bold_36);
LV_FONT_DECLARE(lv_font_inter_bold_38);
LV_FONT_DECLARE(lv_font_inter_bold_40);
LV_FONT_DECLARE(lv_font_inter_bold_42);
LV_FONT_DECLARE(lv_font_inter_bold_44);
LV_FONT_DECLARE(lv_font_inter_bold_46);
LV_FONT_DECLARE(lv_font_inter_bold_48);
LV_FONT_DECLARE(lv_font_inter_bold_50);
LV_FONT_DECLARE(lv_font_inter_bold_52);
LV_FONT_DECLARE(lv_font_inter_bold_54);
LV_FONT_DECLARE(lv_font_inter_bold_56);
LV_FONT_DECLARE(lv_font_inter_bold_58);
LV_FONT_DECLARE(lv_font_inter_bold_60);
LV_FONT_DECLARE(lv_font_inter_bold_70);
LV_FONT_DECLARE(lv_font_inter_bold_80);

extern lv_style_t grid_style;
extern lv_style_t label_style;
extern lv_style_t box_panels_style;

void init_custom_styles(void);

lv_obj_t *lv_vertical_pair_label(lv_obj_t *parent, const char *up_text, const lv_font_t *up_text_font, const char *bottom_text, const lv_font_t *bottom_text_font);
lv_obj_t *lv_horizontal_pair_label(lv_obj_t *parent, const char *left_text, const lv_font_t *left_text_font, const char *right_text, const lv_font_t *right_text_font);
lv_obj_t *lv_triple_label(lv_obj_t *parent, const char *left_text, const lv_font_t *left_text_font , const char *right_text, const lv_font_t *right_text_font, const char *bottom_text, const lv_font_t *bottom_text_font );

lv_obj_t *create_notch(lv_obj_t *parent);

#endif