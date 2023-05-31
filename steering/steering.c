#include "steering.h"

steering_t steering;

void test_value_update_incremental(void){
    LV_UPDATE_LABEL(general_info, delta_time, ++steering.general_info.delta_time);
    
    /*
    LV_UPDATE_LABEL(general_info, estimated_velocity, ++steering.general_info.estimated_velocity);
    if(steering.general_info.estimated_velocity > steering.control.power){   
       steering.general_info.estimated_velocity = 1;
    }
    lv_meter_set_indicator_end_value(steering.custom_meter, steering.indicator_blue, steering.general_info.estimated_velocity);
    */   
}

void steering_values_init(){
    steering.general_info.delta_time = 1;

    steering.general_info.estimated_velocity = 1;
    steering.control.power = 100;
}
