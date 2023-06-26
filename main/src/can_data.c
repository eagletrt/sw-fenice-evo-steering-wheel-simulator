#include "can_data.h"

#define DESERIALIZE(network, message)                                          \
  network##_message_##message data;                                            \
  network##_deserialize_##message(&data, raw);

#define DESERIALIZE_CONVERSION(network, message)                               \
  DESERIALIZE(network, message)                                                \
  network##_message_##message##_conversion conversion;                         \
  network##_raw_to_conversion_struct_##message(&conversion, &data);

char *car_status_to_string(int car_status);

void can_handle_primary(struct can_frame frame) {

  int length = frame.can_dlc;
  uint8_t *raw = malloc(length);
  memcpy(raw, frame.data, length * sizeof(uint8_t));

  // printf("%d\n", frame.can_id);

  switch (frame.can_id) {
    /*
    case PRIMARY_: {

        // DESERIALIZE_CONVERSION(primary, SPEED);
        // steering.general_info.estimated_velocity = conversion.encoder_l;

        //LV_UPDATE_VALUE(general_info, estimated_velocity,
    conversion.encoder_l);

        //if(conversion.encoder_l > 100)
            //LV_UPDATE_LABEL(general_info, estimated_velocity,
    conversion.encoder_l);

        break;
    }

    case primary_ID_TIMESTAMP: {
        // DESERIALIZE(primary, TIMESTAMP);
        //LV_UPDATE_LABEL()
        break;
    }

    case PRIMARY_ID_DAS_VERSION: {
        // DESERIALIZE(primary, DAS_VERSION);
        // to be defined
        break;
    }

    case primary_ID_HV_VERSION: {
        // DESERIALIZE(primary, HV_VERSION);;
        //to be defined
        break;
    }

    case primary_ID_LV_VERSION: {
        // DESERIALIZE(primary, LV_VERSION);
        //to be defined
        break;
    }
    case primary_ID_TLM_VERSION: {
        // DESERIALIZE(primary, TLM_VERSION);
        // to be defined
        break;
    }
    case primary_ID_TLM_STATUS: {
        // DESERIALIZE(primary, TLM_STATUS);
        // to be defined -> pallino on/off
        break;
    }
    case primary_ID_CAR_STATUS: {
        // DESERIALIZE(primary, CAR_STATUS);
        //if(steering.general_info.estimated_velocity < 100)
        // LV_UPDATE_LABEL(low_voltage, car_status, "running");

        break;
    }
    case primary_ID_INV_L_RESPONSE: {
        // DESERIALIZE(primary, INV_L_RESPONSE);
        // to be defined
        break;
    }
    case primary_ID_INV_R_RESPONSE: {
        // DESERIALIZE(primary, INV_R_RESPONSE);
        // to be defined
        break;
    }
    case primary_ID_LV_CURRENT: {
        // DESERIALIZE(primary, LV_CURRENT);
        // LV_UPDATE_LABEL(low_voltage, lv_current, data.current);
        break;
    }
    case primary_ID_LV_VOLTAGE: {
        // DESERIALIZE(primary, LV_VOLTAGE);
        // LV_UPDATE_LABEL(low_voltage, lv_voltage, data.voltage_1);
        break;
    }
    case primary_ID_LV_TEMPERATURE: {
        // DESERIALIZE_CONVERSION(primary, LV_TEMPERATURE);
        // LV_UPDATE_LABEL(low_voltage, lv_temp, conversion.bp_temperature_1);
    break;
    }
    case primary_ID_HV_CURRENT: {
        // DESERIALIZE(primary, HV_CURRENT);
        // LV_UPDATE_LABEL(hv, hv_current, data.current);
        break;
    }
    case primary_ID_HV_VOLTAGE: {
        // DESERIALIZE(primary, HV_VOLTAGE);
        // LV_UPDATE_LABEL(hv, hv_voltage, data.pack_voltage);
    break;
    }
    case primary_ID_HV_TEMP: {
        // DESERIALIZE(primary, HV_TEMP);
        // LV_UPDATE_LABEL(hv, hv_temp, data.average_temp);
        break;
    }
    case primary_ID_HV_ERRORS: {
        // DESERIALIZE(primary, HV_ERRORS);
        // to be defined
        break;
    }
    case primary_ID_TS_STATUS: {
        // DESERIALIZE(primary, TS_STATUS);
        // to be defined
        break;
    }
    case primary_ID_HV_FEEDBACKS_STATUS: {
        // DESERIALIZE(primary, HV_FEEDBACKS_STATUS);
        // to be defined
        break;
    }
    case primary_ID_DAS_ERRORS: {
        // DESERIALIZE(primary, DAS_ERRORS);
        // to be defined
        break;
    }
    case primary_ID_LV_ERRORS: {
        // DESERIALIZE(primary, LV_ERRORS);
        // to be defined
        break;
    }
    default:
        break;*/
  }
}

void update_lv_temp(uint8_t val) {
  // LV_UPDATE_LABEL(low_voltage, lv_temp, val);
}

void update_car_status(uint8_t val);
void can_handle_secondary(struct can_frame frame) {
  int length = frame.can_dlc;
  uint8_t *raw = malloc(length);
  memcpy(raw, frame.data, length * sizeof(uint8_t));

  /*
  switch(frame.can_id)
  {
      case secondary_ID_STEERING_ANGLE:{
          // DESERIALIZE(secondary, STEERING_ANGLE);

          // if(steering.curr_focus == STEER)
              // lv_slider_set_value(steering.slider, (int)data.angle,
  LV_ANIM_OFF);

          break;
      }
      case secondary_ID_PEDALS_OUTPUT:{
          // DESERIALIZE_CONVERSION(secondary, PEDALS_RANGE);

          // if(steering.curr_focus == APPS)
              // lv_slider_set_value(steering.slider, (int)conversion.apps,
  LV_ANIM_OFF);
          // else if(steering.curr_focus == BSE)
              // lv_slider_set_value(steering.slider, (int)conversion.bse_front,
  LV_ANIM_OFF);

          break;
      }
      case secondary_ID_GPS_SPEED:{
          // DESERIALIZE(secondary, GPS_SPEED); does not compile

          break;
      }
  }*/
}
