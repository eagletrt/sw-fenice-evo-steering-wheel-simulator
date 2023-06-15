#include "tab_debug.h"
#include <stdio.h>

#define CELL_HEIGHT 40
#define CELL_WIDTH  180

#define CENTRAL_PANEL_WIDTH 780
#define DATA_PANEL_HEIGHT 430

lv_style_t box_debug_style_yellow;
lv_style_t box_debug_style_green;
lv_style_t box_debug_style_red;
lv_style_t box_label_style;

lv_obj_t* cell_create(lv_obj_t* parent, const char* text, uint8_t pos_col, uint8_t pos_row, lv_style_t* style ){
    lv_obj_t * cell= lv_obj_create(parent);
    lv_obj_set_layout(cell, LV_LAYOUT_GRID);
    lv_obj_remove_style_all(cell);
    lv_obj_clear_flag(cell, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(cell, CELL_WIDTH, CELL_HEIGHT);

    lv_obj_add_style(cell, style, 0);
    lv_obj_center(cell);
    lv_obj_set_style_base_dir(cell, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_cell(cell, LV_GRID_ALIGN_CENTER, pos_col, 1, LV_GRID_ALIGN_CENTER, pos_row, 1);

    lv_obj_t *label= lv_label_create(cell);
    lv_obj_add_style(label, &box_label_style, LV_PART_MAIN);
    lv_label_set_text(label, text);
    lv_obj_set_style_text_font(label, &lv_font_inter_bold_14, LV_STATE_DEFAULT);
}

void init_debug_styles(void){

    /*setting box_debug_style*/
    lv_style_init(&box_debug_style_yellow);
    lv_style_set_pad_all(&box_debug_style_yellow, 0);
    lv_style_set_pad_bottom(&box_debug_style_yellow, 0);
    lv_style_set_pad_column(&box_debug_style_yellow, 0);
    lv_style_set_pad_top(&box_debug_style_yellow, 0);
    lv_style_set_pad_row(&box_debug_style_yellow, 0);
    lv_style_set_bg_opa(&box_debug_style_yellow, LV_OPA_COVER);
    lv_style_set_border_color(&box_debug_style_yellow, lv_color_hex(COLOR_YELLOW_STATUS_HEX)); 
    lv_style_set_border_width(&box_debug_style_yellow, 3);
    lv_style_set_bg_color(&box_debug_style_yellow, lv_color_hex(COLOR_YELLOW_STATUS_HEX));
    lv_style_set_radius(&box_debug_style_yellow, 10);


    /*setting box_debug_style_green*/
    lv_style_init(&box_debug_style_green);
    lv_style_set_pad_all(&box_debug_style_green, 0);
    lv_style_set_pad_bottom(&box_debug_style_green, 0);
    lv_style_set_pad_column(&box_debug_style_green, 0);
    lv_style_set_pad_top(&box_debug_style_green, 0);
    lv_style_set_pad_row(&box_debug_style_green, 0);
    lv_style_set_bg_opa(&box_debug_style_green, LV_OPA_COVER);
    lv_style_set_border_color(&box_debug_style_green, lv_color_hex(COLOR_GREEN_STATUS_HEX)); 
    lv_style_set_border_width(&box_debug_style_green, 3);
    lv_style_set_bg_color(&box_debug_style_green, lv_color_hex(COLOR_GREEN_STATUS_HEX));
    lv_style_set_radius(&box_debug_style_green, 10);

    /*setting box_debug_style_red*/
    lv_style_init(&box_debug_style_red);
    lv_style_set_pad_all(&box_debug_style_red, 0);
    lv_style_set_pad_bottom(&box_debug_style_red, 0);
    lv_style_set_pad_column(&box_debug_style_red, 0);
    lv_style_set_pad_top(&box_debug_style_red, 0);
    lv_style_set_pad_row(&box_debug_style_red, 0);
    lv_style_set_bg_opa(&box_debug_style_red, LV_OPA_COVER);
    lv_style_set_border_color(&box_debug_style_red, lv_color_hex(COLOR_RED_STATUS_HEX)); 
    lv_style_set_border_width(&box_debug_style_red, 3);
    lv_style_set_bg_color(&box_debug_style_red, lv_color_hex(COLOR_RED_STATUS_HEX));
    lv_style_set_radius(&box_debug_style_red, 10);

    /*setting label style*/
    lv_style_set_text_color(&box_label_style, lv_color_hex(COLOR_PRIMARY_HEX));
}



void tab_debug(lv_obj_t * parent){
    init_debug_styles();

    /*---creating MAIN GRID ---*/

    static lv_coord_t main_panel_cols[] =  {SCREEN_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t main_panel_rows[] = {TOP_BAR_HEIGHT, DATA_PANEL_HEIGHT, LV_GRID_TEMPLATE_LAST};

    lv_obj_t * main_panel = lv_obj_create(parent);
    lv_obj_add_style(main_panel, &grid_style, 0);
    lv_obj_set_layout(main_panel, LV_LAYOUT_GRID);
    lv_obj_clear_flag(main_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(main_panel, SCREEN_WIDTH, SCREEN_HEIGHT);

    lv_obj_center(main_panel);
    lv_obj_set_style_base_dir(main_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(main_panel, main_panel_cols, main_panel_rows);

    /*--- inserting TOP NOTCH ---*/

    lv_obj_t *notch = create_notch(main_panel, TAB_DEBUG);
    lv_obj_align(lv_obj_get_child(notch, 0), LV_ALIGN_TOP_MID, 0, 10);
    lv_obj_set_grid_cell(notch, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_START, 0, 1);

    
    /*--- creating DATA PANEL ---*/

    static lv_coord_t hvErrors_panel_cols[] =  {CELL_WIDTH, CELL_WIDTH, CELL_WIDTH, CELL_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t hvErrors_panel_rows[] = {CELL_HEIGHT, CELL_HEIGHT, CELL_HEIGHT, CELL_HEIGHT, CELL_HEIGHT, LV_GRID_TEMPLATE_LAST};

    lv_obj_t * hv_errors_panel = lv_obj_create(main_panel);
    lv_obj_remove_style_all(hv_errors_panel);
    lv_obj_set_layout(hv_errors_panel, LV_LAYOUT_GRID);
    lv_obj_clear_flag(hv_errors_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(hv_errors_panel, CENTRAL_PANEL_WIDTH, CELL_HEIGHT*7); 

    lv_obj_add_style(hv_errors_panel, &grid_style, 0);
    lv_obj_align(hv_errors_panel, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_base_dir(hv_errors_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(hv_errors_panel, hvErrors_panel_cols, hvErrors_panel_rows);

    lv_obj_set_style_pad_row(hv_errors_panel, ROW_PADDING, 0);
    lv_obj_set_style_pad_column(hv_errors_panel, COLUMN_PADDING, 0);
    
    lv_obj_set_grid_cell(hv_errors_panel, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 1, 1);


    lv_obj_t * cell_0_0 = cell_create(hv_errors_panel, "TSAL GREEN FAULT", 0, 0, &box_debug_style_yellow);
    lv_obj_t * cell_1_0 = cell_create(hv_errors_panel, "TSAL GREEN", 1, 0, &box_debug_style_yellow);
    lv_obj_t * cell_2_0 = cell_create(hv_errors_panel, "AIRN GATE", 2, 0, &box_debug_style_yellow);
    lv_obj_t * cell_3_0 = cell_create(hv_errors_panel, "SD OUT", 3, 0, &box_debug_style_yellow);

    lv_obj_t * cell_0_1 = cell_create(hv_errors_panel, "IMD LATCHED", 0, 1, &box_debug_style_yellow);
    lv_obj_t * cell_1_1 = cell_create(hv_errors_panel, "TS OVER 60V STATUS", 1, 1, &box_debug_style_yellow);
    lv_obj_t * cell_2_1 = cell_create(hv_errors_panel, "PRECHARGE STATUS", 2, 1, &box_debug_style_yellow);
    lv_obj_t * cell_3_1 = cell_create(hv_errors_panel, "RELAY SD", 3, 1, &box_debug_style_yellow);

    lv_obj_t * cell_0_2 = cell_create(hv_errors_panel, "TSAL GREEN F LATCHED", 0, 2, &box_debug_style_yellow);
    lv_obj_t * cell_1_2 = cell_create(hv_errors_panel, "AIRN STATUS", 1, 2, &box_debug_style_yellow);
    lv_obj_t * cell_2_2 = cell_create(hv_errors_panel, "TSP OVER 60V STATUS", 2, 2, &box_debug_style_yellow);
    lv_obj_t * cell_3_2 = cell_create(hv_errors_panel, "IMD FAULT", 3, 2, &box_debug_style_yellow);

    lv_obj_t * cell_0_3 = cell_create(hv_errors_panel, "BMS LATCHED", 0, 3, &box_debug_style_yellow);
    lv_obj_t * cell_1_3 = cell_create(hv_errors_panel, "AIRP STATUS", 1, 3, &box_debug_style_yellow);
    lv_obj_t * cell_2_3 = cell_create(hv_errors_panel, "CHECK MUX", 2, 3, &box_debug_style_yellow);
    lv_obj_t * cell_3_3 = cell_create(hv_errors_panel, "SD END", 3, 3, &box_debug_style_yellow);

    lv_obj_t * cell_0_4 = cell_create(hv_errors_panel, "EXT LATCHED", 0, 4, &box_debug_style_yellow);
    lv_obj_t * cell_1_4 = cell_create(hv_errors_panel, "AIRP GATE", 1, 4, &box_debug_style_yellow);
    lv_obj_t * cell_2_4 = cell_create(hv_errors_panel, "SD IN", 2, 4, &box_debug_style_yellow);



}