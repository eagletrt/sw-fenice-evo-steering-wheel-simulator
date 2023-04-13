#include "steer_calibration.h"

void steer_calibration(lv_obj_t *parent){

    /*---creating main grid---*/

    static lv_coord_t main_panel_cols[] =  {SCREEN_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t main_panel_rows[] = { TOP_BAR_HEIGHT, TOP_LABELS_HEIGHT, CALIBRATION_TOOL_HEIGHT, BUTTONS_ROW_HEIGHT, BOTTOM_LABELS_HEIGHT, LV_GRID_TEMPLATE_LAST};

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

    /*--- inserting TOP LABELS ---*/

    lv_obj_t *top_lx_label = lv_label_create(main_panel);
    lv_obj_add_style(top_lx_label, &label_style, LV_PART_MAIN);
    lv_label_set_text(top_lx_label, " <-- SET FULL SX (B1)");
    lv_obj_set_style_text_font(top_lx_label, &lv_font_inter_bold_20, LV_PART_MAIN);
    lv_obj_set_grid_cell(top_lx_label, LV_GRID_ALIGN_START, 0, 1, LV_GRID_ALIGN_CENTER, 1, 1);

    lv_obj_t *top_rx_label = lv_label_create(main_panel);
    lv_obj_add_style(top_rx_label, &label_style, LV_PART_MAIN);
    lv_label_set_text(top_rx_label, "SET FULL DX (B2) --> ");
    lv_obj_set_style_text_font(top_rx_label, &lv_font_inter_bold_20, LV_PART_MAIN);
    lv_obj_set_grid_cell(top_rx_label, LV_GRID_ALIGN_END, 0, 1, LV_GRID_ALIGN_CENTER, 1, 1);

    /*--- inserting CALIBRATION TOOL ---*/

    lv_obj_t *tool_container = lv_obj_create(main_panel);
    lv_obj_remove_style_all(tool_container);
    lv_obj_set_size(tool_container, 760, CALIBRATION_TOOL_HEIGHT);
    lv_obj_set_style_bg_color(tool_container, lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(tool_container, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_grid_cell(tool_container, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_STRETCH, 2, 1);

    lv_obj_t *tool_label = lv_label_create(tool_container);
    lv_label_set_text(tool_label, "STEER");
    lv_obj_set_style_text_color(tool_label, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_text_font(tool_label, &lv_font_inter_bold_36, LV_PART_MAIN);
    lv_obj_align(tool_label, LV_ALIGN_TOP_MID, 0, 10);

    lv_bar_t *tool_bar = lv_bar_create(tool_container);
    lv_obj_set_size(tool_bar, TOOL_BAR_WIDTH, TOOL_BAR_HEIGTH);
    lv_obj_set_style_bg_color(tool_bar, lv_color_hex(COLOR_SECONDARY_HEX), LV_PART_MAIN);
    lv_obj_align(tool_bar, LV_ALIGN_BOTTOM_MID, 0, -10);
    lv_obj_set_style_bg_opa(tool_bar, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_style_radius(tool_bar, 0, LV_PART_MAIN);


    /*--- inserting BUTTONS ---*/
    
    lv_obj_t *buttons_container = lv_obj_create(main_panel);
    lv_obj_remove_style_all(buttons_container);
    lv_obj_set_size(buttons_container, 680, BUTTONS_ROW_HEIGHT);
    lv_obj_set_grid_cell(buttons_container, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_STRETCH, 3, 1);

    lv_obj_t *btn_sx = lv_btn_create(buttons_container);
    lv_obj_remove_style_all(btn_sx);
    lv_obj_set_size(btn_sx, BTN_WIDTH, BTN_HEIGHT);
    lv_obj_set_style_bg_color(btn_sx, lv_color_hex(COLOR_SECONDARY_HEX), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(btn_sx, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_style_radius(btn_sx, 4, LV_PART_MAIN);
    lv_obj_align(btn_sx, LV_ALIGN_BOTTOM_LEFT, 0, 0);

    lv_obj_t *label_btn_sx = lv_label_create(btn_sx);
    lv_label_set_text(label_btn_sx, "Set Full SX");
    lv_obj_set_style_text_color(label_btn_sx, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_text_font(label_btn_sx, &lv_font_inter_bold_30, LV_PART_MAIN);
    lv_obj_set_align(label_btn_sx, LV_ALIGN_CENTER);

    lv_obj_t *btn_rx = lv_btn_create(buttons_container);
    lv_obj_remove_style_all(btn_rx);
    lv_obj_set_size(btn_rx, BTN_WIDTH, BTN_HEIGHT);
    lv_obj_set_style_bg_color(btn_rx, lv_color_hex(COLOR_SECONDARY_HEX), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(btn_rx, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_style_radius(btn_rx, 4, LV_PART_MAIN);
    lv_obj_align(btn_rx, LV_ALIGN_BOTTOM_RIGHT, 0, 0);

    lv_obj_t *label_btn_rx = lv_label_create(btn_rx);
    lv_label_set_text(label_btn_rx, "Set Full DX");
    lv_obj_set_style_text_color(label_btn_rx, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_text_font(label_btn_rx, &lv_font_inter_bold_30, LV_PART_MAIN);
    lv_obj_set_align(label_btn_rx, LV_ALIGN_CENTER);


}