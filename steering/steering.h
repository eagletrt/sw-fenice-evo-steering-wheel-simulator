#ifndef STEERING_H
#define STEERING_H

#include "lvgl.h"
#include "primary/primary_network.h"
#include "utils.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef enum { BSE, STEER, APPS, CALBOX_N } calibration_box_t;

#define STEER_UPDATE_LABEL(name, value)                                        \
  for (uint32_t itab = 0; itab < NUM_TABS; itab++) {                           \
    if (name[itab] != NULL)                                                    \
      lv_label_set_text_fmt(name[itab], "%s", value);                          \
  }

#define STEER_UPDATE_COLOR_LABEL(name, color)                                  \
  for (uint32_t itab = 0; itab < NUM_TABS; itab++) {                           \
    if (name[itab] != NULL)                                                    \
      lv_obj_set_style_text_color(name[itab], lv_color_hex(color),             \
                                  LV_PART_MAIN);                               \
  }

#define STEER_ERROR_UPDATE(device, error_name, aindex)                         \
  if (device##_last_message.error_name != data->error_name) {                  \
    device##_last_message.error_name = data->error_name;                       \
    if (data->error_name)                                                      \
      lv_obj_set_style_bg_color(steering.car_errors.device[aindex],            \
                                lv_color_hex(COLOR_YELLOW_STATUS_HEX),         \
                                LV_PART_MAIN);                                 \
    else                                                                       \
      lv_obj_set_style_bg_color(steering.car_errors.device[aindex],            \
                                lv_color_hex(COLOR_RED_STATUS_HEX),            \
                                LV_PART_MAIN);                                 \
  }

