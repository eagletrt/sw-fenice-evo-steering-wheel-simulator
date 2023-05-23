#ifndef STEERING_H
#define STEERING_H

#include <stdlib.h>
#include <unistd.h>
#include "lvgl/lvgl.h"
#include <time.h>

#define NUM_TABS 5

/*
    THE LABELS ARE ASSIGNED TO EACH TAB WITH TabIdentification structure in utils.h,
     HOPEFULLY THERE WILL BE NO CONFLICT ON THE SAME LABEL
*/

#define LV_PROPERTY(type, name) \
    type name; \
    lv_obj_t * lb_##name[NUM_TABS];

#define LV_UPDATE_LABEL(struct, name, value) \
    steering.struct.name = value; \ 
    for(int i=0 ; i<NUM_TABS ; i++){ \
        if(steering.struct.lb_##name[i] != NULL) \
            lv_label_set_text_fmt(steering.struct.lb_##name[i], "%d", steering.struct.name); \
    }


typedef struct {
 
    struct {
        LV_PROPERTY(uint8_t, hv_voltage)
        LV_PROPERTY(uint8_t, hv_current)
        LV_PROPERTY(uint8_t, hv_temp)
        LV_PROPERTY(uint8_t, hv_percent)
    } hv;

    struct {
        LV_PROPERTY(uint8_t, lv_voltage)
        LV_PROPERTY(uint8_t, lv_current)
        LV_PROPERTY(uint8_t, lv_temp)
        LV_PROPERTY(uint8_t, lv_percent)
        LV_PROPERTY(uint8_t, car_status)
    } low_voltage;

    struct {
        LV_PROPERTY(uint8_t, gps_speed)
        LV_PROPERTY(uint8_t, lap_count)
    } secondary_messages;

    struct {
        LV_PROPERTY(uint8_t, power)
        LV_PROPERTY(uint8_t, torque)
        LV_PROPERTY(uint8_t, slip)
    } control;
    
    struct {
        LV_PROPERTY(uint8_t, fl_temp)
        LV_PROPERTY(uint8_t, fr_temp)
        LV_PROPERTY(uint8_t, rl_temp)
        LV_PROPERTY(uint8_t, rr_temp)
    } tyre_temps;

    struct{
        LV_PROPERTY(uint8_t, fl_press)
        LV_PROPERTY(uint8_t, fr_press)
        LV_PROPERTY(uint8_t, rl_press)
        LV_PROPERTY(uint8_t, rr_press)
    } tyre_pressures;

    /*----the following are guessed (don't know which messages are in can)----*/
    struct {
        LV_PROPERTY(uint8_t, motor_temp)
        LV_PROPERTY(uint8_t, inverter_temp)
    } motor_inverter;

    /*values for lap*/
    struct {
        LV_PROPERTY(uint8_t, ambient_temperature)
        LV_PROPERTY(uint8_t, best_time)
        LV_PROPERTY(uint8_t, last_time)
        LV_PROPERTY(uint8_t, delta_time)
        LV_PROPERTY(uint8_t, estimated_velocity)
        LV_PROPERTY(uint8_t, km)
    } general_info;

    /*parts to elements that can't be accessed otherwise*/
    lv_obj_t *custom_meter;
    lv_meter_indicator_t *indicator_blue;
    lv_meter_indicator_t *indicator_white;

    //lv_obj_t *indicator_blue;
    //lv_obj_t *indicator_white;

} steering_t;


extern steering_t steering;
void test_value_update_incremental(void);

void steering_values_init();

#endif
