#include "tab_racing.h"

void tab_racing(lv_obj_t * parent)
{
    static lv_style_t grid_style;
    lv_style_init(&grid_style);
    lv_style_set_pad_all(&grid_style, 0);
    lv_style_set_pad_bottom(&grid_style, 0);
    lv_style_set_pad_column(&grid_style, 0);
    lv_style_set_pad_top(&grid_style, 0);
    lv_style_set_pad_row(&grid_style, 0);

    static lv_coord_t main_panel_cols[] =  {SIDE_BAR_WIDTH, CENTRAL_PANEL_WIDTH, SIDE_BAR_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t main_panel_rows[] = {SCREEN_HEIGHT, LV_GRID_TEMPLATE_LAST};

    lv_obj_t * tab_racing = lv_obj_create(parent);
    lv_obj_set_layout(tab_racing, LV_LAYOUT_GRID);
    lv_obj_clear_flag(tab_racing, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(tab_racing, SCREEN_WIDTH, SCREEN_HEIGHT);

    lv_obj_add_style(tab_racing, &grid_style, 0);
    lv_obj_center(tab_racing);
    lv_obj_set_style_base_dir(tab_racing, LV_BASE_DIR_RTL, 0);
    lv_obj_set_grid_dsc_array(tab_racing, main_panel_cols, main_panel_rows);


    static lv_style_t bar_style;

    lv_style_init(&bar_style);
    lv_style_set_bg_opa(&bar_style, LV_OPA_COVER);
    lv_style_set_bg_color(&bar_style, lv_palette_main(LV_PALETTE_RED));
    lv_style_set_bg_grad_color(&bar_style, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_bg_grad_dir(&bar_style, LV_GRAD_DIR_VER);


    // LEFT BAR
    lv_obj_t* hv_bar = lv_bar_create(tab_racing);
    lv_obj_remove_style_all(hv_bar);
    lv_obj_add_style(hv_bar, &bar_style, LV_PART_INDICATOR);
    lv_obj_set_size(hv_bar, 20, 200);
    lv_obj_center(hv_bar);
    lv_bar_set_range(hv_bar, -20, 40);
    lv_obj_set_grid_cell(hv_bar, LV_GRID_ALIGN_STRETCH, 2, 1,
                         LV_GRID_ALIGN_STRETCH, 0, 1);

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
    lv_obj_t * o1 = lv_obj_create(central_panel);
    lv_obj_t * l1 = lv_label_create(o1);
    lv_label_set_text(l1, "change-tabs view");
    lv_obj_set_grid_cell(o1, LV_GRID_ALIGN_STRETCH, 0, 1,
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

    // DATA LEFT
    lv_obj_t * o4 = lv_obj_create(data_panel);
    lv_obj_t * l4 = lv_label_create(o4);
    lv_label_set_text(l4, "data left");
    lv_obj_set_grid_cell(o4, LV_GRID_ALIGN_STRETCH, 0, 1,
                         LV_GRID_ALIGN_STRETCH, 0, 1);

    // DATA CENTER
    lv_obj_t * o5 = lv_obj_create(data_panel);
    lv_obj_t * l5 = lv_label_create(o5);
    lv_label_set_text(l5, "data center");
    lv_obj_set_grid_cell(o5, LV_GRID_ALIGN_STRETCH, 1, 1,
                         LV_GRID_ALIGN_STRETCH, 0, 1);

    // DATA RIGHT
    lv_obj_t * o6 = lv_obj_create(data_panel);
    lv_obj_t * l6 = lv_label_create(o6);
    lv_label_set_text(l6, "data right");
    lv_obj_set_grid_cell(o6, LV_GRID_ALIGN_STRETCH, 2, 1,
                         LV_GRID_ALIGN_STRETCH, 0, 1);


    // setting data panel position in central panel
    lv_obj_set_grid_cell(data_panel, LV_GRID_ALIGN_STRETCH, 0, 1,
                         LV_GRID_ALIGN_STRETCH, 1, 1);

    // BOTTOM BAR
    lv_obj_t * o3 = lv_obj_create(central_panel);
    lv_obj_t * l3 = lv_label_create(o3);
    lv_label_set_text(l3, "bottom bar");
    lv_obj_set_grid_cell(o3, LV_GRID_ALIGN_STRETCH, 0, 1,
                         LV_GRID_ALIGN_STRETCH, 2, 1);

    // setting central panel position in tab racing
    lv_obj_set_grid_cell(central_panel, LV_GRID_ALIGN_STRETCH, 1, 1,
                         LV_GRID_ALIGN_STRETCH, 0, 1);


    // RIGHT BAR
    lv_obj_t* lv_bar = lv_bar_create(tab_racing);
    lv_obj_remove_style_all(lv_bar);
    lv_obj_add_style(lv_bar, &bar_style, LV_PART_INDICATOR);
    lv_obj_set_size(lv_bar, 20, 200);
    lv_obj_center(lv_bar);
    lv_bar_set_range(lv_bar, -20, 40);
    lv_obj_set_grid_cell(lv_bar, LV_GRID_ALIGN_STRETCH, 0, 1,
                         LV_GRID_ALIGN_STRETCH, 0, 1);
}