#include "tab_calibration.h"

lv_obj_t *lx_box;
lv_obj_t *center_box;
lv_obj_t *rx_box;

lv_obj_t *new_screen;

lv_style_t box_style;
lv_style_t box_label_style;
lv_style_t buttons_style;
lv_style_t buttons_label_style;

void init_calibration_tab_styles(void){
    /* BOX STYLE */
    lv_style_init(&box_style);
    lv_style_set_width(&box_style, BOX_WIDTH);
    lv_style_set_height(&box_style, BOX_HEIGHT);
    lv_style_set_bg_color(&box_style, lv_color_hex(COLOR_SECONDARY_HEX));
    lv_style_set_bg_opa(&box_style, LV_OPA_COVER);
    lv_style_set_radius(&box_style, 14);

    /* BOX LABEL STYLE */
    lv_style_init(&box_label_style);
    lv_style_set_base_dir(&box_label_style, LV_BASE_DIR_LTR);
    lv_style_set_bg_opa(&box_label_style, LV_OPA_TRANSP);
    lv_style_set_text_color(&box_label_style, lv_color_hex(COLOR_TERTIARY_HEX));
    lv_style_set_text_align(&box_label_style, LV_TEXT_ALIGN_CENTER);
    lv_style_set_text_color(&box_label_style, lv_color_hex(0x000000));
    lv_style_set_text_font(&box_label_style, &lv_font_inter_bold_30);
    lv_style_set_align(&box_label_style, LV_ALIGN_CENTER);

    /* BUTTON STYLE*/
    lv_style_init(&buttons_style);
    lv_style_set_width(&buttons_style, BUTTON_WIDTH);
    lv_style_set_height(&buttons_style, BUTTON_HEIGHT);
    lv_style_set_radius(&buttons_style, 14);
    lv_style_set_bg_color(&buttons_style, lv_color_hex(COLOR_SECONDARY_HEX));
    lv_style_set_bg_opa(&buttons_style, LV_OPA_COVER);

    /* BUTTON LABEL STYLE */
    lv_style_init(&buttons_label_style);
    lv_style_set_base_dir(&buttons_label_style, LV_BASE_DIR_LTR);
    lv_style_set_bg_opa(&buttons_label_style, LV_OPA_TRANSP);
    lv_style_set_text_color(&buttons_label_style, lv_color_hex(COLOR_TERTIARY_HEX));
    lv_style_set_text_align(&buttons_label_style, LV_TEXT_ALIGN_CENTER);
    lv_style_set_text_color(&buttons_label_style, lv_color_hex(0x000000));
    lv_style_set_text_font(&buttons_label_style, &lv_font_inter_bold_22);
    lv_style_set_align(&buttons_label_style, LV_ALIGN_CENTER);
}

