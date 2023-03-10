#ifndef TAB_RACING_H
#define TAB_RACING_H

#include "lvgl.h"
#include "utils.h"

void tab_racing(lv_obj_t *parent);

static lv_style_t grid_style;
static lv_style_t bar_hv_style;
static lv_style_t bar_lv_style;
static lv_style_t bar_back_style;
static lv_style_t label_style;
static lv_style_t side_panels_style;

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
    //lv_style_set_border_opa(&grid_style, LV_OPA_COVER);
    lv_style_set_border_opa(&grid_style, 0); //to remove borders, keeping bc useful

    /* BAR_HV_STYLE */
    lv_style_init(&bar_hv_style);
    lv_style_set_bg_opa(&bar_hv_style, LV_OPA_COVER);
    lv_style_set_bg_color(&bar_hv_style, lv_color_hex(COLOR_ORANGE_STATUS_HEX));

    /* BAR_LV_STYLE */
    lv_style_init(&bar_lv_style);
    lv_style_set_bg_opa(&bar_lv_style, LV_OPA_COVER);
    lv_style_set_bg_color(&bar_lv_style, lv_color_hex(COLOR_GREEN_STATUS_HEX));

    /* BAR_BACKGROUND_STYLE */
    lv_style_init(&bar_back_style);
    lv_style_set_bg_opa(&bar_back_style, LV_OPA_COVER);
    lv_style_set_bg_color(&bar_back_style, lv_color_hex(COLOR_SECONDARY_HEX));


    /* LABEL_STYLE */
    lv_style_init(&label_style);
    lv_style_set_base_dir(&label_style, LV_BASE_DIR_LTR);
    lv_style_set_bg_opa(&label_style, LV_OPA_TRANSP);
    lv_style_set_text_color(&label_style, lv_color_hex(COLOR_TERTIARY_HEX));
    lv_style_set_text_align(&label_style, LV_TEXT_ALIGN_CENTER);

    /* SIDE_PANELS_STYLE */
    lv_style_init(&side_panels_style);
    lv_style_set_pad_all(&side_panels_style, 0);
    lv_style_set_pad_bottom(&side_panels_style, 0);
    lv_style_set_pad_column(&side_panels_style, 0);
    lv_style_set_pad_top(&side_panels_style, 0);
    lv_style_set_pad_row(&side_panels_style, 0);
    lv_style_set_bg_opa(&side_panels_style, LV_OPA_TRANSP);
    lv_style_set_border_color(&side_panels_style, lv_color_hex(COLOR_TERTIARY_HEX)); //to remove borders, keeping bc useful

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

static void custom_side_bar(lv_obj_t *bar){
    lv_obj_remove_style_all(bar);
    lv_obj_add_style(bar, &bar_lv_style, LV_PART_INDICATOR);
    lv_obj_add_style(bar, &bar_back_style, LV_PART_MAIN);
    lv_obj_set_size(bar, 65, 360);
    lv_obj_center(bar);
    lv_bar_set_range(bar, 0, 100);
    lv_bar_set_value(bar, 80, LV_ANIM_OFF);

    /* adding levels for side bars LV_BAR */
    lv_obj_t* rect1 = lv_bar_create(bar);
    lv_obj_add_style(rect1, &grid_style, LV_PART_MAIN);
    lv_obj_set_size(rect1, 100, 5);
    lv_obj_align(rect1, LV_ALIGN_CENTER, 0, 36);

    lv_obj_t* rect2 = lv_bar_create(bar);
    lv_obj_add_style(rect2, &grid_style, LV_PART_MAIN);
    lv_obj_set_size(rect2, 100, 5);
    lv_obj_align(rect2, LV_ALIGN_CENTER, 0, -36);


    lv_obj_t* rect3 = lv_bar_create(bar);
    lv_obj_add_style(rect3, &grid_style, LV_PART_MAIN);
    lv_obj_set_size(rect3, 100, 5);
    lv_obj_align(rect3, LV_ALIGN_CENTER, 0, 108);

    lv_obj_t* rect4 = lv_bar_create(bar);
    lv_obj_add_style(rect4, &grid_style, LV_PART_MAIN);
    lv_obj_set_size(rect4, 100, 5);
    lv_obj_align(rect4, LV_ALIGN_CENTER, 0, -108);
}

#endif // TAB_RACING_H