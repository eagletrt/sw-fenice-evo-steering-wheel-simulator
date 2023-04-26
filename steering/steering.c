#include "steering.h"

steering_t steering;

void test_value_update_incremental(void){
    LV_UPDATE_LABEL(general_info, estimated_velocity, steering.general_info.ambient_temperature++);
}
