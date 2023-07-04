#include "steering.h"

steering_t steering = {0};
extern bool steering_initialized;

primary_car_status_converted_t car_status_last_message = {0};
primary_control_output_converted_t control_output_last_message = {0};

primary_ambient_temperature_converted_t ambient_temperature_last_message = {0};
primary_tlm_status_converted_t tlm_status_last_message = {0};
primary_speed_converted_t speed_last_message = {0};

primary_hv_voltage_converted_t hv_voltage_last_message = {0};
primary_hv_current_converted_t hv_current_last_message = {0};
primary_hv_temp_converted_t hv_temp_last_message = {0};
primary_hv_errors_converted_t hv_errors_last_message = {0};
primary_hv_feedbacks_status_converted_t hv_feedbacks_status_last_message = {0};
primary_hv_cells_voltage_converted_t hv_cells_voltage_last_message = {0};
primary_hv_cells_temp_converted_t hv_cells_temp_last_message = {0};

primary_das_errors_converted_t das_errors_last_message = {0};

primary_lv_currents_converted_t lv_currents_last_message = {0};
primary_lv_cells_voltage_converted_t lv_cells_voltage_last_message_1 = {0};
primary_lv_cells_voltage_converted_t lv_cells_voltage_last_message_2 = {0};
primary_lv_cells_temp_converted_t lv_cells_temp_last_message = {0};
primary_lv_total_voltage_converted_t lv_total_voltage_last_message = {0};
primary_lv_errors_converted_t lv_errors_last_message = {0};

