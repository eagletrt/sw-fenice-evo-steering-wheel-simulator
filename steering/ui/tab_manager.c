#include "tab_manager.h"

#define COLOR_PRIMARY_HEX 0x383838
#define COLOR_BLUE_STATUS_HEX 0x466189
#define COLOR_TERTIARY_HEX 0xF2F3F5
#define COLOR_SECONDARY_HEX 0X575757

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


/*********PROVA CON custom_meter*******************/
static lv_obj_t * custom_meter;

static void set_value(void * indic, int32_t v)
{
    lv_meter_set_indicator_end_value(custom_meter, indic, v);
}


/**
 * A custom_meter with multiple arcs
 */
void lv_custom_meter()
{
    /*Remove the circle from the middle*/
    lv_obj_remove_style(custom_meter, NULL, LV_PART_MAIN);
    lv_obj_remove_style(custom_meter, NULL, LV_PART_INDICATOR);

    //lv_obj_center(custom_meter);
    //lv_obj_set_grid_cell(custom_meter, LV_GRID_ALIGN_CENTER, 1, 1, LV_GRID_ALIGN_CENTER, 0, 1);

    //lv_obj_set_grid_cell(custom_meter, LV_)

    //lv_obj_set_grid_cell(custom_meter, LV_GRID_ALIGN_STRETCH, 2, 1, LV_GRID_ALIGN_STRETCH, 2, 1);
    lv_obj_set_size(custom_meter, 270, 290);

    /*Add a scale first*/
    lv_meter_scale_t * scale = lv_meter_add_scale(custom_meter);
    //lv_obj_align(custom_meter,  )
    //lv_meter_set_scale_ticks(custom_meter, scale, 11, 2, 10, lv_palette_main(LV_PALETTE_GREY));
    lv_meter_set_scale_ticks(custom_meter, scale, 0, 0, 0, lv_color_black()); /*to remove spedometer ticks*/
    //lv_meter_set_scale_major_ticks(custom_meter, scale, 1, 2, 30, lv_color_hex3(0xeee), 10);
    //lv_meter_set_scale_range(custom_meter, scale, 60, 100, 270, 90);

    
    lv_meter_set_scale_range(custom_meter, scale, 0, 100, 240, 150);

    /*Add a three arc indicator*/
    
    lv_meter_indicator_t * back = lv_meter_add_arc(custom_meter, scale, 22, lv_color_hex(COLOR_SECONDARY_HEX), -5);
    lv_meter_indicator_t * indic2 = lv_meter_add_arc(custom_meter, scale, 16, lv_color_hex(COLOR_TERTIARY_HEX), -8);
    lv_meter_indicator_t * indic1 = lv_meter_add_arc(custom_meter, scale, 18, lv_color_hex(COLOR_BLUE_STATUS_HEX), -7);
   
    
    lv_meter_set_indicator_start_value(custom_meter, back, 0);
    lv_meter_set_indicator_end_value(custom_meter, back, 100);

    lv_meter_set_indicator_start_value(custom_meter, indic2, 1);
    lv_meter_set_indicator_end_value(custom_meter, indic2, 80);/*range values 0-100*/

    lv_meter_set_indicator_start_value(custom_meter, indic1, 0);
    lv_meter_set_indicator_end_value(custom_meter, indic1, 40);/*range values 0-100*/

    //lv_meter_indicator_t * indic3 = lv_meter_add_arc(custom_meter, scale, 10, lv_palette_main(LV_PALETTE_BLUE), 0);

    //lv_coord_t indic_w = 0;

    

    /*
    lv_meter_set_indicator_start_value(custom_meter, indic2, 200);
    lv_meter_set_indicator_end_value(custom_meter, indic2, 240);*/


    /*Create an animation to set the value*/

    /*
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_exec_cb(&a, set_value);
    lv_anim_set_values(&a, 60, 100);
    lv_anim_set_repeat_delay(&a, 100);
    lv_anim_set_playback_delay(&a, 100);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);

    lv_anim_set_time(&a, 2000);
    lv_anim_set_playback_time(&a, 500);
    lv_anim_set_var(&a, indic1);
    lv_anim_start(&a);

    lv_anim_set_time(&a, 1000);
    lv_anim_set_playback_time(&a, 1000);
    lv_anim_set_var(&a, indic2);
    lv_anim_start(&a);

    lv_anim_set_time(&a, 1000);
    lv_anim_set_playback_time(&a, 2000);
    lv_anim_set_var(&a, indic3);
    lv_anim_start(&a);*/

}

/****************************/


