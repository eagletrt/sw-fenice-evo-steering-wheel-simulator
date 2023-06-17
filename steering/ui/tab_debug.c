#include "tab_debug.h"
#include <stdio.h>

#define CELL_HEIGHT 40
#define CELL_WIDTH  180

#define CENTRAL_PANEL_WIDTH 780
#define DATA_PANEL_HEIGHT 425

lv_style_t box_debug_style_yellow;
lv_style_t box_debug_style_green;
lv_style_t box_debug_style_red;
lv_style_t box_label_style;

lv_obj_t *scr_debug;

lv_obj_t * hv_feedbacks_panel;
lv_obj_t * hv_errors_panel;
lv_obj_t * lv_errors_panel;
lv_obj_t * das_errors_panel;

lv_obj_t* cell_create(lv_obj_t* parent, const char* text, uint8_t pos_col, uint8_t pos_row, lv_style_t* style ){
    lv_obj_t * cell= lv_obj_create(parent);
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

    return cell;
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

    scr_debug = parent;

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

    
    /*--- creating HV FEEDBACKS PANEL ---*/


    static lv_coord_t hvFeedbacks_panel_cols[] =  {CELL_WIDTH, CELL_WIDTH, CELL_WIDTH, CELL_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t hvFeedbacks_panel_rows[] = {DATA_TITLE_HEIGHT, CELL_HEIGHT, CELL_HEIGHT, CELL_HEIGHT, CELL_HEIGHT, CELL_HEIGHT, LV_GRID_TEMPLATE_LAST};

    hv_feedbacks_panel = lv_obj_create(main_panel);
    lv_obj_remove_style_all(hv_feedbacks_panel);
    lv_obj_set_layout(hv_feedbacks_panel, LV_LAYOUT_GRID);
    lv_obj_clear_flag(hv_feedbacks_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(hv_feedbacks_panel, CENTRAL_PANEL_WIDTH, DATA_PANEL_HEIGHT); 

    lv_obj_add_style(hv_feedbacks_panel, &grid_style, 0);
    lv_obj_align(hv_feedbacks_panel, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_base_dir(hv_feedbacks_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_style_opa(hv_feedbacks_panel, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_grid_dsc_array(hv_feedbacks_panel, hvFeedbacks_panel_cols, hvFeedbacks_panel_rows);

    lv_obj_set_style_pad_row(hv_feedbacks_panel, ROW_PADDING, 0);
    lv_obj_set_style_pad_column(hv_feedbacks_panel, COLUMN_PADDING, 0);
    
    lv_obj_set_grid_cell(hv_feedbacks_panel, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 1, 1);

    lv_obj_t* hv_feedbacks_title_container = lv_obj_create(hv_feedbacks_panel);
    lv_obj_remove_style_all(hv_feedbacks_title_container);
    lv_obj_set_size(hv_feedbacks_title_container, 250, 50);
    lv_obj_add_style(hv_feedbacks_title_container, &box_panels_style, LV_PART_MAIN);
    lv_obj_set_grid_cell(hv_feedbacks_title_container, LV_GRID_ALIGN_CENTER, 0, 4, LV_GRID_ALIGN_END, 0, 1);


    lv_obj_t* hv_feedbacks_title = lv_label_create(hv_feedbacks_title_container);
    lv_obj_remove_style_all(hv_feedbacks_title);
    lv_obj_add_style(hv_feedbacks_title, &label_style, LV_PART_MAIN);
    //lv_obj_add_style(hv_feedbacks_title, &box_panels_style, LV_PART_MAIN);
    lv_obj_align(hv_feedbacks_title, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_style_text_font(hv_feedbacks_title, &lv_font_inter_bold_30, LV_PART_MAIN);
    lv_obj_set_style_text_align(hv_feedbacks_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    lv_obj_align(hv_feedbacks_title, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(hv_feedbacks_title, "HV FEEDBACKS");


    lv_obj_t * hv_feedbacks_cell_0_1 = cell_create(hv_feedbacks_panel, "TSAL GREEN FAULT", 0, 1, &box_debug_style_yellow);
    lv_obj_t * hv_feedbacks_cell_1_1 = cell_create(hv_feedbacks_panel, "TSAL GREEN", 1, 1, &box_debug_style_yellow);
    lv_obj_t * hv_feedbacks_cell_2_1 = cell_create(hv_feedbacks_panel, "AIRN GATE", 2, 1, &box_debug_style_yellow);
    lv_obj_t * hv_feedbacks_cell_3_1 = cell_create(hv_feedbacks_panel, "SD OUT", 3, 1, &box_debug_style_yellow);

    lv_obj_t * hv_feedbacks_cell_0_2 = cell_create(hv_feedbacks_panel, "IMD LATCHED", 0, 2, &box_debug_style_yellow);
    lv_obj_t * hv_feedbacks_cell_1_2 = cell_create(hv_feedbacks_panel, "TS OVER 60V STATUS", 1, 2, &box_debug_style_yellow);
    lv_obj_t * hv_feedbacks_cell_2_2 = cell_create(hv_feedbacks_panel, "PRECHARGE STATUS", 2, 2, &box_debug_style_yellow);
    lv_obj_t * hv_feedbacks_cell_3_2 = cell_create(hv_feedbacks_panel, "RELAY SD", 3, 2, &box_debug_style_yellow);

    lv_obj_t * hv_feedbacks_cell_0_3 = cell_create(hv_feedbacks_panel, "TSAL GREEN F LATCHED", 0, 3, &box_debug_style_yellow);
    lv_obj_t * hv_feedbacks_cell_1_3 = cell_create(hv_feedbacks_panel, "AIRN STATUS", 1, 3, &box_debug_style_yellow);
    lv_obj_t * hv_feedbacks_cell_2_3 = cell_create(hv_feedbacks_panel, "TSP OVER 60V STATUS", 2, 3, &box_debug_style_yellow);
    lv_obj_t * hv_feedbacks_cell_3_3 = cell_create(hv_feedbacks_panel, "IMD FAULT", 3, 3, &box_debug_style_yellow);

    lv_obj_t * hv_feedbacks_cell_0_4 = cell_create(hv_feedbacks_panel, "BMS LATCHED", 0, 4, &box_debug_style_yellow);
    lv_obj_t * hv_feedbacks_cell_1_4 = cell_create(hv_feedbacks_panel, "AIRP STATUS", 1, 4, &box_debug_style_yellow);
    lv_obj_t * hv_feedbacks_cell_2_4 = cell_create(hv_feedbacks_panel, "CHECK MUX", 2, 4, &box_debug_style_yellow);
    lv_obj_t * hv_feedbacks_cell_3_4 = cell_create(hv_feedbacks_panel, "SD END", 3, 4, &box_debug_style_yellow);

    lv_obj_t * hv_feedbacks_cell_0_5 = cell_create(hv_feedbacks_panel, "EXT LATCHED", 0, 5, &box_debug_style_yellow);
    lv_obj_t * hv_feedbacks_cell_1_5 = cell_create(hv_feedbacks_panel, "AIRP GATE", 1, 5, &box_debug_style_yellow);
    lv_obj_t * hv_feedbacks_cell_2_5 = cell_create(hv_feedbacks_panel, "SD IN", 2, 5, &box_debug_style_yellow);


    /*--- creating HV ERRORS PANEL ---*/

    static lv_coord_t hvErrors_panel_cols[] =  {CELL_WIDTH, CELL_WIDTH, CELL_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t hvErrors_panel_rows[] = {DATA_TITLE_HEIGHT, CELL_HEIGHT, CELL_HEIGHT, CELL_HEIGHT, CELL_HEIGHT, CELL_HEIGHT, LV_GRID_TEMPLATE_LAST};

    hv_errors_panel = lv_obj_create(main_panel);
    lv_obj_remove_style_all(hv_errors_panel);
    lv_obj_set_layout(hv_errors_panel, LV_LAYOUT_GRID);
    lv_obj_clear_flag(hv_errors_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(hv_errors_panel, CELL_WIDTH*3+COLUMN_PADDING*2, DATA_PANEL_HEIGHT); 

    lv_obj_add_style(hv_errors_panel, &grid_style, 0);
    lv_obj_align(hv_errors_panel, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_base_dir(hv_errors_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(hv_errors_panel, hvErrors_panel_cols, hvErrors_panel_rows);

    lv_obj_set_style_pad_row(hv_errors_panel, ROW_PADDING, 0);
    lv_obj_set_style_pad_column(hv_errors_panel, COLUMN_PADDING, 0);
    
    lv_obj_set_style_opa(hv_errors_panel, LV_OPA_0, LV_PART_MAIN);

    lv_obj_set_grid_cell(hv_errors_panel, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 1, 1);

    lv_obj_t* hv_errors_title_container = lv_obj_create(hv_errors_panel);
    lv_obj_remove_style_all(hv_errors_title_container);
    lv_obj_set_size(hv_errors_title_container, 250, 50);
    lv_obj_add_style(hv_errors_title_container, &box_panels_style, LV_PART_MAIN);
    lv_obj_set_grid_cell(hv_errors_title_container, LV_GRID_ALIGN_CENTER, 0, 3, LV_GRID_ALIGN_END, 0, 1);


    lv_obj_t* hv_errors_title = lv_label_create(hv_errors_title_container);
    lv_obj_remove_style_all(hv_errors_title);
    lv_obj_add_style(hv_errors_title, &label_style, LV_PART_MAIN);
    lv_obj_align(hv_errors_title, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_style_text_font(hv_errors_title, &lv_font_inter_bold_30, LV_PART_MAIN);
    lv_obj_set_style_text_align(hv_errors_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    lv_obj_align(hv_errors_title, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(hv_errors_title, "HV ERRORS");


    lv_obj_t * hv_errors_cell_0_1 = cell_create(hv_errors_panel, "CELL LOW VOLTAGE", 0, 1, &box_debug_style_yellow);
    lv_obj_t * hv_errors_cell_1_1 = cell_create(hv_errors_panel, "OVER CURRENT", 1, 1, &box_debug_style_yellow);
    lv_obj_t * hv_errors_cell_2_1 = cell_create(hv_errors_panel, "FEEDBACK", 2, 1, &box_debug_style_yellow);
    
    lv_obj_t * hv_errors_cell_0_2 = cell_create(hv_errors_panel, "CELL UNDER VOLT", 0, 2, &box_debug_style_yellow);
    lv_obj_t * hv_errors_cell_1_2 = cell_create(hv_errors_panel, "CAN", 1, 2, &box_debug_style_yellow);
    lv_obj_t * hv_errors_cell_2_2 = cell_create(hv_errors_panel, "FEEDBACK CIRCUITRY", 2, 2, &box_debug_style_yellow);
    
    lv_obj_t * hv_errors_cell_0_3 = cell_create(hv_errors_panel, "CELL OVER VOLT", 0, 3, &box_debug_style_yellow);
    lv_obj_t * hv_errors_cell_1_3 = cell_create(hv_errors_panel, "INT VOLTAGE MISMATCH", 1, 3, &box_debug_style_yellow);
    lv_obj_t * hv_errors_cell_2_3 = cell_create(hv_errors_panel, "EEPROM COMM", 2, 3, &box_debug_style_yellow);
    
    lv_obj_t * hv_errors_cell_0_4 = cell_create(hv_errors_panel, "CELL HIGH TEMP", 0, 4, &box_debug_style_yellow);
    lv_obj_t * hv_errors_cell_1_4 = cell_create(hv_errors_panel, "CELLBOARD COMM", 1, 4, &box_debug_style_yellow);
    lv_obj_t * hv_errors_cell_2_4 = cell_create(hv_errors_panel, "EEPROM WHITE", 2, 4, &box_debug_style_yellow);
    
    lv_obj_t * hv_errors_cell_0_5 = cell_create(hv_errors_panel, "CELL OVER TEMP", 0, 5, &box_debug_style_yellow);
    lv_obj_t * hv_errors_cell_1_5 = cell_create(hv_errors_panel, "CELLBOARD INTERNAL", 1, 5, &box_debug_style_yellow);
    

    /*--- creating DAS ERRORS PANEL ---*/

    static lv_coord_t dasErrors_panel_cols[] =  {CELL_WIDTH, CELL_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t dasErrors_panel_rows[] = {DATA_TITLE_HEIGHT, CELL_HEIGHT, CELL_HEIGHT, CELL_HEIGHT, CELL_HEIGHT, CELL_HEIGHT, LV_GRID_TEMPLATE_LAST};

    das_errors_panel = lv_obj_create(main_panel);
    lv_obj_remove_style_all(das_errors_panel);
    lv_obj_set_layout(das_errors_panel, LV_LAYOUT_GRID);
    lv_obj_clear_flag(das_errors_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(das_errors_panel, CELL_WIDTH*2+COLUMN_PADDING*1, DATA_PANEL_HEIGHT); 

    lv_obj_add_style(das_errors_panel, &grid_style, 0);
    lv_obj_align(das_errors_panel, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_base_dir(das_errors_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(das_errors_panel, dasErrors_panel_cols, dasErrors_panel_rows);

    lv_obj_set_style_pad_row(das_errors_panel, ROW_PADDING, 0);
    lv_obj_set_style_pad_column(das_errors_panel, COLUMN_PADDING, 0);
    
    lv_obj_set_style_opa(das_errors_panel, LV_OPA_0, LV_PART_MAIN);
    lv_obj_set_grid_cell(das_errors_panel, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 1, 1);

    lv_obj_t* das_errors_title_container = lv_obj_create(das_errors_panel);
    lv_obj_remove_style_all(das_errors_title_container);
    lv_obj_set_size(das_errors_title_container, 250, 50);
    lv_obj_add_style(das_errors_title_container, &box_panels_style, LV_PART_MAIN);
    lv_obj_set_grid_cell(das_errors_title_container, LV_GRID_ALIGN_CENTER, 0, 2, LV_GRID_ALIGN_END, 0, 1);


    lv_obj_t* das_errors_title = lv_label_create(das_errors_title_container);
    lv_obj_remove_style_all(das_errors_title);
    lv_obj_add_style(das_errors_title, &label_style, LV_PART_MAIN);
    lv_obj_align(das_errors_title, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_style_text_font(das_errors_title, &lv_font_inter_bold_30, LV_PART_MAIN);
    lv_obj_set_style_text_align(das_errors_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    lv_obj_align(das_errors_title, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(das_errors_title, "DAS ERRORS");


    lv_obj_t * das_errors_cell_0_1 = cell_create(das_errors_panel, "PEDAL ADC", 0, 1, &box_debug_style_yellow);
    lv_obj_t * das_errors_cell_1_1 = cell_create(das_errors_panel, "INVL TOUT", 1, 1, &box_debug_style_yellow);
    
    lv_obj_t * das_errors_cell_0_2 = cell_create(das_errors_panel, "PEDAL IMPLAUS", 0, 2, &box_debug_style_yellow);
    lv_obj_t * das_errors_cell_1_2 = cell_create(das_errors_panel, "INVR TOUT", 1, 2, &box_debug_style_yellow);
    
    lv_obj_t * das_errors_cell_0_3 = cell_create(das_errors_panel, "IMU TOUT", 0, 3, &box_debug_style_yellow);
    lv_obj_t * das_errors_cell_1_3 = cell_create(das_errors_panel, "STEER TOUT", 1, 3, &box_debug_style_yellow);
    
    lv_obj_t * das_errors_cell_0_4 = cell_create(das_errors_panel, "IRTS TOUT", 0, 4, &box_debug_style_yellow);
    lv_obj_t * das_errors_cell_1_4 = cell_create(das_errors_panel, "FSM", 1, 4, &box_debug_style_yellow);
    
    lv_obj_t * das_errors_cell_0_5 = cell_create(das_errors_panel, "TS TOUT", 0, 5, &box_debug_style_yellow);


    /*--- creating LV ERRORS PANEL ---*/


    static lv_coord_t lvErrors_panel_cols[] =  {CELL_WIDTH, CELL_WIDTH, CELL_WIDTH, CELL_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t lvErrors_panel_rows[] = {DATA_TITLE_HEIGHT, CELL_HEIGHT, CELL_HEIGHT, CELL_HEIGHT, CELL_HEIGHT, CELL_HEIGHT, CELL_HEIGHT, LV_GRID_TEMPLATE_LAST};

    lv_errors_panel = lv_obj_create(main_panel);
    lv_obj_remove_style_all(lv_errors_panel);
    lv_obj_set_layout(lv_errors_panel, LV_LAYOUT_GRID);
    lv_obj_clear_flag(lv_errors_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(lv_errors_panel, CELL_WIDTH*4+COLUMN_PADDING*3, DATA_PANEL_HEIGHT); 

    lv_obj_add_style(lv_errors_panel, &grid_style, 0);
    lv_obj_align(lv_errors_panel, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_base_dir(lv_errors_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(lv_errors_panel, lvErrors_panel_cols, lvErrors_panel_rows);

    lv_obj_set_style_pad_row(lv_errors_panel, ROW_PADDING, 0);
    lv_obj_set_style_pad_column(lv_errors_panel, COLUMN_PADDING, 0);
    lv_obj_set_style_opa(lv_errors_panel, LV_OPA_0, LV_PART_MAIN);
    
    lv_obj_set_grid_cell(lv_errors_panel, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 1, 1);

    lv_obj_t* lv_errors_title_container = lv_obj_create(lv_errors_panel);
    lv_obj_remove_style_all(lv_errors_title_container);
    lv_obj_set_size(lv_errors_title_container, 250, 50);
    lv_obj_add_style(lv_errors_title_container, &box_panels_style, LV_PART_MAIN);
    lv_obj_set_grid_cell(lv_errors_title_container, LV_GRID_ALIGN_CENTER, 0, 4, LV_GRID_ALIGN_END, 0, 1);


    lv_obj_t* lv_errors_title = lv_label_create(lv_errors_title_container);
    lv_obj_remove_style_all(lv_errors_title);
    lv_obj_add_style(lv_errors_title, &label_style, LV_PART_MAIN);
    lv_obj_align(lv_errors_title, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_style_text_font(lv_errors_title, &lv_font_inter_bold_30, LV_PART_MAIN);
    lv_obj_set_style_text_align(lv_errors_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    lv_obj_align(lv_errors_title, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(lv_errors_title, "LV ERRORS");


    lv_obj_t * lv_errors_cell_0_1 = cell_create(lv_errors_panel, "CELL UNDERVOLT", 0, 1, &box_debug_style_yellow);
    lv_obj_t * lv_errors_cell_1_1 = cell_create(lv_errors_panel, "DCDC12 UNDER TEMP", 1, 1, &box_debug_style_yellow);
    lv_obj_t * lv_errors_cell_2_1 = cell_create(lv_errors_panel, "CELL UNDER TEMP", 2, 1, &box_debug_style_yellow);
    lv_obj_t * lv_errors_cell_3_1 = cell_create(lv_errors_panel, "MCP23017", 3, 1, &box_debug_style_yellow);

    lv_obj_t * lv_errors_cell_0_2 = cell_create(lv_errors_panel, "CELL OVERVOLT", 0, 2, &box_debug_style_yellow);
    lv_obj_t * lv_errors_cell_1_2 = cell_create(lv_errors_panel, "DCDC12 OVER TEMP", 1, 2, &box_debug_style_yellow);
    lv_obj_t * lv_errors_cell_2_2 = cell_create(lv_errors_panel, "CELL OVER TEMP", 2, 2, &box_debug_style_yellow);
    lv_obj_t * lv_errors_cell_3_2 = cell_create(lv_errors_panel, "RADIATOR", 3, 2, &box_debug_style_yellow);

    lv_obj_t * lv_errors_cell_0_3 = cell_create(lv_errors_panel, "OPEN WIRE", 0, 3, &box_debug_style_yellow);
    lv_obj_t * lv_errors_cell_1_3 = cell_create(lv_errors_panel, "DCDC24 UNDER TEMP", 1, 3, &box_debug_style_yellow);
    lv_obj_t * lv_errors_cell_2_3 = cell_create(lv_errors_panel, "RELAY", 2, 3, &box_debug_style_yellow);
    lv_obj_t * lv_errors_cell_3_3 = cell_create(lv_errors_panel, "FAN", 3, 3, &box_debug_style_yellow);

    lv_obj_t * lv_errors_cell_0_4 = cell_create(lv_errors_panel, "CAN", 0, 4, &box_debug_style_yellow);
    lv_obj_t * lv_errors_cell_1_4 = cell_create(lv_errors_panel, "DCDC24 OVER TEMP", 1, 4, &box_debug_style_yellow);
    lv_obj_t * lv_errors_cell_2_4 = cell_create(lv_errors_panel, "LTC6810", 2, 4, &box_debug_style_yellow);
    lv_obj_t * lv_errors_cell_3_4 = cell_create(lv_errors_panel, "PUMP", 3, 4, &box_debug_style_yellow);

    lv_obj_t * lv_errors_cell_0_5 = cell_create(lv_errors_panel, "SPI", 0, 5, &box_debug_style_yellow);
    lv_obj_t * lv_errors_cell_1_5 = cell_create(lv_errors_panel, "DCDC12", 1, 5, &box_debug_style_yellow);
    lv_obj_t * lv_errors_cell_2_5 = cell_create(lv_errors_panel, "VOLTS NOT READY", 2, 5, &box_debug_style_yellow);
    lv_obj_t * lv_errors_cell_3_5 = cell_create(lv_errors_panel, "ADC INIT", 3, 5, &box_debug_style_yellow);

    lv_obj_t * lv_errors_cell_0_6 = cell_create(lv_errors_panel, "OVER CURRENT", 0, 6, &box_debug_style_yellow);
    lv_obj_t * lv_errors_cell_1_6 = cell_create(lv_errors_panel, "DCDC24", 1, 6, &box_debug_style_yellow);
    
}

ErrorTabID errors_focus = HV_ERRORS;

void change_errors_view(shift direction){
    
    if(lv_disp_get_scr_act(NULL) == scr_debug){

        if(direction == LEFT){
            if(errors_focus == 0)
                errors_focus = LV_ERRORS;
            else
                errors_focus--;

        }else if(direction == RIGHT){
            errors_focus++;
            errors_focus %= NUM_TYPE_ERRORS;
        }

        //printf("%d", curr_focus);    
        //fflush(stdout);

        switch (errors_focus)
        {
        case HV_FEEDBACKS:
            lv_obj_set_style_opa(hv_feedbacks_panel, LV_OPA_COVER, LV_PART_MAIN);
            lv_obj_set_style_opa(hv_errors_panel, LV_OPA_0, LV_PART_MAIN);
            lv_obj_set_style_opa(lv_errors_panel, LV_OPA_0, LV_PART_MAIN);

            break;

        case HV_ERRORS:
            lv_obj_set_style_opa(hv_errors_panel, LV_OPA_COVER, LV_PART_MAIN);
            lv_obj_set_style_opa(hv_feedbacks_panel, LV_OPA_0, LV_PART_MAIN);
            lv_obj_set_style_opa(das_errors_panel, LV_OPA_0, LV_PART_MAIN);

            break;

        case DAS_ERRORS:
            lv_obj_set_style_opa(das_errors_panel, LV_OPA_COVER, LV_PART_MAIN);
            lv_obj_set_style_opa(hv_errors_panel, LV_OPA_0, LV_PART_MAIN);
            lv_obj_set_style_opa(lv_errors_panel, LV_OPA_0, LV_PART_MAIN);


            break;

        case LV_ERRORS:
            lv_obj_set_style_opa(lv_errors_panel, LV_OPA_COVER, LV_PART_MAIN);
            lv_obj_set_style_opa(das_errors_panel, LV_OPA_0, LV_PART_MAIN);
            lv_obj_set_style_opa(hv_feedbacks_panel, LV_OPA_0, LV_PART_MAIN);


            break;

        default:
            break;
        }
    }
}