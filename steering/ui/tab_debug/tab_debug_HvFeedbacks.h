#ifndef TAB_DEBUG_HVFEEDBACKS_H
#define TAB_DEBUG_HVFEEDBACKS_H

#include "lvgl.h"
#include "../utils.h"
#include "../../steering.h"

#define CENTRAL_PANEL_WIDTH 660
#define BOTTOM_BAR_HEIGHT 120
#define TOP_BAR_HEIGHT 55
#define DATA_PANEL_HEIGHT 430
#define ROW_PADDING 20
#define COLUMN_PADDING 20

void tab_debug_HvFeedbacks(lv_obj_t *parent);
void init_debug_styles(void);


#endif // TAB_DEBUG_HVFEEDBACKS_H