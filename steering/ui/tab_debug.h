#ifndef TAB_DEBUG_h
#define TAB_DEBUG_H

#include "lvgl.h"
#include "utils.h"
#include "../steering.h"

#define TAB_DEBUG_TOP_BAR_HEIGHT 55
#define TAB_DEBUG_DATA_PANEL_HEIGHT 425
#define TAB_DEBUG_DATA_PANEL_WIDTH 780
#define TAB_DEBUG_DATA_TITLE_HEIGHT 70


#define ERROR_BOX_HEIGHT 50

#define TAB_DEBUG_ROW_PADDING 10
#define TAB_DEBUG_COLUMN_PADDING 10

#define TAB_DEBUG_CELL_HEIGHT 40
#define TAB_DEBUG_CELL_WIDTH  180


#define NUM_TYPE_ERRORS 4

typedef enum{
 HV_FEEDBACKS,
 HV_ERRORS,
 DAS_ERRORS,
 LV_ERRORS
} ErrorTabID;

void tab_debug(lv_obj_t *parent);
void init_debug_styles(void);

lv_obj_t* cell_create(lv_obj_t* parent, const char* text, uint8_t pos_row, uint8_t pos_col, lv_style_t* style );

void change_errors_view(shift direction);

#endif // TAB_DEBUG_HVFEEDBACKS_H