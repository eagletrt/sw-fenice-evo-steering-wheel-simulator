#include "tab_calibration.h"

lv_bar_t *lx_box;
lv_bar_t *center_box;
lv_bar_t *rx_box;

lv_obj_t *new_screen;
void tab_calibration(lv_obj_t *parent){
    new_screen = lv_obj_create(NULL);


    /*---creating main grid---*/

    static lv_coord_t main_panel_cols[] =  {SCREEN_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t main_panel_rows[] = {TOP_BAR_HEIGHT, TOP_LABELS_HEIGHT, CENTER_OPTIONS_HEIGHT, BOTTOM_LABELS_HEIGHT, LV_GRID_TEMPLATE_LAST};

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
    lv_obj_align(lv_obj_get_child(notch, NULL), LV_ALIGN_TOP_MID, 0, 15);
    lv_obj_set_grid_cell(notch, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_START, 0, 1);


    /*--- inserting TOP LABELS ---*/

    lv_obj_t *top_lx_label = lv_label_create(main_panel);
    lv_obj_add_style(top_lx_label, &label_style, LV_PART_MAIN);
    lv_label_set_text(top_lx_label, " <-- MOVE LEFT (B1)");
    lv_obj_set_style_text_font(top_lx_label, &lv_font_inter_bold_20, LV_PART_MAIN);
    lv_obj_set_grid_cell(top_lx_label, LV_GRID_ALIGN_START, 0, 1, LV_GRID_ALIGN_CENTER, 1, 1);

    lv_obj_t *top_rx_label = lv_label_create(main_panel);
    lv_obj_add_style(top_rx_label, &label_style, LV_PART_MAIN);
    lv_label_set_text(top_rx_label, "MOVE RIGHT (B2) --> ");
    lv_obj_set_style_text_font(top_rx_label, &lv_font_inter_bold_20, LV_PART_MAIN);
    lv_obj_set_grid_cell(top_rx_label, LV_GRID_ALIGN_END, 0, 1, LV_GRID_ALIGN_CENTER, 1, 1);


    /*--- inserting CENTER OPTIONS ---*/

    lv_obj_t *box_container = lv_obj_create(main_panel);
    lv_obj_remove_style_all(box_container);
    lv_obj_set_grid_cell(box_container, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_STRETCH, 2, 1);

    lx_box = lv_bar_create(box_container);
    lv_obj_set_size(lx_box, BOX_WIDTH, BOX_HEIGHT);
    lv_obj_set_style_bg_color(lx_box, lv_color_hex(COLOR_SECONDARY_HEX), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(lx_box, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_style_radius(lx_box, 4, LV_PART_MAIN);
    lv_obj_align(lx_box, LV_ALIGN_LEFT_MID, 40, 0);

    lv_obj_t *lx_box_label = lv_label_create(lx_box);
    lv_obj_add_style(lx_box_label, &label_style, LV_PART_MAIN);
    lv_label_set_text(lx_box_label, "BSE");
    lv_obj_set_style_text_color(lx_box_label, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_text_font(lx_box_label, &lv_font_inter_bold_30, LV_PART_MAIN);
    lv_obj_set_align(lx_box_label, LV_ALIGN_CENTER);

    center_box = lv_bar_create(box_container);
    lv_obj_set_size(center_box, BOX_WIDTH, BOX_HEIGHT);
    lv_obj_set_style_bg_color(center_box, lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(center_box, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_style_radius(center_box, 4, LV_PART_MAIN);
    lv_obj_align(center_box, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t *center_box_label = lv_label_create(center_box);
    lv_obj_add_style(center_box_label, &label_style, LV_PART_MAIN);
    lv_label_set_text(center_box_label, "STEER");
    lv_obj_set_style_text_color(center_box_label, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_text_font(center_box_label, &lv_font_inter_bold_30, LV_PART_MAIN);
    lv_obj_set_align(center_box_label, LV_ALIGN_CENTER);

    rx_box = lv_bar_create(box_container);
    lv_obj_set_size(rx_box, BOX_WIDTH, BOX_HEIGHT);
    lv_obj_set_style_bg_color(rx_box, lv_color_hex(COLOR_SECONDARY_HEX), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(rx_box, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_style_radius(rx_box, 4, LV_PART_MAIN);
    lv_obj_align(rx_box, LV_ALIGN_RIGHT_MID, -40, 0);

    lv_obj_t *rx_box_label = lv_label_create(rx_box);
    lv_obj_add_style(rx_box_label, &label_style, LV_PART_MAIN);
    lv_label_set_text(rx_box_label, "APPS");
    lv_obj_set_style_text_color(rx_box_label, lv_color_hex(0x000000), LV_PART_MAIN);
    lv_obj_set_style_text_font(rx_box_label, &lv_font_inter_bold_30, LV_PART_MAIN);
    lv_obj_set_align(rx_box_label, LV_ALIGN_CENTER);


    /*--- inserting BOTTOM LABELS ---*/

    lv_obj_t *bot_lx_label = lv_label_create(main_panel);
    lv_obj_add_style(bot_lx_label, &label_style, LV_PART_MAIN);
    lv_label_set_text(bot_lx_label, " <-- HIDE HELP (G1)");
    lv_obj_set_style_text_font(bot_lx_label, &lv_font_inter_bold_20, LV_PART_MAIN);
    lv_obj_set_grid_cell(bot_lx_label, LV_GRID_ALIGN_START, 0, 1, LV_GRID_ALIGN_CENTER, 3, 1);

    lv_obj_t *bot_rx_label = lv_label_create(main_panel);
    lv_obj_add_style(bot_rx_label, &label_style, LV_PART_MAIN);
    lv_label_set_text(bot_rx_label, "SELECT BOX (G2) --> ");
    lv_obj_set_style_text_font(bot_rx_label, &lv_font_inter_bold_20, LV_PART_MAIN);
    lv_obj_set_grid_cell(bot_rx_label, LV_GRID_ALIGN_END, 0, 1, LV_GRID_ALIGN_CENTER, 3, 1);

}

void shift_box_focus(shift direction){
    
    if(direction == LEFT && curr_focus > 0){
        curr_focus--;
    }else if(direction == RIGHT && curr_focus < 2){
        curr_focus++;
    }

    printf("%d", curr_focus);    
    fflush(stdout);

    switch (curr_focus)
    {
    case 0:
        lv_obj_set_style_bg_color(lx_box, lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
        lv_obj_set_style_bg_color(center_box, lv_color_hex(COLOR_SECONDARY_HEX), LV_PART_MAIN);
        break;

    case 1:
        lv_obj_set_style_bg_color(lx_box, lv_color_hex(COLOR_SECONDARY_HEX), LV_PART_MAIN);
        lv_obj_set_style_bg_color(center_box, lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
        lv_obj_set_style_bg_color(rx_box, lv_color_hex(COLOR_SECONDARY_HEX), LV_PART_MAIN);
        break;

    case 2:
        lv_obj_set_style_bg_color(rx_box, lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
        lv_obj_set_style_bg_color(center_box, lv_color_hex(COLOR_SECONDARY_HEX), LV_PART_MAIN);

        break;
    default:
        break;
    }
}


uint8_t get_box_selected(){
    return curr_focus;
}