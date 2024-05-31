/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-marin.lagie
** File description:
** event_settings.c
*/
#include "../../include/my.h"


static void is_clicked_fps(gstruct_t *gstruct, sfEvent *event)
{
    is_clicked(SET_->but_fps30, event);
    is_clicked(SET_->but_fps60, event);
    is_clicked(SET_->but_fps120, event);
}

static void is_clicked_res(gstruct_t *gstruct, sfEvent *event)
{
    is_clicked(SET_->but_fullscreen, event);
    is_clicked(SET_->but_auto, event);
    is_clicked(SET_->but_res2, event);
    is_clicked(SET_->but_res3, event);
    is_clicked(SET_->but_res4, event);
}

static void change_select(button_t **select, button_t *new)
{
    (*select)->state = NONE;
    new->state = SELECT;
    (*select) = new;
}

static void fps_event(gstruct_t *gstruct, sfEvent *event, sfRenderWindow *win)
{
    static button_t *select_fps = NULL;

    if (!select_fps)
        select_fps = SET_->but_fps60;
    is_clicked_fps(gstruct, event);
    if (BUTTON_SELECT(SET_->but_fps30)) {
        change_select(&select_fps, SET_->but_fps30);
        sfRenderWindow_setFramerateLimit(win, 30);
    }
    if (BUTTON_SELECT(SET_->but_fps60)) {
        change_select(&select_fps, SET_->but_fps60);
        sfRenderWindow_setFramerateLimit(win, 60);
    }
    if (BUTTON_SELECT(SET_->but_fps120)) {
        change_select(&select_fps, SET_->but_fps120);
        sfRenderWindow_setFramerateLimit(win, 120);
    }
}

static void res_event2(gstruct_t *gstruct, sfEvent *event,
    sfRenderWindow *win, button_t **select_res)
{
    if (BUTTON_SELECT(SET_->but_res3) && is_fs(gstruct, win, 0)) {
        change_select(select_res, SET_->but_res3);
        sfRenderWindow_setSize(win, V2U {1280.0, 720.0});
    }
    if (BUTTON_SELECT(SET_->but_res4) && is_fs(gstruct, win, 0)) {
        change_select(select_res, SET_->but_res4);
        sfRenderWindow_setSize(win, V2U {960.0, 540.0});
    }
}

static void res_event(gstruct_t *gstruct, sfEvent *event, sfRenderWindow *win)
{
    static button_t *select_res = NULL;

    if (!select_res)
        select_res = SET_->but_auto;
    is_clicked_res(gstruct, event);
    if (BUTTON_SELECT(SET_->but_fullscreen)) {
        change_select(&select_res, SET_->but_fullscreen);
        set_fullscreen(gstruct, win);
    }
    if (BUTTON_SELECT(SET_->but_auto) && is_fs(gstruct, win, 1)) {
        change_select(&select_res, SET_->but_auto);
        sfRenderWindow_setSize(win, V2U {1920.0, 1080.0});
    }
    if (BUTTON_SELECT(SET_->but_res2) && is_fs(gstruct, win, 0)) {
        change_select(&select_res, SET_->but_res2);
        sfRenderWindow_setSize(win, V2U {1920.0, 1080.0});
    }
    res_event2(gstruct, event, win, &select_res);
}

void set_events(gstruct_t *gstruct, sfEvent *event, sfRenderWindow *window)
{
    fps_event(gstruct, event, window);
    res_event(gstruct, event, window);
}
