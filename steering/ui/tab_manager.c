#include "tab_manager.h"



void tab_manager(void)
{
    lv_obj_t *tab_view = lv_tabview_create(lv_scr_act(), LV_DIR_TOP, 0);

    lv_obj_t *tab1 = lv_tabview_add_tab(tab_view, "Tab 1");
    lv_obj_t *tab2 = lv_tabview_add_tab(tab_view, "Tab 2");
    lv_obj_t *tab3 = lv_tabview_add_tab(tab_view, "Tab 3");

    tab_racing(tab1);

    lv_obj_t * label1 = lv_label_create(tab2);
    lv_label_set_text(label1, "Second tab");

    lv_obj_t * label2 = lv_label_create(tab3);
    lv_label_set_text(label2, "Third tab");
}