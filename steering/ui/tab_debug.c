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
    lv_style_set_border_color(&box_debug_style, lv_color_hex(COLOR_YELLOW_STATUS_HEX)); 
    lv_style_set_border_width(&box_debug_style, 3);
    lv_style_set_bg_color(&box_debug_style, lv_color_hex(COLOR_YELLOW_STATUS_HEX));
    lv_style_set_radius(&box_debug_style, 10);
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
    //lv_obj_set_style_pad_row(main_panel, 0, 0);


    /*--- inserting TOP NOTCH ---*/

    lv_obj_t *notch = create_notch(main_panel, TAB_DEBUG);
    lv_obj_align(lv_obj_get_child(notch, 0), LV_ALIGN_TOP_MID, 0, 10);
    lv_obj_set_grid_cell(notch, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_START, 0, 1);

    
    /*--- creating DATA PANEL ---*/

 
    static lv_coord_t hvErrors_panel_cols[] =  {CELL_WIDTH, CELL_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t hvErrors_panel_rows[] = {CELL_HEIGHT, CELL_HEIGHT, LV_GRID_TEMPLATE_LAST};

    lv_obj_t * hv_errors_panel = lv_obj_create(main_panel);
    lv_obj_remove_style_all(hv_errors_panel);
    lv_obj_set_style_bg_opa(hv_errors_panel, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_layout(hv_errors_panel, LV_LAYOUT_GRID);
    lv_obj_clear_flag(hv_errors_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(hv_errors_panel, 200, 10); 

    //lv_obj_add_style(hv_errors_panel, &grid_style, 0);
    lv_obj_align(hv_errors_panel, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_base_dir(hv_errors_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(hv_errors_panel, hvErrors_panel_cols, hvErrors_panel_rows);

    lv_obj_set_style_pad_row(hv_errors_panel, ROW_PADDING, 0);
    lv_obj_set_style_pad_column(hv_errors_panel, COLUMN_PADDING, 0);
    
    lv_obj_set_grid_cell(hv_errors_panel, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 1, 1);


}