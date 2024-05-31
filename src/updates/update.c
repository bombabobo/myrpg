/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** update_game
*/

#include "../../include/my.h"

/// @brief update the window size to stay in a 16:9 ratio
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
void upd_window(gstruct_t *gstruct, sfRenderWindow *window)
{
    sfVector2u size = sfRenderWindow_getSize(window);
    sfVector2i pos = sfRenderWindow_getPosition(window);
    float new_aspect_ratio = (float) size.x / size.y;
    int new_width = 0;
    int new_height = 0;

    if (new_aspect_ratio != INFO_->aspect_ratio){
        INFO_->aspect_ratio = new_aspect_ratio;
        sfClock_restart(gstruct->windowclock);
    }
    if (new_aspect_ratio != (float) RES_.x / RES_.y &&
        CLOCK_GETTIME(gstruct->windowclock) > 1000000) {
        new_width = size.x;
        new_height = size.x * RES_.y / RES_.x;
        sfRenderWindow_setSize(window, (sfVector2u){new_width, new_height});
        sfRenderWindow_setPosition(window, pos);
        sfClock_restart(gstruct->windowclock);
    }
}

/// @brief call every update
/// @param gstruct_t *gst
/// @param sfRenderWindow *window
void upd_all(gstruct_t *gstruct, sfRenderWindow *window)
{
    if (gstruct->settings->autoresize == sfTrue)
        upd_window(gstruct, window);
    if (GSTATE_(in_game) || GSTATE_(paused) || GSTATE_(gameover))
        upd_game(gstruct, window);
    sfRenderWindow_setView(window, gstruct->view);
    upd_ui(gstruct, window);
}
