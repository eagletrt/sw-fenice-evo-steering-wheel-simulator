#ifndef STEERING_H
#define STEERING_H

#include <stdlib.h>
#include <unistd.h>
#include "lvgl/lvgl.h"
#include <time.h>

typedef struct {
 
/*----primary messages-----*/
    uint8_t value_AMBIENT_TEMPERATURE;
    lv_obj_t * lb_AMBIENT_TEMPERATURE;


    /*--HV system--*/
    uint8_t value_HV_VOLTAGE;
    lv_obj_t * lb_HV_VOLTAGE;

    uint8_t value_HV_CURRENT;
    lv_obj_t * lb_HV_CURRENT;

    uint8_t value_HV_TEMP;
    lv_obj_t * lb_HV_TEMP;

    uint8_t value_HV_PERCENT;
    lv_obj_t * lb_HV_PERCENT;


    /*--LV system--*/
    uint8_t value_LV_VOLTAGE;
    lv_obj_t * lb_LV_VOLTAGE;

    uint8_t value_LV_CURRENT;
    lv_obj_t * lb_LV_CURRENT;

    uint8_t value_LV_TEMP;
    lv_obj_t * lb_LV_TEMP;

    uint8_t value_LV_PERCENT;
    lv_obj_t * lb_LV_PERCENT;



    uint8_t value_CAR_STATUS;
    uint8_t lb_CAR_STATUS;



/*----secondary messages-----*/
    uint8_t value_GPS_SPEED;
    lv_obj_t * lb_GPS_SPEED;

    uint8_t value_LAP_COUNT;
    lv_obj_t * lb_LAP_COUNT;


    /*secondary_message_CONTROL_OUTPUT;*/

    uint8_t value_ESTIMATED_VELOCITY;
    lv_obj_t * lb_ESTIMATED_VELOCITY;

    uint8_t value_TORQUE;
    lv_obj_t * lb_TORQUE;
    
    /*temps tyres*/

    uint8_t value_FL_TEMP;
    lv_obj_t * lb_FL_TEMP;

    uint8_t value_FR_TEMP;
    lv_obj_t * lb_FR_TEMP;

    uint8_t value_RL_TEMP;
    lv_obj_t * lb_RL_TEMP;

    uint8_t value_RR_TEMP;
    lv_obj_t * lb_RR_TEMP;


    /*pressure tyres*/

    uint8_t value_FL_PRESS;
    lv_obj_t * lb_FL_PRESS;

    uint8_t value_FR_PRESS;
    lv_obj_t * lb_FR_PRESS;

    uint8_t value_RL_PRESS;
    lv_obj_t * lb_RL_PRESS;

    uint8_t value_RR_PRESS;
    lv_obj_t * lb_RR_PRESS;


/*----the following are guessed (don't know which messages are in can)----*/

    uint8_t value_MOTOR_TEMP;
    lv_obj_t * lb_MOTOR_TEMP;

    uint8_t value_INVERTER_TEMP;
    lv_obj_t * lb_INVERTER_TEMP;


    /*values for lap*/
    uint8_t value_BEST_TIME;
    lv_obj_t * lb_BEST_TIME;

    uint8_t value_LAST_TIME;
    lv_obj_t * lb_LAST_TIME;

    uint8_t value_DELTA_TIME;
    lv_obj_t * lb_DELTA_TIME;

    

    uint8_t value_SLIP;
    lv_obj_t * lb_SLIP;

    uint8_t value_POWER;
    lv_obj_t * lb_POWER;

    uint8_t value_KM;
    lv_obj_t * lb_KM;

    

    /*parts to elements that can't be accessed otherwise*/

    lv_obj_t *custom_meter;


} steering_t;


extern steering_t sensors_data;
void test_value_update();
void test_value_update_incremental();


#endif