/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** update_ui
*/

#include "../../include/my.h"

/// @brief update a single button
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
void upd_button(gstruct_t *gstruct, button_t *but, sfRenderWindow *window,
    int enabled)
{
    but->texture_rect.top = (WEIRD_UI ? 100 : 200) * but->state;
    sfRectangleShape_setTextureRect(but->button, but->texture_rect);
    RECT_S_POS(but->button, V2F {V_PO_X(but->pos.x), V_PO_Y(but->pos.y)});
    RECT_S_SIZE(but->button, V2F {V_CO_X(but->size.x), V_CO_Y(but->size.y)});
    is_hover(but, window, gstruct, enabled);
    sfText_setCharacterSize(but->name, V_CO_X(50 * but->size.x / 300.f));
    sfText_setOrigin(but->name, V2F {sfText_getLocalBounds(but->name).width /
        2, sfText_getLocalBounds(but->name).height / 2});
    sfText_setPosition(but->name, V2F {V_PO_X(but->pos.x +
        (RECT_G_GB(but->button).width / 2)), V_PO_Y(but->pos.y +
            (RECT_G_GB(but->button).height / 2) * 0.8)});
    sfRenderWindow_drawRectangleShape(window, but->button, 0);
    sfText_setColor(but->name, (but->state == HOVER ||
        but->state == SELECT) ? sfRed : sfWhite);
    sfRenderWindow_drawText(window, but->name, 0);
}

/// @brief update "wanna quit" menu
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
void upd_wanna_quit(gstruct_t *gstruct, sfRenderWindow *window)
{
    gstruct->gamestate = QUIT_UI->game_while;
    RECT_S_SIZE(QUIT_UI->quit_box, V2F {V_CO_X(520), V_CO_Y(320)});
    RECT_S_POS(QUIT_UI->quit_box, V2F {V_PO_X(700), V_PO_Y(380)});
    sfRectangleShape_setFillColor(QUIT_UI->quit_box, SF_DGREY);
    sfRenderWindow_drawRectangleShape(window, QUIT_UI->quit_box, 0);
    RECT_S_SIZE(QUIT_UI->quit_box, V2F {V_CO_X(500), V_CO_Y(300)});
    RECT_S_POS(QUIT_UI->quit_box, V2F {V_PO_X(710), V_PO_Y(390)});
    sfRectangleShape_setFillColor(QUIT_UI->quit_box, SF_GREY);
    sfRenderWindow_drawRectangleShape(window, QUIT_UI->quit_box, 0);
    sfText_setOrigin(QUIT_UI->wanna_quit,
        V2F {sfText_getLocalBounds(QUIT_UI->wanna_quit).width / 2,
            sfText_getLocalBounds(QUIT_UI->wanna_quit).height / 2});
    sfText_setPosition(QUIT_UI->wanna_quit, V2F {V_PO_X(960), V_PO_Y(480)});
    sfText_setScale(QUIT_UI->wanna_quit, V2F {V_SCA_X(0.5), V_SCA_Y(0.5)});
    sfRenderWindow_drawText(window, QUIT_UI->wanna_quit, 0);
    upd_button(gstruct, QUIT_UI->quit_no, window, 1);
    upd_button(gstruct, QUIT_UI->quit_yes, window, 1);
}

/// @brief print the red text if there is no save.txt
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
/// @param sfVector2f pos
void no_save_found(gstruct_t *gstruct, sfRenderWindow *window, sfVector2f pos)
{
    sfText_setOrigin(START_UI->no_save,
        V2F {sfText_getLocalBounds(START_UI->no_save).width / 2,
            sfText_getLocalBounds(START_UI->no_save).height / 2});
    sfText_setPosition(START_UI->no_save, V2F {V_PO_X(pos.x), V_PO_Y(pos.y)});
    sfRenderWindow_drawText(window, START_UI->no_save, 0);
}

/// @brief update the inventory menu
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
void upd_start_ui(gstruct_t *gstruct, sfRenderWindow *window)
{
    sfView_zoom(VIEW_, 1920.f / sfView_getSize(VIEW_).x);
    sfRectangleShape_setSize(START_UI->box, V2F {V_CO_X(1920), V_CO_Y(1080)});
    RECT_S_POS(START_UI->box, V2F {V_PO_X(0), V_PO_Y(0)});
    sfSprite_setPosition(START_UI->menu, V2F {V_PO_X(100), V_PO_Y(420)});
    sfRenderWindow_drawRectangleShape(window, START_UI->box, 0);
    sfRenderWindow_drawSprite(window, START_UI->menu, 0);
    upd_button(gstruct, START_UI->but_start, window, UISTATE_(start_ui));
    upd_button(gstruct, START_UI->but_load, window, UISTATE_(start_ui));
    upd_button(gstruct, START_UI->but_set, window, UISTATE_(start_ui));
    upd_button(gstruct, START_UI->but_quit, window, UISTATE_(start_ui));
    if (!gstruct->save)
        no_save_found(gstruct, window, V2F {1530, 480});
}

/// @brief upd the UI depending on the current UISTATE_
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
void upd_ui(gstruct_t *gstruct, sfRenderWindow *window)
{
    if (GSTATE_(start))
        upd_start_ui(gstruct, window);
    upd_ingame_ui(gstruct, window);
    if (UISTATE_(set_ui))
        upd_set(gstruct, window);
    if (GSTATE_(gameover))
        upd_gameover(gstruct, window);
    if (UISTATE_(wanna_quit))
        upd_wanna_quit(gstruct, window);
}
