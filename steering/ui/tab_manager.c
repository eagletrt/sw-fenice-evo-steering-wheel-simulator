#include "tab_manager.h"


lv_obj_t * scr1;
lv_obj_t * scr2;
lv_obj_t * scr3;
int tab_num = 0;


/*
lv_obj_t *tab1;
lv_obj_t *tab2;
lv_obj_t *tab3;
lv_tabview_t *tab_view;*///cpmmented because screen switching was not working with tabs

void tab_manager(void)
{   
    
    //tab_view = lv_tabview_create(lv_scr_act(), LV_DIR_TOP, 0);
    
    /*
    tab1 = lv_tabview_add_tab(tab_view, "Tab 1");
    tab2 = lv_tabview_add_tab(tab_view, "Tab 2");
    tab3 = lv_tabview_add_tab(tab_view, "Tab 3");
    
    lv_obj_clear_flag(tab1, LV_OBJ_FLAG_SCROLLABLE);
    tab_racing(tab1);
    
    lv_obj_t * label1 = lv_label_create(tab2);
    lv_label_set_text(label1, "Second tab");
    
    lv_obj_t * label2 = lv_label_create(tab3);
    lv_label_set_text(label2, "Third tab");*/
    //group = lv_group_create();
    //scr1  = lv_scr_act();

    scr1  = lv_obj_create(NULL);
    scr2  = lv_obj_create(NULL);
    scr3  = lv_obj_create(NULL);
    
    lv_group_add_obj(g, scr1);
    lv_group_add_obj(g, scr2);
    lv_group_add_obj(g, scr3);
    
    lv_obj_t * label2 = lv_label_create(scr2);
    lv_label_set_text(label2, "Second screen");

    lv_obj_t * label3 = lv_label_create(scr3);
    lv_label_set_text(label3, "Third screen");

    tab_racing(scr1);
    lv_scr_load(scr1);

}

void change_tab(scroll direction){
    
    if(direction == FORWARD){
        tab_num++;
    }else{
        tab_num--;
        if(tab_num == -1){
            tab_num = 2;
        }
    }

    //printf("tab_num: %d\n", tab_num);
        
    switch (tab_num%N_SCREENS)
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

