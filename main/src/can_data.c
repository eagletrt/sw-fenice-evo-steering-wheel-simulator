#include "can_data.h"

#define DESERIALIZE(network, message)                                                                                  \
  network##_message_##message data;                                                                                    \
  network##_deserialize_##message(&data, raw);

#define DESERIALIZE_CONVERSION(network, message)                                                                       \
  DESERIALIZE(network, message)                                                                                        \
  network##_message_##message##_conversion conversion;                                                                 \
  network##_raw_to_conversion_struct_##message(&conversion, &data);


void can_handle_primary(struct can_frame frame){

    int length = frame.can_dlc;
    uint8_t *raw = malloc(length);
    memcpy(raw, frame.data, length * sizeof(uint8_t));

    // printf("%d\n", frame.can_id);

    switch (frame.can_id)
    {
        case primary_ID_SPEED: {
            
            DESERIALIZE(primary, SPEED);
            LV_UPDATE_LABEL(general_info, estimated_velocity, data.encoder_l%255);
            break;
        } 
        
    
        default:
            break;
    }
}

void can_handle_secondary(struct can_frame frame){
    int length = frame.can_dlc;
    uint8_t *raw = malloc(length);
    memcpy(raw, frame.data, length * sizeof(uint8_t));

    switch(frame.can_id)
    {
        case secondary_ID_STEERING_ANGLE:{
            DESERIALIZE(secondary, STEERING_ANGLE);

            if(steering.curr_focus == STEER)
                lv_slider_set_value(steering.slider, (int)data.angle, LV_ANIM_OFF);
            
            break;
        }
        case secondary_ID_PEDALS_OUTPUT:{
            DESERIALIZE_CONVERSION(secondary, PEDALS_OUTPUT);

            if(steering.curr_focus == APPS)
                lv_slider_set_value(steering.slider, (int)conversion.apps, LV_ANIM_OFF);
            else if(steering.curr_focus == BSE)
                lv_slider_set_value(steering.slider, (int)conversion.bse_front, LV_ANIM_OFF);
            
            break;
        }
        case secondary_ID_GPS_SPEED:{
            DESERIALIZE(secondary, GPS_SPEED);

            break;
        }
    }

}