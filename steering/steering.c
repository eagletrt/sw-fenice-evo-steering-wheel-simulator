#include "steering.h"

steering_t steering;

void test_value_update_incremental(void){
    LV_UPDATE_PROPERTY(estimated_velocity, steering.ambient_temperature++);
}
