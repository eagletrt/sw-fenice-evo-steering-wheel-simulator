#include "tab_manager.h"


lv_obj_t * scr1;
lv_obj_t * scr2;
lv_obj_t * scr3;
lv_obj_t * scr4;
lv_obj_t * scr5;
lv_group_t * g;

int tab_num = 1; //change name to tab_position

void tab_manager(void)
{   
    srand(time(NULL)); //init time to gen random numbers
    init_custom_styles();

    scr1 = lv_obj_create(NULL);
    scr2 = lv_obj_create(NULL);
    scr3 = lv_obj_create(NULL);
    scr4 = lv_obj_create(NULL);
    scr5 = lv_obj_create(NULL);
    
    lv_group_add_obj(g, scr1);
    lv_group_add_obj(g, scr2);
    lv_group_add_obj(g, scr3);
    lv_group_add_obj(g, scr4);
    lv_group_add_obj(g, scr5);

    tab_racing(scr1);
    tab_sensors(scr2);
    tab_calibration(scr3);
    tab_track_test(scr4);

    tab_debug(scr5);

    lv_scr_load(scr1);

}

void change_tab(bool forward){
    
    if(forward){
        tab_num++;
        tab_num = tab_num%N_SCREENS;
    }else{
        tab_num--;
        if(tab_num < 0){
            tab_num = (N_SCREENS-1);
        }
    }
        
    switch (tab_num)
    {
    case 0:
        lv_scr_load(scr1);
        break;

    case 1:
        lv_scr_load(scr3);
        break;

    case 2:
        lv_scr_load(scr5); 
        break;

    case 3:
        lv_scr_load(scr4); 
        break;

    case 4:
        lv_scr_load(scr2);
        break;
    
    default:
        break;
    }
}
