
/**
 * @file main
 *
 */

/*********************
 *      INCLUDES
 *********************/
#define _DEFAULT_SOURCE /* needed for usleep() */
#include <stdlib.h>
#include <unistd.h>
#define SDL_MAIN_HANDLED /*To fix SDL's "undefined reference to WinMain" issue*/
#include <SDL2/SDL.h>
#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lv_examples/lv_demo.h"
#include "lv_drivers/display/monitor.h"
#include "lv_drivers/indev/mouse.h"
#include "lv_drivers/indev/keyboard.h"
#include "lv_drivers/indev/mousewheel.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void hal_init(void);
static int tick_thread(void *data);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/*********************
 *      DEFINES
 *********************/
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 480

#define CENTER_PANEL_WIDTH SCREEN_WIDTH * 82.5/100
#define CENTER_PANEL_HEIGHT SCREEN_HEIGHT

#define SIDE_PANEL_WIDTH 70
#define SIDE_PANEL_HEIGHT SCREEN_HEIGHT

#define FOCUS_PANEL_WIDTH CENTER_PANEL_WIDTH
#define FOCUS_PANEL_HEIGHT CENTER_PANEL_HEIGHT * 56.25/100

#define TOP_PANEL_WIDTH CENTER_PANEL_WIDTH
#define TOP_PANEL_HEIGHT CENTER_PANEL_HEIGHT * 21.875/100  // (100 - 56.25) / 2

#define BOTTOM_PANEL_WIDTH CENTER_PANEL_WIDTH
#define BOTTOM_PANEL_HEIGHT CENTER_PANEL_HEIGHT * 21.875/100

#define TIMING_PANEL_WIDTH FOCUS_PANEL_WIDTH * 25.0/100
#define TIMING_PANEL_HEIGHT FOCUS_PANEL_HEIGHT

#define DATA_PANEL_WIDTH FOCUS_PANEL_WIDTH * 25.0/100
#define DATA_PANEL_HEIGHT FOCUS_PANEL_HEIGHT

#define SPEEDOMETER_PANEL_WIDTH FOCUS_PANEL_WIDTH * 50.0/100
#define SPEEDOMETER_PANEL_HEIGHT FOCUS_PANEL_HEIGHT

/**********************
 *      TYPEDEFS
 **********************/

