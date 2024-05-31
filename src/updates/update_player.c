/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** update_player
*/

#include "../../include/my.h"

/// @brief hardcode for the anim state
/// @param float fstate
/// @return the .left of the sftexrect
int anim(float fstate)
{
    int istate = fstate / 1;

    switch (istate) {
    case 0:
        return 32;
    case 1:
        return 0;
    case 2:
        return 32;
    case 3:
        return 64;
    case 4:
        return 32;
    default:
        return 32;
    }
}

/// @brief update the level of the stamina bar
/// @param gstruct_t *gstruct
static void update_stamina(gstruct_t *gstruct)
{
    if (GSTATE_(in_game))
        STATS_->current_stam = (__SPRINT__ && STATS_->iswalking != 0) ?
            MAX(STATS_->current_stam - (MAX(60 / FPS_, 1) * 0.5), 0) :
            MIN(STATS_->current_stam + (MAX(60 / FPS_, 1) * 0.25),
            PSTATS_->max_stam);
    if (GSTATE_(in_game))
        change_health(gstruct, - PSTATS_->health / 1000.f);
}

void next_level(gstruct_t *gstruct)
{
    STATS_->dir = 0;
    STATS_->iswalking = 0;
    INFO_->map_completed++;
    STATS_->stats_points += 3;
    LEVEL_->completed = sfFalse;
    recreate_level(gstruct, V2F {-1, -1}, -1);
}

/// @brief move in the right directions if there is no walls
/// @param gstruct_t *gstruct
static void player_movments(gstruct_t *gstruct)
{
    if (LEVEL_->completed && blue_collision(gstruct))
        next_level(gstruct);
    if (!STATS_->iswalking)
        return;
    if (STATS_->dir == 1)
        for (int i = 0; i < SPEED_; i++)
            STATS_->coords.y += (!HB_PLAYER(1)) ? (60.f / FPS_) : 0;
    if (STATS_->dir == 2)
        for (int i = 0; i < SPEED_; i++)
            STATS_->coords.x -= (!HB_PLAYER(2)) ? (60.f / FPS_) : 0;
    if (STATS_->dir == 3)
        for (int i = 0; i < SPEED_; i++)
            STATS_->coords.x += (!HB_PLAYER(3)) ? (60.f / FPS_) : 0;
    if (STATS_->dir == 4)
        for (int i = 0; i < SPEED_; i++)
            STATS_->coords.y -= (!HB_PLAYER(4)) ? (60.f / FPS_) : 0;
}

/// @brief cycle the player animation
/// @param gstruct_t *gstruct
static void player_anim(gstruct_t *gstruct)
{
    long int micro = sfClock_getElapsedTime(PLAYER_->tex_clock).microseconds;

    if (GSTATE_(paused))
        STATS_->iswalking = 0;
    if (STATS_->iswalking == 0){
        STATS_->fstate = 0;
    }
    if (micro > 16666){
        STATS_->fstate = (STATS_->fstate <= 4) ?
            STATS_->fstate + P_ANIM_RR : P_ANIM_RR;
        sfClock_restart(PLAYER_->tex_clock);
        update_stamina(gstruct);
    }
    player_movments(gstruct);
}

/// @brief draw attack rect and damage hitbox
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
void draw_rects(gstruct_t *gstruct, sfRenderWindow *window)
{
    draw_dbrect(gstruct, FR {X_P + 16, Y_P + 16, 64, 64}, window, sfGreen);
    draw_dbrect(gstruct, STATS_->atk_zone, window, sfBlue);
    if (STATS_->has_attacked)
        draw_atrect(STATS_->atk_zone, window, sfWhite);
}

/// @brief update the player
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
void upd_player(gstruct_t *gstruct, sfRenderWindow *window)
{
    sfSprite_setPosition(PLAYER_->sp_player, STATS_->coords);
    player_anim(gstruct);
    if (STATS_->current_stam <= 0 && __SPRINT__)
        STATS_->is_sprinting = sfFalse;
    if (STATS_->dir)
        PLAYER_->texture_rect.top = 32 * (STATS_->dir - 1);
    PLAYER_->texture_rect.left = 96 * STATS_->armor + anim(STATS_->fstate);
    sfSprite_setTextureRect(PLAYER_->sp_player, PLAYER_->texture_rect);
    sfRenderWindow_drawSprite(window, PLAYER_->sp_player, NULL);
    draw_rects(gstruct, window);
    sfView_setCenter(gstruct->view,
        (sfVector2f){STATS_->coords.x + (PLAYER_PX_SIZE / 2),
        STATS_->coords.y + (PLAYER_PX_SIZE / 2)});
    sfView_zoom(gstruct->view, ZOOM_);
}
