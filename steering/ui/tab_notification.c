#include "tab_notification.h"

extern steering_t steering;

void tab_notification_screen_create(lv_obj_t *notification_screen) {

  lv_obj_t *notification_background = lv_obj_create(notification_screen);
  lv_obj_remove_style_all(notification_background);
  lv_obj_set_style_bg_color(notification_background, lv_color_hex(COLOR_SECONDARY_HEX), LV_PART_MAIN);
  lv_obj_set_size(notification_background, SCREEN_WIDTH, SCREEN_HEIGHT);
  lv_obj_set_style_bg_opa(notification_background, LV_OPA_COVER, LV_PART_MAIN);
  lv_obj_align(notification_background, LV_ALIGN_CENTER, 0, 0);

  
  steering.notification_screen_label = lv_label_create(notification_background);
  lv_obj_remove_style_all(steering.notification_screen_label);

  lv_obj_add_style(steering.notification_screen_label, &label_style, LV_PART_MAIN);

  lv_obj_set_style_text_color(steering.notification_screen_label,
                              lv_color_hex(COLOR_PRIMARY_HEX), LV_PART_MAIN);
  lv_obj_set_style_text_font(steering.notification_screen_label,
                             &lv_font_inter_bold_70, LV_PART_MAIN);

  lv_obj_set_style_opa(steering.notification_screen_label, LV_OPA_COVER,
                       LV_PART_MAIN);
  lv_obj_align(steering.notification_screen_label, LV_ALIGN_CENTER, 0, 0);

}