void car_status_update(primary_car_status_converted_t *data) {

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

void control_output_update(primary_control_output_converted_t *data) {}

void tlm_status_update(primary_tlm_status_converted_t *data) {}

void ambient_temperature_update(primary_ambient_temperature_converted_t *data) {
}

void speed_update(primary_speed_converted_t *data) {}

void hv_voltage_update(primary_hv_voltage_converted_t *data) {}

void hv_current_update(primary_hv_current_converted_t *data) {}

void hv_temp_update(primary_hv_temp_converted_t *data) {
  if (data->average_temp == hv_temp_last_message.average_temp &&
      data->max_temp == hv_temp_last_message.max_temp &&
      data->min_temp == hv_temp_last_message.min_temp)
    return;
  hv_temp_last_message.max_temp = data->max_temp;
  hv_temp_last_message.min_temp = data->min_temp;
  hv_temp_last_message.average_temp = data->average_temp;
  char buffer[64];
  snprintf(buffer, sizeof(buffer), "%f", (float)data->max_temp);
  STEER_UPDATE_LABEL(steering.hv.lb_max_temperature, buffer);
  snprintf(buffer, sizeof(buffer), "%f", (float)data->min_temp);
  STEER_UPDATE_LABEL(steering.hv.lb_min_temperature, buffer);
  snprintf(buffer, sizeof(buffer), "%f", (float)data->average_temp);
  STEER_UPDATE_LABEL(steering.hv.lb_average_temperature, buffer);
}

void hv_errors_update(primary_hv_errors_converted_t *data) {}

void hv_total_voltage_update(primary_hv_voltage_converted_t *data) {
  uint16_t old_max_v = hv_voltage_last_message.max_cell_voltage;
  uint16_t old_min_v = hv_voltage_last_message.min_cell_voltage;
  uint16_t old_bus_v = hv_voltage_last_message.bus_voltage;
  uint16_t old_pack_v = hv_voltage_last_message.pack_voltage;
  if (old_max_v == data->max_cell_voltage &&
      old_min_v == data->min_cell_voltage && old_bus_v == data->bus_voltage &&
      old_pack_v == data->pack_voltage)
    return;

  hv_voltage_last_message.max_cell_voltage = data->max_cell_voltage;
  hv_voltage_last_message.min_cell_voltage = data->min_cell_voltage;
  hv_voltage_last_message.bus_voltage = data->bus_voltage;
  hv_voltage_last_message.pack_voltage = data->pack_voltage;

  char buffer[64];
  snprintf(buffer, sizeof(buffer), "%f", (float)data->max_cell_voltage);
  STEER_UPDATE_LABEL(steering.hv.lb_max_cell_voltage, buffer);
  snprintf(buffer, sizeof(buffer), "%f", (float)data->min_cell_voltage);
  STEER_UPDATE_LABEL(steering.hv.lb_min_cell_voltage, buffer);
  snprintf(buffer, sizeof(buffer), "%f", (float)data->bus_voltage);
  STEER_UPDATE_LABEL(steering.hv.lb_bus_voltage, buffer);
  snprintf(buffer, sizeof(buffer), "%f", (float)data->pack_voltage);
  STEER_UPDATE_LABEL(steering.hv.lb_pack_voltage, buffer);

  lv_bar_set_value(steering.hv_bar, data->pack_voltage, LV_ANIM_OFF);
}

void hv_feedbacks_status_update(primary_hv_feedbacks_status_converted_t *data) {
}

void hv_cells_voltage_update(primary_hv_cells_voltage_converted_t *data) {}

void hv_cells_temp_update(primary_hv_cells_temp_converted_t *data) {}

void das_errors_update(primary_das_errors_converted_t *data) {}

void lv_currents_update(primary_lv_currents_converted_t *data) {
  uint16_t old_current_lv_battery = lv_currents_last_message.current_lv_battery;
  if (old_current_lv_battery == data->current_lv_battery)
    return;
  lv_currents_last_message.current_lv_battery = data->current_lv_battery;
  char buffer[64];
  snprintf(buffer, sizeof(buffer), "%f", (float)data->current_lv_battery);
  STEER_UPDATE_LABEL(steering.lv.lb_current, buffer);
}

void lv_control_update(primary_control_output_converted_t *data) {
  /*right now gps speed is used beacuse is the one conncected to the labels of
  the UI, later should be changed to existing estimtated velocity variables*/

  float old_estimated_velocity = control_output_last_message.estimated_velocity;
  // TODO: the other field of the struct
  if (old_estimated_velocity == data->estimated_velocity)
    return;
  control_output_last_message.estimated_velocity = data->estimated_velocity;
  char buffer[64];
  snprintf(buffer, sizeof(buffer), "%f", data->estimated_velocity);
  STEER_UPDATE_LABEL(steering.telemetry.lb_gps_speed, buffer);
  lv_meter_set_indicator_value(steering.custom_meter, steering.indicator_blue,
                               data->estimated_velocity);
}

void lv_cells_voltage_update(primary_lv_cells_voltage_converted_t *data) {
  uint16_t old_cells_voltage_0;
  uint16_t old_cells_voltage_1;
  uint16_t old_cells_voltage_2;
  if (data->start_index == 0) {
    old_cells_voltage_0 = lv_cells_voltage_last_message_1.voltage_0;
    old_cells_voltage_1 = lv_cells_voltage_last_message_1.voltage_1;
    old_cells_voltage_2 = lv_cells_voltage_last_message_1.voltage_2;
    lv_cells_voltage_last_message_1.voltage_0 = data->voltage_0;
    lv_cells_voltage_last_message_1.voltage_1 = data->voltage_1;
    lv_cells_voltage_last_message_1.voltage_2 = data->voltage_2;
  } else {
    old_cells_voltage_0 = lv_cells_voltage_last_message_2.voltage_0;
    old_cells_voltage_1 = lv_cells_voltage_last_message_2.voltage_1;
    old_cells_voltage_2 = lv_cells_voltage_last_message_2.voltage_2;
    lv_cells_voltage_last_message_2.voltage_0 = data->voltage_0;
    lv_cells_voltage_last_message_2.voltage_1 = data->voltage_1;
    lv_cells_voltage_last_message_2.voltage_2 = data->voltage_2;
  }

  if (old_cells_voltage_0 == data->voltage_0 &&
      old_cells_voltage_1 == data->voltage_1 &&
      old_cells_voltage_2 == data->voltage_2)
    return;
  char buffer[64];
  uint16_t mean = (lv_cells_voltage_last_message_1.voltage_0 +
                   lv_cells_voltage_last_message_1.voltage_1 +
                   lv_cells_voltage_last_message_1.voltage_2 +
                   lv_cells_voltage_last_message_2.voltage_0 +
                   lv_cells_voltage_last_message_2.voltage_1 +
                   lv_cells_voltage_last_message_2.voltage_2) /
                  6;
  snprintf(buffer, sizeof(buffer), "%u", (unsigned int)mean);
  STEER_UPDATE_LABEL(steering.lv.lb_voltage, buffer);
}

void lv_cells_temp_update(primary_lv_cells_temp_converted_t *data) {
  float old_lv_temp_0 = lv_cells_temp_last_message.temp_0;
  float old_lv_temp_1 = lv_cells_temp_last_message.temp_1;
  float old_lv_temp_2 = lv_cells_temp_last_message.temp_2;
  if (old_lv_temp_0 == data->temp_0 && old_lv_temp_1 == data->temp_1 &&
      old_lv_temp_2 == data->temp_2)
    return;
  lv_cells_temp_last_message.temp_0 = data->temp_0;
  lv_cells_temp_last_message.temp_1 = data->temp_1;
  lv_cells_temp_last_message.temp_2 = data->temp_2;
  uint16_t mean_temp = (data->temp_0 + data->temp_1 + data->temp_2) / 3;
  char buffer[64];
  snprintf(buffer, sizeof(buffer), "%u", (unsigned int)mean_temp);
  STEER_UPDATE_LABEL(steering.lv.lb_battery_temperature, buffer);
}

void lv_total_voltage_update(primary_lv_total_voltage_converted_t *data) {
  uint32_t old_total_v = lv_total_voltage_last_message.total_voltage;
  if (old_total_v == data->total_voltage)
    return;
  lv_total_voltage_last_message.total_voltage = data->total_voltage;
  char buffer[64];
  snprintf(buffer, sizeof(buffer), "%f", (double)data->total_voltage);
  lv_bar_set_value(steering.lv_bar, data->total_voltage, LV_ANIM_OFF);
  STEER_UPDATE_LABEL(steering.lv.lb_total_voltage, buffer);
}

void lv_errors_update(primary_lv_errors_converted_t *data) {}