typedef struct {
  struct {
    lv_obj_t *lb_car_status[NUM_TABS];
    lv_obj_t *lb_inverter_left[NUM_TABS];
    lv_obj_t *lb_inverter_right[NUM_TABS];
    lv_obj_t *lb_left_speed_rads[NUM_TABS];
    lv_obj_t *lb_right_speed_rads[NUM_TABS];
    lv_obj_t *lb_speed[NUM_TABS];
    lv_obj_t *lb_apps[NUM_TABS];
    lv_obj_t *lb_bse[NUM_TABS];
    lv_obj_t *lb_steering_angle[NUM_TABS];
    lv_obj_t *lb_encoder_right[NUM_TABS];
    lv_obj_t *lb_encoder_left[NUM_TABS];
    lv_obj_t *lb_version_component[NUM_TABS];
    lv_obj_t *lb_version_cancicd[NUM_TABS];
    lv_obj_t *lb_errors[NUM_TABS];
    lv_obj_t *bottom_lb_speed;
  } das;

  struct {
    lv_obj_t *lb_pack_voltage[NUM_TABS];
    lv_obj_t *lb_bus_voltage[NUM_TABS];
    lv_obj_t *lb_max_cell_voltage[NUM_TABS];
    lv_obj_t *lb_min_cell_voltage[NUM_TABS];
    lv_obj_t *lb_current[NUM_TABS];
    lv_obj_t *lb_power[NUM_TABS];
    lv_obj_t *lb_average_temperature[NUM_TABS];
    lv_obj_t *lb_max_temperature[NUM_TABS];
    lv_obj_t *lb_min_temperature[NUM_TABS];
    lv_obj_t *lb_errors[NUM_TABS];
    lv_obj_t *lb_feedbacks[NUM_TABS];
    lv_obj_t *lb_warnings[NUM_TABS];
    lv_obj_t *lb_ts_status[NUM_TABS];
    lv_obj_t *lb_version_component[NUM_TABS];
    lv_obj_t *lb_version_cancicd[NUM_TABS];
    lv_obj_t *lb_hv_percent[NUM_TABS];
  } hv;

  struct {
    lv_obj_t *lb_right_temperature[NUM_TABS];
    lv_obj_t *lb_left_temperature[NUM_TABS];
    lv_obj_t *lb_right_errors[NUM_TABS];
    lv_obj_t *lb_right_status[NUM_TABS];
    lv_obj_t *lb_right_io_info[NUM_TABS];
    lv_obj_t *lb_right_motor_temp[NUM_TABS];
    lv_obj_t *lb_right_inverter_temp[NUM_TABS];
    lv_obj_t *lb_right_speed[NUM_TABS];
    lv_obj_t *lb_left_errors[NUM_TABS];
    lv_obj_t *lb_left_status[NUM_TABS];
    lv_obj_t *lb_left_io_info[NUM_TABS];
    lv_obj_t *lb_left_motor_temp[NUM_TABS];
    lv_obj_t *lb_left_inverter_temp[NUM_TABS];
    lv_obj_t *lb_left_speed[NUM_TABS];
  } inverters;

  struct {
    lv_obj_t *lb_current[NUM_TABS];
    lv_obj_t *lb_voltage[NUM_TABS];
    lv_obj_t *lb_total_voltage[NUM_TABS];
    lv_obj_t *lb_dcdc_temperature[NUM_TABS];
    lv_obj_t *lb_battery_temperature[NUM_TABS];
    lv_obj_t *lb_version_component[NUM_TABS];
    lv_obj_t *lb_version_cancicd[NUM_TABS];
    lv_obj_t *lb_errors[NUM_TABS];
    lv_obj_t *lb_lv_percent[NUM_TABS];
  } lv;

  struct {
    lv_obj_t *lb_temperature[NUM_TABS];
    lv_obj_t *lb_ptt[NUM_TABS];
    lv_obj_t *lb_canlib_build_hash[NUM_TABS];
    lv_obj_t *lb_debug_mode[NUM_TABS];
    lv_obj_t *lb_ambient_temperature[NUM_TABS];
    lv_obj_t *lb_best_time[NUM_TABS];
    lv_obj_t *lb_last_time[NUM_TABS];
    lv_obj_t *lb_delta_time[NUM_TABS];
    lv_obj_t *lb_estimated_velocity[NUM_TABS];
  } steering;

  struct {
    lv_obj_t *lb_status[NUM_TABS];
    lv_obj_t *lb_latitude[NUM_TABS];
    lv_obj_t *lb_longitude[NUM_TABS];
    lv_obj_t *lb_gps_speed[NUM_TABS];
    lv_obj_t *lb_version_component[NUM_TABS];
    lv_obj_t *lb_version_cancicd[NUM_TABS];
    lv_obj_t *lb_lap_count[NUM_TABS];
  } telemetry;

  struct {
    lv_obj_t *lb_power[NUM_TABS];
    lv_obj_t *lb_torque[NUM_TABS];
    lv_obj_t *lb_slip[NUM_TABS];
  } control;

  struct {
    lv_obj_t *lb_fl_temp[NUM_TABS];
    lv_obj_t *lb_fr_temp[NUM_TABS];
    lv_obj_t *lb_rl_temp[NUM_TABS];
    lv_obj_t *lb_rr_temp[NUM_TABS];
  } tyre_temps;

  struct {
    lv_obj_t *lb_fl_press[NUM_TABS];
    lv_obj_t *lb_fr_press[NUM_TABS];
    lv_obj_t *lb_rl_press[NUM_TABS];
    lv_obj_t *lb_rr_press[NUM_TABS];
  } tyre_pressures;

  struct {
    lv_obj_t *lb_radiators_speed[NUM_TABS];
    lv_obj_t *lb_pumps_speed[NUM_TABS];
  } cooling_status;

  struct {
    lv_obj_t *hv_feedbacks_status[20];
    lv_obj_t *hv_errors[16];
    lv_obj_t *das_errors[9];
    lv_obj_t *lv_errors[17];
  } car_errors;

  lv_obj_t *notification_screen_label;

  /* Tab Racing */
  lv_obj_t *custom_meter;

  lv_obj_t *hv_bar;
  lv_obj_t *lv_bar;

  lv_meter_indicator_t *indicator_blue;
  lv_meter_indicator_t *indicator_white;
  lv_obj_t *racing_hv_bar;
  lv_obj_t *racing_lv_bar;

  /* Tab Sensors */

  /* Calibration Tab */
  calibration_box_t curr_focus;
  lv_obj_t *slider;

  uint32_t timestamp;

} steering_t;

extern steering_t steering;

void car_status_update(primary_car_status_converted_t *);
void control_output_update(primary_control_output_converted_t *data);
void tlm_status_update(primary_tlm_status_converted_t *);
void ambient_temperature_update(primary_ambient_temperature_converted_t *);
void speed_update(primary_speed_converted_t *);

void hv_voltage_update(primary_hv_voltage_converted_t *);
void hv_current_update(primary_hv_current_converted_t *);
void hv_temp_update(primary_hv_temp_converted_t *);
void hv_errors_update(primary_hv_errors_converted_t *);
void hv_feedbacks_status_update(primary_hv_feedbacks_status_converted_t *);
void hv_cells_voltage_update(primary_hv_cells_voltage_converted_t *);
void hv_cells_temp_update(primary_hv_cells_temp_converted_t *);

void das_errors_update(primary_das_errors_converted_t *);

void lv_currents_update(primary_lv_currents_converted_t *);
void lv_cells_voltage_update(primary_lv_cells_voltage_converted_t *);
void lv_cells_temp_update(primary_lv_cells_temp_converted_t *);
void lv_total_voltage_update(primary_lv_total_voltage_converted_t *);
void lv_errors_update(primary_lv_errors_converted_t *);

#endif
