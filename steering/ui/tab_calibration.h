#ifndef TAB_CALIBRATION_H
#define TAB_CALIBRATION_H

#include "lvgl.h"
#include "utils.h"
#include <stdio.h>
#include "../steering.h"


#define CALIBR_TAB_TOP_BAR_HEIGHT 65
#define CALIBR_TAB_TOP_BAR_WIDTH SCREEN_WIDTH
#define CALIBR_TAB_CENTER_OPTIONS_HEIGHT 230
#define CALIBR_TAB_CENTER_OPTIONS_WIDTH SCREEN_WIDTH
#define CALIBR_TAB_BUTTONS_BAR_HEIGHT 55
#define CALIBR_TAB_BUTTONS_BAR_WIDTH SCREEN_WIDTH
#define CALIBR_TAB_TOOL_HEIGHT 130
#define CALIBR_TAB_TOOL_WIDTH SCREEN_WIDTH


#define BOX_SIDE_PADDING 40

#define BOX_HEIGHT 200
#define BOX_WIDTH 200

#define BUTTON_WIDTH BOX_WIDTH
#define BUTTON_HEIGHT 45

void tab_calibration(lv_obj_t *parent);

void shift_box_focus(shift direction);

void init_calibration_tab_styles(void);

#endif