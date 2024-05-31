/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** event_ui
*/

#include "../../include/my.h"

/// @brief for eschap menu events
/// @param gstruct_t *gstruct
/// @param sfEvent *event
void esc_events(gstruct_t *gstruct, sfEvent *event)
{
    is_clicked(ESC_->but_inv, event);
    is_clicked(ESC_->but_save, event);
    is_clicked(ESC_->but_load, event);
    is_clicked(ESC_->but_settings, event);
    is_clicked(ESC_->but_back, event);
    if (BUTTON_CLICKED(ESC_->but_inv) && UISTATE_(esc_ui))
        gstruct->uistate = inv_ui;
    if (BUTTON_CLICKED(ESC_->but_settings) && UISTATE_(esc_ui))
        gstruct->uistate = set_ui;
    if (BUTTON_CLICKED(ESC_->but_save) && UISTATE_(esc_ui))
        save_struct(gstruct);
    if (BUTTON_CLICKED(ESC_->but_load) && UISTATE_(esc_ui))
        load_struct(gstruct);
    if (BUTTON_CLICKED(ESC_->but_back))
        gstruct->uistate = (UISTATE_(game_ui) ? esc_ui : game_ui);
}

/// @brief for inventory menu events
/// @param gstruct_t *gstruct
/// @param sfEvent *event
static void box_events(gstruct_t *gstruct, sfEvent *event)
{
    is_clicked(INV_->b_strenght->plus, event);
    is_clicked(INV_->b_dexterity->plus, event);
    is_clicked(INV_->b_agility->plus, event);
    is_clicked(INV_->b_defense->plus, event);
    is_clicked(INV_->b_endurance->plus, event);
    if (!(STATS_->stats_points > 0))
        return;
    if (BUTTON_CLICKED(INV_->b_strenght->plus))
        set_stat(&PSTATS_->strenght, &STATS_->stats_points, 1);
    if (BUTTON_CLICKED(INV_->b_dexterity->plus))
        set_stat(&PSTATS_->dexterity, &STATS_->stats_points, 1);
    if (BUTTON_CLICKED(INV_->b_agility->plus))
        set_stat(&PSTATS_->agility, &STATS_->stats_points, 1);
    if (BUTTON_CLICKED(INV_->b_defense->plus))
        set_stat(&PSTATS_->defense, &STATS_->stats_points, 1);
    if (BUTTON_CLICKED(INV_->b_endurance->plus))
        set_stat(&PSTATS_->health, &STATS_->stats_points, 10);
}

/// @brief for inventory menu events
/// @param gstruct_t *gstruct
/// @param sfEvent *event
void inv_events(gstruct_t *gstruct, sfEvent *event)
{
    is_clicked(ESC_->but_back, event);
    is_clicked(INV_->but_p_armor, event);
    is_clicked(INV_->but_p_skin, event);
    is_clicked(INV_->but_m_armor, event);
    is_clicked(INV_->but_m_skin, event);
    box_events(gstruct, event);
    if (BUTTON_CLICKED(ESC_->but_back))
        gstruct->uistate = game_ui;
    if (BUTTON_CLICKED(INV_->but_p_armor))
        STATS_->armor = ((STATS_->armor < 4) ? STATS_->armor + 1 : 0);
    if (BUTTON_CLICKED(INV_->but_m_armor))
        STATS_->armor = ((STATS_->armor > 0) ? STATS_->armor - 1 : 4);
    if (BUTTON_CLICKED(INV_->but_p_skin))
        set_skin(gstruct, ((STATS_->skin < 8) ? STATS_->skin + 1 : 1));
    if (BUTTON_CLICKED(INV_->but_m_skin))
        set_skin(gstruct, ((STATS_->skin > 1) ? STATS_->skin - 1 : 8));
}

/// @brief for start menu events
/// @param gstruct_t *gstruct
/// @param sfEvent *event
void start_events(gstruct_t *gstruct, sfEvent *event)
{
    is_clicked(START_UI->but_start, event);
    is_clicked(START_UI->but_set, event);
    is_clicked(START_UI->but_load, event);
    is_clicked(START_UI->but_quit, event);
    if (BUTTON_CLICKED(START_UI->but_start)){
        free_struct(gstruct, 0);
        create_structs(gstruct, DEBUG_, 0);
        gstruct->uistate = game_ui;
    }
    if (BUTTON_CLICKED(START_UI->but_quit)){
        gstruct->uistate = wanna_quit;
        QUIT_UI->ui_to_load = start_ui;
        QUIT_UI->game_to_load = start;
        QUIT_UI->game_while = start;
    }
    if (BUTTON_CLICKED(START_UI->but_set))
        gstruct->uistate = set_ui;
    if (BUTTON_CLICKED(START_UI->but_load))
        load_struct(gstruct);
}

/// @brief for wana_quit menu events
/// @param gstruct_t *gstruct
/// @param sfEvent *event
void wanna_quit_events(gstruct_t *gstruct, sfEvent *event)
{
    is_clicked(QUIT_UI->quit_yes, event);
    is_clicked(QUIT_UI->quit_no, event);
    if (BUTTON_CLICKED(QUIT_UI->quit_no)){
        gstruct->uistate = QUIT_UI->ui_to_load;
        gstruct->gamestate = QUIT_UI->game_to_load;
    }
    if (BUTTON_CLICKED(QUIT_UI->quit_yes)){
        gstruct->gamestate = end;
        gstruct->uistate = start_ui;
        gstruct->close_game = sfTrue;
    }
    if (event->type == sfEvtClosed)
        gstruct->close_game = sfTrue;
}
