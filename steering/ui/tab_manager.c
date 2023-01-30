#include "tab_manager.h"

void tab_manager() {
    static lv_style_t foo;
    lv_style_init(&foo);
    lv_style_set_pad_all(&foo, 0);
    lv_style_set_pad_bottom(&foo, 0);
    lv_style_set_pad_column(&foo, 0);

    static lv_coord_t main_panel_cols[] =  {100, 600, 100, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t main_panel_rows[] = {480, LV_GRID_TEMPLATE_LAST};

    lv_obj_t * cont = lv_obj_create(lv_scr_act());
	lv_obj_set_layout(cont, LV_LAYOUT_GRID);
    lv_obj_clear_flag(cont, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(cont, SCREEN_WIDTH, SCREEN_HEIGHT);

    lv_obj_add_style(cont, &foo, 0);
    lv_obj_center(cont);
    lv_obj_set_style_base_dir(cont, LV_BASE_DIR_RTL, 0);
    lv_obj_set_grid_dsc_array(cont, main_panel_cols, main_panel_rows);

    lv_obj_t * obj = lv_obj_create(cont);
    lv_obj_set_grid_cell(obj, LV_GRID_ALIGN_STRETCH, 2, 1,
                         LV_GRID_ALIGN_STRETCH, 0, 1);
    lv_obj_t * label = lv_label_create(obj);
    lv_label_set_text(label, "HV BAR");

    lv_obj_t * obj2 = lv_obj_create(cont);
    lv_obj_set_grid_cell(obj2, LV_GRID_ALIGN_STRETCH, 1, 1,
                         LV_GRID_ALIGN_STRETCH, 0, 1);
    lv_obj_t * label2 = lv_label_create(obj2);
    lv_label_set_text(label2, "CENTRAL LAYOUT");

    lv_obj_t * obj3 = lv_obj_create(cont);
    lv_obj_set_grid_cell(obj3, LV_GRID_ALIGN_STRETCH, 0, 1,
                         LV_GRID_ALIGN_STRETCH, 0, 1);
    lv_obj_t * label3 = lv_label_create(obj3);
    lv_label_set_text(label3, "LV BAR");

}