#include "utils.h"

lv_style_t grid_style;
lv_style_t label_style;
lv_style_t box_panels_style;

lv_obj_t *lv_vertical_pair_label(lv_obj_t *parent, lv_obj_t **main_l,
                                 const char *up_text,
                                 const lv_font_t *up_text_font,
                                 const char *bottom_text,
                                 const lv_font_t *bottom_text_font) {
  static lv_coord_t grid_col_dsc[] = {LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};
  static lv_coord_t grid_row_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT,
                                      LV_GRID_TEMPLATE_LAST};

  lv_obj_t *grid = lv_obj_create(parent);
  lv_obj_remove_style_all(grid);
  lv_obj_set_size(grid, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
  lv_obj_set_grid_dsc_array(grid, grid_col_dsc, grid_row_dsc);

  lv_obj_t *up_o = lv_obj_create(grid);
  lv_obj_remove_style_all(up_o);
  lv_obj_set_size(up_o, LV_SIZE_CONTENT, LV_SIZE_CONTENT);

  *main_l = lv_label_create(up_o);
  lv_obj_add_style(*main_l, &label_style, LV_PART_MAIN);
  lv_label_set_text(*main_l, up_text);
  lv_obj_set_style_text_font(*main_l, up_text_font, LV_STATE_DEFAULT);
  lv_obj_align(*main_l, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_grid_cell(up_o, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER,
                       0, 1);

  lv_obj_t *bot_o = lv_obj_create(grid);
  lv_obj_remove_style_all(bot_o);
  lv_obj_set_size(bot_o, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
  lv_obj_set_style_pad_top(bot_o, 8, LV_PART_MAIN);
  lv_obj_t *bl = lv_label_create(bot_o);
  lv_obj_add_style(bl, &label_style, LV_PART_MAIN);
  lv_label_set_text(bl, bottom_text);
  lv_obj_set_style_text_font(bl, bottom_text_font, LV_STATE_DEFAULT);
  lv_obj_align(bl, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_grid_cell(bot_o, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_CONTENT, 1,
                       1);

  return grid;
}

lv_obj_t *lv_vertical_pair_two_labels(lv_obj_t *parent, lv_obj_t **main_l,
                                      const char *up_text,
                                      const lv_font_t *up_text_font,
                                      lv_obj_t **bottom_label,
                                      const char *bottom_text,
                                      const lv_font_t *bottom_text_font) {
  static lv_coord_t grid_col_dsc[] = {LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};
  static lv_coord_t grid_row_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT,
                                      LV_GRID_TEMPLATE_LAST};

  lv_obj_t *grid = lv_obj_create(parent);
  lv_obj_remove_style_all(grid);
  lv_obj_set_size(grid, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
  lv_obj_set_grid_dsc_array(grid, grid_col_dsc, grid_row_dsc);

  lv_obj_t *up_o = lv_obj_create(grid);
  lv_obj_remove_style_all(up_o);
  lv_obj_set_size(up_o, LV_SIZE_CONTENT, LV_SIZE_CONTENT);

  *main_l = lv_label_create(up_o);
  lv_obj_add_style(*main_l, &label_style, LV_PART_MAIN);
  lv_label_set_text(*main_l, up_text);
  lv_obj_set_style_text_font(*main_l, up_text_font, LV_STATE_DEFAULT);
  lv_obj_align(*main_l, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_grid_cell(up_o, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER,
                       0, 1);

  lv_obj_t *bot_o = lv_obj_create(grid);
  lv_obj_remove_style_all(bot_o);
  lv_obj_set_size(bot_o, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
  lv_obj_set_style_pad_top(bot_o, 8, LV_PART_MAIN);
  *bottom_label = lv_label_create(bot_o);
  lv_obj_add_style(*bottom_label, &label_style, LV_PART_MAIN);
  lv_label_set_text(*bottom_label, bottom_text);
  lv_obj_set_style_text_font(*bottom_label, bottom_text_font, LV_STATE_DEFAULT);
  lv_obj_align(*bottom_label, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_grid_cell(bot_o, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_CONTENT, 1,
                       1);

  return grid;
}

lv_obj_t *lv_horizontal_pair_label(lv_obj_t *parent, lv_obj_t **main_l,
                                   const char *left_text,
                                   const lv_font_t *left_text_font,
                                   const char *right_text,
                                   const lv_font_t *right_text_font) {
  static lv_coord_t grid_col_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT,
                                      LV_GRID_TEMPLATE_LAST};
  static lv_coord_t grid_row_dsc[] = {LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};

  lv_obj_t *grid = lv_obj_create(parent);
  lv_obj_remove_style_all(grid);
  lv_obj_set_size(grid, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
  lv_obj_set_grid_dsc_array(grid, grid_col_dsc, grid_row_dsc);

  // left label
  *main_l = lv_label_create(grid);
  lv_label_set_text(*main_l, left_text);
  lv_obj_add_style(*main_l, &label_style, LV_PART_MAIN);
  lv_obj_set_style_text_font(*main_l, left_text_font, LV_STATE_DEFAULT);
  lv_obj_align(*main_l, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_grid_cell(*main_l, LV_GRID_ALIGN_CENTER, 0, 1,
                       LV_GRID_ALIGN_CENTER, 0, 1);

  // right label
  lv_obj_t *rx_o = lv_obj_create(
      grid); // inside an obj so I have better management of label positioning
  lv_obj_remove_style_all(rx_o);
  lv_obj_set_size(rx_o, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
  lv_obj_t *rx_l = lv_label_create(rx_o);
  lv_obj_add_style(rx_l, &label_style, LV_PART_MAIN);
  lv_label_set_text(rx_l, right_text);
  lv_obj_align(rx_l, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_style_text_font(rx_l, right_text_font, LV_STATE_DEFAULT);
  lv_obj_set_grid_cell(rx_o, LV_GRID_ALIGN_START, 1, 1, LV_GRID_ALIGN_START, 0,
                       1);

  return grid;
}

lv_obj_t *
lv_triple_label(lv_obj_t *parent, lv_obj_t **main_l, const char *left_text,
                const lv_font_t *left_text_font, const char *right_text,
                const lv_font_t *right_text_font, const char *bottom_text,
                const lv_font_t *bottom_text_font) {
  static lv_coord_t grid_col_dsc[] = {LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};
  static lv_coord_t grid_row_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT,
                                      LV_GRID_TEMPLATE_LAST};

  lv_obj_t *grid = lv_obj_create(parent);
  lv_obj_remove_style_all(grid);
  lv_obj_set_size(grid, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
  lv_obj_set_grid_dsc_array(grid, grid_col_dsc, grid_row_dsc);

  lv_obj_t *up_l = lv_horizontal_pair_label(
      grid, main_l, left_text, left_text_font, right_text, right_text_font);
  lv_obj_set_size(up_l, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
  lv_obj_set_grid_cell(up_l, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER,
                       0, 1);

  // bottom label
  lv_obj_t *bot_o = lv_obj_create(grid);
  lv_obj_remove_style_all(bot_o);
  lv_obj_set_size(bot_o, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
  lv_obj_t *bot_l = lv_label_create(bot_o);
  lv_obj_add_style(bot_l, &label_style, LV_PART_MAIN);
  lv_obj_set_style_pad_top(bot_l, 8, LV_PART_MAIN);
  lv_label_set_text(bot_l, bottom_text);
  lv_obj_align(bot_l, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_style_text_font(bot_l, bottom_text_font, LV_STATE_DEFAULT);
  lv_obj_set_grid_cell(bot_o, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_CONTENT, 1,
                       1);

  return grid;
}

lv_style_t bubble_small_style;
lv_style_t bubble_large_style;

char *notch_labels[NUM_TABS] = {"RACE", "CALIBRATE", "DEBUG", "TEST",
                                "SENSORS"};
lv_obj_t *create_notch(lv_obj_t *parent, tab_t TabId) {

  lv_obj_t *notch = lv_obj_create(parent);
  lv_obj_remove_style_all(notch);
  lv_obj_set_size(notch, 600, 100);

  static lv_coord_t notch_cols[] = {NOTCH_WIDTH / 6, NOTCH_WIDTH / 6,
                                    NOTCH_WIDTH / 3, NOTCH_WIDTH / 6,
                                    NOTCH_WIDTH / 6, LV_GRID_TEMPLATE_LAST};
  static lv_coord_t notch_rows[] = {NOTCH_HEIGHT, LV_GRID_TEMPLATE_LAST};

  lv_obj_t *notch_panel = lv_obj_create(notch);
  lv_obj_clear_flag(notch_panel, LV_OBJ_FLAG_SCROLLABLE);
  lv_obj_set_size(notch_panel, NOTCH_WIDTH, NOTCH_HEIGHT);
  lv_obj_add_style(notch_panel, &grid_style, 0);
  lv_obj_set_style_base_dir(notch_panel, LV_BASE_DIR_LTR, 0);
  lv_obj_set_grid_dsc_array(notch_panel, notch_cols, notch_rows);

  // center item
  lv_obj_t *center = lv_bar_create(notch_panel);
  lv_obj_add_style(center, &bubble_large_style, LV_PART_MAIN);
  lv_obj_set_grid_cell(center, LV_GRID_ALIGN_CENTER, 2, 1, LV_GRID_ALIGN_START,
                       0, 1);

  lv_obj_t *center_o = lv_obj_create(notch_panel);
  lv_obj_remove_style_all(center_o);
  // lv_obj_set_size(center_o, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
  lv_obj_t *center_l = lv_label_create(center_o);
  lv_obj_add_style(center_l, &label_style, LV_PART_MAIN);
  lv_label_set_text(center_l, notch_labels[(TabId++) % NUM_TABS]);
  lv_obj_set_style_text_font(center_l, &lv_font_inter_bold_22, LV_PART_MAIN);
  lv_obj_align(center_l, LV_ALIGN_TOP_MID, 0, NOTCH_BAR_HEIGHT_L + 5);
  lv_obj_set_size(center_l, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
  lv_obj_set_grid_cell(center_o, LV_GRID_ALIGN_CENTER, 2, 1,
                       LV_GRID_ALIGN_STRETCH, 0, 1);

  //  right item
  lv_obj_t *right = lv_bar_create(notch_panel);
  lv_obj_add_style(right, &bubble_small_style, LV_PART_MAIN);
  // lv_obj_set_style_pad_bottom(right, 15, LV_PART_MAIN);
  lv_obj_set_grid_cell(right, LV_GRID_ALIGN_CENTER, 3, 1, LV_GRID_ALIGN_START,
                       0, 1);

  lv_obj_t *right_o = lv_obj_create(notch_panel);
  lv_obj_remove_style_all(right_o);
  // lv_obj_set_size(right_o, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
  lv_obj_t *right_l = lv_label_create(right_o);
  lv_obj_add_style(right_l, &label_style, LV_PART_MAIN);
  lv_label_set_text(right_l, notch_labels[(TabId++) % NUM_TABS]);
  lv_obj_set_style_text_font(right_l, &lv_font_inter_bold_14, LV_PART_MAIN);
  lv_obj_align(right_l, LV_ALIGN_TOP_MID, 0, NOTCH_BAR_HEIGHT_S + 5);
  lv_obj_set_grid_cell(right_o, LV_GRID_ALIGN_CENTER, 3, 1,
                       LV_GRID_ALIGN_STRETCH, 0, 1);

  // most right item
  lv_obj_t *most_right = lv_bar_create(notch_panel);
  lv_obj_add_style(most_right, &bubble_small_style, LV_PART_MAIN);
  lv_obj_set_grid_cell(most_right, LV_GRID_ALIGN_CENTER, 4, 1,
                       LV_GRID_ALIGN_START, 0, 1);

  lv_obj_t *most_right_o = lv_obj_create(notch_panel);
  lv_obj_remove_style_all(most_right_o);
  // lv_obj_set_size(most_right_o, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
  lv_obj_t *most_right_l = lv_label_create(most_right_o);
  lv_obj_add_style(most_right_l, &label_style, LV_PART_MAIN);
  lv_label_set_text(most_right_l, notch_labels[(TabId++) % NUM_TABS]);
  lv_obj_align(most_right_l, LV_ALIGN_TOP_MID, 0, NOTCH_BAR_HEIGHT_S + 5);
  lv_obj_set_style_text_font(most_right_l, &lv_font_inter_bold_14,
                             LV_PART_MAIN);
  lv_obj_set_grid_cell(most_right_o, LV_GRID_ALIGN_CENTER, 4, 1,
                       LV_GRID_ALIGN_STRETCH, 0, 1);

  // most left item
  lv_obj_t *most_left = lv_bar_create(notch_panel);
  lv_obj_add_style(most_left, &bubble_small_style, LV_PART_MAIN);
  lv_obj_set_grid_cell(most_left, LV_GRID_ALIGN_CENTER, 0, 1,
                       LV_GRID_ALIGN_START, 0, 1);

  lv_obj_t *most_left_o = lv_obj_create(notch_panel);
  lv_obj_remove_style_all(most_left_o);
  // lv_obj_set_size(most_left_o, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
  lv_obj_t *most_left_l = lv_label_create(most_left_o);
  lv_obj_add_style(most_left_l, &label_style, LV_PART_MAIN);
  lv_label_set_text(most_left_l, notch_labels[(TabId++) % NUM_TABS]);
  lv_obj_set_style_text_font(most_left_l, &lv_font_inter_bold_14, LV_PART_MAIN);
  lv_obj_align(most_left_l, LV_ALIGN_TOP_MID, 0, NOTCH_BAR_HEIGHT_S + 5);
  lv_obj_set_grid_cell(most_left_o, LV_GRID_ALIGN_CENTER, 0, 1,
                       LV_GRID_ALIGN_STRETCH, 0, 1);

  // left item
  lv_obj_t *left = lv_bar_create(notch_panel);
  lv_obj_add_style(left, &bubble_small_style, LV_PART_MAIN);
  lv_obj_set_grid_cell(left, LV_GRID_ALIGN_CENTER, 1, 1, LV_GRID_ALIGN_START, 0,
                       1);

  lv_obj_t *left_o = lv_obj_create(notch_panel);
  lv_obj_remove_style_all(left_o);
  // lv_obj_set_size(left_o, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
  lv_obj_t *left_l = lv_label_create(left_o);
  lv_obj_add_style(left_l, &label_style, LV_PART_MAIN);
  lv_label_set_text(left_l, notch_labels[(TabId++) % NUM_TABS]);
  lv_obj_set_style_text_font(left_l, &lv_font_inter_bold_14, LV_PART_MAIN);
  lv_obj_align(left_l, LV_ALIGN_TOP_MID, 0, NOTCH_BAR_HEIGHT_S + 5);
  lv_obj_set_grid_cell(left_o, LV_GRID_ALIGN_CENTER, 1, 1,
                       LV_GRID_ALIGN_STRETCH, 0, 1);

  return notch;
}

void init_custom_styles(void) {

  /* GRID_STYLE */
  lv_style_init(&grid_style);
  lv_style_set_pad_all(&grid_style, 0);
  lv_style_set_pad_bottom(&grid_style, 0);
  lv_style_set_pad_column(&grid_style, 0);
  lv_style_set_pad_right(&grid_style, 0);
  lv_style_set_pad_left(&grid_style, 0);
  lv_style_set_pad_top(&grid_style, 0);
  lv_style_set_pad_row(&grid_style, 0);
  lv_style_set_bg_color(&grid_style, lv_color_hex(COLOR_PRIMARY_HEX));
  lv_style_set_bg_opa(&grid_style, LV_OPA_COVER);
  lv_style_set_border_opa(&grid_style, LV_OPA_COVER);
  lv_style_set_outline_width(&grid_style, 0);
  lv_style_set_border_width(&grid_style, 0);
  lv_style_set_border_opa(&grid_style,
                          0); // to remove borders, keeping bc useful

  /* LABEL_STYLE */
  lv_style_init(&label_style);
  lv_style_set_base_dir(&label_style, LV_BASE_DIR_LTR);
  lv_style_set_bg_opa(&label_style, LV_OPA_TRANSP);
  lv_style_set_text_color(&label_style, lv_color_hex(COLOR_TERTIARY_HEX));
  lv_style_set_text_align(&label_style, LV_TEXT_ALIGN_CENTER);

  /* SIDE_DATA_PANELS_STYLE */
  lv_style_init(&box_panels_style);
  lv_style_set_pad_all(&box_panels_style, 0);
  lv_style_set_pad_bottom(&box_panels_style, 0);
  lv_style_set_pad_column(&box_panels_style, 0);
  lv_style_set_pad_top(&box_panels_style, 0);
  lv_style_set_pad_row(&box_panels_style, 0);
  lv_style_set_bg_opa(&box_panels_style, LV_OPA_TRANSP);
  lv_style_set_border_color(
      &box_panels_style,
      lv_color_hex(
          COLOR_SECONDARY_HEX)); // to remove borders, keeping bc useful
  lv_style_set_border_width(&box_panels_style, 3);
  lv_style_set_radius(&box_panels_style, 10);

  /* NOTCH STYLES */
  lv_style_init(&bubble_small_style);
  lv_style_set_width(&bubble_small_style, NOTCH_BAR_WIDTH_S);
  lv_style_set_height(&bubble_small_style, NOTCH_BAR_HEIGHT_S);
  lv_style_set_bg_color(&bubble_small_style, lv_color_hex(COLOR_TERTIARY_HEX));
  lv_style_set_bg_opa(&bubble_small_style, LV_OPA_COVER);
  lv_style_set_radius(&bubble_small_style, 4);

  lv_style_init(&bubble_large_style);
  lv_style_set_width(&bubble_large_style, NOTCH_BAR_WIDTH_L);
  lv_style_set_height(&bubble_large_style, NOTCH_BAR_HEIGHT_L);
  lv_style_set_bg_color(&bubble_large_style, lv_color_hex(COLOR_TERTIARY_HEX));
  lv_style_set_bg_opa(&bubble_large_style, LV_OPA_COVER);
  lv_style_set_radius(&bubble_large_style, 9);
}