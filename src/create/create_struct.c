/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** create_struct
*/

#include "../../include/my.h"

/// @brief init info
/// @param gstruct_t *gstruct
static void create_info(gstruct_t *gstruct)
{
    INFO_ = malloc(sizeof(struct info_s));
    RES_ = V2F {1920, 1080};
    FPS_ = 60;
    ZOOM_ = 1;
    INFO_->aspect_ratio = RES_.x / RES_.y;
    INFO_->isfullscreen = sfFalse;
    INFO_->map_completed = 0;
}

/// @brief malloc all the interfaces
/// @param gstruct_t *gstruct
static void malloc_internal_structs(gstruct_t *gstruct)
{
    UI_ = malloc(sizeof(struct ui_s));
    PLAYER_ = malloc(sizeof(struct player_s));
    LEVEL_ = malloc(sizeof(struct level_s));
    MAPS_ = malloc(sizeof(maps_t) * NB_MAPS);
}

/// @brief init gstruct
/// @param gstruct_t *gstruct
static void create_gstruct(gstruct_t *gstruct, int debug)
{
    create_info(gstruct);
    DEBUG_ = debug;
    malloc_internal_structs(gstruct);
    LEVEL_->map_id = -1;
    gstruct->gamestate = start;
    gstruct->uistate = start_ui;
    VIEW_ = sfView_create();
    sfView_setSize(gstruct->view, RES_);
    sfView_zoom(gstruct->view, VIEW_ZOOM);
    sfView_setCenter(gstruct->view, (sfVector2f){0, 0});
    gstruct->fpsclock = sfClock_create();
    gstruct->windowclock = sfClock_create();
    gstruct->save = sfTrue;
    gstruct->settings = malloc(sizeof(struct settings_s));
    gstruct->settings->autoresize = sfFalse;
    gstruct->close_game = sfFalse;
}

/// @brief generate the path to the desired map files
/// @param int i
/// @param int mode
/// @param char *str
/// @return path to desired file
char *map_path(int i, int mode, char *str)
{
    switch (mode){
    case 1:
        sprintf(str, "map/map%d/hitboxs.txt", i + 1);
        break;
    case 2:
        sprintf(str, "map/map%d/tiles.txt", i + 1);
        break;
    case 3:
        sprintf(str, "map%d", i + 1);
        break;
    default:
        break;
    }
    return str;
}

/// @brief init maps
/// @param gstruct_t *gstruct
void create_maps(gstruct_t *gstruct)
{
    char *str = malloc(255);

    MAPS_->id = 0;
    for (int i = 0; i < NB_MAPS; i++) {
        MAPS_[i].id = i;
        str = map_path(i, 3, str);
        MAPS_[i].name = strdup(str);
        str = map_path(i, 2, str);
        MAPS_[i].tiles = creat_tab(recup_file_str(str));
        str = map_path(i, 1, str);
        MAPS_[i].hitboxes = creat_tab(recup_file_str(str));
    }
    free(str);
}

/// @brief create the game structure
/// @param gstruct_t *gstruct
void create_structs(gstruct_t *gstruct, int debug, int start)
{
    srand(time(NULL));
    create_gstruct(gstruct, debug);
    create_maps(gstruct);
    create_gamescene(gstruct);
    create_ui(gstruct);
    if (start)
        gstruct->gameclock = sfClock_create();
}
