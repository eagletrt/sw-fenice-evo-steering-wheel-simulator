#ifndef TAB_DEBUG_h
#define TAB_DEBUG_H

#include "lvgl.h"
#include "utils.h"
#include "../steering.h"

#define TOP_BAR_HEIGHT 55
#define DATA_PANEL_HEIGHT 425
#define DATA_TITLE_PANEL_HEIGHT 45
#define DATA_ERRORS_PANEL_HEIGHT 340

// ERROR_BOX_WIDTH -> STRECHT GRID
#define ERROR_BOX_HEIGHT 50

#define ROW_PADDING 20
#define COLUMN_PADDING 20


void tab_debug(lv_obj_t *parent);
void init_debug_styles(void);


#endif // TAB_DEBUG_HVFEEDBACKS_H