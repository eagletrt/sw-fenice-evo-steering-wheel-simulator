#ifndef TAB_CALIBRATION_H
#define TAB_CALIBRATION_H

#include "lvgl.h"
#include "utils.h"
#include <stdio.h>

#define TOP_BAR_HEIGHT 65
#define TOP_BAR_WIDTH SCREEN_WIDTH
#define CENTER_OPTIONS_HEIGHT 230
#define CENTER_OPTIONS_WIDTH SCREEN_WIDTH
#define BUTTONS_BAR_HEIGHT 55
#define BUTTONS_BAR_WIDTH SCREEN_WIDTH
#define BOTTOM_LABELS_HEIGHT 30
#define BOTTOM_LABELS_WIDTH SCREEN_WIDTH 

#define BOX_SIDE_PADDING 40

#define BOX_HEIGHT 200
#define BOX_WIDTH 200

#define BUTTON_WIDTH BOX_WIDTH
#define BUTTON_HEIGHT 45

typedef enum{
 LEFT,
 RIGHT
}shift;

void tab_calibration(lv_obj_t *parent);

void shift_box_focus(shift direction);

//uint8_t get_box_selected(); old calibration

void init_calibration_tab_styles();

#endif