/**********************FOCUS_PANEL_WIDTH * 25.0/100
 *      VARIABLES
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

void gridConstructions(){

  lv_obj_t *tab_racing = lv_scr_act();
  lv_obj_set_layout(tab_racing, LV_LAYOUT_GRID);
  lv_obj_set_style_pad_column(tab_racing, 0, 0);
  lv_obj_set_style_pad_row(tab_racing, 0, 0);
  lv_obj_clear_flag(tab_racing, LV_OBJ_FLAG_SCROLLABLE);

  lv_obj_t *panel_lv = lv_obj_create(tab_racing);
  lv_obj_set_layout(panel_lv, LV_LAYOUT_GRID);
  lv_obj_set_scrollbar_mode(panel_lv, LV_SCROLLBAR_MODE_OFF);
  lv_obj_set_style_pad_column(panel_lv, 0, 0);
  lv_obj_set_style_pad_row(panel_lv, 0, 0);
  lv_obj_clear_flag(panel_lv, LV_OBJ_FLAG_SCROLLABLE);

  lv_obj_t *panel_hv = lv_obj_create(tab_racing);
  lv_obj_set_style_pad_column(panel_hv, 0, 0);
  lv_obj_set_style_pad_row(panel_hv, 0, 0);
  lv_obj_clear_flag(panel_hv, LV_OBJ_FLAG_SCROLLABLE);
  lv_obj_set_layout(panel_hv, LV_LAYOUT_GRID);

  lv_obj_t *panel_center = lv_obj_create(tab_racing);
  lv_obj_set_style_pad_column(panel_center, 0, 0);
  lv_obj_set_style_pad_row(panel_center, 0, 0);
  lv_obj_clear_flag(panel_center, LV_OBJ_FLAG_SCROLLABLE);
  lv_obj_set_layout(panel_center, LV_LAYOUT_GRID);

  lv_obj_t *panel_top_tab = lv_obj_create(panel_center);
  lv_obj_set_layout(panel_center, LV_LAYOUT_GRID);

  lv_obj_t *panel_focus = lv_obj_create(panel_center);
  lv_obj_set_layout(panel_center, LV_LAYOUT_GRID);

  lv_obj_t *panel_bottom_bar = lv_obj_create(panel_center);
  lv_obj_set_layout(panel_center, LV_LAYOUT_GRID);

  lv_obj_t *panel_timing = lv_obj_create(panel_focus);
  lv_obj_set_layout(panel_center, LV_LAYOUT_GRID);  

  lv_obj_t *panel_speedometer = lv_obj_create(panel_focus);
  lv_obj_set_layout(panel_center, LV_LAYOUT_GRID);

  lv_obj_t *panel_data = lv_obj_create(panel_focus);
  lv_obj_set_layout(panel_center, LV_LAYOUT_GRID);
  

  // ho provato ad inserirlo nelle celle per vedere come fossero venute le dimensioni
  lv_obj_t *color1 = lv_obj_create(panel_lv);
  lv_obj_set_style_bg_color(color1, lv_palette_main(LV_PALETTE_GREEN), LV_STATE_DEFAULT);
 
  /* main panel */                         // put width
  static lv_coord_t grid_main_col_dsc[] = {SIDE_PANEL_WIDTH, CENTER_PANEL_WIDTH, SIDE_PANEL_WIDTH, LV_GRID_TEMPLATE_LAST};
  static lv_coord_t grid_main_row_dsc[] = {SCREEN_HEIGHT, LV_GRID_TEMPLATE_LAST};

  /* center panel grid */
  static lv_coord_t center_main_col_dsc[] = { CENTER_PANEL_HEIGHT, LV_GRID_TEMPLATE_LAST};
  static lv_coord_t center_main_row_dsc[] = { TOP_PANEL_HEIGHT, FOCUS_PANEL_HEIGHT, BOTTOM_PANEL_HEIGHT, LV_GRID_TEMPLATE_LAST};

  /* side main panel grid */
  static lv_coord_t side_main_col_dsc[] = { SIDE_PANEL_WIDTH, LV_GRID_TEMPLATE_LAST};
  static lv_coord_t side_main_row_dsc[] = { SIDE_PANEL_HEIGHT * 12/100, SIDE_PANEL_HEIGHT * 76/100, SIDE_PANEL_HEIGHT * 12/100, LV_GRID_TEMPLATE_LAST};
                                                          

  /* focus panel grid */
  static lv_coord_t focus_panel_col_dsc[] = { TIMING_PANEL_WIDTH, SPEEDOMETER_PANEL_WIDTH, DATA_PANEL_WIDTH, LV_GRID_TEMPLATE_LAST};
  static lv_coord_t focus_panel_row_dsc[] = { FOCUS_PANEL_HEIGHT, LV_GRID_TEMPLATE_LAST};
  
  /* timing panel grid */
  static lv_coord_t timing_panel_col_dsc[] = { TIMING_PANEL_WIDTH, LV_GRID_TEMPLATE_LAST};
  static lv_coord_t timing_panel_row_dsc[] = { TIMING_PANEL_HEIGHT/3, TIMING_PANEL_HEIGHT/3, TIMING_PANEL_HEIGHT/3, LV_GRID_TEMPLATE_LAST};

  /* speedometer panel grid */
  static lv_coord_t speedometer_panel_col_dsc[] = { SPEEDOMETER_PANEL_WIDTH, LV_GRID_TEMPLATE_LAST};
  static lv_coord_t speedometer_panel_row_dsc[] = { SPEEDOMETER_PANEL_HEIGHT * 12.96/100, SPEEDOMETER_PANEL_HEIGHT * 72.23/100, SPEEDOMETER_PANEL_HEIGHT * 14.81/100, LV_GRID_TEMPLATE_LAST};

  /* data panel grid */
  static lv_coord_t data_panel_col_dsc[] = { DATA_PANEL_WIDTH * 0.5, DATA_PANEL_WIDTH * 0.5, LV_GRID_TEMPLATE_LAST};
  static lv_coord_t data_panel_row_dsc[] = { DATA_PANEL_HEIGHT * 0.33, DATA_PANEL_HEIGHT * 0.33, DATA_PANEL_HEIGHT * 0.33, LV_GRID_TEMPLATE_LAST};

  lv_obj_set_grid_dsc_array(tab_racing, grid_main_col_dsc, grid_main_row_dsc);
  lv_obj_set_grid_cell(panel_lv, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_STRETCH, 0, 1);
  lv_obj_set_grid_cell(panel_center, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_STRETCH, 0, 1);
  lv_obj_set_grid_cell(panel_hv, LV_GRID_ALIGN_STRETCH, 2, 1, LV_GRID_ALIGN_STRETCH, 0, 1);

  lv_obj_set_grid_dsc_array(panel_lv, side_main_col_dsc, side_main_row_dsc);
  lv_obj_set_grid_cell(color1, LV_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 0, 1);
  lv_obj_set_size(color1, side_main_col_dsc[0], side_main_row_dsc[0]);
  // add obj to panel_lv

  lv_obj_set_grid_dsc_array(panel_hv, side_main_col_dsc, side_main_row_dsc);
  // add obj to panel_hv

  lv_obj_set_grid_dsc_array(panel_center, center_main_col_dsc, center_main_row_dsc);
  lv_obj_set_grid_cell(panel_top_tab, LV_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 0, 0);
  lv_obj_set_grid_cell(panel_focus, LV_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 1, 0);
  lv_obj_set_grid_cell(panel_bottom_bar, LV_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 2, 0);

  lv_obj_set_grid_dsc_array(panel_focus, focus_panel_col_dsc, focus_panel_row_dsc);
  lv_obj_set_grid_cell(panel_timing, LV_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 0, 1);
  lv_obj_set_grid_cell(panel_speedometer, LV_ALIGN_CENTER, 1, 1, LV_GRID_ALIGN_CENTER, 0, 1);
  lv_obj_set_grid_cell(panel_data, LV_ALIGN_CENTER, 2, 1, LV_GRID_ALIGN_CENTER, 0, 1);

  lv_obj_set_grid_dsc_array(panel_timing, timing_panel_col_dsc, timing_panel_row_dsc);
  // add obj to panel_timing

  lv_obj_set_grid_dsc_array(panel_speedometer, speedometer_panel_col_dsc, speedometer_panel_row_dsc);
  //lv_obj_set_height(color1, speedometer_panel_row_dsc[1]);
  // add obj to panel_speedometer

  lv_obj_set_grid_dsc_array(panel_data, data_panel_col_dsc, data_panel_row_dsc);
  // add obj to panel_data


  /*
  lv_obj_set_grid_cell(color1, LV_GRID_ALIGN_CENTER, 1, 1, LV_GRID_ALIGN_CENTER, 0, 1);
  lv_obj_set_width(color1, grid_main_col_dsc[1]);
  lv_obj_set_height(color1, grid_main_row_dsc[0]);
  */

}

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