void tab_manager() {

    /*setting main display background color*/
    lv_disp_set_bg_color(lv_disp_get_default(), lv_color_hex(COLOR_PRIMARY_HEX));

    /*setting grid style*/
    static lv_style_t grid_style;
    lv_style_init(&grid_style);
    lv_style_set_pad_all(&grid_style, 0);
    lv_style_set_pad_bottom(&grid_style, 0);
    lv_style_set_pad_column(&grid_style, 0);
    lv_style_set_pad_top(&grid_style, 0);
    lv_style_set_pad_row(&grid_style, 0);
    lv_style_set_bg_color(&grid_style, lv_color_hex(COLOR_PRIMARY_HEX));
    lv_style_set_border_color(&grid_style, lv_color_hex(COLOR_PRIMARY_HEX));

    /*spacing of the main panel (tab racing) grid 1x3 */
    static lv_coord_t main_panel_cols[] =  {SIDE_BAR_WIDTH, CENTRAL_PANEL_WIDTH, SIDE_BAR_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t main_panel_rows[] = {SCREEN_HEIGHT, LV_GRID_TEMPLATE_LAST};

    /*creation of tab racing GRID*/
    lv_obj_t * tab_racing = lv_obj_create(lv_scr_act());
    lv_obj_set_layout(tab_racing, LV_LAYOUT_GRID);
    lv_obj_clear_flag(tab_racing, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(tab_racing, SCREEN_WIDTH, SCREEN_HEIGHT);

    lv_obj_add_style(tab_racing, &grid_style, 0);
    lv_obj_center(tab_racing);
    lv_obj_set_style_base_dir(tab_racing, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(tab_racing, main_panel_cols, main_panel_rows);




    static lv_style_t bar_style;
    lv_style_init(&bar_style);
    lv_style_set_bg_opa(&bar_style, LV_OPA_COVER);
    lv_style_set_bg_color(&bar_style, lv_color_hex(COLOR_BLUE_STATUS_HEX));

    static lv_style_t bar_style_back;
    lv_style_init(&bar_style_back);
    lv_style_set_bg_opa(&bar_style_back, LV_OPA_COVER);
    lv_style_set_bg_color(&bar_style_back, lv_color_hex(COLOR_SECONDARY_HEX));

    //lv_style_set_bg_grad_color(&bar_style, lv_palette_main(LV_PALETTE_BLUE));
    //lv_style_set_bg_grad_dir(&bar_style, LV_GRAD_DIR_VER);


    // LEFT BAR
    lv_obj_t* hv_bar = lv_bar_create(tab_racing);
    lv_obj_remove_style_all(hv_bar);
    lv_obj_add_style(hv_bar, &bar_style, LV_PART_INDICATOR);
    lv_obj_add_style(hv_bar, &bar_style_back, LV_PART_MAIN);

    //lv_style_set_bg_color
    lv_obj_set_size(hv_bar, 70, 400);
    lv_obj_center(hv_bar);
    lv_bar_set_range(hv_bar, 0, 100);
    lv_bar_set_value(hv_bar, 70, LV_ANIM_OFF);
    lv_obj_set_grid_cell(hv_bar, LV_GRID_ALIGN_START, 0, 1, LV_GRID_ALIGN_CENTER, 0, 1);

    // CENTRAL PANEL

    static lv_coord_t cpanel_cols[] =  {CENTRAL_PANEL_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t cpanel_rows[] = {TOP_BAR_HEIGHT, DATA_PANEL_HEIGHT, BOTTOM_BAR_HEIGHT, LV_GRID_TEMPLATE_LAST};


    lv_obj_t * central_panel = lv_obj_create(tab_racing);
    lv_obj_set_layout(central_panel, LV_LAYOUT_GRID);
    lv_obj_clear_flag(central_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(central_panel, CENTRAL_PANEL_WIDTH, SCREEN_HEIGHT);

    lv_obj_add_style(central_panel, &grid_style, 0);
    lv_obj_center(central_panel);
    lv_obj_set_style_base_dir(central_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(central_panel, cpanel_cols, cpanel_rows);

    // CHANGE-TABS VIEW (I don't remember the right name)
    lv_obj_t * o1 = lv_obj_create(central_panel);
    lv_obj_t * l1 = lv_label_create(o1);
    lv_label_set_text(l1, "change-tabs view");
    lv_obj_set_grid_cell(o1, LV_GRID_ALIGN_STRETCH, 0, 1,
                         LV_GRID_ALIGN_STRETCH, 0, 1);


    // DATA PANEL
    static lv_coord_t dpanel_cols[] =  {DATA_LEFT_WIDTH, DATA_CENTER_WIDTH, DATA_RIGHT_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t dpanel_rows[] = {DATA_PANEL_HEIGHT, LV_GRID_TEMPLATE_LAST};

    lv_obj_t * data_panel = lv_obj_create(central_panel);
    lv_obj_set_layout(data_panel, LV_LAYOUT_GRID);
    lv_obj_clear_flag(data_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(data_panel, CENTRAL_PANEL_WIDTH, DATA_PANEL_HEIGHT);

    lv_obj_add_style(data_panel, &grid_style, 0);
    lv_obj_center(data_panel);
    lv_obj_set_style_base_dir(data_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(data_panel, dpanel_cols, dpanel_rows);

    static lv_coord_t speedometer_cols[] =  {LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    static lv_coord_t speedometer_rows[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    lv_obj_t * speedometer_panel = lv_obj_create(data_panel);
    lv_obj_set_layout(speedometer_panel, LV_LAYOUT_GRID);
    lv_obj_clear_flag(speedometer_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_border_opa(speedometer_panel, 0, 0 );
    lv_obj_add_style(speedometer_panel, &grid_style, 0);
    lv_obj_center(speedometer_panel);
    lv_obj_set_style_base_dir(speedometer_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(speedometer_panel, speedometer_cols, speedometer_rows);


    // DATA LEFT

    /*
    lv_obj_t * o4 = lv_obj_create(data_panel);
    lv_obj_t * l4 = lv_label_create(o4);
    lv_label_set_text(l4, "data left");
    lv_obj_set_grid_cell(o4, LV_GRID_ALIGN_STRETCH, 0, 1,
                         LV_GRID_ALIGN_STRETCH, 0, 1);*/

    

    //DATA CENTER

    /*
    lv_obj_t * speedometer_panel = lv_obj_create(data_panel);
    lv_obj_set_layout(speedometer_panel, LV_LAYOUT_GRID);

    
    lv_obj_t * o5 = lv_obj_create(data_panel);
    lv_obj_t * l5 = lv_label_create(o5);
    lv_label_set_text(l5, "data center");
    lv_obj_set_grid_cell(o5, LV_GRID_ALIGN_STRETCH, 1, 1,LV_GRID_ALIGN_STRETCH, 0, 1); */

    /* COMINCIA CODICE BACATO */

    lv_style_t text_style;
    lv_style_init(&text_style);

    lv_style_set_text_font(&text_style, &lv_font_montserrat_22);

    // top
    lv_obj_t * power = lv_label_create(data_panel);
    lv_label_set_text(power, "POWER 60%");
    lv_obj_set_style_text_color(power, lv_color_hex(COLOR_TERTIARY_HEX), NULL);
    lv_obj_set_grid_cell(power, LV_GRID_ALIGN_CENTER, 1, 1, LV_GRID_ALIGN_START, 0, 1);
    lv_obj_set_style_text_font(power, &lv_font_inter_bold_22, LV_STATE_DEFAULT);
    lv_obj_set_style_base_dir(power, LV_BASE_DIR_LTR, 0);

    // center
    lv_obj_set_grid_cell(speedometer_panel, LV_GRID_ALIGN_CENTER, 1, 1, LV_GRID_ALIGN_CENTER, 0, 1);

    lv_obj_t *speed = lv_label_create(speedometer_panel);
    lv_label_set_text_fmt(speed, "169");
    //lv_obj_align(speed, LV_ALIGN_DEFAULT, 0, 0);
    lv_obj_set_grid_cell(speed, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_START, 0, 1);
    lv_obj_set_style_text_color(speed, lv_color_hex(COLOR_TERTIARY_HEX), NULL);
    lv_obj_set_style_text_font(speed, &lv_font_inter_bold_70, LV_STATE_DEFAULT);
    lv_obj_set_style_base_dir(speed, LV_BASE_DIR_LTR, 0);
    lv_obj_t *speed_unit = lv_label_create(speedometer_panel);
    lv_label_set_text_fmt(speed_unit, "km/h");
    lv_obj_set_style_text_color(speed_unit, lv_color_hex(COLOR_TERTIARY_HEX), NULL);
    lv_obj_set_grid_cell(speed_unit, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_START, 1, 1);
    lv_obj_set_style_text_font(speed_unit, &lv_font_inter_bold_30, LV_STATE_DEFAULT);
    lv_obj_set_style_base_dir(speed_unit, LV_BASE_DIR_LTR, 0);

    /*    
    lv_obj_t * arc_1 = lv_arc_create(data_panel);
    lv_obj_remove_style(arc_1, NULL, LV_PART_KNOB);
    lv_obj_clear_flag(arc_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_arc_color(arc_1, lv_color_hex(COLOR_TERTIARY_HEX), LV_PART_INDICATOR);
    lv_obj_set_style_arc_color(arc_1, lv_color_hex(COLOR_SECONDARY_HEX), LV_PART_MAIN);
    
    lv_arc_set_end_angle(arc_1, 300);
    lv_obj_set_size(arc_1, 250, 250);
    
    
    lv_obj_set_style_arc_width(arc_1, 15, LV_PART_MAIN);
    lv_obj_set_style_arc_width(arc_1, 15, LV_PART_INDICATOR);
    lv_obj_set_grid_cell(arc_1, LV_GRID_ALIGN_CENTER, 1, 1, LV_GRID_ALIGN_CENTER, 0, 1);*/

    
    custom_meter = lv_meter_create(lv_scr_act());
    lv_custom_meter();
    //lv_obj_set_grid_cell(custom_meter, LV_GRID_ALIGN_CENTER, 0, 0, LV_GRID_ALIGN_CENTER, 0, 0);
    lv_obj_align(custom_meter, LV_ALIGN_CENTER, 0, 10);


    //lv_style_t a2;
    //lv_style_init(&a2);

    /*
    lv_obj_t * arc_2 = lv_arc_create(data_panel);
    //lv_style_set_arc_rounded(0, 0);
    lv_obj_set_style_arc_color(arc_2, lv_color_hex(COLOR_BLUE_STATUS_HEX), LV_PART_INDICATOR);
    lv_obj_remove_style(arc_2, NULL, LV_PART_MAIN);
    lv_obj_remove_style(arc_2, NULL, LV_PART_KNOB);
    lv_obj_clear_flag(arc_2, LV_OBJ_FLAG_CLICKABLE);
    lv_arc_set_end_angle(arc_2, 240);
    lv_obj_set_size(arc_2, 250, 250);
    lv_obj_set_style_arc_width(arc_2, 15, LV_PART_INDICATOR);
    lv_obj_set_grid_cell(arc_2, LV_GRID_ALIGN_CENTER, 1, 1, LV_GRID_ALIGN_CENTER, 0, 1);*/

    // bottom 
    lv_obj_t *lap_counter = lv_label_create(data_panel);
    lv_label_set_text(lap_counter, "  12\nLAP");
    lv_obj_set_style_text_color(lap_counter, lv_color_hex(COLOR_TERTIARY_HEX), NULL);
    lv_obj_set_grid_cell(lap_counter, LV_GRID_ALIGN_CENTER, 1, 1, LV_GRID_ALIGN_END, 0, 1);
    lv_obj_set_style_text_font(lap_counter, &lv_font_inter_bold_22, LV_STATE_DEFAULT);
    lv_obj_set_style_base_dir(lap_counter, LV_BASE_DIR_LTR, 0);
    lv_obj_set_style_pad_bottom(lap_counter, 10, NULL);


    /* FINE CODICE BACATO */


    // DATA RIGHT

    /*
    lv_obj_t * o6 = lv_obj_create(data_panel);
    lv_obj_t * l6 = lv_label_create(o6);
    lv_label_set_text(l6, "data right");
    lv_obj_set_grid_cell(o6, LV_GRID_ALIGN_STRETCH, 2, 1,
                         LV_GRID_ALIGN_STRETCH, 0, 1);*/


    // setting data panel position in central panel
    lv_obj_set_grid_cell(data_panel, LV_GRID_ALIGN_STRETCH, 0, 1,
                         LV_GRID_ALIGN_STRETCH, 1, 1);

    
    // BOTTOM BAR
    /*
    lv_obj_t * o3 = lv_obj_create(central_panel);
    lv_obj_t * l3 = lv_label_create(o3);
    lv_label_set_text(l3, "bottom bar");
    lv_obj_set_grid_cell(o3, LV_GRID_ALIGN_STRETCH, 0, 1,
                         LV_GRID_ALIGN_STRETCH, 2, 1);*/

    // setting central panel position in tab racing
    lv_obj_set_grid_cell(central_panel, LV_GRID_ALIGN_STRETCH, 1, 1,
                         LV_GRID_ALIGN_STRETCH, 0, 1);


    // RIGHT BAR
    
    lv_obj_t* lv_bar = lv_bar_create(tab_racing);
    lv_obj_remove_style_all(lv_bar);
    lv_obj_add_style(lv_bar, &bar_style, LV_PART_INDICATOR);
    lv_obj_add_style(lv_bar, &bar_style_back, LV_PART_MAIN);
    lv_obj_set_size(lv_bar, 70 , 400);
    lv_obj_center(lv_bar);
    lv_bar_set_range(lv_bar, 0, 100);
    lv_bar_set_value(lv_bar, 70, LV_ANIM_OFF);
    lv_obj_set_grid_cell(lv_bar, LV_GRID_ALIGN_END, 2, 1, LV_GRID_ALIGN_CENTER, 0, 1);

}