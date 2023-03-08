#ifndef TAB_RACING_H
#define TAB_RACING_H

#include "lvgl.h"
#include "ratios.h"

LV_FONT_DECLARE(lv_font_inter_bold_16);
LV_FONT_DECLARE(lv_font_inter_bold_18);
LV_FONT_DECLARE(lv_font_inter_bold_20);
LV_FONT_DECLARE(lv_font_inter_bold_22);
LV_FONT_DECLARE(lv_font_inter_bold_24);
LV_FONT_DECLARE(lv_font_inter_bold_26);
LV_FONT_DECLARE(lv_font_inter_bold_28);
LV_FONT_DECLARE(lv_font_inter_bold_30);
LV_FONT_DECLARE(lv_font_inter_bold_40);
LV_FONT_DECLARE(lv_font_inter_bold_50);
LV_FONT_DECLARE(lv_font_inter_bold_70);

void tab_racing(lv_obj_t *parent);

static lv_style_t grid_style;
static lv_style_t bar_style;
static lv_style_t label_style;

static void init_custom_styles(){

    /* GRID_STYLE */
    lv_style_init(&grid_style);
    lv_style_set_pad_all(&grid_style, 0);
    lv_style_set_pad_bottom(&grid_style, 0);
    lv_style_set_pad_column(&grid_style, 0);
    lv_style_set_pad_top(&grid_style, 0);
    lv_style_set_pad_row(&grid_style, 0);
    lv_style_set_bg_color(&grid_style, lv_color_hex(COLOR_PRIMARY_HEX));
    lv_style_set_bg_opa(&grid_style, LV_OPA_COVER);
    // lv_style_set_border_opa(&grid_style, 0); to remove borders, keeping bc useful

    /* BAR_STYLE */
    lv_style_init(&bar_style);
    lv_style_set_bg_opa(&bar_style, LV_OPA_COVER);
    lv_style_set_bg_color(&bar_style, lv_palette_main(LV_PALETTE_RED));
    lv_style_set_bg_grad_color(&bar_style, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_bg_grad_dir(&bar_style, LV_GRAD_DIR_VER);

    /* LABEL_STYLE */
    lv_style_init(&label_style);
    lv_style_set_base_dir(&label_style, LV_BASE_DIR_LTR);
    lv_style_set_bg_opa(&label_style, LV_OPA_TRANSP);
    lv_style_set_text_color(&label_style, lv_color_hex(COLOR_TERTIARY_HEX));
    lv_style_set_text_align(&label_style, LV_TEXT_ALIGN_CENTER);

}



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

static void lv_custom_meter(lv_obj_t *custom_meter)
{

    /*Remove the circle from the middle*/
    lv_obj_remove_style(custom_meter, NULL, LV_PART_MAIN);
    lv_obj_remove_style(custom_meter, NULL, LV_PART_INDICATOR);

    // lv_obj_set_grid_cell(custom_meter, LV_GRID_ALIGN_STRETCH, 2, 1, LV_GRID_ALIGN_STRETCH, 2, 1);
    lv_obj_set_size(custom_meter, 290, 290);

    /*Add a scale first*/
    lv_meter_scale_t *scale = lv_meter_add_scale(custom_meter);
    // lv_obj_align(custom_meter,  )
    // lv_meter_set_scale_ticks(custom_meter, scale, 11, 2, 10, lv_palette_main(LV_PALETTE_GREY));
    lv_meter_set_scale_ticks(custom_meter, scale, 0, 0, 0, lv_color_black()); /*to remove spedometer ticks*/
    // lv_meter_set_scale_major_ticks(custom_meter, scale, 1, 2, 30, lv_color_hex3(0xeee), 10);
    // lv_meter_set_scale_range(custom_meter, scale, 60, 100, 270, 90);

    lv_meter_set_scale_range(custom_meter, scale, 0, 100, 240, 150);

    /*Add a three arc indicator*/

    lv_meter_indicator_t *back = lv_meter_add_arc(custom_meter, scale, 22, lv_color_hex(COLOR_SECONDARY_HEX), -5);
    lv_meter_indicator_t *indic2 = lv_meter_add_arc(custom_meter, scale, 16, lv_color_hex(COLOR_TERTIARY_HEX), -8);
    lv_meter_indicator_t *indic1 = lv_meter_add_arc(custom_meter, scale, 18, lv_color_hex(COLOR_BLUE_STATUS_HEX), -7);

    lv_meter_set_indicator_start_value(custom_meter, back, 0);
    lv_meter_set_indicator_end_value(custom_meter, back, 100);

    lv_meter_set_indicator_start_value(custom_meter, indic2, 1);
    lv_meter_set_indicator_end_value(custom_meter, indic2, 80); /*range values 0-100*/

    lv_meter_set_indicator_start_value(custom_meter, indic1, 0);
    lv_meter_set_indicator_end_value(custom_meter, indic1, 40); /*range values 0-100*/

    // lv_meter_indicator_t * indic3 = lv_meter_add_arc(custom_meter, scale, 10, lv_palette_main(LV_PALETTE_BLUE), 0);

    // lv_coord_t indic_w = 0;

    // return custom_meter;
}

#endif // TAB_RACING_H