#ifndef STEERING_H
#define STEERING_H

#include "lvgl.h"
#include "primary/primary_network.h"
#include "utils.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef enum { BSE, STEER, APPS } calibration_box_t;

#define STEER_PROPERTY(type, name)                                             \
  type name;                                                                   \
  lv_obj_t *lb_##name[NUM_TABS];

#define STEER_PROPERTY2(device, name)                                          \
  device##_##name##_t name;                                                    \
  lv_obj_t *lb_##name[NUM_TABS];

#define STEER_UPDATE_LABEL(name, value)                                        \
  for (int i = 0; i < NUM_TABS; i++) {                                         \
    if (name[i] != NULL)                                                       \
      lv_label_set_text_fmt(name[i], "%s", value);                             \
  }

typedef struct {
  struct {
    STEER_PROPERTY(uint8_t, car_status);
    STEER_PROPERTY(uint8_t, inverter_left);
    STEER_PROPERTY(uint8_t, inverter_right);
    STEER_PROPERTY(int32_t, left_speed_rads);
    STEER_PROPERTY(int32_t, right_speed_rads);
    STEER_PROPERTY(float, speed);
    STEER_PROPERTY(uint16_t, apps);
    STEER_PROPERTY(float, bse);
    STEER_PROPERTY(float, steering_angle);
    STEER_PROPERTY(uint16_t, encoder_right);
    STEER_PROPERTY(uint16_t, encoder_left);
    STEER_PROPERTY(uint8_t, version_component);
    STEER_PROPERTY(uint32_t, version_cancicd);
    STEER_PROPERTY(uint32_t, errors);
    lv_obj_t *bottom_lb_speed;
  } das;

  struct {
    STEER_PROPERTY(float, pack_voltage);
    STEER_PROPERTY(uint16_t, bus_voltage);
    STEER_PROPERTY(float, max_cell_voltage);
    STEER_PROPERTY(float, min_cell_voltage);
    STEER_PROPERTY(uint16_t, current);
    STEER_PROPERTY(int16_t, power);
    STEER_PROPERTY(float, average_temperature);
    STEER_PROPERTY(float, max_temperature);
    STEER_PROPERTY(float, min_temperature);
    STEER_PROPERTY(primary_hv_errors_t, errors);
    STEER_PROPERTY(uint32_t, feedbacks);
    STEER_PROPERTY(uint16_t, warnings);
    STEER_PROPERTY(primary_ts_status_t, ts_status);
    STEER_PROPERTY(uint8_t, version_component);
    STEER_PROPERTY(uint32_t, version_cancicd);
    STEER_PROPERTY(uint32_t, hv_percent);
  } hv;

  struct {
    STEER_PROPERTY(float, right_temperature);
    STEER_PROPERTY(float, left_temperature);
    STEER_PROPERTY(uint32_t, right_errors);
    STEER_PROPERTY(uint32_t, right_status);
    STEER_PROPERTY(uint16_t, right_io_info);
    STEER_PROPERTY(float, right_motor_temp);
    STEER_PROPERTY(float, right_inverter_temp);
    STEER_PROPERTY(uint32_t, right_speed);
    STEER_PROPERTY(uint32_t, left_errors);
    STEER_PROPERTY(uint32_t, left_status);
    STEER_PROPERTY(uint16_t, left_io_info);
    STEER_PROPERTY(float, left_motor_temp);
    STEER_PROPERTY(float, left_inverter_temp);
    STEER_PROPERTY(uint32_t, left_speed);
  } inverters;

  struct {
    STEER_PROPERTY(float, current);
    STEER_PROPERTY(float, voltage);
    STEER_PROPERTY(uint16_t, total_voltage);
    STEER_PROPERTY(float, dcdc_temperature);
    STEER_PROPERTY(float, battery_temperature);
    STEER_PROPERTY(uint8_t, version_component);
    STEER_PROPERTY(uint32_t, version_cancicd);
    STEER_PROPERTY(uint32_t, errors);
    STEER_PROPERTY(uint32_t, lv_percent);
  } lv;

  struct {
    STEER_PROPERTY(float, temperature);
    STEER_PROPERTY(bool, ptt);
    STEER_PROPERTY(uint32_t, canlib_build_hash);
    STEER_PROPERTY(bool, debug_mode);
    STEER_PROPERTY(uint8_t, ambient_temperature);
    STEER_PROPERTY(uint8_t, best_time);
    STEER_PROPERTY(uint8_t, last_time);
    STEER_PROPERTY(uint8_t, delta_time);
    STEER_PROPERTY(uint8_t, estimated_velocity);
  } steering;

  struct {
    STEER_PROPERTY(bool, status);
    STEER_PROPERTY(float, latitude);
    STEER_PROPERTY(float, longitude);
    STEER_PROPERTY(uint16_t, gps_speed);
    STEER_PROPERTY(uint8_t, version_component);
    STEER_PROPERTY(uint32_t, version_cancicd);
    STEER_PROPERTY(uint8_t, lap_count);
  } telemetry;

  struct {
    STEER_PROPERTY(uint8_t, power);
    STEER_PROPERTY(uint8_t, torque);
    STEER_PROPERTY(uint8_t, slip);
  } control;

  struct {
    STEER_PROPERTY(uint8_t, fl_temp);
    STEER_PROPERTY(uint8_t, fr_temp);
    STEER_PROPERTY(uint8_t, rl_temp);
    STEER_PROPERTY(uint8_t, rr_temp);
  } tyre_temps;

  struct {
    STEER_PROPERTY(uint8_t, fl_press);
    STEER_PROPERTY(uint8_t, fr_press);
    STEER_PROPERTY(uint8_t, rl_press);
    STEER_PROPERTY(uint8_t, rr_press);
  } tyre_pressures;

  struct {
    STEER_PROPERTY(uint8_t, radiators_speed);
    STEER_PROPERTY(uint8_t, pumps_speed);
  } cooling_status;

  lv_obj_t *notification_screen_label;
  lv_obj_t *custom_meter;
  lv_meter_indicator_t *indicator_blue;
  lv_meter_indicator_t *indicator_white;

  calibration_box_t curr_focus;
  lv_obj_t *slider;

  uint32_t timestamp;

} steering_t;

extern steering_t steering;

void car_status_update(primary_car_status_t *data);
void hv_errors_update(primary_hv_errors_t *data);
void lv_errors_update(primary_lv_errors_t *data);
void hv_feedback_update(primary_hv_feedbacks_status_t *data);
void hv_temp_update(primary_hv_temp_t *data);
void lv_total_voltage_update(primary_lv_total_voltage_t *data);
void lv_cells_voltage_update(primary_lv_cells_voltage_t *data);
void lv_currents_update(primary_lv_currents_t *data);
void lv_cells_temp_update(primary_lv_cells_temp_t *data);
void tlm_status_update(primary_tlm_status_t *data);

#endif
