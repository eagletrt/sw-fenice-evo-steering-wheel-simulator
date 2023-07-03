#include "steering.h"

steering_t steering = {0};
extern bool steering_initialized;

primary_car_status_t car_status_last_message = {0};
primary_control_output_t control_output_last_message = {0};

primary_ambient_temperature_t ambient_temperature_last_message = {0};
primary_tlm_status_t tlm_status_last_message = {0};
primary_speed_t speed_last_message = {0};

primary_hv_voltage_t hv_voltage_last_message = {0};
primary_hv_current_t hv_current_last_message = {0};
primary_hv_temp_t hv_temp_last_message = {0};
primary_hv_errors_t hv_errors_last_message = {0};
primary_hv_feedbacks_status_t hv_feedbacks_status_last_message = {0};
primary_hv_cells_voltage_t hv_cells_voltage_last_message = {0};
primary_hv_cells_temp_t hv_cells_temp_last_message = {0};

primary_das_errors_t das_errors_last_message = {0};

primary_lv_currents_t lv_currents_last_message = {0};
primary_lv_cells_voltage_t lv_cells_voltage_last_message = {0};
primary_lv_cells_temp_t lv_cells_temp_last_message = {0};
primary_lv_total_voltage_t lv_total_voltage_last_message = {0};
primary_lv_errors_t lv_errors_last_message = {0};

primary_steer_status_t steer_status_last_message = {
    .map_pw = 0, .map_sc = 0, .map_tv = 0};

void car_status_update(primary_car_status_t *data) {

  if (data->car_status != car_status_last_message.car_status) {
    car_status_last_message.car_status = data->car_status;
    switch (data->car_status) {
    case primary_car_status_car_status_INIT:
    case primary_car_status_car_status_ENABLE_INV_UPDATES:
    case primary_car_status_car_status_CHECK_INV_SETTINGS:
    case primary_car_status_car_status_IDLE: {
      lv_label_set_text_fmt(steering.das.bottom_lb_speed, "-");
      STEER_UPDATE_LABEL(steering.das.lb_speed, "IDLE");
      break;
    }
    case primary_car_status_car_status_START_TS_PRECHARGE:
    case primary_car_status_car_status_WAIT_TS_PRECHARGE: {
      lv_label_set_text_fmt(steering.das.bottom_lb_speed, "-");
      STEER_UPDATE_LABEL(steering.das.lb_speed, "PRCHG");
      break;
    }
    case primary_car_status_car_status_WAIT_DRIVER: {
      lv_label_set_text_fmt(steering.das.bottom_lb_speed, "-");
      STEER_UPDATE_LABEL(steering.das.lb_speed, "SETUP");
      break;
    }
    case primary_car_status_car_status_DRIVE: {
      lv_label_set_text_fmt(steering.das.bottom_lb_speed, "-");
      STEER_UPDATE_LABEL(steering.das.lb_speed, "DRIVE");
      break;
    }
    case primary_car_status_car_status_DISABLE_INV_DRIVE:
    case primary_car_status_car_status_START_TS_DISCHARGE:
    case primary_car_status_car_status_WAIT_TS_DISCHARGE: {
      lv_label_set_text_fmt(steering.das.bottom_lb_speed, "-");
      STEER_UPDATE_LABEL(steering.das.lb_speed, "TSOFF");
      break;
    }
    case primary_car_status_car_status_FATAL_ERROR: {
      lv_label_set_text_fmt(steering.das.bottom_lb_speed, "-");
      STEER_UPDATE_LABEL(steering.das.lb_speed, "FATAL");
      break;
    }
    default:
      break;
    }
  }

  primary_car_status_inverter_l invl = data->inverter_l;

  if (invl != car_status_last_message.inverter_l) {
  }

  primary_car_status_inverter_r invr = data->inverter_r;

  if (invr != car_status_last_message.inverter_r) {
  }
}

void control_output_update(primary_control_output_t *data) {}

void lv_errors_update(primary_lv_errors_t *data) {

}

void hv_feedback_update(primary_hv_feedbacks_status_t *data) {
  
}

void hv_temp_update(primary_hv_temp_t *data) {
  if (data->average_temp == hv_temp_last_message.average_temp &&
      data->max_temp == hv_temp_last_message.max_temp &&
      data->min_temp == hv_temp_last_message.min_temp)
    return;
  hv_temp_last_message.max_temp = data->max_temp;
  hv_temp_last_message.min_temp = data->min_temp;
  hv_temp_last_message.average_temp = data->average_temp;
  char buffer[64];
  snprintf(buffer, sizeof(buffer), "%d", data->max_temp);
  STEER_UPDATE_LABEL(steering.hv.lb_max_temperature, buffer);
  snprintf(buffer, sizeof(buffer), "%d", data->min_temp);
  STEER_UPDATE_LABEL(steering.hv.lb_min_temperature, buffer);
  snprintf(buffer, sizeof(buffer), "%d", data->average_temp);
  STEER_UPDATE_LABEL(steering.hv.lb_average_temperature, buffer);
}

