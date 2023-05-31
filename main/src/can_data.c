#include "can_data.h"

#define DESERIALIZE(network, message)                                                                                  \
  network##_message_##message data;                                                                                    \
  network##_deserialize_##message(&data, raw);

void can_handle_primary(struct can_frame frame){

    int length = frame.can_dlc;
    uint8_t *raw = malloc(length);
    memcpy(raw, frame.data, length * sizeof(uint8_t));

    printf("%d\n", frame.can_id);

    switch (frame.can_id)
    {
        case primary_ID_SPEED: {
            
            DESERIALIZE(primary, SPEED);
            LV_UPDATE_LABEL(general_info, estimated_velocity, data.encoder_l%255);

            
            //vest_data_in.omega_fl = conversion.encoder_l;
            break;
        } 
    
        default:
            break;
    }
}