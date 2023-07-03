#include "can_data.h"

/*
#define DESERIALIZE(network, message)                                                                                  \
  network##_message_##message data;                                                                                    \
  network##_deserialize_##message(&data, raw);

#define DESERIALIZE_CONVERSION(network, message)                                                                       \
  DESERIALIZE(network, message)                                                                                        \
  network##_message_##message##_conversion conversion;                                                                 \
  network##_raw_to_conversion_struct_##message(&conversion, &data);*/

#define PRIMARY_UNPACK(type)                                                   \
  primary_##type##_t data;                                                     \
  primary_##type##_unpack(&data, msg->data, msg->size);

//TO-DO these values are not 
char* car_status_to_string(int car_status){
    switch(car_status)
    {
        case 0:
            return "idle";
            break;
        case 1:
            return "running";
            break;
        case 2:
            return "NONe";
    }
}

void can_handle_primary(struct can_frame frame){

    can_message_t* msg;
    msg->size = frame.can_dlc;
    //uint8_t *raw = malloc(length);
    memcpy(msg->data, frame.data, msg->size * sizeof(uint8_t));

    // printf("%d\n", frame.can_id);

    switch (frame.can_id)
    {    
        
        case PRIMARY_NLG5_DIAG_TX_FRAME_ID: {
            break;
        } 
        case PRIMARY_NLG5_DIAG_RX_FRAME_ID: {
            break;
        } 
        case PRIMARY_NLG5_ERR_FRAME_ID: {
            break;
        } 
        case PRIMARY_NLG5_TEMP_FRAME_ID: {
            break;
        } 
        case PRIMARY_NLG5_ACT_II_FRAME_ID: {
            break;
        } 
        case PRIMARY_NLG5_ACT_I_FRAME_ID: {
            break;
        } 
        case PRIMARY_NLG5_ST_FRAME_ID: {
            break;
        } 
        case PRIMARY_NLG5_CTL_FRAME_ID: {
            break;
        } 
        case PRIMARY_BMS_HV_JMP_TO_BLT_FRAME_ID: {
            break;
        }
        case PRIMARY_FLASH_BMS_HV_TX_FRAME_ID: {
            break;
        }
        case PRIMARY_FLASH_BMS_HV_RX_FRAME_ID: {
            break;
        }
        case PRIMARY_HV_CAN_FORWARD_FRAME_ID: {
            break;
        }
        case PRIMARY_FLASH_CELLBOARD_0_TX_FRAME_ID: {
            break;
        }
        case PRIMARY_FLASH_CELLBOARD_0_RX_FRAME_ID: {
            break;
        }
        case PRIMARY_FLASH_CELLBOARD_1_TX_FRAME_ID: {
            break;
        }
        case PRIMARY_FLASH_CELLBOARD_1_RX_FRAME_ID: {
            break;
        }
        case PRIMARY_FLASH_CELLBOARD_2_TX_FRAME_ID: {
            break;
        }
        case PRIMARY_FLASH_CELLBOARD_2_RX_FRAME_ID: {
            break;
        }
        case PRIMARY_FLASH_CELLBOARD_3_TX_FRAME_ID: {
            break;
        }
        case PRIMARY_FLASH_CELLBOARD_3_RX_FRAME_ID: {
            break;
        }
        case PRIMARY_FLASH_CELLBOARD_4_TX_FRAME_ID: {
            break;
        }
        case PRIMARY_FLASH_CELLBOARD_4_RX_FRAME_ID: {
            break;
        }
        case PRIMARY_FLASH_CELLBOARD_5_TX_FRAME_ID: {
            break;
        }
        case PRIMARY_FLASH_CELLBOARD_5_RX_FRAME_ID: {
            break;
        }
        case PRIMARY_BMS_LV_JMP_TO_BLT_FRAME_ID: {
            break;
        }
        case PRIMARY_FLASH_BMS_LV_TX_FRAME_ID: {
            break;
        }
        case PRIMARY_FLASH_BMS_LV_RX_FRAME_ID: {
            break;
        }
        case PRIMARY_ECU_JMP_TO_BLT_FRAME_ID: {
            break;
        }
        case PRIMARY_FLASH_ECU_TX_FRAME_ID: {
            break;
        }
        case PRIMARY_FLASH_ECU_RX_FRAME_ID: {
            break;
        }
        case PRIMARY_STEERING_JMP_TO_BLT_FRAME_ID: {
            break;
        }
        case PRIMARY_FLASH_STEERING_TX_FRAME_ID: {
            break;
        }
        case PRIMARY_FLASH_STEERING_RX_FRAME_ID: {
            break;
        }
        case PRIMARY_STEER_VERSION_FRAME_ID: {
            break;
        } 
        case PRIMARY_DAS_VERSION_FRAME_ID: {
            break;
        } 
        case PRIMARY_HV_VERSION_FRAME_ID: {
            break;
        } 
        case PRIMARY_LV_VERSION_FRAME_ID: {
            break;
        } 
        case PRIMARY_TLM_VERSION_FRAME_ID: {
            break;
        } 
        case PRIMARY_TIMESTAMP_FRAME_ID: {
            break;
        } 
        case PRIMARY_AMBIENT_TEMPERATURE_FRAME_ID: {
            break;
        } 
        case PRIMARY_DATA_LOGGER_FRAME_ID: {
            break;
        } 
        case PRIMARY_SET_TLM_STATUS_FRAME_ID: {
            break;
        } 
        case PRIMARY_TLM_STATUS_FRAME_ID: {
            break;
        } 
        case PRIMARY_STEER_SYSTEM_STATUS_FRAME_ID: {
            break;
        } 
        case PRIMARY_HV_VOLTAGE_FRAME_ID: {
            PRIMARY_UNPACK(hv_voltage);
            steering.hv.bus_voltage = data.bus_voltage;
            LV_UPDATE_LABEL(hv, pack_voltage, steering.hv.bus_voltage);
            break;
        } 
        case PRIMARY_HV_CURRENT_FRAME_ID: {
            PRIMARY_UNPACK(hv_current);
            steering.hv.current = data.current;
            LV_UPDATE_LABEL(hv, current, steering.hv.current);
            break;
        } 

        case PRIMARY_HV_TEMP_FRAME_ID: {
            PRIMARY_UNPACK(hv_temp);
            steering.hv.max_temperature = data.max_temp;
            steering.hv.min_temperature = data.min_temp;
            steering.hv.average_temperature = data.average_temp;
            LV_UPDATE_LABEL(hv, max_temperature, steering.hv.max_temperature);
            LV_UPDATE_LABEL(hv, min_temperature, steering.hv.min_temperature);
            LV_UPDATE_LABEL(hv, average_temperature, steering.hv.average_temperature);
            break;
        } 
        case PRIMARY_HV_ERRORS_FRAME_ID: {
            break;
        }
        case PRIMARY_HV_FANS_OVERRIDE_FRAME_ID: {
            break;
        }
        case PRIMARY_HV_CAN_FORWARD_STATUS_FRAME_ID: {
            break;
        }
        case PRIMARY_HV_FANS_OVERRIDE_STATUS_FRAME_ID: {
            break;
        } 
        case PRIMARY_HV_FEEDBACKS_STATUS_FRAME_ID: {
            break;
        } 
        case PRIMARY_HV_IMD_STATUS_FRAME_ID: {
            break;
        } 
        case PRIMARY_TS_STATUS_FRAME_ID: {
            break;
        }
        case PRIMARY_SET_TS_STATUS_DAS_FRAME_ID: {
            break;
        }
        case PRIMARY_SET_TS_STATUS_HANDCART_FRAME_ID: {
            break;
        }
        case PRIMARY_STEER_STATUS_FRAME_ID: {
            break;
        } 
        case PRIMARY_SET_CAR_STATUS_FRAME_ID: {
            break;
        }
        case PRIMARY_SET_PEDAL_CALIBRATION_FRAME_ID: {
            break;
        } 
        case PRIMARY_PEDAL_CALIBRATION_ACK_FRAME_ID: {
            break;
        } 
        case PRIMARY_CAR_STATUS_FRAME_ID: {
            PRIMARY_UNPACK(car_status);
            steering.das.car_status = data.car_status;
            LV_UPDATE_LABEL(das, car_status, car_status_to_string(steering.das.car_status));
            break;
        }
        case PRIMARY_DAS_ERRORS_FRAME_ID: {
            break;
        }
        case PRIMARY_LV_CURRENTS_FRAME_ID: {
            break;
        } 
        case PRIMARY_LV_CELLS_VOLTAGE_FRAME_ID: {
            PRIMARY_UNPACK(lv_cells_voltage);
            steering.lv.voltage_0 = data.voltage_0;
            steering.lv.voltage_1 = data.voltage_1;
            steering.lv.voltage_2 = data.voltage_2;
            LV_UPDATE_LABEL(lv, voltage_0, steering.lv.voltage_0);
            LV_UPDATE_LABEL(lv, voltage_1, steering.lv.voltage_1);
            LV_UPDATE_LABEL(lv, voltage_2, steering.lv.voltage_2);
            break;
        } 
        case PRIMARY_LV_TOTAL_VOLTAGE_FRAME_ID: {
            PRIMARY_UNPACK(lv_total_voltage);
            steering.lv.total_voltage = data.total_voltage;
            LV_UPDATE_LABEL(lv, total_voltage, steering.lv.total_voltage);
            break;
        } 
        case PRIMARY_LV_CELLS_TEMP_FRAME_ID: {
            PRIMARY_UNPACK(lv_cells_temp);
            steering.lv.battery_temperature = (data.temp_0+data.temp_1+data.temp_2)/3;
            LV_UPDATE_LABEL(lv, battery_temperature , steering.lv.battery_temperature);
            break;
        } 
        case PRIMARY_COOLING_STATUS_FRAME_ID: {
            break;
        } 
        case PRIMARY_SET_RADIATOR_SPEED_FRAME_ID: {
            break;
        } 
        case PRIMARY_SET_PUMPS_SPEED_FRAME_ID: {
            break;
        } 
        case PRIMARY_SET_INVERTER_CONNECTION_STATUS_FRAME_ID: {
            break;
        } 
        case PRIMARY_INVERTER_CONNECTION_STATUS_FRAME_ID: {
            break;
        } 
        case PRIMARY_LV_ERRORS_FRAME_ID: {
            break;
        } 
        case PRIMARY_LV_HEALTH_SIGNALS_FRAME_ID: {
            break;
        } 
        case PRIMARY_LV_FEEDBACKS_FRAME_ID: {
            break;
        } 
        case PRIMARY_SHUTDOWN_STATUS_FRAME_ID: {
            break;
        } 
        case PRIMARY_LV_CAN_FLASH_REQ_FRAME_ID: {
            break;
        } 
        case PRIMARY_LV_CAN_FLASH_ACK_FRAME_ID: {
            break;
        } 
        case PRIMARY_MARKER_FRAME_ID: {
            break;
        }
        case PRIMARY_HV_CELLS_VOLTAGE_FRAME_ID: {
            PRIMARY_UNPACK(hv_current);
            steering.hv.current = data.current;
            LV_UPDATE_LABEL(hv, current, steering.hv.current);
            break;
        } 
        case PRIMARY_HV_CELLS_TEMP_FRAME_ID: {
            PRIMARY_UNPACK(hv_current);
            steering.hv.current = data.current;
            LV_UPDATE_LABEL(hv, current, steering.hv.current);
            break;
        } 
        case PRIMARY_HV_CELL_BALANCING_STATUS_FRAME_ID: {
            break;
        } 
        case PRIMARY_SET_CELL_BALANCING_STATUS_FRAME_ID: {
            break;
        } 
        case PRIMARY_SPEED_FRAME_ID: {
            break;
        } 
        case PRIMARY_INV_L_REQUEST_FRAME_ID: {
            break;
        } 
        case PRIMARY_INV_R_REQUEST_FRAME_ID: {
            break;
        } 
        case PRIMARY_INV_L_RESPONSE_FRAME_ID: {
            break;
        } 
        case PRIMARY_INV_R_RESPONSE_FRAME_ID: {
            break;
        } 
        case PRIMARY_CONTROL_OUTPUT_FRAME_ID: {
            break;
        } 
        case PRIMARY_LC_RESET_FRAME_ID: {
            break;
        } 
        case PRIMARY_HANDCART_STATUS_FRAME_ID: {
            break;
        } 
        case PRIMARY_HANDCART_SETTINGS_FRAME_ID: {
            break;
        } 
        case PRIMARY_HANDCART_SETTINGS_SET_FRAME_ID: {
            break;
        } 
        case PRIMARY_SET_PTT_STATUS_FRAME_ID: {
            break;
        } 
        case PRIMARY_PTT_STATUS_FRAME_ID: {
            break;
        }
    }
}



