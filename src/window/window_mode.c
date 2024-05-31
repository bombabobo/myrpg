/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-marin.lagie
** File description:
** window_mode.c
*/
#include "../../include/my.h"

int is_fs(gstruct_t *gstruct, sfRenderWindow *win, int def_style)
{
    if (INFO_->isfullscreen == sfTrue) {
        INFO_->isfullscreen = sfFalse;
    }
    set_windowed(gstruct, win, def_style);
    return 1;
}

/// @brief for set the windowed
/// @param gstruct *gstruct
/// @param window *window
/// @param def_style If we have a default style where then the window and block
void set_windowed(gstruct_t *gstruct, sfRenderWindow *window, int def_style)
{
    sfImage *icon = sfImage_createFromFile(LOGO);

    sfRenderWindow_destroy(window);
    if (def_style)
        window = sfRenderWindow_create((sfVideoMode) {V_MODE}, TITLE,
            sfDefaultStyle, NULL);
    else
        window = sfRenderWindow_create((sfVideoMode) {V_MODE}, TITLE,
            sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, FPS_ + 1);
    sfRenderWindow_setKeyRepeatEnabled(window, sfFalse);
    sfRenderWindow_setIcon(window, sfImage_getSize(icon).x,
        sfImage_getSize(icon).y, sfImage_getPixelsPtr(icon));
    sfImage_destroy(icon);
}

/// @brief for set the window fullscreen
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
void set_fullscreen(gstruct_t *gstruct, sfRenderWindow *window)
{
    sfImage *icon = sfImage_createFromFile(LOGO);

    sfRenderWindow_destroy(window);
    if (!INFO_->isfullscreen)
        window = sfRenderWindow_create((sfVideoMode) {V_MODE}, TITLE,
            sfFullscreen, NULL);
    else
        window = sfRenderWindow_create((sfVideoMode) {V_MODE}, TITLE,
            sfDefaultStyle, NULL);
    INFO_->isfullscreen = (INFO_->isfullscreen) ? sfFalse : sfTrue;
    sfRenderWindow_setFramerateLimit(window, FPS_ + 1);
    sfRenderWindow_setKeyRepeatEnabled(window, sfFalse);
    sfRenderWindow_setIcon(window, sfImage_getSize(icon).x,
        sfImage_getSize(icon).y, sfImage_getPixelsPtr(icon));
    sfImage_destroy(icon);
}
