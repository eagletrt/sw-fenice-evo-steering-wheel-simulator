#include "steering.h"

steering_t steering = {
    .das.car_status = primary_car_status_car_status_IDLE,
    .das.inverter_left = primary_car_status_inverter_l_OFF,
    .das.inverter_right = primary_car_status_inverter_r_OFF,
    .das.left_speed_rads = 0,
    .das.right_speed_rads = 0,
    .das.speed = 0,
    .das.apps = 0,
    .das.bse = 0,
    .das.steering_angle = 90,
    .das.encoder_right = 0,
    .das.encoder_left = 0,
    .das.version_component = 0,
    .das.version_cancicd = 0,
    .das.errors = 0,

    .hv.pack_voltage = 0,
    .hv.bus_voltage = 0,
    .hv.max_cell_voltage = 0,
    .hv.min_cell_voltage = 0,
    .hv.current = 0,
    .hv.power = 0,
    .hv.average_temperature = 0,
    .hv.max_temperature = 0,
    .hv.min_temperature = 0,
    .hv.errors = 0,
    .hv.feedbacks = 0,
    .hv.warnings = 0,
    .hv.ts_status = primary_ts_status_ts_status_OFF,
    .hv.version_component = 0,
    .hv.version_cancicd = 0,
    .hv.hv_percent = 0,

    .inverters.right_temperature = 0.0f,
    .inverters.left_temperature = 0.0f,
    .inverters.right_errors = 0,
    .inverters.right_status = 0,
    .inverters.right_io_info = 0,
    .inverters.right_motor_temp = 0.0f,
    .inverters.right_inverter_temp = 0.0f,
    .inverters.right_speed = 0,
    .inverters.left_errors = 0,
    .inverters.left_status = 0,
    .inverters.left_io_info = 0,
    .inverters.left_motor_temp = 0.0f,
    .inverters.left_inverter_temp = 0.0f,
    .inverters.left_speed = 0,

    .lv.current = 0,
    .lv.voltage = 0,
    .lv.total_voltage = 0,
    .lv.dcdc_temperature = 0,
    .lv.battery_temperature = 0,
    .lv.version_component = 0,
    .lv.version_cancicd = 0,
    .lv.errors = 0,
    .lv.lv_percent = 0,

    .steering.temperature = 0,
    .steering.ptt = false,
    .steering.canlib_build_hash = 0,
    .steering.debug_mode = false,
    .steering.ambient_temperature = 0,
    .steering.best_time = 0,
    .steering.last_time = 0,
    .steering.delta_time = 0,
    .steering.estimated_velocity = 0,

    .telemetry.status = false,
    .telemetry.latitude = 0.0f,
    .telemetry.longitude = 0.0f,
    .telemetry.gps_speed = 0,
    .telemetry.version_component = 0,
    .telemetry.version_cancicd = 0,
    .telemetry.lap_count = 0,

    // check with dynamics team
    .control.power = 0,
    .control.torque = 0,
    .control.slip = 0,

    .tyre_temps.fl_temp = 0,
    .tyre_temps.fr_temp = 0,
    .tyre_temps.rl_temp = 0,
    .tyre_temps.rr_temp = 0,
    .tyre_pressures.fl_press = 0,
    .tyre_pressures.fr_press = 0,
    .tyre_pressures.rl_press = 0,
    .tyre_pressures.rr_press = 0,

    .cooling_status.radiators_speed = 0,
    .cooling_status.pumps_speed = 0,

    .timestamp = 0,
};

void car_status_update(primary_car_status_t *data) {
  steering.das.car_status = *data;
  switch (data->car_status) {
  case primary_car_status_car_status_INIT:
  case primary_car_status_car_status_ENABLE_INV_UPDATES:
  case primary_car_status_car_status_CHECK_INV_SETTINGS:
  case primary_car_status_car_status_IDLE: {
    lv_label_set_text_fmt(steering.das.bottom_lb_speed, "-");
    STEER_UPDATE_LABEL(steering.das.lb_speed, "IDLE");
    break;
  }
  case primary_car_status_car_status_START_TS_PRECHARGE: {
    lv_label_set_text_fmt(steering.das.bottom_lb_speed, "-");
    STEER_UPDATE_LABEL(steering.das.lb_speed, "TSON");
    break;
  }
  case primary_car_status_car_status_WAIT_TS_PRECHARGE: {
    lv_label_set_text_fmt(steering.das.bottom_lb_speed, "-");
    STEER_UPDATE_LABEL(steering.das.lb_speed, "TSON");
    break;
  }
  case primary_car_status_car_status_WAIT_DRIVER: {
    lv_label_set_text_fmt(steering.das.bottom_lb_speed, "-");
    STEER_UPDATE_LABEL(steering.das.lb_speed, "TSON");
    break;
  }
  case primary_car_status_car_status_ENABLE_INV_DRIVE: {
    lv_label_set_text_fmt(steering.das.bottom_lb_speed, "-");
    STEER_UPDATE_LABEL(steering.das.lb_speed, "TSON");
    break;
  }
  case primary_car_status_car_status_DRIVE: {
    lv_label_set_text_fmt(steering.das.bottom_lb_speed, "-");
    STEER_UPDATE_LABEL(steering.das.lb_speed, "DRIVE");
    break;
  }
  case primary_car_status_car_status_DISABLE_INV_DRIVE: {
    lv_label_set_text_fmt(steering.das.bottom_lb_speed, "-");
    STEER_UPDATE_LABEL(steering.das.lb_speed, "DRIVE");
    break;
  }
  case primary_car_status_car_status_START_TS_DISCHARGE: {
    lv_label_set_text_fmt(steering.das.bottom_lb_speed, "-");
    STEER_UPDATE_LABEL(steering.das.lb_speed, "TSDIS");
    break;
  }
  case primary_car_status_car_status_WAIT_TS_DISCHARGE: {
    lv_label_set_text_fmt(steering.das.bottom_lb_speed, "-");
    STEER_UPDATE_LABEL(steering.das.lb_speed, "TSDIS");
    break;
  }
  case primary_car_status_car_status_FATAL_ERROR: {
    lv_label_set_text_fmt(steering.das.bottom_lb_speed, "-");
    STEER_UPDATE_LABEL(steering.das.lb_speed, "FATAL");
    break;
  }
  }
}

void hv_errors_update(primary_hv_errors_t *data) {}

void lv_errors_update(primary_lv_errors_t *data) {}

void hv_feedback_update(primary_hv_feedbacks_status_t *data) {}
