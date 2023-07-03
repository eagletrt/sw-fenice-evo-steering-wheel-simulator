#include "tab_calibration.h"

lv_obj_t *lx_box;
lv_obj_t *center_box;
lv_obj_t *rx_box;

lv_style_t box_style;
lv_style_t box_label_style;
lv_style_t buttons_style;
lv_style_t buttons_label_style;
lv_style_t calib_tool_bar_style;

lv_obj_t *bar_start;

lv_obj_t *set_min_btn;
lv_obj_t *set_max_btn;

lv_obj_t *scr_calib;

extern tab_t current_tab;

void init_calibration_tab_styles(void) {
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
  lv_style_set_text_color(&buttons_label_style,
                          lv_color_hex(COLOR_TERTIARY_HEX));
  lv_style_set_text_align(&buttons_label_style, LV_TEXT_ALIGN_CENTER);
  lv_style_set_text_color(&buttons_label_style, lv_color_hex(0x000000));
  lv_style_set_text_font(&buttons_label_style, &lv_font_inter_bold_22);
  lv_style_set_align(&buttons_label_style, LV_ALIGN_CENTER);

  /* CALIB. TOOL BARS */
  lv_style_init(&calib_tool_bar_style);
  lv_style_set_height(&calib_tool_bar_style, 55);
  lv_style_set_width(&calib_tool_bar_style, 2);
  lv_style_set_bg_color(&calib_tool_bar_style, lv_color_hex(0x000000));
  lv_style_set_bg_opa(&calib_tool_bar_style, LV_OPA_COVER);
}

