/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** free_ingame_ui
*/

#include "../../include/my.h"

/// @brief destroy game user interface
/// @param gstruct_t *gstruct
void free_gui(gstruct_t *gstruct)
{
    sfRectangleShape_destroy(GUI_->max_hp);
    sfRectangleShape_destroy(GUI_->current_hp);
    sfRectangleShape_destroy(GUI_->max_st);
    sfRectangleShape_destroy(GUI_->current_st);
    sfRectangleShape_destroy(GUI_->box);
    sfRectangleShape_destroy(GUI_->profile);
    sfRectangleShape_destroy(PAUSED_UI->box);
    free_button(GUI_->but_esc);
    free(GUI_->but_esc);
}

/// @brief free echap menu
/// @param gstruct_t *gstruct
static void free_esc(gstruct_t *gstruct)
{
    free_button(ESC_->but_inv);
    free_button(ESC_->but_load);
    free_button(ESC_->but_save);
    free_button(ESC_->but_settings);
    free_button(ESC_->but_back);
    free(ESC_->but_inv);
    free(ESC_->but_load);
    free(ESC_->but_save);
    free(ESC_->but_settings);
    free(ESC_->but_back);
    sfRectangleShape_destroy(ESC_->box);
    sfTexture_destroy(ESC_->menu_tex);
    sfSprite_destroy(ESC_->menu);
}

/// @brief free a single inventory box
/// @param s_box box to free
void free_box(stat_box_t *s_box)
{
    sfText_destroy(s_box->stat_text);
    free_button(s_box->plus);
    free(s_box->plus);
    sfRectangleShape_destroy(s_box->box);
    free(s_box->stat_name);
}

/// @brief free inventory menu
/// @param gstruct_t *gstruct
static void free_boxes(gstruct_t *gstruct)
{
    free_box(INV_->b_strenght);
    free_box(INV_->b_dexterity);
    free_box(INV_->b_agility);
    free_box(INV_->b_defense);
    free_box(INV_->b_endurance);
    free(INV_->b_strenght);
    free(INV_->b_dexterity);
    free(INV_->b_agility);
    free(INV_->b_defense);
    free(INV_->b_endurance);
    sfRectangleShape_destroy(INV_->box);
    sfRectangleShape_destroy(INV_->stats_box);
    sfRectangleShape_destroy(INV_->skin_box);
    free_button(INV_->but_p_armor);
    free_button(INV_->but_p_skin);
    free_button(INV_->but_m_armor);
    free_button(INV_->but_m_skin);
}

/// @brief free inventory menu
/// @param gstruct_t *gstruct
static void free_inv(gstruct_t *gstruct)
{
    free_boxes(gstruct);
    free(INV_->but_p_armor);
    free(INV_->but_p_skin);
    free(INV_->but_m_armor);
    free(INV_->but_m_skin);
    sfFont_destroy(INV_->font);
    sfTexture_destroy(INV_->menu_tex);
    sfSprite_destroy(INV_->menu);
    sfText_destroy(INV_->inv_text);
    free(INV_->stats_string);
    sfTexture_destroy(INV_->arrows_tex);
    sfRectangleShape_destroy(INV_->arrows);
}

/// @brief free user interfaces
/// @param gstruct_t *gstruct
void free_ingame_ui(gstruct_t *gstruct)
{
    free_esc(gstruct);
    free_inv(gstruct);
    free_gui(gstruct);
}
