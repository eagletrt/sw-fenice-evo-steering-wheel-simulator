#include "tab_racing.h"

void tab_racing(lv_obj_t * parent){

    init_custom_styles();

    static lv_coord_t main_panel_cols[] =  {SIDE_BAR_WIDTH, CENTRAL_PANEL_WIDTH, SIDE_BAR_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t main_panel_rows[] = {SCREEN_HEIGHT, LV_GRID_TEMPLATE_LAST};

    lv_obj_t * tab_racing = lv_obj_create(parent);
    lv_obj_set_layout(tab_racing, LV_LAYOUT_GRID);
    lv_obj_set_size(tab_racing, SCREEN_WIDTH, SCREEN_HEIGHT);
    lv_obj_add_style(tab_racing, &grid_style, 0);
    lv_obj_center(tab_racing);
    
    lv_obj_set_grid_dsc_array(tab_racing, main_panel_cols, main_panel_rows);

    // LEFT BAR

    //  bar grid setup
    static lv_coord_t bar_panel_cols[] =  {SIDE_BAR_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t bar_panel_rows[] = { 70, 360, 50, LV_GRID_TEMPLATE_LAST};

    lv_obj_t * bar_panel_lv = lv_obj_create(tab_racing);
    lv_obj_remove_style_all(bar_panel_lv);
    lv_obj_add_style(bar_panel_lv, &grid_style, 0);
    lv_obj_set_size(bar_panel_lv, SIDE_BAR_WIDTH, SCREEN_HEIGHT);
    lv_obj_clear_flag(bar_panel_lv, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_grid_dsc_array(bar_panel_lv, bar_panel_cols, bar_panel_rows);

    lv_obj_set_grid_cell(bar_panel_lv, LV_GRID_CONTENT, 0, 1, LV_GRID_CONTENT, 0, 1);
    
    // lv percentage
    lv_obj_t *lv_perc = lv_label_create(bar_panel_lv);
    lv_obj_add_style(lv_perc, &label_style, LV_PART_MAIN);
    lv_obj_set_style_text_font(lv_perc, &lv_font_inter_bold_38, LV_STATE_DEFAULT);
    lv_label_set_text(lv_perc, "80");

    lv_obj_set_grid_cell(lv_perc, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 0, 1);

    // lv state of charge bar
    lv_obj_t* lv_bar = lv_bar_create(bar_panel_lv);
    lv_obj_remove_style_all(lv_bar);
    lv_obj_add_style(lv_bar, &bar_lv_style, LV_PART_INDICATOR);
    lv_obj_add_style(lv_bar, &bar_back_style, LV_PART_MAIN);
    lv_obj_set_size(lv_bar, 65, 360);
    lv_obj_center(lv_bar);
    lv_bar_set_range(lv_bar, 0, 100);
    lv_bar_set_value(lv_bar, 80, LV_ANIM_OFF);

    /* adding levels for side bars LV_BAR */
    lv_obj_t* rect6 = lv_bar_create(lv_bar);
    lv_obj_add_style(rect6, &grid_style, LV_PART_MAIN);
    lv_obj_set_size(rect6, 100, 5);
    lv_obj_align(rect6, LV_ALIGN_CENTER, 0, 36);

    lv_obj_t* rect7 = lv_bar_create(lv_bar);
    lv_obj_add_style(rect7, &grid_style, LV_PART_MAIN);
    lv_obj_set_size(rect7, 100, 5);
    lv_obj_align(rect7, LV_ALIGN_CENTER, 0, -36);


    lv_obj_t* rect8 = lv_bar_create(lv_bar);
    lv_obj_add_style(rect8, &grid_style, LV_PART_MAIN);
    lv_obj_set_size(rect8, 100, 5);
    lv_obj_align(rect8, LV_ALIGN_CENTER, 0, 108);

    lv_obj_t* rect9 = lv_bar_create(lv_bar);
    lv_obj_add_style(rect9, &grid_style, LV_PART_MAIN);
    lv_obj_set_size(rect9, 100, 5);
    lv_obj_align(rect9, LV_ALIGN_CENTER, 0, -108);

    lv_obj_set_grid_cell(lv_bar, LV_GRID_CONTENT, 0, 1, LV_GRID_ALIGN_END, 1, 1);

    // lv label
    lv_obj_t *label_lv = lv_label_create(bar_panel_lv);
    lv_obj_add_style(label_lv, &label_style, LV_PART_MAIN);
    lv_obj_set_style_text_font(label_lv, &lv_font_inter_bold_30, LV_STATE_DEFAULT);
    lv_label_set_text(label_lv, "LV");

    lv_obj_set_grid_cell(label_lv, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 2, 1);

    /*-----------------------*/


    // CENTRAL PANEL

    static lv_coord_t cpanel_cols[] =  {CENTRAL_PANEL_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t cpanel_rows[] = {TOP_BAR_HEIGHT, DATA_PANEL_HEIGHT, BOTTOM_BAR_HEIGHT, LV_GRID_TEMPLATE_LAST};


    lv_obj_t * central_panel = lv_obj_create(tab_racing);
    lv_obj_set_layout(central_panel, LV_LAYOUT_GRID);
    lv_obj_clear_flag(central_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(central_panel, CENTRAL_PANEL_WIDTH, SCREEN_HEIGHT);

    lv_obj_add_style(central_panel, &grid_style, 0);
    lv_obj_center(central_panel);
    lv_obj_set_style_base_dir(central_panel, LV_BASE_DIR_RTL, 0);
    lv_obj_set_grid_dsc_array(central_panel, cpanel_cols, cpanel_rows);

    // CHANGE-TABS VIEW (I don't remember the right name)
    lv_obj_t * l1 = lv_label_create(central_panel);
    lv_label_set_text(l1, "change-tabs view");
    lv_obj_set_grid_cell(l1, LV_GRID_ALIGN_STRETCH, 2, 1,
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
    lv_obj_set_style_base_dir(data_panel, LV_BASE_DIR_RTL, 0);
    lv_obj_set_grid_dsc_array(data_panel, dpanel_cols, dpanel_rows);


    // DATA RIGHT PANEL
    
    
    static lv_coord_t rxd_panel_cols[] =  {90, 90 , LV_GRID_TEMPLATE_LAST};
    static lv_coord_t rxd_panel_rows[] = {100, 100, 100, LV_GRID_TEMPLATE_LAST};

    lv_obj_t * right_data_panel = lv_obj_create(data_panel);
    lv_obj_set_layout(right_data_panel, LV_LAYOUT_GRID);
    lv_obj_clear_flag(right_data_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(right_data_panel, DATA_RIGHT_WIDTH, DATA_PANEL_HEIGHT-20);

    lv_obj_add_style(right_data_panel, &side_panels_style, 0);
    lv_obj_center(right_data_panel);
    lv_obj_set_style_base_dir(right_data_panel, LV_BASE_DIR_RTL, 0);
    lv_obj_set_grid_dsc_array(right_data_panel, rxd_panel_cols, rxd_panel_rows);
    
    
    lv_obj_set_grid_cell(right_data_panel, LV_GRID_ALIGN_CENTER, 0, 1,
                         LV_GRID_ALIGN_CENTER, 0, 1);

    
    // DATA CENTER

    // power
    lv_obj_t * power = lv_label_create(data_panel);
    lv_obj_add_style(power, &label_style, LV_PART_MAIN);
    lv_obj_set_style_text_font(power, &lv_font_inter_bold_22, LV_STATE_DEFAULT);
    lv_label_set_text(power, "POWER 60%");
    lv_obj_set_grid_cell(power, LV_GRID_ALIGN_CENTER, 1, 1, LV_GRID_ALIGN_START, 0, 1);

    // speedometer
    lv_obj_t *speed = lv_vertical_pair_label(data_panel, "169", &lv_font_inter_bold_70, "km/h", &lv_font_inter_bold_22);
    lv_obj_set_grid_cell(speed, LV_GRID_ALIGN_CENTER, 1, 1, LV_GRID_ALIGN_CENTER, 0, 1);

    lv_obj_t *custom_meter = lv_meter_create(lv_scr_act());
    lv_custom_meter(custom_meter);
    lv_obj_align(custom_meter, LV_ALIGN_CENTER, 0, 15);

    // lap counter
    lv_obj_t *lap_counter = lv_vertical_pair_label(data_panel, "12", &lv_font_inter_bold_38, "LAP", &lv_font_inter_bold_22);
    lv_obj_set_grid_cell(lap_counter, LV_GRID_ALIGN_CENTER, 1, 1, LV_GRID_ALIGN_END, 0, 1);
    lv_obj_set_style_pad_bottom(lap_counter, 5, 0);


    // DATA PANEL LEFT
    static lv_coord_t lxd_panel_cols[] =  {DATA_LEFT_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t lxd_panel_rows[] = {100, 100, 100, LV_GRID_TEMPLATE_LAST};

    lv_obj_t * left_data_panel = lv_obj_create(data_panel);
    lv_obj_set_layout(left_data_panel, LV_LAYOUT_GRID);
    lv_obj_clear_flag(left_data_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(left_data_panel, DATA_LEFT_WIDTH, DATA_PANEL_HEIGHT-20);

    lv_obj_add_style(left_data_panel, &side_panels_style, 0);
    lv_obj_center(left_data_panel);
    lv_obj_set_style_base_dir(left_data_panel, LV_BASE_DIR_RTL, 0);
    lv_obj_set_grid_dsc_array(left_data_panel, lxd_panel_cols, lxd_panel_rows);
    
    lv_obj_set_grid_cell(left_data_panel, LV_GRID_ALIGN_CENTER, 2, 1,
                         LV_GRID_ALIGN_CENTER, 0, 1);


    // setting data panel position in central panel
    lv_obj_set_grid_cell(data_panel, LV_GRID_ALIGN_STRETCH, 0, 1,
                         LV_GRID_ALIGN_STRETCH, 1, 1);

    // BOTTOM BAR
    lv_obj_t * bottom_bar = lv_label_create(central_panel);
    lv_label_set_text(bottom_bar, "bottom bar");
    lv_obj_set_grid_cell(bottom_bar, LV_GRID_ALIGN_STRETCH, 0, 1,
                         LV_GRID_ALIGN_STRETCH, 2, 1);

    // setting central panel position in tab racing
    lv_obj_set_grid_cell(central_panel, LV_GRID_ALIGN_STRETCH, 1, 1,
                         LV_GRID_ALIGN_STRETCH, 0, 1);


    //RIGHT BAR
    
    //  bar grid setup

    lv_obj_t * bar_panel_hv = lv_obj_create(tab_racing);
    lv_obj_remove_style_all(bar_panel_hv);
    lv_obj_add_style(bar_panel_hv, &grid_style, 0);
    lv_obj_set_size(bar_panel_hv, SIDE_BAR_WIDTH, SCREEN_HEIGHT);
    lv_obj_clear_flag(bar_panel_hv, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_grid_dsc_array(bar_panel_hv, bar_panel_cols, bar_panel_rows);  // same as LEFT BAR

    lv_obj_set_grid_cell(bar_panel_hv, LV_GRID_CONTENT, 2, 1, LV_GRID_CONTENT, 0, 1);
    
    // hv percentage
    lv_obj_t *hv_perc = lv_label_create(bar_panel_hv);
    lv_obj_add_style(hv_perc, &label_style, LV_PART_MAIN);
    lv_obj_set_style_text_font(hv_perc, &lv_font_inter_bold_38, LV_STATE_DEFAULT);
    lv_label_set_text(hv_perc, "50");

    lv_obj_set_grid_cell(hv_perc, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 0, 1);

    // hv state of charge bar
    lv_obj_t* hv_bar = lv_bar_create(bar_panel_hv);
    lv_obj_remove_style_all(hv_bar);
    lv_obj_add_style(hv_bar, &bar_hv_style, LV_PART_INDICATOR);
    lv_obj_add_style(hv_bar, &bar_back_style, LV_PART_MAIN);
    lv_obj_set_size(hv_bar, 65, 360);
    lv_obj_center(hv_bar);
    lv_bar_set_range(hv_bar, 0, 100);
    lv_bar_set_value(hv_bar, 50, LV_ANIM_OFF);

    /* adding levels for side bars LV_BAR */
    lv_obj_t* rect2 = lv_bar_create(hv_bar);
    lv_obj_add_style(rect2, &grid_style, LV_PART_MAIN);
    lv_obj_set_size(rect2, 100, 5);
    lv_obj_align(rect2, LV_ALIGN_CENTER, 0, 36);

    lv_obj_t* rect3 = lv_bar_create(hv_bar);
    lv_obj_add_style(rect3, &grid_style, LV_PART_MAIN);
    lv_obj_set_size(rect3, 100, 5);
    lv_obj_align(rect3, LV_ALIGN_CENTER, 0, -36);

    lv_obj_t* rect4 = lv_bar_create(hv_bar);
    lv_obj_add_style(rect4, &grid_style, LV_PART_MAIN);
    lv_obj_set_size(rect4, 100, 5);
    lv_obj_align(rect4, LV_ALIGN_CENTER, 0, 108);

    lv_obj_t* rect5 = lv_bar_create(hv_bar);
    lv_obj_add_style(rect5, &grid_style, LV_PART_MAIN);
    lv_obj_set_size(rect5, 100, 5);
    lv_obj_align(rect5, LV_ALIGN_CENTER, 0, -108);

    lv_obj_set_grid_cell(hv_bar, LV_GRID_CONTENT, 0, 1, LV_GRID_ALIGN_END, 1, 1);

    // lv label
    lv_obj_t *label_hv = lv_label_create(bar_panel_hv);
    lv_obj_add_style(label_hv, &label_style, LV_PART_MAIN);
    lv_obj_set_style_text_font(label_hv, &lv_font_inter_bold_30, LV_STATE_DEFAULT);
    lv_label_set_text(label_hv, "HV");

    lv_obj_set_grid_cell(label_hv, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 2, 1);

    /*-------------------------------------*/


}