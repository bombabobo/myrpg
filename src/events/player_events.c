/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** event
*/

#include "../../include/my.h"

/// @brief movments (and player input)
/// @param gstruct_t *gstruct
static void movment_keys(gstruct_t *gstruct)
{
    STATS_->iswalking = 1;
    STATS_->dir = 0;
    if ((KKP_(sfKeyS) || KKP_(sfKeyDown)))
        STATS_->dir = 1;
    if ((KKP_(sfKeyQ) || KKP_(sfKeyLeft)))
        STATS_->dir = 2;
    if ((KKP_(sfKeyD) || KKP_(sfKeyRight)))
        STATS_->dir = 3;
    if ((KKP_(sfKeyZ) || KKP_(sfKeyUp)))
        STATS_->dir = 4;
    if (STATS_->dir == 0)
        STATS_->iswalking = 0;
}

/// @brief make the player facing the pointed direction
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
static void face_direction(gstruct_t *gstruct, sfRenderWindow *window)
{
    sfVector2i mouseposi = sfMouse_getPositionRenderWindow(window);
    sfVector2f mousepos = V2F {mouseposi.x / 1920.f, mouseposi.y / 1080.f};

    if ((mousepos.x > 0.5) && (mousepos.y > 0.5))
        STATS_->dir = (mousepos.x > mousepos.y) ? 3 : 1;
    if ((mousepos.x < 0.5) && (mousepos.y < 0.5))
        STATS_->dir = (mousepos.x < mousepos.y) ? 2 : 4;
    if ((mousepos.x < 0.5) && (mousepos.y > 0.5))
        STATS_->dir = (1 - mousepos.x > mousepos.y) ? 2 : 1;
    if ((mousepos.x > 0.5) && (mousepos.y < 0.5))
        STATS_->dir = (mousepos.x < 1 - mousepos.y) ? 4 : 3;
}

/// @brief set the hitbox from the dash
/// @param gstruct_t *gstruct
/// @param previous previous positions of the player
static void dash_atk_box(gstruct_t *gstruct, sfVector2f previous)
{
    STATS_->atk_zone.left = (!(DIR_ % 2)) ? COORDS_.x : 0;
    STATS_->atk_zone.top = (!(DIR_ % 2)) ? COORDS_.y : 0;
    STATS_->atk_zone.width = (STATS_->dir == 1 || STATS_->dir == 4) ? 96 : 0;
    STATS_->atk_zone.height = (STATS_->dir == 1 || STATS_->dir == 4) ? 0 : 96;
    if (STATS_->dir == 1){
        STATS_->atk_zone.height = COORDS_.y - previous.y + 96;
        STATS_->atk_zone.left = previous.x;
        STATS_->atk_zone.top = previous.y;
    }
    if (STATS_->dir == 2)
        STATS_->atk_zone.width = previous.x - COORDS_.x + 96;
    if (STATS_->dir == 3){
        STATS_->atk_zone.width = COORDS_.x - previous.x + 96;
        STATS_->atk_zone.left = previous.x;
        STATS_->atk_zone.top = previous.y;
    }
    if (STATS_->dir == 4)
        STATS_->atk_zone.height = previous.y - COORDS_.y + 96;
}

/// @brief dash forward
/// @param gstruct_t *gstruct
static void dash_attack(gstruct_t *gstruct)
{
    sfVector2f previous = COORDS_;

    STATS_->has_attacked = 2;
    if (STATS_->dir == 1)
        for (int i = 0; i < 16 * PSTATS_->dexterity; i++)
            COORDS_.y += (!HB_PLAYER(1)) ? 1 : 0;
    if (STATS_->dir == 2)
        for (int i = 0; i < 16 * PSTATS_->dexterity; i++)
            COORDS_.x -= (!HB_PLAYER(2)) ? 1 : 0;
    if (STATS_->dir == 3)
        for (int i = 0; i < 16 * PSTATS_->dexterity; i++)
            COORDS_.x += (!HB_PLAYER(3)) ? 1 : 0;
    if (STATS_->dir == 4)
        for (int i = 0; i < 16 * PSTATS_->dexterity; i++)
            COORDS_.y -= (!HB_PLAYER(4)) ? 1 : 0;
    sfSound_play(AUDIO_.dash_au);
    dash_atk_box(gstruct, previous);
}

