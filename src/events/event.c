/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** event
*/

#include "../../include/my.h"

/// @brief for game events
/// @param sfEvent *event
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
void global_events(gstruct_t *gstruct, sfEvent *event)
{
    if ((KKP_(sfKeyLAlt) && KKP_(sfKeyF4)) || event->type == sfEvtClosed){
        QUIT_UI->ui_to_load = (GSTATE_(start) ? start_ui : esc_ui);
        QUIT_UI->game_to_load = gstruct->gamestate;
        QUIT_UI->game_while = (GSTATE_(start) ? start : paused);
        gstruct->uistate = wanna_quit;
    }
    if (KEY_(sfKeyEscape) && (GSTATE_(paused) || GSTATE_(in_game)))
        gstruct->uistate = (UISTATE_(game_ui) ? esc_ui : game_ui);
    if (KEY_(sfKeyEscape) && (GSTATE_(start)))
        gstruct->uistate = start_ui;
}

/// @brief get events
/// @param sfRenderWindow *window
/// @param sfEvent *event
/// @param gstruct_t *gstruct
void analyse_events(sfRenderWindow *window, sfEvent *event, gstruct_t *gstruct)
{
    ZOOM_ = 1;
    while (sfRenderWindow_pollEvent(window, event)){
        if (UISTATE_(wanna_quit) && !KEY_(sfKeyEscape)){
            wanna_quit_events(gstruct, event);
            continue;
        }
        if (UISTATE_(start_ui))
            start_events(gstruct, event);
        if (GSTATE_(in_game))
            player_events(gstruct, event, window);
        if (UISTATE_(esc_ui) || UISTATE_(game_ui))
            esc_events(gstruct, event);
        if (UISTATE_(set_ui) && GSTATE_(paused) && 0)
            esc_events(gstruct, event);
        if (UISTATE_(set_ui))
            set_events(gstruct, event, window);
        if (UISTATE_(inv_ui) && GSTATE_(paused))
            inv_events(gstruct, event);
        global_events(gstruct, event);
    }
}
