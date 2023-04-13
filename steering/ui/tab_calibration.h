#ifndef TAB_CALIBRATION_H
#define TAB_CALIBRATION_H

#include "lvgl.h"
#include "utils.h"
#include "steer_calibration.h"
#include <stdio.h>

#define TOP_BAR_HEIGHT 70
#define TOP_BAR_WIDTH SCREEN_WIDTH
#define TOP_LABELS_HEIGHT 30
#define TOP_LABELS_WIDTH SCREEN_WIDTH
#define CENTER_OPTIONS_HEIGHT 270
#define CENTER_OPTIONS_WIDTH SCREEN_WIDTH
#define BOTTOM_LABELS_HEIGHT 30
#define BOTTOM_LABELS_WIDTH SCREEN_WIDTH 

#define BOX_HEIGHT 200
#define BOX_WIDTH 200

typedef enum{
 LEFT,
 RIGHT
}shift;

static uint8_t curr_focus = 1;

void tab_calibration(lv_obj_t *parent);

void shift_box_focus(shift direction);
uint8_t get_box_selected();

static lv_style_t info_label_style;
static lv_style_t box_style;
static lv_style_t box_label_style;

static void init_calibration_tab_styles();

#endif