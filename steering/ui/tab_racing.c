#include "tab_racing.h"

void tab_racing(lv_obj_t * parent){

    init_custom_styles();

    static lv_coord_t main_panel_cols[] =  {SIDE_BAR_WIDTH, CENTRAL_PANEL_WIDTH, SIDE_BAR_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t main_panel_rows[] = {SCREEN_HEIGHT, LV_GRID_TEMPLATE_LAST};

    lv_obj_t * tab_racing = lv_obj_create(parent);
    lv_obj_set_layout(tab_racing, LV_LAYOUT_GRID);
    lv_obj_set_size(tab_racing, SCREEN_WIDTH, SCREEN_HEIGHT);
    lv_obj_add_style(tab_racing, &grid_style, 0);
    lv_obj_clear_flag(tab_racing, LV_OBJ_FLAG_SCROLLABLE);
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
    lv_obj_t *lv_perc = lv_horizontal_pair_label(bar_panel_lv, "80", &lv_font_inter_bold_38, "%", &lv_font_inter_bold_18);
    lv_obj_align(lv_obj_get_child(lv_obj_get_child(lv_perc, 1), NULL) , LV_ALIGN_CENTER, 0, 5);  // change "%" position
    lv_obj_set_grid_cell(lv_perc, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 0, 1);

    // lv state of charge bar
    lv_obj_t *lv_bar = lv_bar_create(bar_panel_lv);
    custom_side_bar(lv_bar);

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

    lv_obj_t *custom_meter = lv_meter_create(data_panel);
    lv_custom_meter(custom_meter);
    lv_obj_set_grid_cell(custom_meter, LV_GRID_ALIGN_CENTER, 1, 1, LV_GRID_ALIGN_CENTER, 0, 1);
    //lv_obj_align(custom_meter, LV_ALIGN_CENTER, 0, 0);

    // lap counter
    lv_obj_t *lap_counter = lv_vertical_pair_label(data_panel, "12", &lv_font_inter_bold_38, "LAP", &lv_font_inter_bold_22);
    lv_obj_set_grid_cell(lap_counter, LV_GRID_ALIGN_CENTER, 1, 1, LV_GRID_ALIGN_END, 0, 1);
    lv_obj_set_style_pad_bottom(lap_counter, 5, 0);

    lv_obj_t *km_counter = lv_vertical_pair_label(data_panel, "12", &lv_font_inter_bold_38, "KM", &lv_font_inter_bold_22);
    lv_obj_set_grid_cell(km_counter, LV_GRID_ALIGN_CENTER, 1, 1, LV_GRID_ALIGN_END, 0, 1);
    lv_obj_set_style_pad_bottom(km_counter, 5, 0);


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
    lv_obj_t *hv_perc = lv_horizontal_pair_label(bar_panel_hv, "50", &lv_font_inter_bold_38, "%", &lv_font_inter_bold_18);
    lv_obj_align(lv_obj_get_child(lv_obj_get_child(hv_perc, 1), NULL) , LV_ALIGN_CENTER, 0, 5);  // change "%" position
    lv_obj_set_grid_cell(hv_perc, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 0, 1);


    // hv state of charge bar
    lv_obj_t* hv_bar = lv_bar_create(bar_panel_hv);
    custom_side_bar(hv_bar);
    lv_bar_set_value(hv_bar, 50, LV_ANIM_OFF);
    lv_obj_set_style_bg_color(hv_bar, lv_color_hex(COLOR_ORANGE_STATUS_HEX), LV_PART_INDICATOR);

    lv_obj_set_grid_cell(hv_bar, LV_GRID_CONTENT, 0, 1, LV_GRID_ALIGN_END, 1, 1);

    // lv label
    lv_obj_t *label_hv = lv_label_create(bar_panel_hv);
    lv_obj_add_style(label_hv, &label_style, LV_PART_MAIN);
    lv_obj_set_style_text_font(label_hv, &lv_font_inter_bold_30, LV_STATE_DEFAULT);
    lv_label_set_text(label_hv, "HV");

    lv_obj_set_grid_cell(label_hv, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 2, 1);

    /*-------------------------------------*/


}