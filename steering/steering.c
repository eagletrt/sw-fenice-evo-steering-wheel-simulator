#include "steering.h"

steering_t sensors_data;



/*make more functions with different updating rates*/ //incremental and random;

void test_value_update(){

    sensors_data.value_LV_PERCENT = rand()%100;
    lv_label_set_text_fmt(sensors_data.lb_LV_PERCENT, "%d", sensors_data.value_LV_PERCENT);

    sensors_data.value_LV_TEMP = rand()%100;
    lv_label_set_text_fmt(sensors_data.lb_LV_TEMP, "%d", sensors_data.value_LV_TEMP);

    sensors_data.value_HV_PERCENT = rand()%100;
    lv_label_set_text_fmt(sensors_data.lb_LV_PERCENT, "%d", sensors_data.value_LV_PERCENT);

    sensors_data.value_HV_TEMP = rand()%100;
    lv_label_set_text_fmt(sensors_data.lb_HV_TEMP, "%d", sensors_data.value_HV_TEMP);



    sensors_data.value_SLIP = rand()%100;
    lv_label_set_text_fmt(sensors_data.lb_SLIP, "%d", sensors_data.value_SLIP);

    sensors_data.value_TORQUE = rand()%100;
    lv_label_set_text_fmt(sensors_data.lb_TORQUE, "%d", sensors_data.value_TORQUE);




    sensors_data.value_DELTA_TIME = rand()%100;
    lv_label_set_text_fmt(sensors_data.lb_DELTA_TIME, "%d", sensors_data.value_DELTA_TIME);

}

void test_value_update_incremental(){

    sensors_data.value_ESTIMATED_VELOCITY++;
    lv_label_set_text_fmt(sensors_data.lb_ESTIMATED_VELOCITY, "%d", sensors_data.value_ESTIMATED_VELOCITY);

    //lv_meter_set_indicator_end_value(&sensors_data.custom_meter, &sensors_data.lb_GPS_SPEED, &sensors_data.value_ESTIMATED_VELOCITY);

}