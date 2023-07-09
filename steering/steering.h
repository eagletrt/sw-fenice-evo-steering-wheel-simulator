#ifndef STEERING_H
#define STEERING_H

#include "lvgl.h"
#include "primary/primary_network.h"
#include "secondary/secondary_network.h"
#include "utils.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef enum { BSE, STEER, APPS, CALBOX_N } calibration_box_t;

#define STEER_PROPERTY(name) lv_obj_t *lb_##name[NUM_TABS];

#define STEER_UPDATE_LABEL(name, value)                                        \
  for (int i = 0; i < NUM_TABS; i++) {                                         \
    if (name[i] != NULL)                                                       \
      lv_label_set_text_fmt(name[i], "%s", value);                             \
  }

#define STEER_CAN_TO_LABEL_UPDATE(old_value, new_value, label)                  \
  if ( old_value != new_value ){                                                \
    sprintf(buffer, "%d", (int)new_value);                                     \
    STEER_UPDATE_LABEL(label, buffer);                                          \
    old_value = new_value;                                                      \
  }

#define STEER_ERROR_UPDATE(device, error_name, aindex) \
if ( device##_last_message.error_name != data->error_name ){ \
  device##_last_message.error_name = data->error_name; \
  if( data->error_name ) \
    lv_obj_set_style_bg_color(steering.car_errors.device [ aindex ], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN); \
  else \
    lv_obj_set_style_bg_color(steering.car_errors.device [ aindex ], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN); \
}

typedef struct {
  struct {
    STEER_PROPERTY(car_status);
    STEER_PROPERTY(inverter_left);
    STEER_PROPERTY(inverter_right);
    STEER_PROPERTY(left_speed_rads);
    STEER_PROPERTY(right_speed_rads);
    STEER_PROPERTY(speed);
    STEER_PROPERTY(apps);
    STEER_PROPERTY(bse);
    STEER_PROPERTY(steering_angle);
    STEER_PROPERTY(encoder_right);
    STEER_PROPERTY(encoder_left);
    STEER_PROPERTY(version_component);
    STEER_PROPERTY(version_cancicd);
    STEER_PROPERTY(errors);
    lv_obj_t *bottom_lb_speed;
  } das;

  struct {
    STEER_PROPERTY(pack_voltage);
    STEER_PROPERTY(bus_voltage);
    STEER_PROPERTY(max_cell_voltage);
    STEER_PROPERTY(min_cell_voltage);
    STEER_PROPERTY(current);
    STEER_PROPERTY(power);
    STEER_PROPERTY(average_temperature);
    STEER_PROPERTY(max_temperature);
    STEER_PROPERTY(min_temperature);
    STEER_PROPERTY(errors);
    STEER_PROPERTY(feedbacks);
    STEER_PROPERTY(warnings);
    STEER_PROPERTY(ts_status);
    STEER_PROPERTY(version_component);
    STEER_PROPERTY(version_cancicd);
    STEER_PROPERTY(hv_percent);
  } hv;

  struct {
    STEER_PROPERTY(right_temperature);
    STEER_PROPERTY(left_temperature);
    STEER_PROPERTY(right_errors);
    STEER_PROPERTY(right_status);
    STEER_PROPERTY(right_io_info);
    STEER_PROPERTY(right_motor_temp);
    STEER_PROPERTY(right_inverter_temp);
    STEER_PROPERTY(right_speed);
    STEER_PROPERTY(left_errors);
    STEER_PROPERTY(left_status);
    STEER_PROPERTY(left_io_info);
    STEER_PROPERTY(left_motor_temp);
    STEER_PROPERTY(left_inverter_temp);
    STEER_PROPERTY(left_speed);
  } inverters;

  struct {
    STEER_PROPERTY(current);
    STEER_PROPERTY(voltage);
    STEER_PROPERTY(total_voltage);
    STEER_PROPERTY(dcdc_temperature);
    STEER_PROPERTY(battery_temperature);
    STEER_PROPERTY(version_component);
    STEER_PROPERTY(version_cancicd);
    STEER_PROPERTY(errors);
    STEER_PROPERTY(lv_percent);
  } lv;

  struct {
    STEER_PROPERTY(temperature);
    STEER_PROPERTY(ptt);
    STEER_PROPERTY(canlib_build_hash);
    STEER_PROPERTY(debug_mode);
    STEER_PROPERTY(ambient_temperature);
    STEER_PROPERTY(best_time);
    STEER_PROPERTY(last_time);
    STEER_PROPERTY(delta_time);
    STEER_PROPERTY(estimated_velocity);
  } steering;

  struct {
    STEER_PROPERTY(status);
    STEER_PROPERTY(latitude);
    STEER_PROPERTY(longitude);
    STEER_PROPERTY(gps_speed);
    STEER_PROPERTY(version_component);
    STEER_PROPERTY(version_cancicd);
    STEER_PROPERTY(lap_count);
  } telemetry;

  struct {
    STEER_PROPERTY(power);
    STEER_PROPERTY(torque);
    STEER_PROPERTY(slip);
  } control;

  struct {
    STEER_PROPERTY(fl_temp);
    STEER_PROPERTY(fr_temp);
    STEER_PROPERTY(rl_temp);
    STEER_PROPERTY(rr_temp);
  } tyre_temps;

  struct {
    STEER_PROPERTY(fl_press);
    STEER_PROPERTY(fr_press);
    STEER_PROPERTY(rl_press);
    STEER_PROPERTY(rr_press);
  } tyre_pressures;

  struct {
    STEER_PROPERTY(radiators_speed);
    STEER_PROPERTY(pumps_speed);
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

void tyres_info_update(secondary_tpms_converted_t *);

#endif
