/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** init
*/
#include "my.h"
#ifndef INIT_H_
    #define INIT_H_

    #define DEBUG_MODE 0
    #define WEIRD_UI 0
    #define V_MODE 1920, 1080, 32
    #define VIEW_ZOOM 1
    #define NB_MAPS 5
    #define NB_BOSSMAPS 1
    #define CELL_SIZE_MULTI 1.125
    #define PLAYER_PX_SIZE 96
    #define PLAYER_ANIME_FPS 8
    #define BASE_SKIN 1
    #define WALK_SPEED 10
    #define BASE_ARMOR 0
    #define MENU_X 500
    #define MENU_Y 800

    #define BASE_STRENGHT 20
    #define BASE_DEXT 20
    #define BASE_AGI 20
    #define BASE_HP 50
    #define BASE_DEFENSE 0
    #define BASE_ST 50

    #define M_PI 3.14159265358979323846
    #define LOGO "ressources/logo.png"
    #define TITLE "Forbidden Ruins"
    #define LARGE_BUT "ressources/button.png"
    #define SMALL_BUT "ressources/button2.png"
    #define BUTTON_FILE(nb) ((nb) ? LARGE_BUT : SMALL_BUT)
    #define FONT_PATH(font) "ressources/"#font".ttf"
    #define MENU_TITLE "ressources/menu.png"
    #define SETTINGS_TITLE "ressources/settings.png"
    #define INVENTORY_TITLE "ressources/inventory.png"
    #define START_TITLE "ressources/start.png"
    #define TILES_ "ressources/tilemap.png"
    #define ARROWS_ "ressources/arrows.png"
    #define GHOST_ "ressources/enemies/ghost.png"
    #define KNIFE_TEX "ressources/knife.png"
    #define KNIFE_AU "ressources/audio/knife.ogg"
    #define DASH_AU "ressources/audio/dash.ogg"
    #define MUSIC_AU "ressources/audio/music.ogg"
    #define P_ANIM_RR (float) 8 / MIN(60, FPS_) * (__SPRINT__ ? 1.5 : 1)
    #define M_ANIM_RR (float) 2 / MIN(60, FPS_)
    #define MODE_ sfResize | sfClose
    #define BG_COLOR ((DEBUG_) ? sfWhite : sfBlack)
    #define IMG_SIZE_X 2500
    #define IMG_SIZE_Y 2500
    #define RUN_K sfKeyLControl
    #define PASSWORD_HASH 928513990

#endif /* !INIT_H_ */
