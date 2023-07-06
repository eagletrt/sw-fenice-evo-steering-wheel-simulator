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
primary_lv_errors_converted_t lv_errors_last_message = {1};

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

void hv_errors_update(primary_hv_errors_converted_t *data) {
  
  if(hv_errors_last_message.errors_cell_low_voltage != data->errors_cell_low_voltage){
    hv_errors_last_message.errors_cell_low_voltage = data->errors_cell_low_voltage;

    if(data->errors_cell_low_voltage)
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[0], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[0], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);

  }


  if(hv_errors_last_message.errors_cell_under_voltage != data->errors_cell_under_voltage){
    hv_errors_last_message.errors_cell_under_voltage = data->errors_cell_under_voltage;

    if(data->errors_cell_under_voltage)
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[1], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[1], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);

  }


  if(hv_errors_last_message.errors_cell_over_voltage != data->errors_cell_over_voltage){
    hv_errors_last_message.errors_cell_over_voltage = data->errors_cell_over_voltage;

    if(data->errors_cell_over_voltage)
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[2], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[2], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);

  }


  if(hv_errors_last_message.errors_cell_high_temperature != data->errors_cell_high_temperature){
    hv_errors_last_message.errors_cell_high_temperature = data->errors_cell_high_temperature;

    if(data->errors_cell_high_temperature)
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[3], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[3], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);

  }


  if(hv_errors_last_message.errors_cell_over_temperature != data->errors_cell_over_temperature){
    hv_errors_last_message.errors_cell_over_temperature = data->errors_cell_over_temperature;

    if(data->errors_cell_over_temperature)
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[4], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[4], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);

  }


  if(hv_errors_last_message.errors_over_current != data->errors_over_current){
    hv_errors_last_message.errors_over_current = data->errors_over_current;

    if(data->errors_over_current)
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[5], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[5], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);

  }


  if(hv_errors_last_message.errors_can != data->errors_can){
    hv_errors_last_message.errors_can = data->errors_can;

    if(data->errors_can)
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[6], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[6], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);

  }


  if(hv_errors_last_message.errors_int_voltage_mismatch != data->errors_int_voltage_mismatch){
    hv_errors_last_message.errors_int_voltage_mismatch = data->errors_int_voltage_mismatch;

    if(data->errors_int_voltage_mismatch)
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[7], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[7], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);

  }


  if(hv_errors_last_message.errors_cellboard_comm != data->errors_cellboard_comm){
    hv_errors_last_message.errors_cellboard_comm = data->errors_cellboard_comm;

    if(data->errors_cellboard_comm)
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[8], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[8], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);

  }


  if(hv_errors_last_message.errors_cellboard_internal != data->errors_cellboard_internal){
    hv_errors_last_message.errors_cellboard_internal = data->errors_cellboard_internal;

    if(data->errors_cellboard_internal)
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[9], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[9], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);

  }


  if(hv_errors_last_message.errors_connector_disconnected != data->errors_connector_disconnected){
    hv_errors_last_message.errors_connector_disconnected = data->errors_connector_disconnected;

    if(data->errors_connector_disconnected)
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[10], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[10], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);

  }


  if(hv_errors_last_message.errors_fans_disconnected != data->errors_fans_disconnected){
    hv_errors_last_message.errors_fans_disconnected = data->errors_fans_disconnected;

    if(data->errors_fans_disconnected)
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[11], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[11], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);

  }


  if(hv_errors_last_message.errors_feedback != data->errors_feedback){
    hv_errors_last_message.errors_feedback = data->errors_feedback;

    if(data->errors_feedback)
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[12], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[12], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);

  }


  if(hv_errors_last_message.errors_feedback_circuitry != data->errors_feedback_circuitry){
    hv_errors_last_message.errors_feedback_circuitry = data->errors_feedback_circuitry;

    if(data->errors_feedback_circuitry)
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[13], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[13], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);

  }


  if(hv_errors_last_message.errors_eeprom_comm != data->errors_eeprom_comm){
    hv_errors_last_message.errors_eeprom_comm = data->errors_eeprom_comm;

    if(data->errors_eeprom_comm)
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[14], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[14], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);

  }


  if(hv_errors_last_message.errors_eeprom_write != data->errors_eeprom_write){
    hv_errors_last_message.errors_eeprom_write = data->errors_eeprom_write;

    if(data->errors_eeprom_write)
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[15], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_errors[15], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);

  }


}

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

  if(hv_feedbacks_status_last_message.feedbacks_status_feedback_implausibility_detected != data->feedbacks_status_feedback_implausibility_detected){
    hv_feedbacks_status_last_message.feedbacks_status_feedback_implausibility_detected = data->feedbacks_status_feedback_implausibility_detected;

    if(data->feedbacks_status_feedback_implausibility_detected)
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[0], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[0], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(hv_feedbacks_status_last_message.feedbacks_status_feedback_imd_cockpit != data->feedbacks_status_feedback_imd_cockpit){
    hv_feedbacks_status_last_message.feedbacks_status_feedback_imd_cockpit = data->feedbacks_status_feedback_imd_cockpit;

    if(data->feedbacks_status_feedback_imd_cockpit)
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[1], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[1], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(hv_feedbacks_status_last_message.feedbacks_status_feedback_tsal_green_fault_latched != data->feedbacks_status_feedback_tsal_green_fault_latched){
    hv_feedbacks_status_last_message.feedbacks_status_feedback_tsal_green_fault_latched = data->feedbacks_status_feedback_tsal_green_fault_latched;

    if(data->feedbacks_status_feedback_tsal_green_fault_latched)
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[2], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[2], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(hv_feedbacks_status_last_message.feedbacks_status_feedback_bms_cockpit != data->feedbacks_status_feedback_bms_cockpit){
    hv_feedbacks_status_last_message.feedbacks_status_feedback_bms_cockpit = data->feedbacks_status_feedback_bms_cockpit;

    if(data->feedbacks_status_feedback_bms_cockpit)
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[3], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[3], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(hv_feedbacks_status_last_message.feedbacks_status_feedback_ext_latched != data->feedbacks_status_feedback_ext_latched){
    hv_feedbacks_status_last_message.feedbacks_status_feedback_ext_latched = data->feedbacks_status_feedback_ext_latched;

    if(data->feedbacks_status_feedback_ext_latched)
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[4], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[4], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(hv_feedbacks_status_last_message.feedbacks_status_feedback_tsal_green != data->feedbacks_status_feedback_tsal_green){
    hv_feedbacks_status_last_message.feedbacks_status_feedback_tsal_green = data->feedbacks_status_feedback_tsal_green;

    if(data->feedbacks_status_feedback_tsal_green)
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[5], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[5], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(hv_feedbacks_status_last_message.feedbacks_status_feedback_ts_over_60v_status != data->feedbacks_status_feedback_ts_over_60v_status){
    hv_feedbacks_status_last_message.feedbacks_status_feedback_ts_over_60v_status = data->feedbacks_status_feedback_ts_over_60v_status;

    if(data->feedbacks_status_feedback_ts_over_60v_status)
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[6], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[6], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(hv_feedbacks_status_last_message.feedbacks_status_feedback_airn_status != data->feedbacks_status_feedback_airn_status){
    hv_feedbacks_status_last_message.feedbacks_status_feedback_airn_status = data->feedbacks_status_feedback_airn_status;

    if(data->feedbacks_status_feedback_airn_status)
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[7], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[7], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(hv_feedbacks_status_last_message.feedbacks_status_feedback_airp_status != data->feedbacks_status_feedback_airp_status){
    hv_feedbacks_status_last_message.feedbacks_status_feedback_airp_status = data->feedbacks_status_feedback_airp_status;

    if(data->feedbacks_status_feedback_airp_status)
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[8], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[8], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(hv_feedbacks_status_last_message.feedbacks_status_feedback_airp_gate != data->feedbacks_status_feedback_airp_gate){
    hv_feedbacks_status_last_message.feedbacks_status_feedback_airp_gate = data->feedbacks_status_feedback_airp_gate;

    if(data->feedbacks_status_feedback_airp_gate)
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[9], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[9], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(hv_feedbacks_status_last_message.feedbacks_status_feedback_airn_gate != data->feedbacks_status_feedback_airn_gate){
    hv_feedbacks_status_last_message.feedbacks_status_feedback_airn_gate = data->feedbacks_status_feedback_airn_gate;

    if(data->feedbacks_status_feedback_airn_gate)
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[10], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[10], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(hv_feedbacks_status_last_message.feedbacks_status_feedback_precharge_status != data->feedbacks_status_feedback_precharge_status){
    hv_feedbacks_status_last_message.feedbacks_status_feedback_precharge_status = data->feedbacks_status_feedback_precharge_status;

    if(data->feedbacks_status_feedback_precharge_status)
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[11], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[11], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(hv_feedbacks_status_last_message.feedbacks_status_feedback_tsp_over_60v_status != data->feedbacks_status_feedback_tsp_over_60v_status){
    hv_feedbacks_status_last_message.feedbacks_status_feedback_tsp_over_60v_status = data->feedbacks_status_feedback_tsp_over_60v_status;

    if(data->feedbacks_status_feedback_tsp_over_60v_status)
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[12], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[12], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(hv_feedbacks_status_last_message.feedbacks_status_feedback_imd_fault != data->feedbacks_status_feedback_imd_fault){
    hv_feedbacks_status_last_message.feedbacks_status_feedback_imd_fault = data->feedbacks_status_feedback_imd_fault;

    if(data->feedbacks_status_feedback_imd_fault)
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[13], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[13], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(hv_feedbacks_status_last_message.feedbacks_status_feedback_check_mux != data->feedbacks_status_feedback_check_mux){
    hv_feedbacks_status_last_message.feedbacks_status_feedback_check_mux = data->feedbacks_status_feedback_check_mux;

    if(data->feedbacks_status_feedback_check_mux)
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[14], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[14], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(hv_feedbacks_status_last_message.feedbacks_status_feedback_sd_end != data->feedbacks_status_feedback_sd_end){
    hv_feedbacks_status_last_message.feedbacks_status_feedback_sd_end = data->feedbacks_status_feedback_sd_end;

    if(data->feedbacks_status_feedback_sd_end)
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[15], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[15], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(hv_feedbacks_status_last_message.feedbacks_status_feedback_sd_out != data->feedbacks_status_feedback_sd_out){
    hv_feedbacks_status_last_message.feedbacks_status_feedback_sd_out = data->feedbacks_status_feedback_sd_out;

    if(data->feedbacks_status_feedback_sd_out)
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[16], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[16], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }

  if(hv_feedbacks_status_last_message.feedbacks_status_feedback_sd_in != data->feedbacks_status_feedback_sd_in){
    hv_feedbacks_status_last_message.feedbacks_status_feedback_sd_in = data->feedbacks_status_feedback_sd_in;

    if(data->feedbacks_status_feedback_sd_in)
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[17], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[17], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(hv_feedbacks_status_last_message.feedbacks_status_feedback_sd_bms != data->feedbacks_status_feedback_sd_bms){
    hv_feedbacks_status_last_message.feedbacks_status_feedback_sd_bms = data->feedbacks_status_feedback_sd_bms;

    if(data->feedbacks_status_feedback_sd_bms)
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[18], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[18], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(hv_feedbacks_status_last_message.feedbacks_status_feedback_sd_imd != data->feedbacks_status_feedback_sd_imd){
    hv_feedbacks_status_last_message.feedbacks_status_feedback_sd_imd = data->feedbacks_status_feedback_sd_imd;

    if(data->feedbacks_status_feedback_sd_imd)
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[19], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.hv_feedbacks[19], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }

}

void hv_cells_voltage_update(primary_hv_cells_voltage_converted_t *data) {}

void hv_cells_temp_update(primary_hv_cells_temp_converted_t *data) {}

void das_errors_update(primary_das_errors_converted_t *data) {

  if(das_errors_last_message.das_error_pedal_adc != data->das_error_pedal_adc){
    das_errors_last_message.das_error_pedal_adc = data->das_error_pedal_adc;

    if(data->das_error_pedal_adc)
      lv_obj_set_style_bg_color(steering.car_errors.das_errors[0], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.das_errors[0], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }

  if(das_errors_last_message.das_error_pedal_adc != data->das_error_pedal_implausibility){
    das_errors_last_message.das_error_pedal_implausibility = data->das_error_pedal_implausibility;

    if(data->das_error_pedal_implausibility)
      lv_obj_set_style_bg_color(steering.car_errors.das_errors[1], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.das_errors[1], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }

  if(das_errors_last_message.das_error_imu_tout != data->das_error_imu_tout){
    das_errors_last_message.das_error_imu_tout = data->das_error_imu_tout;

    if(data->das_error_imu_tout)
      lv_obj_set_style_bg_color(steering.car_errors.das_errors[2], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.das_errors[2], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }

  if(das_errors_last_message.das_error_irts_tout != data->das_error_irts_tout){
    das_errors_last_message.das_error_irts_tout = data->das_error_irts_tout;

    if(data->das_error_irts_tout)
      lv_obj_set_style_bg_color(steering.car_errors.das_errors[3], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.das_errors[3], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }

  if(das_errors_last_message.das_error_ts_tout != data->das_error_ts_tout){
    das_errors_last_message.das_error_ts_tout = data->das_error_ts_tout;

    if(data->das_error_ts_tout)
      lv_obj_set_style_bg_color(steering.car_errors.das_errors[4], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.das_errors[4], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }

  if(das_errors_last_message.das_error_invl_tout != data->das_error_invl_tout){
    das_errors_last_message.das_error_invl_tout = data->das_error_invl_tout;

    if(data->das_error_invl_tout)
      lv_obj_set_style_bg_color(steering.car_errors.das_errors[5], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.das_errors[5], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }

  if(das_errors_last_message.das_error_invr_tout != data->das_error_invr_tout){
    das_errors_last_message.das_error_invr_tout = data->das_error_invr_tout;

    if(data->das_error_invr_tout)
      lv_obj_set_style_bg_color(steering.car_errors.das_errors[6], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.das_errors[6], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }

  if(das_errors_last_message.das_error_steer_tout != data->das_error_steer_tout){
    das_errors_last_message.das_error_steer_tout = data->das_error_steer_tout;

    if(data->das_error_steer_tout)
      lv_obj_set_style_bg_color(steering.car_errors.das_errors[7], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.das_errors[7], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }

  if(das_errors_last_message.das_error_fsm != data->das_error_fsm){
    das_errors_last_message.das_error_fsm = data->das_error_fsm;

    if(data->das_error_fsm)
      lv_obj_set_style_bg_color(steering.car_errors.das_errors[8], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.das_errors[8], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }
}

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

void lv_errors_update(primary_lv_errors_converted_t *data) {

  if(lv_errors_last_message.errors_cell_undervoltage != data->errors_cell_undervoltage){
    lv_errors_last_message.errors_cell_undervoltage = data->errors_cell_undervoltage;

    if(data->errors_cell_undervoltage)
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[0], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[0], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }
    
    
  if(lv_errors_last_message.errors_cell_overvoltage != data->errors_cell_overvoltage){
    lv_errors_last_message.errors_cell_overvoltage = data->errors_cell_overvoltage;

    if(data->errors_cell_overvoltage)
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[1], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[1], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(lv_errors_last_message.errors_battery_open_wire != data->errors_battery_open_wire){
    lv_errors_last_message.errors_battery_open_wire = data->errors_battery_open_wire;

    if(data->errors_battery_open_wire)
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[2], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[2], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(lv_errors_last_message.errors_can != data->errors_can){
    lv_errors_last_message.errors_can = data->errors_can;

    if(data->errors_can)
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[3], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[3], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(lv_errors_last_message.errors_spi != data->errors_spi){
    lv_errors_last_message.errors_spi = data->errors_spi;

    if(data->errors_spi)
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[4], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[4], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(lv_errors_last_message.errors_over_current != data->errors_over_current){
    lv_errors_last_message.errors_over_current = data->errors_over_current;

    if(data->errors_over_current)
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[5], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[5], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(lv_errors_last_message.errors_cell_under_temperature != data->errors_cell_under_temperature){
    lv_errors_last_message.errors_cell_under_temperature = data->errors_cell_under_temperature;

    if(data->errors_cell_under_temperature)
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[6], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[6], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(lv_errors_last_message.errors_cell_over_temperature != data->errors_cell_over_temperature){
    lv_errors_last_message.errors_cell_over_temperature = data->errors_cell_over_temperature;

    if(data->errors_cell_over_temperature)
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[7], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[7], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(lv_errors_last_message.errors_relay != data->errors_relay){
    lv_errors_last_message.errors_relay = data->errors_relay;

    if(data->errors_relay)
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[8], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[8], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(lv_errors_last_message.errors_bms_monitor != data->errors_bms_monitor){
    lv_errors_last_message.errors_bms_monitor = data->errors_bms_monitor;

    if(data->errors_bms_monitor)
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[9], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[9], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(lv_errors_last_message.errors_voltages_not_ready != data->errors_voltages_not_ready){
    lv_errors_last_message.errors_voltages_not_ready = data->errors_voltages_not_ready;

    if(data->errors_voltages_not_ready)
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[10], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[10], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(lv_errors_last_message.errors_mcp23017 != data->errors_mcp23017){
    lv_errors_last_message.errors_mcp23017 = data->errors_mcp23017;

    if(data->errors_mcp23017)
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[11], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[11], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(lv_errors_last_message.errors_radiator != data->errors_radiator){
    lv_errors_last_message.errors_radiator = data->errors_radiator;

    if(data->errors_radiator)
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[12], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[12], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(lv_errors_last_message.errors_fan != data->errors_fan){
    lv_errors_last_message.errors_fan = data->errors_fan;

    if(data->errors_fan)
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[13], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[13], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(lv_errors_last_message.errors_pump != data->errors_pump){
    lv_errors_last_message.errors_pump = data->errors_pump;

    if(data->errors_pump)
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[14], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[14], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(lv_errors_last_message.errors_adc_init != data->errors_adc_init){
    lv_errors_last_message.errors_adc_init = data->errors_adc_init;

    if(data->errors_adc_init)
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[15], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[15], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }


  if(lv_errors_last_message.errors_mux != data->errors_mux){
    lv_errors_last_message.errors_mux = data->errors_mux;

    if(data->errors_mux)
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[16], lv_color_hex(COLOR_YELLOW_STATUS_HEX), LV_PART_MAIN);
    else
      lv_obj_set_style_bg_color(steering.car_errors.lv_errors[16], lv_color_hex(COLOR_RED_STATUS_HEX), LV_PART_MAIN);
  }
}