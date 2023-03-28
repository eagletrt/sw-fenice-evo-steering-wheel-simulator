#include "tab_debug.h"
#include <stdio.h>

#define CELL_HEIGHT 200
#define CELL_WIDTH 180


void tab_debug(lv_obj_t * parent){


    //optional label
    lv_obj_t * label2 = lv_label_create(parent);
    lv_label_set_text(label2, "Second screen");


    /*---creating main grid---*/

    static lv_coord_t main_panel_cols[] =  {SCREEN_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t main_panel_rows[] = {TOP_BAR_HEIGHT-40, DATA_PANEL_HEIGHT + BOTTOM_BAR_HEIGHT + 80, LV_GRID_TEMPLATE_LAST};

    lv_obj_t * main_panel = lv_obj_create(parent);
    lv_obj_set_layout(main_panel, LV_LAYOUT_GRID);
    lv_obj_clear_flag(main_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(main_panel, SCREEN_WIDTH, SCREEN_HEIGHT);

    lv_obj_add_style(main_panel, &grid_style, 0);
    lv_obj_center(main_panel);
    lv_obj_set_style_base_dir(main_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(main_panel, main_panel_cols, main_panel_rows);


    /*--- inserting TOP NOTCH ---*/

    lv_obj_t *notch = create_notch(main_panel);
    lv_obj_align(lv_obj_get_child(notch, NULL), LV_ALIGN_TOP_MID, 0, 5);
    lv_obj_set_grid_cell(notch, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_START, 0, 1);


    /*--- creating DATA PANEL ---*/

    static lv_coord_t dpanel_cols[] =  {CELL_WIDTH, CELL_WIDTH, CELL_WIDTH, CELL_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t dpanel_rows[] = {CELL_HEIGHT, CELL_HEIGHT, LV_GRID_TEMPLATE_LAST};

    lv_obj_t * data_panel = lv_obj_create(main_panel);
    lv_obj_set_layout(data_panel, LV_LAYOUT_GRID);
    lv_obj_clear_flag(data_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(data_panel, CENTRAL_PANEL_WIDTH, DATA_PANEL_HEIGHT);

    lv_obj_add_style(data_panel, &grid_style, 0);
    lv_obj_center(data_panel);
    lv_obj_set_style_base_dir(data_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(data_panel, dpanel_cols, dpanel_rows);

    lv_obj_set_grid_cell(data_panel, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 1, 1);



    /*--- cell 0,0 ---*/
    
    static lv_coord_t lxd_panel_cols[] =  {CELL_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t lxd_panel_rows[] = {65, 65, 65, LV_GRID_TEMPLATE_LAST};

    lv_obj_t * left_data_panel = lv_obj_create(data_panel);
    lv_obj_set_layout(left_data_panel, LV_LAYOUT_GRID);
    lv_obj_remove_style_all(left_data_panel);
    lv_obj_clear_flag(left_data_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(left_data_panel, CELL_WIDTH, CELL_HEIGHT);

    lv_obj_add_style(left_data_panel, &side_panels_style, 0);
    lv_obj_center(left_data_panel);
    lv_obj_set_style_base_dir(left_data_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(left_data_panel, lxd_panel_cols, lxd_panel_rows);

    lv_obj_set_grid_cell(left_data_panel, LV_GRID_ALIGN_CENTER, 0, 1,
                         LV_GRID_ALIGN_CENTER, 0, 1);

    
    /*--- cell 1,0*/

    lv_obj_t * b_data_panel = lv_obj_create(data_panel);
    lv_obj_set_layout(b_data_panel, LV_LAYOUT_GRID);
    lv_obj_remove_style_all(b_data_panel);
    lv_obj_clear_flag(b_data_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(b_data_panel, CELL_WIDTH, CELL_HEIGHT);

    lv_obj_add_style(b_data_panel, &side_panels_style, 0);
    lv_obj_center(b_data_panel);
    lv_obj_set_style_base_dir(b_data_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(b_data_panel, lxd_panel_cols, lxd_panel_rows);

    lv_obj_set_grid_cell(b_data_panel, LV_GRID_ALIGN_CENTER, 0, 1,
                         LV_GRID_ALIGN_CENTER, 1, 1);




}

