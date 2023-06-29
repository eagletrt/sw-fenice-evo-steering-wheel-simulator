#ifndef TAB_MANAGER_H
#define TAB_MANAGER_H

#include "../steering.h"
#include "lvgl.h"
#include "tab_calibration.h"
#include "tab_debug.h"
#include "tab_notification.h"
#include "tab_racing.h"
#include "tab_sensors.h"
#include "tab_track_test.h"
#include "utils.h"
#ifndef STM32H723xx
#include "lv_drivers/indev/keyboard.h"
#endif

extern lv_group_t *g;

void tab_manager(void);
void change_tab(bool);
void load_current_tab(void);
void restore_previous_screen(lv_timer_t *timer);
void display_notification(const char *, uint32_t);

#endif