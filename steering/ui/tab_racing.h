#ifndef TAB_RACING_H
#define TAB_RACING_H

#include "lvgl.h"
#include "utils.h"

/* RACING TAB */
#define SIDE_BAR_WIDTH 70
#define CENTRAL_PANEL_WIDTH 660
#define BOTTOM_BAR_HEIGHT 80
#define TOP_BAR_HEIGHT 80
#define DATA_PANEL_HEIGHT 320
#define DATA_LEFT_WIDTH 185
#define DATA_RIGHT_WIDTH 185
#define DATA_CENTER_WIDTH 290

void tab_racing(lv_obj_t *parent);

void init_racing_style();
void lv_custom_meter(lv_obj_t *custom_meter);
void custom_side_bar(lv_obj_t *bar);

#endif // TAB_RACING_H