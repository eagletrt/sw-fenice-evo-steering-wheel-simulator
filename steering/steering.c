#include "steering.h"

steering_t steering;

void test_value_update_incremental(void){
    LV_UPDATE_LABEL(general_info, estimated_velocity, steering.general_info.ambient_temperature++);
    printf("%d\n", steering.general_info.ambient_temperature);
    //lv_meter_set_indicator_end_value(steering.custom_meter, steering.indicator_blue, steering.general_info.ambient_temperature);
    lv_meter_set_indicator_end_value(steering.custom_meter, steering.indicator_white, steering.general_info.ambient_temperature++);
}

void steering_values_init(){
    steering.control.power = 100;
}
