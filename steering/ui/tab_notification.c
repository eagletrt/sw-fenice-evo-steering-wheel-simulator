#include "tab_notification.h"

extern steering_t steering;

void tab_notification_screen_create(lv_obj_t *notification_screen) {

  lv_obj_t *info = lv_label_create(notification_screen);
  lv_obj_add_style(info, &label_style, LV_PART_MAIN);
  lv_obj_set_style_text_color(info, lv_color_hex(COLOR_PRIMARY_HEX),
                              LV_PART_MAIN);
  lv_obj_set_style_text_font(info, &lv_font_inter_bold_70, LV_PART_MAIN);
  lv_label_set_text_fmt(info, "Notification SCREEN");

  steering.notification_screen_label = info;
  lv_obj_set_style_opa(info, LV_OPA_COVER, LV_PART_MAIN);
  lv_obj_align(info, LV_ALIGN_CENTER, 0, 0);
}
