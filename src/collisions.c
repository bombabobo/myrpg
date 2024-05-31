/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** update
*/

#include "../include/my.h"

/// @brief test 2 colors
/// @param sfColor c1
/// @param sfColor c2
/// @return 0 if same colors, 1 if different
int compare(sfColor c1, sfColor c2)
{
    if ((c1.a == c2.a) && (c1.b == c2.b) && (c1.g == c2.g) && (c1.r == c2.r))
        return 1;
    return 0;
}

/// @brief test wall down
/// @param gstruct_t *gstruct
/// @return 0 if no hitbox, 1 if hitbox
static int collision_down(gstruct_t *gstruct, sfVector2f coords)
{
    sfColor test1;
    sfColor test2;
    float x1;
    float y1;
    float x2;
    float y2;

    if (coords.y <= 0 || coords.x <= 0)
        return 0;
    x1 = (1.f / CELL_SCALE_ * (coords.x + MARGE_X(1) + 2));
    y1 = (1.f / CELL_SCALE_ * (coords.y + 96 + MARGE_Y));
    x2 = (1.f / CELL_SCALE_ * (coords.x + 96 - MARGE_X(1) - 2));
    y2 = (1.f / CELL_SCALE_ * (coords.y + 96 + MARGE_Y));
    test1 = sfImage_getPixel(LEVEL_->hitboxes, (int)x1, (int)y1);
    test2 = sfImage_getPixel(LEVEL_->hitboxes, (int)x2, (int)y2);
    fflush(stdout);
    return (compare(test1, sfRed) || compare(test2, sfRed));
}

/// @brief test wall left
/// @param gstruct_t *gstruct
/// @return 0 if no hitbox, 1 if hitbox
static int collision_left(gstruct_t *gstruct, sfVector2f coords)
{
    sfColor test1;
    sfColor test2;
    float x1;
    float y1;
    float x2;
    float y2;

    if (coords.y <= 0 || coords.x <= 0)
        return 0;
    x1 = (1.f / CELL_SCALE_ * (coords.x - MARGE_X(-1)));
    y1 = (1.f / CELL_SCALE_ * (coords.y + MARGE_Y));
    x2 = (1.f / CELL_SCALE_ * (coords.x - MARGE_X(-1)));
    y2 = (1.f / CELL_SCALE_ * (coords.y + 96 - MARGE_Y));
    test1 = sfImage_getPixel(LEVEL_->hitboxes, (int)x1, (int)y1);
    test2 = sfImage_getPixel(LEVEL_->hitboxes, (int)x2, (int)y2);
    return (compare(test1, sfRed) || compare(test2, sfRed));
}

/// @brief test wall right
/// @param gstruct_t *gstruct
/// @return 0 if no hitbox, 1 if hitbox
static int collision_right(gstruct_t *gstruct, sfVector2f coords)
{
    sfColor test1;
    sfColor test2;
    float x1;
    float y1;
    float x2;
    float y2;

    if (coords.y <= 0 || coords.x <= 0)
        return 0;
    x1 = (1.f / CELL_SCALE_ * (coords.x + 96 + MARGE_X(-1)));
    y1 = (1.f / CELL_SCALE_ * (coords.y + MARGE_Y));
    x2 = (1.f / CELL_SCALE_ * (coords.x + 96 + MARGE_X(-1)));
    y2 = (1.f / CELL_SCALE_ * (coords.y + 96 - MARGE_Y));
    test1 = sfImage_getPixel(LEVEL_->hitboxes, (int)x1, (int)y1);
    test2 = sfImage_getPixel(LEVEL_->hitboxes, (int)x2, (int)y2);
    return (compare(test1, sfRed) || compare(test2, sfRed));
}

/// @brief test wall up
/// @param gstruct_t *gstruct
/// @return 0 if no hitbox, 1 if hitbox
static int collision_up(gstruct_t *gstruct, sfVector2f coords)
{
    sfColor test1;
    sfColor test2;
    float x1;
    float y1;
    float x2;
    float y2;

    if (coords.y <= 0 || coords.x <= 0)
        return 0;
    x1 = (1.f / CELL_SCALE_ * (coords.x + MARGE_X(1) + 2));
    y1 = (1.f / CELL_SCALE_ * (coords.y - MARGE_Y));
    x2 = (1.f / CELL_SCALE_ * (coords.x + 96 - MARGE_X(1) - 2));
    y2 = (1.f / CELL_SCALE_ * (coords.y - MARGE_Y));
    test1 = sfImage_getPixel(LEVEL_->hitboxes, (int)x1, (int)y1);
    test2 = sfImage_getPixel(LEVEL_->hitboxes, (int)x2, (int)y2);
    return (compare(test1, sfRed) || compare(test2, sfRed));
}

/// @brief test if there is a wall
/// @param int nb
/// @return 0 if no hitbox, 1 if hitbox
int test_hb(int nb, gstruct_t *gstruct, sfVector2f coords)
{
    switch (nb){
    case 1:
        return collision_down(gstruct, coords);
    case 2:
        return collision_left(gstruct, coords);
    case 3:
        return collision_right(gstruct, coords);
    case 4:
        return collision_up(gstruct, coords);
    default:
        return 0;
    }
}

/// @brief test if the center of the player is touching sfBlue on hitbox image
/// @param gstruct_t *gstruct
/// @return 1 if the player touch sfBlue
int blue_collision(gstruct_t *gstruct)
{
    sfColor test1;
    float x1 = (1.f / CELL_SCALE_ * (STATS_->coords.x + PLAYER_PX_SIZE / 2));
    float y1 = (1.f / CELL_SCALE_ * (STATS_->coords.y + PLAYER_PX_SIZE / 2));

    test1 = sfImage_getPixel(LEVEL_->hitboxes, (int)x1, (int)y1);
    return (compare(test1, sfBlue));
}
