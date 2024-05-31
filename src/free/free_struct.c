/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** free_struct
*/

#include "../../include/my.h"

/// @brief free gstruct
/// @param gstruct_t *gstruct
static void free_gstruct(gstruct_t *gstruct)
{
    free(INFO_);
    free(PLAYER_);
    free(LEVEL_);
    free(UI_);
    free(MAPS_);
    sfView_destroy(gstruct->view);
    sfClock_destroy(gstruct->fpsclock);
    sfClock_destroy(gstruct->windowclock);
    free(gstruct->settings);
}

/// @brief free maps
/// @param gstruct_t *gstruct
static void free_maps(gstruct_t *gstruct)
{
    for (int i = 0; i < NB_MAPS; i++) {
        free(MAPS_[i].name);
        for (int j = 0; MAPS_[i].tiles[j]; j++)
            free(MAPS_[i].tiles[j]);
        free(MAPS_[i].tiles);
        for (int j = 0; MAPS_[i].hitboxes[j]; j++)
            free(MAPS_[i].hitboxes[j]);
        free(MAPS_[i].hitboxes);
    }
}

/// @brief free player
/// @param gstruct_t *gstruct
void free_player(gstruct_t *gstruct)
{
    sfSprite_destroy(PLAYER_->sp_player);
    sfTexture_destroy(PLAYER_->playertex);
    sfClock_destroy(PLAYER_->tex_clock);
    sfMusic_destroy(AUDIO_.music);
    sfSound_destroy(AUDIO_.dash_au);
    sfSound_destroy(AUDIO_.knife_au);
    sfSoundBuffer_destroy(AUDIO_.dash_au_b);
    sfSoundBuffer_destroy(AUDIO_.knife_au_b);
    free(STATS_->skin_path);
    free(PSTATS_);
    free(STATS_);
}

void free_mobs(gstruct_t *gstruct)
{
    for (int i = 0; i < LEVEL_->mobs; i++){
        free(MOB_(i).pstats);
        sfClock_destroy(MOB_(i).stats->attack_cd);
        free(MOB_(i).stats);
        sfSprite_destroy(MOB_(i).sp_mob);
        sfTexture_destroy(MOB_(i).mobtex);
        sfClock_destroy(MOB_(i).tex_clock);
        sfRectangleShape_destroy(MOB_(i).max_hp);
        sfRectangleShape_destroy(MOB_(i).hp);
    }
    free(LEVEL_->mob);
}

/// @brief free level
/// @param gstruct_t *gstruct
void free_level(gstruct_t *gstruct)
{
    sfSprite_destroy(LEVEL_->sp_tilemap);
    sfTexture_destroy(LEVEL_->maptex);
    sfRectangleShape_destroy(LEVEL_->background);
    sfImage_destroy(LEVEL_->buffer);
    sfImage_destroy(LEVEL_->map);
    sfImage_destroy(LEVEL_->hitboxes);
    free_mobs(gstruct);
}

/// @brief free everything
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
void free_struct(gstruct_t *gstruct, int end)
{
    int elapmi = 0;
    int elapsedsec = 0;

    elapmi = sfTime_asMicroseconds(sfClock_getElapsedTime(gstruct->gameclock));
    elapsedsec = elapmi / 1000000;
    free_ui(gstruct);
    free_player(gstruct);
    free_level(gstruct);
    free_maps(gstruct);
    free_gstruct(gstruct);
    if (!end)
        return;
    sfClock_destroy(gstruct->gameclock);
    printf("playtime : %d:%02d\n", elapsedsec / 60, elapsedsec % 60);
}
