#ifndef UTILS_H
#define UTILS_H

#include "lvgl.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 480

#define SIDE_BAR_WIDTH 70
#define CENTRAL_PANEL_WIDTH 660
#define BOTTOM_BAR_HEIGHT 80
#define TOP_BAR_HEIGHT 80
#define DATA_PANEL_HEIGHT 320
#define DATA_LEFT_WIDTH 185
#define DATA_RIGHT_WIDTH 185
#define DATA_CENTER_WIDTH 290

#define COLOR_PRIMARY_HEX 0x383838
#define COLOR_SECONDARY_HEX 0X575757
#define COLOR_TERTIARY_HEX 0xF2F3F5
#define COLOR_BLUE_STATUS_HEX 0x466189
#define COLOR_GREEN_STATUS_HEX 0x39D103
#define COLOR_ORANGE_STATUS_HEX 0xE78A00
#define COLOR_RED_STATUS_HEX 0xCE0000


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


static lv_obj_t *lv_vertical_pair_label(lv_obj_t *parent, const char *up_text, const lv_font_t *up_text_font, const char *bottom_text, const lv_font_t *bottom_text_font)
{
    static lv_coord_t grid_col_dsc[] = {LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t grid_row_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};

    lv_obj_t *grid = lv_obj_create(parent);
    lv_obj_remove_style_all(grid);
    lv_obj_set_size(grid, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_grid_dsc_array(grid, grid_col_dsc, grid_row_dsc);

    lv_obj_t *up_l = lv_label_create(grid);
    lv_label_set_text(up_l, up_text);
    lv_obj_set_style_size(up_l, LV_SIZE_CONTENT, LV_PART_MAIN);
    lv_obj_set_style_text_font(up_l, up_text_font, LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(up_l, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_style_text_color(up_l, lv_color_hex(COLOR_TERTIARY_HEX), 0);
    // lv_obj_align(up_l, LV_ALIGN_CENTER,0,0);
    lv_obj_set_grid_cell(up_l, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 0, 1);

    lv_obj_t *bot_l = lv_label_create(grid);
    lv_label_set_text(bot_l, bottom_text);
    lv_obj_align(bot_l, LV_ALIGN_CENTER, 0, -10);
    lv_obj_set_style_text_font(bot_l, bottom_text_font, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(bot_l, lv_color_hex(COLOR_TERTIARY_HEX), 0);
    lv_obj_set_style_bg_opa(bot_l, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_grid_cell(bot_l, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 1, 1);

    return grid;
}

static lv_obj_t *lv_horizontal_pair_label(lv_obj_t *parent, const char *left_text, const lv_font_t *left_text_font, const char *right_text, const lv_font_t *right_text_font)
{
    static lv_coord_t grid_col_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t grid_row_dsc[] = {LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};

    lv_obj_t *grid = lv_obj_create(parent);
    lv_obj_remove_style_all(grid);
    lv_obj_set_size(grid, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_grid_dsc_array(grid, grid_col_dsc, grid_row_dsc);

    // left label
    lv_obj_t *lx_l = lv_label_create(grid);
    lv_label_set_text(lx_l, left_text);
    lv_obj_set_style_size(lx_l, LV_SIZE_CONTENT, LV_PART_MAIN);
    lv_obj_set_style_text_font(lx_l, left_text_font, LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(lx_l, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_style_text_color(lx_l, lv_color_hex(COLOR_TERTIARY_HEX), 0);
    // lv_obj_align(up_l, LV_ALIGN_CENTER,0,0);
    lv_obj_set_grid_cell(lx_l, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 0, 1);

    // right label
    lv_obj_t *rx_o = lv_obj_create(grid); // inside an obj so I have better management of label positioning
    lv_obj_remove_style_all(rx_o);
    lv_obj_set_size(rx_o, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_t *rx_l = lv_label_create(rx_o);
    lv_label_set_text(rx_l, right_text);
    lv_obj_align(rx_l, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_font(rx_l, right_text_font, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(rx_l, lv_color_hex(COLOR_TERTIARY_HEX), 0);
    lv_obj_set_style_bg_opa(rx_l, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_grid_cell(rx_o, LV_GRID_ALIGN_CENTER, 1, 1, LV_GRID_ALIGN_STRETCH, 0, 1);

    return grid;
}

#endif