void lv_total_voltage_update(primary_lv_total_voltage_t *data) {
  uint32_t old_total_v = steering.lv.total_voltage;
  CHECK_STEER_INIT;
  if (old_total_v == data->total_voltage)
    return;
  steering.lv.total_voltage = data->total_voltage;
  char buffer[64];
  snprintf(buffer, sizeof(buffer), "%ld", data->total_voltage);
  lv_bar_set_value(steering.lv_bar, data->total_voltage, LV_ANIM_OFF);
  STEER_UPDATE_LABEL(steering.lv.lb_total_voltage, buffer);
}

void hv_total_voltage_update(primary_hv_voltage_t *data) {
  uint16_t old_max_v = steering.hv.max_cell_voltage;
  uint16_t  old_min_v = steering.hv.min_cell_voltage;
  uint16_t  old_bus_v = steering.hv.bus_voltage;
  uint16_t  old_pack_v = steering.hv.pack_voltage;
  CHECK_STEER_INIT;
  if (old_max_v == data->max_cell_voltage && old_min_v == data->min_cell_voltage &&
      old_bus_v== data->bus_voltage && old_pack_v == data->pack_voltage)
    return;

  steering.hv.max_cell_voltage = data->max_cell_voltage;
  steering.hv.min_cell_voltage = data->min_cell_voltage;
  steering.hv.bus_voltage = data->bus_voltage;
  steering.hv.pack_voltage = data->pack_voltage;

  char buffer[64];
  snprintf(buffer, sizeof(buffer), "%d", data->max_cell_voltage);
  STEER_UPDATE_LABEL(steering.hv.lb_max_cell_voltage, buffer);
  snprintf(buffer, sizeof(buffer), "%d", data->min_cell_voltage);
  STEER_UPDATE_LABEL(steering.hv.lb_min_cell_voltage, buffer);
  snprintf(buffer, sizeof(buffer), "%d", data->bus_voltage);
  STEER_UPDATE_LABEL(steering.hv.lb_bus_voltage, buffer);
  snprintf(buffer, sizeof(buffer), "%d", data->pack_voltage);
  STEER_UPDATE_LABEL(steering.hv.lb_pack_voltage, buffer);

  lv_bar_set_value(steering.hv_bar, data->pack_voltage, LV_ANIM_OFF);
}


void lv_cells_voltage_update(primary_lv_cells_voltage_t *data){
  uint16_t old_cells_voltage_0 = steering.lv.voltage;
  CHECK_STEER_INIT;
  if (old_cells_voltage_0 == data->voltage_0)
    return;
  steering.lv.voltage = data->voltage_0;
  char buffer[64];
  snprintf(buffer, sizeof(buffer), "%d", data->voltage_0);
  STEER_UPDATE_LABEL(steering.lv.lb_voltage, buffer);
}

void lv_control_update(primary_control_output_converted_t *data) {
  /*right now gps speed is used beacuse is the one conncected to the labels of the UI, later should be changed to existing
  estimtated velocity variables*/
  float old_estimated_velocity = steering.telemetry.gps_speed;
  CHECK_STEER_INIT;
  if (old_estimated_velocity == data->estimated_velocity)
    return;
  steering.telemetry.gps_speed = data->estimated_velocity;
  char buffer[64];
  snprintf(buffer, sizeof(buffer), "%f", data->estimated_velocity);
  STEER_UPDATE_LABEL(steering.telemetry.lb_gps_speed, buffer);
  lv_meter_set_indicator_value(steering.custom_meter, steering.indicator_blue, data->estimated_velocity);
}

void lv_currents_update(primary_lv_currents_t *data) {
  uint16_t old_current_hv_battery = steering.hv.current;
  uint16_t old_current_lv_battery = steering.lv.current;

  CHECK_STEER_INIT;
  if (old_current_hv_battery == data->current_as_battery && old_current_lv_battery == data->current_lv_battery )
    return;
  steering.hv.current = data->current_as_battery;
  steering.lv.current = data->current_lv_battery;
  char buffer[64];
  snprintf(buffer, sizeof(buffer), "%d", data->current_as_battery);
  STEER_UPDATE_LABEL(steering.hv.lb_current, buffer);
  snprintf(buffer, sizeof(buffer), "%d", data->current_lv_battery);
  STEER_UPDATE_LABEL(steering.lv.lb_current, buffer);
}

//then pumps and radiators velocities

void lv_cells_temp_update(primary_lv_cells_temp_t *data) {
  float old_lv_temp= steering.lv.battery_temperature;
  CHECK_STEER_INIT;
  if (old_lv_temp == data->temp_0)
    return;
  steering.lv.battery_temperature = data->temp_0;
  char buffer[64];
  snprintf(buffer, sizeof(buffer), "%f", data->temp_0);
  STEER_UPDATE_LABEL(steering.lv.lb_battery_temperature, buffer);
}

void lv_total_voltage_update(primary_lv_total_voltage_t *data) {}

void lv_errors_update(primary_lv_errors_t *data) {}
