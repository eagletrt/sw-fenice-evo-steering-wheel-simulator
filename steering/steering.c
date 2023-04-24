#include "steering.h"

steering_t steering;

void test_value_update_incremental(void){
    LV_UPDATE_PROPERTY(ESTIMATED_VELOCITY, steering.AMBIENT_TEMPERATURE++);
}