void tab_calibration(lv_obj_t *parent){
    init_calibration_tab_styles();

    new_screen = lv_obj_create(NULL);


    /*---creating main grid---*/

    static lv_coord_t main_panel_cols[] =  {SCREEN_WIDTH, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t main_panel_rows[] = {CALIBR_TAB_TOP_BAR_HEIGHT, CALIBR_TAB_CENTER_OPTIONS_HEIGHT, CALIBR_TAB_BUTTONS_BAR_HEIGHT, CALIBR_TAB_TOOL_HEIGHT, LV_GRID_TEMPLATE_LAST};

    lv_obj_t * main_panel = lv_obj_create(parent);
    lv_obj_set_layout(main_panel, LV_LAYOUT_GRID);
    lv_obj_clear_flag(main_panel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(main_panel, SCREEN_WIDTH, SCREEN_HEIGHT);

    lv_obj_add_style(main_panel, &grid_style, 0);
    lv_obj_center(main_panel);
    lv_obj_set_style_base_dir(main_panel, LV_BASE_DIR_LTR, 0);
    lv_obj_set_grid_dsc_array(main_panel, main_panel_cols, main_panel_rows);


    /*--- inserting TOP NOTCH ---*/

    lv_obj_t *notch = create_notch(main_panel, TAB_CALIBRATION);
    lv_obj_align(lv_obj_get_child(notch, 0), LV_ALIGN_TOP_MID, 0, 10);
    lv_obj_set_grid_cell(notch, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_START, 0, 1);


    /*--- inserting CENTER OPTIONS ---*/

    lv_obj_t *box_container = lv_obj_create(main_panel);
    lv_obj_remove_style_all(box_container);
    lv_obj_set_grid_cell(box_container, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_STRETCH, 1, 1);

    lx_box = lv_obj_create(box_container);
    lv_obj_remove_style_all(lx_box);
    lv_obj_add_style(lx_box, &box_style, LV_PART_MAIN);
    lv_obj_align(lx_box, LV_ALIGN_TOP_LEFT, BOX_SIDE_PADDING, 10);

    lv_obj_t *lx_box_label = lv_label_create(lx_box);
    lv_obj_add_style(lx_box_label, &box_label_style, LV_PART_MAIN);
    lv_label_set_text(lx_box_label, "BSE");


    center_box = lv_obj_create(box_container);
    lv_obj_remove_style_all(center_box);
    lv_obj_add_style(center_box, &box_style, LV_PART_MAIN);
    lv_obj_set_style_bg_color(center_box, lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    lv_obj_align(center_box, LV_ALIGN_TOP_MID, 0, 10);

    lv_obj_t *center_box_label = lv_label_create(center_box);
    lv_obj_add_style(center_box_label, &box_label_style, LV_PART_MAIN);
    lv_label_set_text(center_box_label, "STEER");

    rx_box = lv_obj_create(box_container);
    lv_obj_remove_style_all(rx_box);
    lv_obj_add_style(rx_box, &box_style, LV_PART_MAIN);
    lv_obj_align(rx_box, LV_ALIGN_TOP_RIGHT, -BOX_SIDE_PADDING, 10);

    lv_obj_t *rx_box_label = lv_label_create(rx_box);
    lv_obj_add_style(rx_box_label, &box_label_style, LV_PART_MAIN);
    lv_label_set_text(rx_box_label, "APPS");


    /*--- inserting BUTTONS ---*/
    lv_obj_t *buttons_container = lv_obj_create(main_panel);
    lv_obj_remove_style_all(buttons_container);
    lv_obj_set_grid_cell(buttons_container, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_STRETCH, 2, 1);

    lv_obj_t *lx_btn = lv_obj_create(buttons_container);

    lv_obj_set_size(lx_btn, BUTTON_WIDTH, BUTTON_HEIGHT);
    lv_obj_remove_style_all(lx_btn);
    lv_obj_add_style(lx_btn, &buttons_style, LV_PART_MAIN);
    lv_obj_align(lx_btn, LV_ALIGN_TOP_LEFT, BOX_SIDE_PADDING, 10);

    lv_obj_t *lx_btn_label = lv_label_create(lx_btn);
    lv_obj_add_style(lx_btn_label, &buttons_label_style, LV_PART_MAIN);
    lv_label_set_text(lx_btn_label, "G1 Set Min");
    lv_obj_set_align(lx_btn_label, LV_ALIGN_CENTER);

    lv_obj_t *center_btn = lv_obj_create(buttons_container);
    lv_obj_remove_style_all(center_btn);
    lv_obj_add_style(center_btn, &buttons_style, LV_PART_MAIN);
    lv_obj_align(center_btn, LV_ALIGN_TOP_MID, 0, 10);

    lv_obj_t *center_btn_label = lv_label_create(center_btn);
    lv_obj_add_style(center_btn_label, &buttons_label_style, LV_PART_MAIN);
    lv_label_set_text(center_btn_label, "60 deg");
    lv_obj_set_align(center_btn_label, LV_ALIGN_CENTER);

    lv_obj_t *rx_btn = lv_obj_create(buttons_container);
    lv_obj_remove_style_all(rx_btn);
    lv_obj_add_style(rx_btn, &buttons_style, LV_PART_MAIN);    
    lv_obj_align(rx_btn, LV_ALIGN_TOP_RIGHT, -BOX_SIDE_PADDING, 10);

    lv_obj_t *rx_btn_label = lv_label_create(rx_btn);
    lv_obj_add_style(rx_btn_label, &buttons_label_style, LV_PART_MAIN);
    lv_label_set_text(rx_btn_label, "Set Max G2");
    lv_obj_set_align(rx_btn_label, LV_ALIGN_CENTER);


    /*--- inserting CALIBRATION TOOL ---*/
    lv_obj_t *background_base = lv_obj_create(main_panel);
    lv_obj_remove_style_all(background_base);
    lv_obj_set_style_radius(background_base, 6, LV_PART_MAIN);
    lv_obj_set_style_bg_color(background_base, lv_color_hex(COLOR_SECONDARY_HEX), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(background_base, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_size(background_base, 740, 65);
    lv_obj_set_grid_cell(background_base, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 3, 1);
}

uint8_t curr_focus = 1;
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