int main(int argc, char **argv)
{
  (void)argc; /*Unused*/
  (void)argv; /*Unused*/

  /*Initialize LVGL*/
  lv_init();

  /*Initialize the HAL (display, input devices, tick) for LVGL*/
  hal_init();

//  lv_example_switch_1();
//  lv_example_calendar_1();
//  lv_example_btnmatrix_2();
//  lv_example_checkbox_1();
//  lv_example_colorwheel_1();
//  lv_example_chart_6();
//  lv_example_table_2();
//  lv_example_scroll_2();
//  lv_example_textarea_1();
//  lv_example_msgbox_1();
//  lv_example_dropdown_2();
//  lv_example_btn_1();
//  lv_example_scroll_1();
//  lv_example_tabview_1();
//  lv_example_tabview_1();
//  lv_example_flex_3();
//  lv_example_label_1()

// lv_demo_widgets();

//  lv_demo_keypad_encoder();
//  lv_demo_benchmark();
//  lv_demo_stress();
//  lv_demo_music();

gridConstructions();

  while(1) {
    /* Periodically call the lv_task handler.
     * It could be done in a timer interrupt or an OS task too.*/
    lv_timer_handler();
    usleep(5 * 1000);
  }

  return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the LVGL graphics
 * library
 */
static void hal_init(void)
{
  /* Use the 'monitor' driver which creates window on PC's monitor to simulate a display*/
  monitor_init();
  /* Tick init.
   * You have to call 'lv_tick_inc()' in periodically to inform LittelvGL about
   * how much time were elapsed Create an SDL thread to do this*/
  SDL_CreateThread(tick_thread, "tick", NULL);

  /*Create a display buffer*/
  static lv_disp_draw_buf_t disp_buf1;
  static lv_color_t buf1_1[MONITOR_HOR_RES * 100];
  static lv_color_t buf1_2[MONITOR_HOR_RES * 100];
  lv_disp_draw_buf_init(&disp_buf1, buf1_1, buf1_2, MONITOR_HOR_RES * 100);

  /*Create a display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv); /*Basic initialization*/
  disp_drv.draw_buf = &disp_buf1;
  disp_drv.flush_cb = monitor_flush;
  disp_drv.hor_res = MONITOR_HOR_RES;
  disp_drv.ver_res = MONITOR_VER_RES;
  disp_drv.antialiasing = 1;

  lv_disp_t * disp = lv_disp_drv_register(&disp_drv);

  lv_theme_t * th = lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), LV_THEME_DEFAULT_DARK, LV_FONT_DEFAULT);
  lv_disp_set_theme(disp, th);

  lv_group_t * g = lv_group_create();
  lv_group_set_default(g);

  /* Add the mouse as input device
   * Use the 'mouse' driver which reads the PC's mouse*/
  mouse_init();
  static lv_indev_drv_t indev_drv_1;
  lv_indev_drv_init(&indev_drv_1); /*Basic initialization*/
  indev_drv_1.type = LV_INDEV_TYPE_POINTER;

  /*This function will be called periodically (by the library) to get the mouse position and state*/
  indev_drv_1.read_cb = mouse_read;
  lv_indev_t *mouse_indev = lv_indev_drv_register(&indev_drv_1);

  keyboard_init();
  static lv_indev_drv_t indev_drv_2;
  lv_indev_drv_init(&indev_drv_2); /*Basic initialization*/
  indev_drv_2.type = LV_INDEV_TYPE_KEYPAD;
  indev_drv_2.read_cb = keyboard_read;
  lv_indev_t *kb_indev = lv_indev_drv_register(&indev_drv_2);
  lv_indev_set_group(kb_indev, g);
  mousewheel_init();
  static lv_indev_drv_t indev_drv_3;
  lv_indev_drv_init(&indev_drv_3); /*Basic initialization*/
  indev_drv_3.type = LV_INDEV_TYPE_ENCODER;
  indev_drv_3.read_cb = mousewheel_read;

  lv_indev_t * enc_indev = lv_indev_drv_register(&indev_drv_3);
  lv_indev_set_group(enc_indev, g);

  /*Set a cursor for the mouse*/
  LV_IMG_DECLARE(mouse_cursor_icon); /*Declare the image file.*/
  lv_obj_t * cursor_obj = lv_img_create(lv_scr_act()); /*Create an image object for the cursor */
  lv_img_set_src(cursor_obj, &mouse_cursor_icon);           /*Set the image source*/
  lv_indev_set_cursor(mouse_indev, cursor_obj);             /*Connect the image  object to the driver*/
}

/**
 * A task to measure the elapsed time for LVGL
 * @param data unused
 * @return never return
 */
static int tick_thread(void *data) {
  (void)data;

  while(1) {
    SDL_Delay(5);
    lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
  }

  return 0;
}