void tab_calibration(lv_obj_t *parent) {
  init_calibration_tab_styles();

  scr_calib = parent;

  /*---creating main grid---*/

  static lv_coord_t main_panel_cols[] = {SCREEN_WIDTH, LV_GRID_TEMPLATE_LAST};
  static lv_coord_t main_panel_rows[] = {
      CALIBR_TAB_TOP_BAR_HEIGHT, CALIBR_TAB_CENTER_OPTIONS_HEIGHT,
      CALIBR_TAB_BUTTONS_BAR_HEIGHT, CALIBR_TAB_TOOL_HEIGHT,
      LV_GRID_TEMPLATE_LAST};

  lv_obj_t *main_panel = lv_obj_create(parent);
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
  lv_obj_set_grid_cell(notch, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_START,
                       0, 1);

  /*--- inserting CENTER OPTIONS ---*/

  lv_obj_t *box_container = lv_obj_create(main_panel);
  lv_obj_remove_style_all(box_container);
  lv_obj_set_grid_cell(box_container, LV_GRID_ALIGN_STRETCH, 0, 1,
                       LV_GRID_ALIGN_STRETCH, 1, 1);

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
  lv_obj_set_style_bg_color(center_box, lv_color_hex(COLOR_YELLOW_STATUS_HEX),
                            LV_PART_MAIN);
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
  lv_obj_set_grid_cell(buttons_container, LV_GRID_ALIGN_STRETCH, 0, 1,
                       LV_GRID_ALIGN_STRETCH, 2, 1);

  set_min_btn = lv_obj_create(buttons_container);

  lv_obj_set_size(set_min_btn, BUTTON_WIDTH, BUTTON_HEIGHT);
  lv_obj_remove_style_all(set_min_btn);
  lv_obj_add_style(set_min_btn, &buttons_style, LV_PART_MAIN);
  lv_obj_align(set_min_btn, LV_ALIGN_TOP_LEFT, BOX_SIDE_PADDING, 10);

  lv_obj_t *set_min_btn_label = lv_label_create(set_min_btn);
  lv_obj_add_style(set_min_btn_label, &buttons_label_style, LV_PART_MAIN);
  lv_label_set_text(set_min_btn_label, "G1 Set Min");
  lv_obj_set_align(set_min_btn_label, LV_ALIGN_CENTER);

  lv_obj_t *center_btn = lv_obj_create(buttons_container);
  lv_obj_remove_style_all(center_btn);
  lv_obj_add_style(center_btn, &buttons_style, LV_PART_MAIN);
  lv_obj_align(center_btn, LV_ALIGN_TOP_MID, 0, 10);

  lv_obj_t *center_lbl;
  lv_obj_t *center_btn_label = lv_horizontal_pair_label(
      center_btn, &center_lbl, "15", &lv_font_inter_bold_30, " deg",
      &lv_font_inter_bold_22);
  lv_obj_set_align(center_btn_label, LV_ALIGN_CENTER);
  lv_obj_set_style_text_color(lv_obj_get_child(center_btn_label, 0),
                              lv_color_hex(COLOR_PRIMARY_HEX), LV_PART_MAIN);
  lv_obj_set_style_text_color(
      lv_obj_get_child(lv_obj_get_child(center_btn_label, 1), 0),
      lv_color_hex(COLOR_PRIMARY_HEX), LV_PART_MAIN);
  lv_obj_set_grid_cell(lv_obj_get_child(center_btn_label, 1),
                       LV_GRID_ALIGN_CENTER, 1, 1, LV_GRID_ALIGN_CENTER, 0,
                       1); // center the label "POWER"

  /*
  lv_obj_t *center_btn_label = lv_label_create(center_btn);
  lv_obj_add_style(center_btn_label, &buttons_label_style, LV_PART_MAIN);
  lv_label_set_text(center_btn_label, "60 deg");
  lv_obj_set_style_text_color(center_btn_label,
  lv_color_hex(COLOR_TERTIARY_HEX), LV_PART_MAIN);
  lv_obj_set_align(center_btn_label, LV_ALIGN_CENTER);
  */

  set_max_btn = lv_obj_create(buttons_container);
  lv_obj_remove_style_all(set_max_btn);
  lv_obj_add_style(set_max_btn, &buttons_style, LV_PART_MAIN);
  lv_obj_align(set_max_btn, LV_ALIGN_TOP_RIGHT, -BOX_SIDE_PADDING, 10);

  lv_obj_t *set_max_btn_label = lv_label_create(set_max_btn);
  lv_obj_add_style(set_max_btn_label, &buttons_label_style, LV_PART_MAIN);
  lv_label_set_text(set_max_btn_label, "G2 Set Max");
  lv_obj_set_align(set_max_btn_label, LV_ALIGN_CENTER);

  /*--- inserting CALIBRATION TOOL ---*/
  lv_obj_t *background_base = lv_obj_create(main_panel);
  lv_obj_remove_style_all(background_base);
  lv_obj_set_style_radius(background_base, 6, LV_PART_MAIN);
  lv_obj_set_style_bg_color(background_base, lv_color_hex(COLOR_SECONDARY_HEX),
                            LV_PART_MAIN);
  lv_obj_set_style_bg_opa(background_base, LV_OPA_COVER, LV_PART_MAIN);
  lv_obj_set_size(background_base, 740, 55);
  lv_obj_set_grid_cell(background_base, LV_GRID_ALIGN_CENTER, 0, 1,
                       LV_GRID_ALIGN_CENTER, 3, 1);

  steering.slider = lv_slider_create(background_base);
  lv_obj_remove_style_all(steering.slider);
  lv_obj_set_style_bg_color(steering.slider, lv_color_hex(0x000000),
                            LV_PART_INDICATOR);
  lv_obj_set_style_bg_opa(steering.slider, LV_OPA_70, LV_PART_INDICATOR);

  lv_obj_set_size(steering.slider, 744, 55);
  lv_obj_center(steering.slider);
  lv_slider_set_mode(steering.slider, LV_BAR_MODE_SYMMETRICAL);
  lv_slider_set_range(steering.slider, -80,
                      80); // se range 45 e max value 180 -> set_value( 0.25 *
                           // gradi_inclinazione )
  lv_slider_set_value(steering.slider, 15, LV_ANIM_OFF);
  lv_obj_set_style_radius(steering.slider, 0, LV_PART_INDICATOR);

  for (int i = 1; i <= 12; i++) {
    lv_obj_t *calib_bar = lv_obj_create(background_base);
    lv_obj_remove_style_all(calib_bar);
    lv_obj_add_style(calib_bar, &calib_tool_bar_style, LV_PART_MAIN);
    lv_obj_align(calib_bar, LV_ALIGN_CENTER, (-372 + (i * 62)), 0);

    if (i == 6) {
      bar_start = lv_obj_create(background_base);
      lv_obj_remove_style_all(bar_start);
      lv_obj_add_style(bar_start, &calib_tool_bar_style, LV_PART_MAIN);
      lv_obj_align(bar_start, LV_ALIGN_CENTER, (-372 + (i * 62)), 0);

      lv_obj_set_style_bg_color(bar_start, lv_color_hex(COLOR_TERTIARY_HEX),
                                LV_PART_MAIN);
      lv_obj_set_width(bar_start, 3);
    }
  }

  steering.curr_focus = 1;
}

