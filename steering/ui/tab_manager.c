#include "tab_manager.h"


lv_obj_t * scr1;
lv_obj_t * scr2;
lv_obj_t * scr3;
lv_obj_t * scr4;
lv_obj_t * scr5;
lv_obj_t *notification_scr;
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
    notification_scr= lv_obj_create(NULL);
    
    lv_group_add_obj(g, scr1);
    lv_group_add_obj(g, scr2);
    lv_group_add_obj(g, scr3);
    lv_group_add_obj(g, scr4);
    lv_group_add_obj(g, scr5);
    lv_group_add_obj(g, notification_scr);

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

lv_obj_t *prev_scr;
bool first = true;
void notification_screen(lv_timer_t * timer){

    if(first){
        char *msg = timer->user_data;
        
        lv_obj_t *info = lv_label_create(notification_scr);
        lv_obj_add_style(info, &label_style, LV_PART_MAIN);
        lv_obj_set_style_text_color(info, lv_color_hex(COLOR_PRIMARY_HEX), LV_PART_MAIN);
        lv_obj_set_style_text_font(info, &lv_font_inter_bold_70, LV_PART_MAIN);
        lv_label_set_text_fmt(info, "%s", msg); 
        lv_obj_set_style_opa(info, LV_OPA_COVER, LV_PART_MAIN);
        lv_obj_align(info, LV_ALIGN_CENTER, 0, 0);

        prev_scr = lv_disp_get_scr_act(NULL);
        lv_scr_load(notification_scr);

        first = false;
    }else{
        lv_scr_load(prev_scr);

        first = true;
    }

}