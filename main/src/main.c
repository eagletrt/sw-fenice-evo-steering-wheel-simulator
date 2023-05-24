
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
#include "lv_drivers/display/monitor.h"
#include "lv_drivers/indev/mouse.h"
#include "lv_drivers/indev/keyboard.h"
#include "lv_drivers/indev/mousewheel.h"
#include "steering/ui/tab_manager.h"
#include "steering/ui/tab_calibration.h"
#include "steering/steering.h"


/*canlib libraries*/
#include "can/lib/primary/c/ids.h"
#include "can/lib/secondary/c/ids.h"

#include "can/lib/primary/c/network.h"
#include "can/lib/secondary/c/network.h"

#include "can.h"
#include "queue.h"

/*********************
 *      DEFINES
 *********************/

#define primary_NETWORK_IMPLEMENTATION
#define secondary_NETWORK_IMPLEMENTATION

/**********************
 *      TYPEDEFS
 **********************/

typedef struct thread_data_t {
  can_t *can;
  int can_id;
} thread_data_t;

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void hal_init(void);
static int tick_thread(void *data);
static void data_init(void);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void foo(lv_indev_drv_t *indev_drv, uint8_t e);

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *      VARIABLES
 **********************/

thread_data_t thread_data_1, thread_data_0;

can_t can_primary;
can_t can_secondary;

SDL_mutex* mtx; //LOCK-> SDL_mutexP() , UNLOCK->SDL_mutexV()
queue_t queue;

const int NETWORK_PRIMARY = 0;
const int NETWORK_SECONDARY = 1;

SDL_Thread* thread_id_0;
SDL_Thread* thread_id_1;

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void canread(thread_data_t *thread_data) {
  queue_element_t msg;
  int res;
  while (1) {
    can_receive(&msg.frame, thread_data->can);
    msg.can_network = thread_data->can_id;
    msg.timestamp = SDL_GetTicks();

    SDL_mutexP(mtx);
    enqueue(msg, &queue);
    SDL_mutexV(mtx);
  }
}

int main(int argc, char **argv)
{
  (void)argc; /*Unused*/
  (void)argv; /*Unused*/

  /*Initialize LVGL*/
  lv_init();
  

  /*Initialize the HAL (display, input devices, tick) for LVGL*/
  hal_init();
  data_init();
  
  steering_values_init();

  tab_manager();

  lv_timer_create((lv_timer_cb_t) test_value_update_incremental, 70, NULL);

  /*----init structures and values to read from can----*/

  mtx = SDL_CreateMutex();
  queue_init(&queue);
  can_init("vcan1", &can_primary);
  can_init("vcan0", &can_secondary);
  
  queue_element_t q_element;
  uint16_t readMessage = 0; // 0 = no message, 1 = message read

  if(can_open_socket(&can_primary) < 0){
    printf("[ERR] could not open can_primary\n");
    return -1;
  }

  if(can_open_socket(&can_secondary) < 0){
    printf("[ERR] could not open can_secondary\n");
    return -1;
  }

  thread_data_0.can = &can_primary;
  thread_data_0.can_id = NETWORK_PRIMARY;
  thread_data_1.can = &can_secondary;
  thread_data_1.can_id = NETWORK_SECONDARY;

  thread_id_0 = SDL_CreateThread(canread, "thread_0", &thread_data_0); 
  //thread_id_1 = SDL_CreateThread(canread, "thread_1", &thread_data_1); 

  while(1) {
    /* Periodically call the lv_task handler.
     * It could be done in a timer interrupt or an OS task too.*/
    lv_timer_handler();


    SDL_mutexP(mtx);
    if(queue_first(&queue, &q_element)){
      dequeue(&queue);
      printf("[CAN] message received with ID: %d at time: %d\n", q_element.frame.can_id, q_element.timestamp);
      
    }
    SDL_mutexV(mtx);
    
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
  disp_drv.dpi = 10;

  lv_disp_t * disp = lv_disp_drv_register(&disp_drv);

  lv_theme_t * th = lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), LV_THEME_DEFAULT_DARK, LV_FONT_DEFAULT);
  lv_disp_set_theme(disp, th);

  g = lv_group_create();
  lv_group_set_default(g);

  keyboard_init();
  static lv_indev_drv_t indev_drv_2;
  lv_indev_drv_init(&indev_drv_2); /*Basic initialization*/
  indev_drv_2.type = LV_INDEV_TYPE_KEYPAD;
  indev_drv_2.read_cb = keyboard_read;
  indev_drv_2.feedback_cb = foo;
  lv_indev_t *kb_indev = lv_indev_drv_register(&indev_drv_2);
  lv_indev_set_group(kb_indev, g);
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


/*
 ** Handles keyboard events
 * used for testing
 */
void foo(lv_indev_drv_t *indev_drv, uint8_t e)
{ 
  lv_indev_data_t data;
  keyboard_read(indev_drv, &data);
  
  /*to see witch key was taken as input*/
  printf("data: %c\n", data.key);

    switch (data.key)
    {
      case ' ':
        change_tab(FORWARD);
        break;

      case 'b':
        change_tab(BACKWARD);
        break;

      case 'l':
        shift_box_focus(LEFT);
        break;

      case 'r':
        shift_box_focus(RIGHT);
        break;

      default:
        break;
    }

}

void data_init(void){
  steering.general_info.estimated_velocity = 0;
  steering.control.power = 80;
}