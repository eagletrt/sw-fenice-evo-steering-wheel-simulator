#ifndef STEERING_H
#define STEERING_H

#include <stdlib.h>
#include <unistd.h>
#include "lvgl/lvgl.h"
#include <time.h>

#define LV_PROPERTY(type, name) \
    type name; \
    lv_obj_t * lb_##name; 

#define LV_PROPERTY(type, name) \
    type name; \
    lv_obj_t * lb_##name; 
   // uint8_t num_lb; 

#define LV_UPDATE_LABEL(struct, name, value) \
    steering.struct.name = value; \
    lv_label_set_text_fmt(steering.struct.lb_##name, "%d", steering.struct.name);


/*
    Preparo di default le label (passo il num di lb che mi servono) e le metto in un array,
    ad ogni LV_UPDATE aggiorno tutte le label e per assegnare alla schermata la sua label
    si usa un enum(RACING->0, SENSORS->1, ecc) -> problemi : memoria e indici (se ho 2 label,
    una in racing e una in controls(index 2 per esempio) non pesco la label giusta) 
*/

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

} steering_t;


extern steering_t steering;
void test_value_update_incremental(void);

#endif
