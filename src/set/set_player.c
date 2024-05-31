/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** set_skin
*/

#include "../../include/my.h"

/// @brief set the player skin to skin_id and recreate textures
/// @param gstruct_t *gstruct
/// @param int skin_id
void set_skin(gstruct_t *gstruct, int skin_id)
{
    STATS_->skin = skin_id;
    sprintf(STATS_->skin_path, "ressources/Player/Character%d.png",
        STATS_->skin);
    sfTexture_destroy(PLAYER_->playertex);
    PLAYER_->playertex = sfTexture_createFromFile(STATS_->skin_path, NULL);
    sfSprite_setTexture(PLAYER_->sp_player, PLAYER_->playertex, sfFalse);
    sfRectangleShape_setTexture(GUI_->profile, PLAYER_->playertex, sfFalse);
}

/// @brief set a player stat
/// @param stat pointer the the stat to change (NULL if none)
/// @param stats_points pointer to stats_points (NULL if no stats points loss)
/// @param value positive or negative
void set_stat(int *stat, int *stats_points, int value)
{
    if (stat)
        (*stat) += value;
    if (stats_points)
        (*stats_points) -= 1;
}

/// @brief change player health by nb
/// @param gstruct_t *gstruct
/// @param nb damages/heal (negative nb for heal)
/// @note the function doesn't take defense in count
void change_health(gstruct_t *gstruct, float nb)
{
    float hp = STATS_->current_health - nb;

    if (nb >= 0)
        STATS_->current_health = hp;
    else
        STATS_->current_health = MIN(hp, PSTATS_->health);
    if (STATS_->current_health <= 0){
        gstruct->gamestate = gameover;
        gstruct->uistate = gameover_ui;
    }
    return;
}
