/*
** EPITECH PROJECT, 2016
** Untitled (Workspace)
** File description:
** update_mobs
*/

#include "../../include/my.h"

/// @brief move in the right directions if there is no walls
/// @param gstruct_t *gstruct
static void mob_movments(gstruct_t *gstruct, ennemy_t *mob)
{
    if (mob->stats->iswalking == 0 || mob->stats->dir == 0)
        return;
    if (mob->stats->dir == 1)
        for (int i = 0; i < mob->pstats->speed; i++)
            mob->stats->coords.y += (60.f / FPS_);
    if (mob->stats->dir == 2)
        for (int i = 0; i < mob->pstats->speed; i++)
            mob->stats->coords.x -= (60.f / FPS_);
    if (mob->stats->dir == 3)
        for (int i = 0; i < mob->pstats->speed; i++)
            mob->stats->coords.x += (60.f / FPS_);
    if (mob->stats->dir == 4)
        for (int i = 0; i < mob->pstats->speed; i++)
            mob->stats->coords.y -= (60.f / FPS_);
}

/// @brief move in the right directions if there is no walls
/// @param gstruct_t *gstruct
static void mob_direction(gstruct_t *gstruct, ennemy_t *mob)
{
    double dist = sqrt(pow(X_P - X_M, 2) + pow(Y_P - Y_M, 2));
    double angle = atan2(Y_P - Y_M, X_P - X_M) * 180 / M_PI + 45;

    mob->stats->iswalking = (dist > 500 && mob->max_hp == mob->hp) ? 0 : 1;
    if (dist < mob->stats->approach || (dist > 500 && mob->max_hp == mob->hp))
        return;
    if (A_EQUAL(angle, 0) || A_EQUAL(angle, 90) ||
        A_EQUAL(angle, -90) || A_EQUAL(angle, 180))
        return;
    if (angle > 0 && angle < 90)
        mob->stats->dir = RIGHT;
    if (angle > 90 && angle < 180)
        mob->stats->dir = DOWN;
    if (angle > -90 && angle < 0)
        mob->stats->dir = UP;
    if (angle < -90 || angle > 180)
        mob->stats->dir = LEFT;
}

/// @brief deals damages to the player if their hitbox are colliding)
/// @param gstruct_t *gstruct
/// @param ennemy_t *mob
void mob_collisions(gstruct_t *gstruct, ennemy_t *mob)
{
    sfBool touch_p = sfFloatRect_intersects(&FR {X_M,
        Y_M, 96, 96}, &FR {X_P + 16, Y_P + 16, 64, 64}, NULL);
    sfBool got_hit = sfFloatRect_intersects(&STATS_->atk_zone,
        &FR {X_M + 16, Y_M + 16, 64, 64}, NULL);

    if (touch_p && CLOCK_GETTIME(mob->stats->attack_cd) > 500000.f
        / mob->pstats->atk_speed){
        change_health(gstruct, mob->pstats->damages - PSTATS_->defense / 10);
        sfClock_restart(mob->stats->attack_cd);
    }
    if (STATS_->has_attacked == 2 && got_hit)
        mob->stats->current_health -= PSTATS_->strenght / 4;
    if (mob->stats->current_health <= 0){
        mob->stats->isalive = 0;
        STATS_->level += (0.5 / (1.f + (STATS_->level) / 10.f));
        STATS_->stats_points += 1;
    }
}

/// @brief cycle the player animation
/// @param gstruct_t *gstruct
static void mob_anim(gstruct_t *gstruct, ennemy_t *mob)
{
    long int micro = sfClock_getElapsedTime(mob->tex_clock).microseconds;

    if (GSTATE_(paused))
        mob->stats->iswalking = 0;
    if (mob->stats->iswalking == 0){
        mob->stats->fstate = 0;
    }
    if (micro > 16666){
        mob->stats->fstate = (mob->stats->fstate <= 4) ?
            mob->stats->fstate + M_ANIM_RR : M_ANIM_RR;
        sfClock_restart(mob->tex_clock);
    }
    mob_direction(gstruct, mob);
    mob_movments(gstruct, mob);
    mob_collisions(gstruct, mob);
}

/// @brief print the hp bar of the current ennemy
/// @param mob current ennemy
/// @param sfRenderWindow *window
void upd_hp_bar(ennemy_t *mob, sfRenderWindow *window)
{
    RECT_S_SIZE(mob->max_hp, V2F {96, 2});
    RECT_S_POS(mob->max_hp, mob->stats->coords);
    RECT_S_SIZE(mob->hp, V2F {96 * HP_RATIO_M, 2});
    RECT_S_POS(mob->hp, mob->stats->coords);
    sfRenderWindow_drawRectangleShape(window, mob->max_hp, 0);
    sfRenderWindow_drawRectangleShape(window, mob->hp, 0);
}

/// @brief upd the selected mob
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
/// @param mob mob to update
void upd_mob(gstruct_t *gstruct, sfRenderWindow *window, ennemy_t *mob)
{
    if (GSTATE_(in_game))
        mob_anim(gstruct, mob);
    sfSprite_setPosition(mob->sp_mob, mob->stats->coords);
    if (mob->stats->dir)
        mob->texture_rect.top = 36 * (mob->stats->dir - 1);
    PLAYER_->texture_rect.left = anim(mob->stats->fstate);
    mob->texture_rect.left = 36;
    sfSprite_setTextureRect(mob->sp_mob, mob->texture_rect);
    sfRenderWindow_drawSprite(window, mob->sp_mob, NULL);
    draw_dbrect(gstruct, FR {X_M + 16, Y_M + 16, 64, 64}, window, sfGreen);
    draw_dbrect(gstruct, FR {X_M, Y_M, 96, 96}, window, sfBlue);
    upd_hp_bar(mob, window);
}

/// @brief update all mobs
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
void upd_mobs(gstruct_t *gstruct, sfRenderWindow *window)
{
    int alive_mobs = 0;

    for (int i = 0; i < LEVEL_->mobs; i++) {
        if (!MOB_(i).stats->isalive || LEVEL_->completed)
            continue;
        alive_mobs++;
        upd_mob(gstruct, window, &MOB_(i));
    }
    STATS_->has_attacked = 0;
    if (alive_mobs == 0)
        LEVEL_->completed = sfTrue;
}
