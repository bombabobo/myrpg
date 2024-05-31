/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-marin.lagie
** File description:
** update_settings.c
*/
#include "../../include/my.h"

static void upd_resolution(gstruct_t *gstruct, sfRenderWindow *window)
{
    sfRectangleShape_setSize(SET_->box_res, V2F {V_CO_X(900), V_CO_Y(80)});
    RECT_S_POS(SET_->box_res, V2F {V_PO_X(550), V_PO_Y(400)});
    sfRenderWindow_drawRectangleShape(window, SET_->box_res, 0);
    sfRenderWindow_drawText(window, SET_->res_text, 0);
    upd_button(gstruct, SET_->but_fullscreen, window, 1);
    upd_button(gstruct, SET_->but_auto, window, 1);
    upd_button(gstruct, SET_->but_res2, window, 1);
    upd_button(gstruct, SET_->but_res3, window, 1);
    upd_button(gstruct, SET_->but_res4, window, 1);
    sfText_setPosition(SET_->res_text, V2F {V_PO_X(590), V_PO_Y(410)});
}

static void upd_fps(gstruct_t *gstruct, sfRenderWindow *window)
{
    sfRectangleShape_setSize(SET_->box_fps, V2F {V_CO_X(900), V_CO_Y(80)});
    RECT_S_POS(SET_->box_fps, V2F {V_PO_X(550), V_PO_Y(300)});
    sfRenderWindow_drawRectangleShape(window, SET_->box_fps, 0);
    sfRenderWindow_drawText(window, SET_->fps_text, 0);
    upd_button(gstruct, SET_->but_fps30, window, 1);
    upd_button(gstruct, SET_->but_fps60, window, 1);
    upd_button(gstruct, SET_->but_fps120, window, 1);
    sfText_setPosition(SET_->fps_text, V2F {V_PO_X(590), V_PO_Y(310)});
}

/// @brief update the settings menu
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
void upd_set(gstruct_t *gstruct, sfRenderWindow *window)
{
    upd_paused_ui(gstruct, window);
    sfView_zoom(VIEW_, 1920.f / sfView_getSize(VIEW_).x);
    sfRectangleShape_setSize(SET_->box, V2F {V_CO_X(1920), V_CO_Y(1080)});
    RECT_S_POS(SET_->box, V2F {V_PO_X(0), V_PO_Y(0)});
    sfRectangleShape_setSize(SET_->box_set, V2F {V_CO_X(1000), V_CO_Y(700)});
    RECT_S_POS(SET_->box_set, V2F {V_PO_X(500), V_PO_Y(250)});
    sfSprite_setPosition(SET_->menu, V2F {V_PO_X(960), V_PO_Y(150)});
    sfSprite_setScale(SET_->menu, V2F {V_SCA_X(0.7), V_SCA_Y(0.7)});
    sfRenderWindow_drawRectangleShape(window, SET_->box, 0);
    sfRenderWindow_drawRectangleShape(window, SET_->box_set, 0);
    sfRenderWindow_drawSprite(window, SET_->menu, 0);
    upd_fps(gstruct, window);
    upd_resolution(gstruct, window);
}
