#ifndef TAB_RACING_H
#define TAB_RACING_H

#include "lvgl.h"
#include "utils.h"

/* RACING TAB */
#define RACING_TAB_SIDE_BAR_WIDTH 70
#define RACING_TAB_CENTRAL_PANEL_WIDTH 660
#define RACING_TAB_BOTTOM_BAR_HEIGHT 80
#define RACING_TAB_TOP_BAR_HEIGHT 80
#define RACING_TAB_DATA_PANEL_HEIGHT 320
#define RACING_TAB_DATA_LEFT_WIDTH 185
#define RACING_TAB_DATA_RIGHT_WIDTH 185
#define RACING_TAB_DATA_CENTER_WIDTH 290

void tab_racing(lv_obj_t *parent);

void init_racing_style(void);
void lv_custom_meter(lv_obj_t *custom_meter);
void custom_side_bar(lv_obj_t *bar);

#endif // TAB_RACING_H