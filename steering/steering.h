#ifndef STEERING_H
#define STEERING_H

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "lvgl.h"
#include <time.h>
#include "can/lib/primary/primary_network.h"

#define NUM_TABS 5

typedef enum {
    BSE,
    STEER,
    APPS
} CalibrationBox;

#define LV_PROPERTY(type, name) \
    type name; \
    lv_obj_t* lb_##name[NUM_TABS];

#define LV_UPDATE_LABEL(struct, name, value) \
    steering.struct.name = value; \
    for(int i=0 ; i<NUM_TABS ; i++){ \
        if(steering.struct.lb_##name[i] != NULL) \
            lv_label_set_text_fmt(steering.struct.lb_##name[i], "%d", steering.struct.name); \
    }

typedef struct {
    struct {
        LV_PROPERTY(uint8_t, car_status);
        LV_PROPERTY(uint8_t, inverter_left);
        LV_PROPERTY(uint8_t, inverter_right);
        LV_PROPERTY(int32_t, left_speed_rads);
        LV_PROPERTY(int32_t, right_speed_rads);
        LV_PROPERTY(float, speed);
        LV_PROPERTY(uint16_t, apps);
        LV_PROPERTY(float, bse);
        LV_PROPERTY(float, steering_angle);
        LV_PROPERTY(uint16_t, encoder_right);
        LV_PROPERTY(uint16_t, encoder_left);
        LV_PROPERTY(uint8_t, version_component);
        LV_PROPERTY(uint32_t, version_cancicd);
        LV_PROPERTY(uint32_t, errors);
    } das;

    struct {
        LV_PROPERTY(float, pack_voltage);
        LV_PROPERTY(uint16_t, bus_voltage);
        LV_PROPERTY(float, max_cell_voltage);
        LV_PROPERTY(float, min_cell_voltage);
        LV_PROPERTY(uint16_t, current);
        LV_PROPERTY(int16_t, power);
        LV_PROPERTY(float, average_temperature);
        LV_PROPERTY(float, max_temperature);
        LV_PROPERTY(float, min_temperature);
        LV_PROPERTY(uint16_t, errors);
        LV_PROPERTY(uint32_t, feedbacks);
        LV_PROPERTY(uint16_t, warnings);
        LV_PROPERTY(primary_ts_status_t, ts_status);
        LV_PROPERTY(uint8_t, version_component);
        LV_PROPERTY(uint32_t, version_cancicd);
        LV_PROPERTY(uint32_t, hv_percent);
    } hv;

    struct {
        LV_PROPERTY(float, right_temperature);
        LV_PROPERTY(float, left_temperature);
        LV_PROPERTY(uint32_t, right_errors);
        LV_PROPERTY(uint32_t, right_status);
        LV_PROPERTY(uint16_t, right_io_info);
        LV_PROPERTY(float, right_motor_temp);
        LV_PROPERTY(float, right_inverter_temp);
        LV_PROPERTY(uint32_t, right_speed);
        LV_PROPERTY(uint32_t, left_errors);
        LV_PROPERTY(uint32_t, left_status);
        LV_PROPERTY(uint16_t, left_io_info);
        LV_PROPERTY(float, left_motor_temp);
        LV_PROPERTY(float, left_inverter_temp);
        LV_PROPERTY(uint32_t, left_speed);
    } inverters;

    struct {
        LV_PROPERTY(float, current);
        LV_PROPERTY(float, voltage);
        LV_PROPERTY(uint16_t, total_voltage);
        LV_PROPERTY(float, dcdc_temperature);
        LV_PROPERTY(float, battery_temperature);
        LV_PROPERTY(uint8_t, version_component);
        LV_PROPERTY(uint32_t, version_cancicd);
        LV_PROPERTY(uint32_t, errors);
        LV_PROPERTY(uint32_t, lv_percent);
    } lv;

    struct {
        LV_PROPERTY(float, temperature);
        LV_PROPERTY(bool, ptt);
        LV_PROPERTY(uint32_t, canlib_build_hash);
        LV_PROPERTY(bool, debug_mode);
        LV_PROPERTY(uint8_t, ambient_temperature);
        LV_PROPERTY(uint8_t, best_time);
        LV_PROPERTY(uint8_t, last_time);
        LV_PROPERTY(uint8_t, delta_time);
        LV_PROPERTY(uint8_t, estimated_velocity);
    } steering;

    struct {
        LV_PROPERTY(float, latitude);
        LV_PROPERTY(float, longitude);
        LV_PROPERTY(uint16_t, gps_speed);
        LV_PROPERTY(uint8_t, version_component);
        LV_PROPERTY(uint32_t, version_cancicd);
        LV_PROPERTY(uint8_t, lap_count);
    } telemetry;


    struct {
        LV_PROPERTY(uint8_t, power);
        LV_PROPERTY(uint8_t, torque);
        LV_PROPERTY(uint8_t, slip);
    } control;

    struct {
        LV_PROPERTY(uint8_t, fl_temp);
        LV_PROPERTY(uint8_t, fr_temp);
        LV_PROPERTY(uint8_t, rl_temp);
        LV_PROPERTY(uint8_t, rr_temp);
    } tyre_temps;

    struct {
        LV_PROPERTY(uint8_t, fl_press);
        LV_PROPERTY(uint8_t, fr_press);
        LV_PROPERTY(uint8_t, rl_press);
        LV_PROPERTY(uint8_t, rr_press);
    } tyre_pressures;

    struct {
        LV_PROPERTY(uint8_t, radiators_speed);
        LV_PROPERTY(uint8_t, pumps_speed);
    } cooling_status;


    lv_obj_t *custom_meter;
    lv_meter_indicator_t *indicator_blue;
    lv_meter_indicator_t *indicator_white;

    CalibrationBox curr_focus;
    lv_obj_t *slider;

    uint32_t timestamp;

} steering_t;


extern steering_t steering;
void car_status_update(primary_car_status_t* data);

#endif
