#include "tab_manager.h"

lv_obj_t *tab_racing_ptr;
lv_obj_t *tab_sensors_ptr;
lv_obj_t *tab_calibration_ptr;
lv_obj_t *tab_track_test_ptr;
lv_obj_t *tab_debug_ptr;
lv_obj_t *notif_screen;
lv_timer_t *notification_timer;
lv_group_t *g;

tab_t current_tab;

void tab_manager(void) {
  init_custom_styles();

  tab_racing_ptr = lv_obj_create(NULL);
  tab_sensors_ptr = lv_obj_create(NULL);
  tab_calibration_ptr = lv_obj_create(NULL);
  tab_track_test_ptr = lv_obj_create(NULL);
  tab_debug_ptr = lv_obj_create(NULL);
  notif_screen = lv_obj_create(NULL);

  lv_group_add_obj(g, tab_racing_ptr);
  lv_group_add_obj(g, tab_sensors_ptr);
  lv_group_add_obj(g, tab_calibration_ptr);
  lv_group_add_obj(g, tab_debug_ptr);
  lv_group_add_obj(g, tab_track_test_ptr);
  lv_group_add_obj(g, notif_screen);

  tab_racing(tab_racing_ptr);
  tab_sensors(tab_sensors_ptr);
  tab_calibration(tab_calibration_ptr);
  tab_debug(tab_debug_ptr);
  tab_track_test(tab_track_test_ptr);
  tab_notification_screen_create(notif_screen);

  lv_scr_load(tab_racing_ptr);
  current_tab = TAB_RACING;
}

void load_current_tab(void) {
  switch (current_tab) {
  case TAB_RACING:
    lv_scr_load(tab_racing_ptr);
    break;
  case TAB_CALIBRATION:
    lv_scr_load(tab_calibration_ptr);
    break;
  case TAB_DEBUG:
    lv_scr_load(tab_debug_ptr);
    break;
  case TAB_TRACK_TEST:
    lv_scr_load(tab_track_test_ptr);
    break;
  case TAB_SENSORS:
    lv_scr_load(tab_sensors_ptr);
    break;
  default:
    break;
  }
}

void change_tab(bool forward) {

  if (forward)
    current_tab = (current_tab + 1) % NUM_TABS;
  else
    current_tab = (current_tab - 1 + NUM_TABS) % NUM_TABS;

  load_current_tab();
}

void restore_previous_screen(lv_timer_t *timer) { load_current_tab(); }

void display_notification(const char *label_content, uint32_t timeout_ms) {
  notification_timer =
      lv_timer_create(restore_previous_screen, timeout_ms, NULL);
  lv_timer_set_repeat_count(notification_timer, 1);
  lv_label_set_text(steering.notification_screen_label, label_content);
  lv_scr_load(notif_screen);
  lv_timer_reset(notification_timer);
}
