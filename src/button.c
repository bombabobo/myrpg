/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** event
*/

#include "../include/my.h"

/// @brief set state to clicked when it's clicked
/// @param button_t *button
void is_clicked(button_t *button, sfEvent *event)
{
    if (button->state == CLICKED)
        button->state = PAST_CLICKED;
    if (button->state == HOVER &&
        event->type == sfEvtMouseButtonPressed &&
        event->mouseButton.button == sfMouseLeft){
        button->state = CLICKED;
        sfClock_restart(button->clic_clock);
    }
}

/// @brief test if the mouse is hover the button
/// @param button_t *button
/// @param sfRenderWindow *window
void is_hover(button_t *but, sfRenderWindow *window, gstruct_t *gstruct_t,
    int update)
{
    sfFloatRect rect = {but->pos.x, but->pos.y, but->size.x, but->size.y};
    sfVector2f mouse_pos = V2F {MGPR_(window).x, MGPR_(window).y};
    int isitin = 0;

    if (but->state == SELECT)
        return;
    mouse_pos.x *= 1920.f / sfRenderWindow_getSize(window).x;
    mouse_pos.y *= 1080.f / sfRenderWindow_getSize(window).y;
    if (gstruct_t->settings->autoresize){
        mouse_pos.x += sfRenderWindow_getPosition(window).x;
        mouse_pos.y += sfRenderWindow_getPosition(window).y;
    }
    isitin = sfFloatRect_contains(&rect, (int) mouse_pos.x, (int) mouse_pos.y);
    if (but->state == CLICKED && CLOCK_GETTIME(but->clic_clock) / 75000 < 1)
        but->state = CLICKED;
    else if (isitin && update)
        but->state = HOVER;
    else
        but->state = NONE;
}
