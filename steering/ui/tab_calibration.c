#include "tab_calibration.h"


void tab_calibration(lv_obj_t *parent){

    /*---creating main grid---*/

    static lv_coord_t main_panel_cols[] =  {SCREEN_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t main_panel_rows[] = {SCREEN_HEIGHT, LV_GRID_TEMPLATE_LAST};

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


}