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

void tlm_status_update(primary_tlm_status_t *data) {}

void ambient_temperature_update(primary_ambient_temperature_t *data) {}

void speed_update(primary_speed_t *data) {}

void hv_voltage_update(primary_hv_voltage_t *data) {}

void hv_current_update(primary_hv_current_t *data) {}

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

void hv_errors_update(primary_hv_errors_t *data) {}

void hv_feedbacks_status_update(primary_hv_feedbacks_status_t *data) {}

void hv_cells_voltage_update(primary_hv_cells_voltage_t *data) {}

void hv_cells_temp_update(primary_hv_cells_temp_t *data) {}

void das_errors_update(primary_das_errors_t *data) {}

void lv_currents_update(primary_lv_currents_t *data) {}

void lv_cells_voltage_update(primary_lv_cells_voltage_t *data) {}

void lv_cells_temp_update(primary_lv_cells_temp_t *data) {}

void lv_total_voltage_update(primary_lv_total_voltage_t *data) {}

void lv_errors_update(primary_lv_errors_t *data) {}
