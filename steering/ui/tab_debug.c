#include "tab_debug.h"
#include <stdio.h>

#define CELL_HEIGHT 50
#define CELL_WIDTH  350

lv_style_t box_debug_style;

void init_debug_styles(void){

    /*setting box_debug_style*/
    lv_style_init(&box_debug_style);
    lv_style_set_pad_all(&box_debug_style, 0);
    lv_style_set_pad_bottom(&box_debug_style, 0);
    lv_style_set_pad_column(&box_debug_style, 0);
    lv_style_set_pad_top(&box_debug_style, 0);
    lv_style_set_pad_row(&box_debug_style, 0);
    lv_style_set_bg_opa(&box_debug_style, LV_OPA_COVER);
    lv_style_set_border_color(&box_debug_style, lv_color_hex(COLOR_YELLOW_STATUS_HEX)); //to remove borders, keeping bc useful
    lv_style_set_border_width(&box_debug_style, 3);
    lv_style_set_bg_color(&box_debug_style, lv_color_hex(COLOR_YELLOW_STATUS_HEX));
    lv_style_set_radius(&box_debug_style, 0);
}

void tab_debug(lv_obj_t * parent){
    init_debug_styles();

    /*---creating MAIN GRID ---*/

    static lv_coord_t main_panel_cols[] =  {SCREEN_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t main_panel_rows[] = {TOP_BAR_HEIGHT, DATA_PANEL_HEIGHT, LV_GRID_TEMPLATE_LAST};

    lv_obj_t * main_panel = lv_obj_create(parent);
    lv_obj_set_layout(main_panel, LV_LAYOUT_GRID);
    lv_obj_clear_flag(main_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(main_panel, SCREEN_WIDTH, SCREEN_HEIGHT);

    lv_obj_add_style(main_panel, &grid_style, 0);
    lv_obj_center(main_panel);
    lv_obj_set_style_base_dir(main_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(main_panel, main_panel_cols, main_panel_rows);
    lv_obj_set_style_pad_row(main_panel, 120, 0);


    /*--- inserting TOP NOTCH ---*/

    lv_obj_t *notch = create_notch(main_panel, TAB_DEBUG);
    lv_obj_align(lv_obj_get_child(notch, 0), LV_ALIGN_TOP_MID, 0, 10);
    lv_obj_set_grid_cell(notch, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_START, 0, 1);

    
    /*--- creating DATA PANEL ---*/

    static lv_coord_t dpanel_cols[] =  {CELL_WIDTH, CELL_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t dpanel_rows[] = {CELL_HEIGHT, CELL_HEIGHT, LV_GRID_TEMPLATE_LAST};

    lv_obj_t * data_panel = lv_obj_create(main_panel);
    lv_obj_set_layout(data_panel, LV_LAYOUT_GRID);
    lv_obj_clear_flag(data_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(data_panel, SCREEN_WIDTH-80, DATA_PANEL_HEIGHT); //non andrebbe tolto il 20 per farlo simmetrico(forse qualche errore)

    lv_obj_add_style(data_panel, &grid_style, 0);
    lv_obj_center(data_panel);
    lv_obj_set_style_base_dir(data_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(data_panel, dpanel_cols, dpanel_rows);

    lv_obj_set_style_pad_row(data_panel, ROW_PADDING, 0);
    lv_obj_set_style_pad_column(data_panel, COLUMN_PADDING, 0);

    lv_obj_set_grid_cell(data_panel, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_SPACE_EVENLY, 1, 1);

    
    
    /*--- DATA PANEL: cell 0,0 ---*/
    
    static lv_coord_t lxd_panel_cols[] =  {CELL_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t lxd_panel_rows[] = {CELL_HEIGHT, LV_GRID_TEMPLATE_LAST};

    lv_obj_t * up_left_data_panel = lv_obj_create(data_panel);
    lv_obj_set_layout(up_left_data_panel, LV_LAYOUT_GRID);
    lv_obj_remove_style_all(up_left_data_panel);
    lv_obj_clear_flag(up_left_data_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(up_left_data_panel, CELL_WIDTH, CELL_HEIGHT);

    lv_obj_add_style(up_left_data_panel, &box_debug_style, 0);
    lv_obj_center(up_left_data_panel);
    lv_obj_set_style_base_dir(up_left_data_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(up_left_data_panel, lxd_panel_cols, lxd_panel_rows);
    
    lv_obj_set_grid_cell(up_left_data_panel, LV_GRID_ALIGN_CENTER, 0, 1,
                         LV_GRID_ALIGN_CENTER, 0, 1);

    lv_obj_t *speed = lv_vertical_pair_label(up_left_data_panel, &steering.general_info.lb_estimated_velocity[TAB_DEBUG], "70", &lv_font_inter_bold_70, "KM/H", &lv_font_inter_bold_22);
    lv_obj_set_grid_cell(speed, LV_GRID_ALIGN_CENTER, 0,1, LV_GRID_ALIGN_CENTER, 0,1);

    
    /*--- cell 1,0 ---*/
    
    lv_obj_t * low_left_data_panel = lv_obj_create(data_panel);
    lv_obj_set_layout(low_left_data_panel, LV_LAYOUT_GRID);
    lv_obj_remove_style_all(low_left_data_panel);
    lv_obj_clear_flag(low_left_data_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(low_left_data_panel, CELL_WIDTH, CELL_HEIGHT);

    lv_obj_add_style(low_left_data_panel, &box_debug_style, 0);
    lv_obj_center(low_left_data_panel);
    lv_obj_set_style_base_dir(low_left_data_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(low_left_data_panel, lxd_panel_cols, lxd_panel_rows);

    lv_obj_set_grid_cell(low_left_data_panel, LV_GRID_ALIGN_CENTER, 0, 1,
                         LV_GRID_ALIGN_CENTER, 1, 1);

    
    lv_obj_t *x_axis_g = lv_vertical_pair_label(low_left_data_panel, &steering.general_info.lb_delta_time[TAB_DEBUG], "0.8", &lv_font_inter_bold_70, "AX/G", &lv_font_inter_bold_22);
    lv_obj_set_grid_cell(x_axis_g, LV_GRID_ALIGN_CENTER, 0,1, LV_GRID_ALIGN_CENTER, 0,1);
    

    /*--- cell 0,1 ---*/

    lv_obj_t * up_right_data_panel = lv_obj_create(data_panel);
    lv_obj_set_layout(up_right_data_panel, LV_LAYOUT_GRID);
    lv_obj_remove_style_all(up_right_data_panel);
    lv_obj_clear_flag(up_right_data_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(up_right_data_panel, CELL_WIDTH, CELL_HEIGHT);

    lv_obj_add_style(up_right_data_panel, &box_debug_style, 0);
    lv_obj_center(up_right_data_panel);
    lv_obj_set_style_base_dir(up_right_data_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(up_right_data_panel, lxd_panel_cols, lxd_panel_rows);

    lv_obj_set_grid_cell(up_right_data_panel, LV_GRID_ALIGN_CENTER, 1, 1,
                         LV_GRID_ALIGN_CENTER, 0, 1);

    // TO_DO add pointer to corresponding label (not currently existing)
    lv_obj_t *steer_angle = lv_triple_label(up_right_data_panel, &steering.general_info.lb_delta_time[TAB_DEBUG], "0.8", &lv_font_inter_bold_70, "°", &lv_font_inter_bold_22, "STEER ANGLE", &lv_font_inter_bold_22);
    lv_obj_set_grid_cell(steer_angle, LV_GRID_ALIGN_CENTER, 0,1, LV_GRID_ALIGN_CENTER, 0,1);

    /*--- cell 1,1 ----*/

    lv_obj_t * low_right_data_panel = lv_obj_create(data_panel);
    lv_obj_set_layout(low_right_data_panel, LV_LAYOUT_GRID);
    lv_obj_remove_style_all(low_right_data_panel);
    lv_obj_clear_flag(low_right_data_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(low_right_data_panel, CELL_WIDTH, CELL_HEIGHT);

    lv_obj_add_style(low_right_data_panel, &box_debug_style, 0);
    lv_obj_center(low_right_data_panel);
    lv_obj_set_style_base_dir(low_right_data_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(low_right_data_panel, lxd_panel_cols, lxd_panel_rows);

    lv_obj_set_grid_cell(low_right_data_panel, LV_GRID_ALIGN_STRETCH, 1, 1,
                         LV_GRID_ALIGN_CENTER, 1, 1);

    // TO_DO add pointer to corresponding label (not currently existing)
    lv_obj_t *y_axis_g = lv_vertical_pair_label(low_right_data_panel, &steering.general_info.lb_delta_time[TAB_DEBUG], "0.2", &lv_font_inter_bold_70, "AY/G", &lv_font_inter_bold_22);
    lv_obj_set_grid_cell(y_axis_g, LV_GRID_ALIGN_CENTER, 0,1, LV_GRID_ALIGN_CENTER, 0,1);

    
}