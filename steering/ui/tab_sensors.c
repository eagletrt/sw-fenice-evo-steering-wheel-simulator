#include "tab_sensors.h"
#include <stdio.h>

#define CELL_HEIGHT 200
#define CELL_WIDTH 180

void init_sensors_styles(void){

}

void tab_sensors(lv_obj_t * parent){
    init_sensors_styles();

    //optional label
    lv_obj_t * label2 = lv_label_create(parent);
    lv_label_set_text(label2, "Second screen");


    /*---creating main grid---*/

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


    /*--- inserting TOP NOTCH ---*/

    lv_obj_t *notch = create_notch(main_panel, TAB_SENSORS);
    lv_obj_align(lv_obj_get_child(notch, 0), LV_ALIGN_TOP_MID, 0, 5);
    lv_obj_set_grid_cell(notch, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_START, 0, 1);


    /*--- creating DATA PANEL ---*/

    static lv_coord_t dpanel_cols[] =  {CELL_WIDTH, CELL_WIDTH, CELL_WIDTH, CELL_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t dpanel_rows[] = {CELL_HEIGHT, CELL_HEIGHT, LV_GRID_TEMPLATE_LAST};

    lv_obj_t * data_panel = lv_obj_create(main_panel);
    lv_obj_set_layout(data_panel, LV_LAYOUT_GRID);
    lv_obj_clear_flag(data_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(data_panel, SCREEN_WIDTH-20, DATA_PANEL_HEIGHT); //non andrebbe tolto il 20 per farlo simmetrico(forse qualche errore)

    lv_obj_add_style(data_panel, &grid_style, 0);
    lv_obj_center(data_panel);
    lv_obj_set_style_base_dir(data_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(data_panel, dpanel_cols, dpanel_rows);

    lv_obj_set_style_pad_row(data_panel, ROW_PADDING, 0);
    lv_obj_set_style_pad_column(data_panel, COLUMN_PADDING, 0);

    lv_obj_set_grid_cell(data_panel, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 1, 1);


    /*--- cell 0,0 ---*/
    
    static lv_coord_t lxd_panel_cols[] =  {CELL_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t lxd_panel_rows[] = {65, 65, 65, LV_GRID_TEMPLATE_LAST};

    lv_obj_t * left_data_panel = lv_obj_create(data_panel);
    lv_obj_set_layout(left_data_panel, LV_LAYOUT_GRID);
    lv_obj_remove_style_all(left_data_panel);
    lv_obj_clear_flag(left_data_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(left_data_panel, CELL_WIDTH, CELL_HEIGHT);

    lv_obj_add_style(left_data_panel, &box_panels_style, 0);
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

    lv_obj_add_style(b_data_panel, &box_panels_style, 0);
    lv_obj_center(b_data_panel);
    lv_obj_set_style_base_dir(b_data_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(b_data_panel, lxd_panel_cols, lxd_panel_rows);

    lv_obj_set_grid_cell(b_data_panel, LV_GRID_ALIGN_CENTER, 0, 1,
                         LV_GRID_ALIGN_CENTER, 1, 1);

    /*--- cell 0,1*/

    lv_obj_t * c_data_panel = lv_obj_create(data_panel);
    lv_obj_set_layout(c_data_panel, LV_LAYOUT_GRID);
    lv_obj_remove_style_all(c_data_panel);
    lv_obj_clear_flag(c_data_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(c_data_panel, CELL_WIDTH, CELL_HEIGHT);

    lv_obj_add_style(c_data_panel, &box_panels_style, 0);
    lv_obj_center(c_data_panel);
    lv_obj_set_style_base_dir(c_data_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(c_data_panel, lxd_panel_cols, lxd_panel_rows);

    lv_obj_set_grid_cell(c_data_panel, LV_GRID_ALIGN_CENTER, 1, 1,
                         LV_GRID_ALIGN_CENTER, 0, 1);

    /*--- cell 1,1 (span 2)*/

    lv_obj_t * d_data_panel = lv_obj_create(data_panel);
    lv_obj_set_layout(d_data_panel, LV_LAYOUT_GRID);
    lv_obj_remove_style_all(d_data_panel);
    lv_obj_clear_flag(d_data_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(d_data_panel, CELL_WIDTH, CELL_HEIGHT);

    lv_obj_add_style(d_data_panel, &box_panels_style, 0);
    lv_obj_center(d_data_panel);
    lv_obj_set_style_base_dir(d_data_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(d_data_panel, lxd_panel_cols, lxd_panel_rows);

    lv_obj_set_grid_cell(d_data_panel, LV_GRID_ALIGN_STRETCH, 1, 2,
                         LV_GRID_ALIGN_CENTER, 1, 1);

    /*--- cell 0,2 */

    lv_obj_t * e_data_panel = lv_obj_create(data_panel);
    lv_obj_set_layout(e_data_panel, LV_LAYOUT_GRID);
    lv_obj_remove_style_all(e_data_panel);
    lv_obj_clear_flag(e_data_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(e_data_panel, CELL_WIDTH, CELL_HEIGHT);

    lv_obj_add_style(e_data_panel, &box_panels_style, 0);
    lv_obj_center(e_data_panel);
    lv_obj_set_style_base_dir(e_data_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(e_data_panel, lxd_panel_cols, lxd_panel_rows);

    lv_obj_set_grid_cell(e_data_panel, LV_GRID_ALIGN_STRETCH, 2, 1,
                         LV_GRID_ALIGN_CENTER, 0, 1);



    /*--- cell 0,3 */

    lv_obj_t * f_data_panel = lv_obj_create(data_panel);
    lv_obj_set_layout(f_data_panel, LV_LAYOUT_GRID);
    lv_obj_remove_style_all(f_data_panel);
    lv_obj_clear_flag(f_data_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(f_data_panel, CELL_WIDTH, CELL_HEIGHT);

    lv_obj_add_style(f_data_panel, &box_panels_style, 0);
    lv_obj_center(f_data_panel);
    lv_obj_set_style_base_dir(f_data_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(f_data_panel, lxd_panel_cols, lxd_panel_rows);

    lv_obj_set_grid_cell(f_data_panel, LV_GRID_ALIGN_STRETCH, 3, 1,
                         LV_GRID_ALIGN_CENTER, 0, 1);


    /*--- cell 2,3*/

    
    lv_obj_t * g_data_panel = lv_obj_create(data_panel);
    lv_obj_set_layout(g_data_panel, LV_LAYOUT_GRID);
    lv_obj_remove_style_all(g_data_panel);
    lv_obj_clear_flag(g_data_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(g_data_panel, CELL_WIDTH, CELL_HEIGHT);

    lv_obj_add_style(g_data_panel, &box_panels_style, 0);
    lv_obj_center(g_data_panel);
    lv_obj_set_style_base_dir(g_data_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(g_data_panel, lxd_panel_cols, lxd_panel_rows);

    lv_obj_set_grid_cell(g_data_panel, LV_GRID_ALIGN_STRETCH, 3, 1,
                         LV_GRID_ALIGN_CENTER, 1, 1);


}