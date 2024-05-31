/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** update_ingame_ui
*/

#include "../../include/my.h"

/// @brief update the transparent black backround when paused
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
void upd_paused_ui(gstruct_t *gstruct, sfRenderWindow *window)
{
    sfRectangleShape_setSize(PAUSED_UI->box, V2F {V_CO_X(1920), V_CO_Y(1080)});
    RECT_S_POS(PAUSED_UI->box, V2F {V_PO_X(0), V_PO_Y(0)});
    sfRenderWindow_drawRectangleShape(window, PAUSED_UI->box, 0);
}

/// @brief update the bars in the gui
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
static void upd_gui_bars(gstruct_t *gstruct, sfRenderWindow *window)
{
    RECT_S_SIZE(GUI_->max_hp, V2F {V_CO_X(250), V_CO_Y(15)});
    RECT_S_POS(GUI_->max_hp, V2F {V_PO_X(125), V_PO_Y(1030)});
    RECT_S_SIZE(GUI_->current_hp, V2F {V_CO_X(250.f * HP_RATIO), V_CO_Y(15)});
    RECT_S_POS(GUI_->current_hp, V2F {V_PO_X(125), V_PO_Y(1030)});
    sfRenderWindow_drawRectangleShape(window, GUI_->max_hp, 0);
    sfRenderWindow_drawRectangleShape(window, GUI_->current_hp, 0);
    RECT_S_SIZE(GUI_->max_st, V2F {V_CO_X(250), V_CO_Y(15)});
    RECT_S_POS(GUI_->max_st, V2F {V_PO_X(125), V_PO_Y(1000)});
    RECT_S_SIZE(GUI_->current_st, V2F {V_CO_X(250.f * ST_RATIO), V_CO_Y(15)});
    RECT_S_POS(GUI_->current_st, V2F {V_PO_X(125), V_PO_Y(1000)});
    sfRenderWindow_drawRectangleShape(window, GUI_->max_st, 0);
    sfRenderWindow_drawRectangleShape(window, GUI_->current_st, 0);
}

/// @brief show to "profile picture" of the hero
/// @param gstruct_t *gstruct
/// @param pos position (later used as V_PO_)
/// @param size size (later used as V_CO_)
/// @param sfRenderWindow *window
void upd_profile(gstruct_t *gstruct, sfVector2f pos, sfVector2f size,
    sfRenderWindow *window)
{
    GUI_->texture_rect.left = 96 * STATS_->armor + 32;
    sfRectangleShape_setTextureRect(GUI_->profile, GUI_->texture_rect);
    RECT_S_SIZE(GUI_->profile, size);
    RECT_S_POS(GUI_->profile, pos);
    sfRenderWindow_drawRectangleShape(window, GUI_->profile, 0);
}

/// @brief update the game user interface
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
static void upd_gui(gstruct_t *gstruct, sfRenderWindow *window)
{
    gstruct->gamestate = in_game;
    sfRectangleShape_setSize(GUI_->box, V2F {V_CO_X(400), V_CO_Y(100)});
    RECT_S_POS(GUI_->box, V2F {V_PO_X(20), V_PO_Y(960)});
    sfRenderWindow_drawRectangleShape(window, GUI_->box, 0);
    upd_profile(gstruct, V2F {V_PO_X(30), V_PO_Y(970)},
        V2F {V_CO_X(80), V_CO_Y(80)}, window);
    upd_gui_bars(gstruct, window);
    upd_button(gstruct, GUI_->but_esc, window, 1);
}

/// @brief update the echap menu
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
static void upd_esc(gstruct_t *gstruct, sfRenderWindow *window)
{
    gstruct->gamestate = paused;
    sfRectangleShape_setSize(ESC_->box, V2F {V_CO_X(MENU_X), V_CO_Y(MENU_Y)});
    ESC_->pos.x = V_PO_X(((1920 - MENU_X) / 2));
    ESC_->pos.y = V_PO_Y(((1080 - MENU_Y) / 2));
    RECT_S_POS(ESC_->box, ESC_->pos);
    sfSprite_setPosition(ESC_->menu, V2F {ESC_->pos.x + V_CO_X(MENU_X / 2),
        ESC_->pos.y + V_CO_Y(100)});
    sfSprite_setScale(ESC_->menu, V2F {V_SCA_X(0.8), V_SCA_Y(0.8)});
    sfRenderWindow_drawRectangleShape(window, ESC_->box, 0);
    sfRenderWindow_drawSprite(window, ESC_->menu, 0);
    upd_button(gstruct, ESC_->but_inv, window, 1);
    upd_button(gstruct, ESC_->but_load, window, 1);
    upd_button(gstruct, ESC_->but_save, window, 1);
    upd_button(gstruct, ESC_->but_settings, window, 1);
    upd_button(gstruct, ESC_->but_back, window, 1);
    if (!gstruct->save)
        no_save_found(gstruct, window, V2F {960, 600});
}

/// @brief gameover screen update
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
void upd_gameover(gstruct_t *gstruct, sfRenderWindow *window)
{
    gstruct->uistate = wanna_quit;
    upd_paused_ui(gstruct, window);
    QUIT_UI->game_to_load = start;
    QUIT_UI->game_while = gameover;
    QUIT_UI->ui_to_load = start_ui;
    upd_wanna_quit(gstruct, window);
}

/// @brief upd the UI in game depending on the current UISTATE_
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
void upd_ingame_ui(gstruct_t *gstruct, sfRenderWindow *window)
{
    if (GSTATE_(paused))
        upd_paused_ui(gstruct, window);
    if (UISTATE_(game_ui))
        upd_gui(gstruct, window);
    if (UISTATE_(esc_ui))
        upd_esc(gstruct, window);
    if (UISTATE_(inv_ui))
        upd_inv(gstruct, window);
}