void update_lv_temp(uint8_t val){
    //LV_UPDATE_LABEL(low_voltage, lv_temp, val);
}

void update_car_status(uint8_t val);
void can_handle_secondary(struct can_frame frame){
    int length = frame.can_dlc;
    uint8_t *raw = malloc(length);
    memcpy(raw, frame.data, length * sizeof(uint8_t));

    /*
    switch(frame.can_id)
    {
        case secondary_ID_STEERING_ANGLE:{
            // DESERIALIZE(secondary, STEERING_ANGLE);

            // if(steering.curr_focus == STEER)
                // lv_slider_set_value(steering.slider, (int)data.angle, LV_ANIM_OFF);
            
            break;
        }
        case secondary_ID_PEDALS_OUTPUT:{
            // DESERIALIZE_CONVERSION(secondary, PEDALS_RANGE);

            // if(steering.curr_focus == APPS)
                // lv_slider_set_value(steering.slider, (int)conversion.apps, LV_ANIM_OFF);
            // else if(steering.curr_focus == BSE)
                // lv_slider_set_value(steering.slider, (int)conversion.bse_front, LV_ANIM_OFF);
            
            break;
        }
        case secondary_ID_GPS_SPEED:{
            // DESERIALIZE(secondary, GPS_SPEED); does not compile

            break;
        }
    }*/

}
