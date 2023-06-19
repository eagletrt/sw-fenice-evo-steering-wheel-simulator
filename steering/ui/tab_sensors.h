#ifndef TAB_SENSORS_H
#define TAB_SENSORS_H

#include "lvgl.h"
#include "utils.h"
#include "../steering.h"

#define TAB_SENSORS_CENTRAL_PANEL_WIDTH 660
#define BOTTOM_BAR_HEIGHT 120
#define TOP_BAR_HEIGHT 55
#define DATA_PANEL_HEIGHT 425
#define ROW_PADDING 20
#define COLUMN_PADDING 20

#define DATA_LEFT_WIDTH 185
#define DATA_RIGHT_WIDTH 185
#define DATA_CENTER_WIDTH 290

void tab_sensors(lv_obj_t *parent);

void init_sensors_styles(void);

#endif // TAB_SENSORS_H