void sim_calibration_tool_set_min_max(bool setting_max_value) {
  if (lv_disp_get_scr_act(NULL) == scr_calib) {
    bool esito;
    switch (steering.curr_focus) {
    case BSE:
      if (setting_max_value) {
        // calibrate max BSE
      } else {
        // calibrate min BSE
      }
      esito = true; // did it work?!
      break;
    case STEER:
      if (setting_max_value) {
        // calibrate max STEER
      } else {
        // calibrate min STEER
      }
      esito = true;
      break;
    case APPS:

      if (setting_max_value) {
        // calibrate max APPS
      } else {
        // calibrate min APPS
      }
      esito = true;
      break;
    default:
      break;
    }
    if (esito) {
      if (setting_max_value)
        lv_obj_set_style_bg_color(
            set_max_btn, lv_color_hex(COLOR_GREEN_STATUS_HEX), LV_PART_MAIN);
      else
        lv_obj_set_style_bg_color(
            set_min_btn, lv_color_hex(COLOR_GREEN_STATUS_HEX), LV_PART_MAIN);
    } else {
      if (setting_max_value)
        lv_obj_set_style_bg_color(
            set_max_btn, lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
      else
        lv_obj_set_style_bg_color(
            set_min_btn, lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
    }
  }
}

void shift_box_focus(bool move_right) {

  if (current_tab == TAB_CALIBRATION) {

    calibration_box_t previous_focus = steering.curr_focus;

    if (move_right == false && steering.curr_focus > 0) {
      steering.curr_focus--;
    } else if (move_right == true && steering.curr_focus < 2) {
      steering.curr_focus++;
    }

    /* look if the focus is changed or not */
    if (previous_focus != steering.curr_focus) {
      switch (steering.curr_focus) {
      case BSE:
        // clean the buttons set min/max
        lv_obj_set_style_bg_color(
            set_min_btn, lv_color_hex(COLOR_SECONDARY_HEX), LV_PART_MAIN);
        lv_obj_set_style_bg_color(
            set_max_btn, lv_color_hex(COLOR_SECONDARY_HEX), LV_PART_MAIN);

        // color the box focused
        lv_obj_set_style_bg_color(lx_box, lv_color_hex(COLOR_YELLOW_STATUS_HEX),
                                  LV_PART_MAIN);
        lv_obj_set_style_bg_color(center_box, lv_color_hex(COLOR_SECONDARY_HEX),
                                  LV_PART_MAIN);

        lv_slider_set_mode(steering.slider, LV_BAR_MODE_RANGE);
        lv_slider_set_range(steering.slider, 0, 100);

        lv_obj_align(bar_start, LV_ALIGN_LEFT_MID, 0, 0);

        break;

      case STEER:
        // clean the buttons set min/max
        lv_obj_set_style_bg_color(
            set_min_btn, lv_color_hex(COLOR_SECONDARY_HEX), LV_PART_MAIN);
        lv_obj_set_style_bg_color(
            set_max_btn, lv_color_hex(COLOR_SECONDARY_HEX), LV_PART_MAIN);

        // color the box focused
        lv_obj_set_style_bg_color(lx_box, lv_color_hex(COLOR_SECONDARY_HEX),
                                  LV_PART_MAIN);
        lv_obj_set_style_bg_color(
            center_box, lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
        lv_obj_set_style_bg_color(rx_box, lv_color_hex(COLOR_SECONDARY_HEX),
                                  LV_PART_MAIN);

        lv_slider_set_mode(steering.slider, LV_BAR_MODE_SYMMETRICAL);
        lv_slider_set_range(steering.slider, -80,
                            80); // se range 45 e max value 180 -> set_value(
                                 // 0.25 * gradi_inclinazione )

        lv_obj_align(bar_start, LV_ALIGN_CENTER, 0, 0);

        break;

      case APPS:
        // clean the buttons set min/max
        lv_obj_set_style_bg_color(
            set_min_btn, lv_color_hex(COLOR_SECONDARY_HEX), LV_PART_MAIN);
        lv_obj_set_style_bg_color(
            set_max_btn, lv_color_hex(COLOR_SECONDARY_HEX), LV_PART_MAIN);

        // color the box focused
        lv_obj_set_style_bg_color(rx_box, lv_color_hex(COLOR_YELLOW_STATUS_HEX),
                                  LV_PART_MAIN);
        lv_obj_set_style_bg_color(center_box, lv_color_hex(COLOR_SECONDARY_HEX),
                                  LV_PART_MAIN);

        lv_slider_set_mode(steering.slider, LV_BAR_MODE_RANGE);
        lv_slider_set_range(steering.slider, 0, 100);

        lv_obj_align(bar_start, LV_ALIGN_LEFT_MID, 0, 0);

        break;
      default:
        break;
      }

      lv_scr_load(scr_calib);
    }
  }
}