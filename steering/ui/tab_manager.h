#ifndef TAB_MANAGER_H
#define TAB_MANAGER_H

#include "lvgl.h"
#include "utils.h"
#include "tab_racing.h"
#include "tab_debug.h"
#include "tab_calibration.h"
#include "lv_drivers/indev/keyboard.h"

#define N_SCREENS 3
extern lv_group_t * g;

typedef enum{
 FORWARD,
 BACKWARD
}scroll;

void tab_manager(void);
void change_tab(scroll direction);


#endif