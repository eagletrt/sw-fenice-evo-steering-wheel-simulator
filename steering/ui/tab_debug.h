#ifndef TAB_DEBUG_H
#define TAB_DEBUG_H

#include "lvgl.h"
#include "utils.h"

#define CENTRAL_PANEL_WIDTH 660
#define BOTTOM_BAR_HEIGHT 120
#define TOP_BAR_HEIGHT 50
#define DATA_PANEL_HEIGHT 430
#define ROW_PADDING 20
#define COLUMN_PADDING 20

#define DATA_LEFT_WIDTH 185
#define DATA_RIGHT_WIDTH 185
#define DATA_CENTER_WIDTH 290

void tab_debug(lv_obj_t *parent);

void init_sensors_styles(void);

#endif // TAB_DEBUG_H