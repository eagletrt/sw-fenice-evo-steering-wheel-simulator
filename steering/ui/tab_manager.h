#ifndef TAB_MANAGER_H
#define TAB_MANAGER_H

#include "lvgl.h"
#include "utils.h"
#include "tab_racing.h"
#include "tab_sensors.h"
#include "tab_track_test.h"
#include "tab_debug.h"
#include "../steering.h"
#include "tab_calibration.h"
#ifndef STM32H723xx
#include "lv_drivers/indev/keyboard.h"
#endif

#define N_SCREENS 5
extern lv_group_t * g;

void tab_manager(void);
void change_tab(bool forward);
void notification_screen(lv_timer_t * timer);

#endif