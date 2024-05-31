/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** free_ui
*/

#include "../../include/my.h"

/// @brief free any button
/// @param button_t *but
void free_button(button_t *but)
{
    sfFont_destroy(but->font);
    sfText_destroy(but->name);
    sfTexture_destroy(but->button_tex);
    sfRectangleShape_destroy(but->button);
    sfClock_destroy(but->clic_clock);
}

void free_set_buttons(gstruct_t *gstruct)
{
    free_button(SET_->but_fps30);
    free_button(SET_->but_fps60);
    free_button(SET_->but_fps120);
    free_button(SET_->but_fullscreen);
    free_button(SET_->but_auto);
    free_button(SET_->but_res2);
    free_button(SET_->but_res3);
    free_button(SET_->but_res4);
    free(SET_->but_fps30);
    free(SET_->but_fps60);
    free(SET_->but_fps120);
    free(SET_->but_fullscreen);
    free(SET_->but_auto);
    free(SET_->but_res2);
    free(SET_->but_res3);
    free(SET_->but_res4);
}

/// @brief free setting menu
/// @param gstruct_t *gstruct
static void free_set(gstruct_t *gstruct)
{
    sfRectangleShape_destroy(SET_->box);
    sfRectangleShape_destroy(SET_->box_set);
    sfRectangleShape_destroy(SET_->box_fps);
    sfRectangleShape_destroy(SET_->box_res);
    sfTexture_destroy(SET_->menu_tex);
    sfSprite_destroy(SET_->menu);
    sfFont_destroy(SET_->font);
    sfText_destroy(SET_->fps_text);
    sfText_destroy(SET_->res_text);
    free_set_buttons(gstruct);
}

/// @brief free start menu
/// @param gstruct_t *gstruct
static void free_start_ui(gstruct_t *gstruct)
{
    free_button(START_UI->but_start);
    free_button(START_UI->but_load);
    free_button(START_UI->but_set);
    free_button(START_UI->but_quit);
    free(START_UI->but_start);
    free(START_UI->but_load);
    free(START_UI->but_set);
    free(START_UI->but_quit);
    sfRectangleShape_destroy(START_UI->box);
    sfTexture_destroy(START_UI->menu_tex);
    sfSprite_destroy(START_UI->menu);
    sfText_destroy(START_UI->no_save);
}

/// @brief free quit menu
/// @param gstruct_t *gstruct
static void free_quit_ui(gstruct_t *gstruct)
{
    free_button(QUIT_UI->quit_yes);
    free_button(QUIT_UI->quit_no);
    free(QUIT_UI->quit_yes);
    free(QUIT_UI->quit_no);
    sfRectangleShape_destroy(QUIT_UI->quit_box);
    sfText_destroy(QUIT_UI->wanna_quit);
}

/// @brief free user interfaces
/// @param gstruct_t *gstruct
void free_ui(gstruct_t *gstruct)
{
    free_ingame_ui(gstruct);
    free_set(gstruct);
    free_quit_ui(gstruct);
    free_start_ui(gstruct);
    free(ESC_);
    free(GUI_);
    free(SET_);
    free(INV_);
    free(START_UI);
    free(QUIT_UI);
    free(PAUSED_UI);
}
