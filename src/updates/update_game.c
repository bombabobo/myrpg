/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** update_game
*/

#include "../../include/my.h"

/// @brief show a rect on the screen (to debug)
/// @param rect_to_draw pretty understandable I think (XD)
/// @param sfRenderWindow *window
/// @param sfColor color
void draw_dbrect(gstruct_t *gstruct, sfFloatRect rect_to_draw,
    sfRenderWindow *win, sfColor c)
{
    sfRectangleShape *test;

    if (!DEBUG_)
        return;
    test = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(test, 2);
    sfRectangleShape_setOutlineColor(test, c);
    sfRectangleShape_setFillColor(test, sfTransparent);
    sfRectangleShape_setPosition(test, V2F {rect_to_draw.left,
    rect_to_draw.top});
    sfRectangleShape_setSize(test, V2F {rect_to_draw.width,
    rect_to_draw.height});
    sfRenderWindow_drawRectangleShape(win, test, NULL);
    sfRectangleShape_destroy(test);
}

/// @brief show the attack rect
/// @param rect_to_draw pretty understandable I think (XD)
/// @param sfRenderWindow *window
/// @param sfColor color
void draw_atrect(sfFloatRect rect_to_draw, sfRenderWindow *win, sfColor c)
{
    sfRectangleShape *test;

    test = sfRectangleShape_create();
    sfRectangleShape_setFillColor(test, c);
    sfRectangleShape_setPosition(test, V2F {rect_to_draw.left,
    rect_to_draw.top});
    sfRectangleShape_setSize(test, V2F {rect_to_draw.width,
    rect_to_draw.height});
    sfRenderWindow_drawRectangleShape(win, test, NULL);
    sfRectangleShape_destroy(test);
}

/// @brief update the whole environement
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
void upd_env(gstruct_t *gstruct, sfRenderWindow *window)
{
    sfRectangleShape_setScale(LEVEL_->background, V2F {3, 3});
    sfRectangleShape_setSize(LEVEL_->background, sfView_getSize(VIEW_));
    sfRectangleShape_setOrigin(LEVEL_->background, V2F {V_MID_X, V_MID_Y});
    sfRectangleShape_setPosition(LEVEL_->background, sfView_getCenter(VIEW_));
    sfRenderWindow_drawRectangleShape(window, LEVEL_->background, 0);
    sfRenderWindow_drawSprite(window, LEVEL_->sp_tilemap, 0);
}

/// @brief update the player and the level
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
void upd_game(gstruct_t *gstruct, sfRenderWindow *window)
{
    upd_env(gstruct, window);
    upd_player(gstruct, window);
    upd_mobs(gstruct, window);
}
