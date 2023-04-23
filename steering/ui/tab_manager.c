#include "tab_manager.h"


lv_obj_t * scr1;
lv_obj_t * scr2;
lv_obj_t * scr3;
lv_obj_t * steer_calib_tab;
lv_group_t * g;

int tab_num = 0; //change name to tab_position

void tab_manager(void)
{   
    srand(time(NULL)); //init time to gen random numbers
    init_custom_styles();

    scr1  = lv_obj_create(NULL);
    scr2  = lv_obj_create(NULL);
    scr3  = lv_obj_create(NULL);

    steer_calib_tab = lv_obj_create(NULL);
    
    lv_group_add_obj(g, scr1);
    lv_group_add_obj(g, scr2);
    lv_group_add_obj(g, scr3);

    lv_obj_t * label3 = lv_label_create(scr3);
    lv_label_set_text(label3, "Third screen");

    tab_racing(scr1);
    tab_debug(scr2);
    tab_calibration(scr3);
    
    lv_scr_load(scr1);

}

void change_tab(scroll direction){
    
    if(direction == FORWARD){
        tab_num++;
        tab_num = tab_num%N_SCREENS;
    }else{
        tab_num--;
        if(tab_num == -1){
            tab_num = 2;
        }
    }
        
    switch (tab_num)
    {
    case 0:
        lv_scr_load(scr1);
        break;

    case 1:
        lv_scr_load(scr2);
        break;

    case 2:
        lv_scr_load(scr3); 
        break;
    default:
        break;
    }
}