/// @brief set the hitbox for the throw
/// @param gstruct_t *gstruct
static void throw_atk_box(gstruct_t *gstruct, int dist)
{
    STATS_->atk_zone.width = (DIR_ == 1 || DIR_ == 4) ? 32 : dist;
    STATS_->atk_zone.height = (DIR_ == 1 || DIR_ == 4) ? dist : 32;
    if (DIR_ == 1 || DIR_ == 4)
        STATS_->atk_zone.left = COORDS_.x + 32;
    else
        STATS_->atk_zone.top = COORDS_.y + 32;
    if (DIR_ == 1)
        STATS_->atk_zone.top = COORDS_.y;
    if (DIR_ == 4)
        STATS_->atk_zone.top = COORDS_.y - dist + 96;
    if (DIR_ == 2)
        STATS_->atk_zone.left = COORDS_.x - dist + 96;
    if (DIR_ == 3)
        STATS_->atk_zone.left = COORDS_.x;
}

/// @brief calcule the throw dist
/// @param gstruct_t *gstruct
/// @return distance
void calc_dist(gstruct_t *gstruct, int *dist, sfColor test)
{
    for (; *dist < 2000 && !compare(test, sfRed); *dist += 1) {
        test = (DIR_ == 1) ? sfImage_getPixel(LEVEL_->hitboxes,
        (1 / CELL_SCALE_ * (COORDS_.x + 46 - MARGE_X(1))),
        (1 / CELL_SCALE_ * (COORDS_.y + (*dist) + MARGE_Y))) : test;
        test = (STATS_->dir == 2) ? sfImage_getPixel(LEVEL_->hitboxes,
        (1 / CELL_SCALE_ * (COORDS_.x + 96 - (*dist - 18) - MARGE_X(1))),
        (1 / CELL_SCALE_ * (COORDS_.y + 48 + MARGE_Y))) : test;
        test = (STATS_->dir == 3) ? sfImage_getPixel(LEVEL_->hitboxes,
        (1 / CELL_SCALE_ * (COORDS_.x + (*dist + 14) - MARGE_X(1))),
        (1 / CELL_SCALE_ * (COORDS_.y + 48 + MARGE_Y))) : test;
        test = (STATS_->dir == 4) ? sfImage_getPixel(LEVEL_->hitboxes,
        (1 / CELL_SCALE_ * (COORDS_.x + 46 - MARGE_X(1))),
        (1 / CELL_SCALE_ * (COORDS_.y + 96 - (*dist) + MARGE_Y))) : test;
    }
}

/// @brief throw knife
/// @param gstruct_t *gstruct
static void throw_attack(gstruct_t *gstruct)
{
    int dist = 48;
    sfColor test = sfWhite;

    calc_dist(gstruct, &dist, test);
    STATS_->has_attacked = 2;
    sfSound_play(AUDIO_.knife_au);
    throw_atk_box(gstruct, dist);
}

/// @brief handle the scroll zoom
/// @param gstruct_t *gstruct
/// @param sfEvent *event
static void mouse_events(gstruct_t *gstruct, sfEvent *event,
    sfRenderWindow *window)
{
    STATS_->has_attacked = MAX(0, STATS_->has_attacked - 1);
    is_clicked(GUI_->but_esc, event);
    if (BUTTON_CLICKED(GUI_->but_esc))
        gstruct->uistate = esc_ui;
    if (event->type == sfEvtMouseWheelScrolled && EMWS_ < 0 &&
        !(sfView_getSize(VIEW_).x > 3840 || sfView_getSize(VIEW_).y > 2160))
        ZOOM_ = 1.05;
    if (event->type == sfEvtMouseWheelScrolled && EMWS_ > 0 &&
        !(sfView_getSize(VIEW_).x < 384 || sfView_getSize(VIEW_).y < 216))
        ZOOM_ = 0.95;
    if (!STATS_->iswalking)
        face_direction(gstruct, window);
    if (MOUSE_PRESS(sfMouseLeft))
        dash_attack(gstruct);
    if (MOUSE_PRESS(sfMouseRight))
        throw_attack(gstruct);
}

/// @brief for game events
/// @param sfEvent *event
/// @param gstruct_t *gstruct
void player_events(gstruct_t *gstruct, sfEvent *event,
    sfRenderWindow *window)
{
    STATS_->is_sprinting = (!KKP_(RUN_K)) ? sfFalse : STATS_->is_sprinting;
    if ((event->key.code == RUN_K) &&
        (STATS_->current_stam > 10))
        STATS_->is_sprinting = (KKP_(RUN_K)) ? sfTrue : sfFalse;
    if (IS_K_EV && KEY_(sfKeyE))
        gstruct->uistate = (UISTATE_(inv_ui) ? game_ui : inv_ui);
    movment_keys(gstruct);
    mouse_events(gstruct, event, window);
}
