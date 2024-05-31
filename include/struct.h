/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** struct
*/
#include "my.h"
#include "init.h"
#ifndef STRUCT_H_
    #define STRUCT_H_
    #define KKP_ sfKeyboard_isKeyPressed
    #define MGPR_ sfMouse_getPositionRenderWindow
    #define MSPR_ sfMouse_setPositionRenderWindow
    #define SSTR_ sfSprite_setTextureRect
    #define VCFR sfView_createFromRect
    #define SBCFF sfSoundBuffer_createFromFile
    #define DRAW_RECT_SHAPE sfRenderWindow_drawRectangleShape
    #define RECT_G_GB sfRectangleShape_getGlobalBounds
    #define RECT_S_SIZE sfRectangleShape_setSize
    #define RECT_S_POS sfRectangleShape_setPosition
    #define VGC sfView_getCenter
    #define VGS sfView_getSize
    #define MIN(a, b) (((a) < (b)) ? (a) : (b))
    #define MAX(a, b) (((a) > (b)) ? (a) : (b))
    #define EMWS_ event->mouseWheelScroll.delta
    #define BG_SCALE ZOOM_ / VIEW_ZOOM, ZOOM_ / VIEW_ZOOM
    #define FR (sfFloatRect)
    #define V2F (sfVector2f)
    #define V2U (sfVector2u)
    #define HP_RATIO ((float) STATS_->current_health / (float) PSTATS_->health)
    #define HP_RATIO_M (mob->stats->current_health / mob->pstats->max_hp)
    #define ST_RATIO (float) STATS_->current_stam / PSTATS_->max_stam
    #define MID_ size.height / 2, size.width / 2
    #define BUFF_ gstruct->info.buffer
    #define TAB_ gstruct->info.tab
    #define LINES_ gstruct->info.lines
    #define RADIAN_ROT atan2(nbrs[3] - nbrs[1], nbrs[2] - nbrs[0])
    #define MID_X RES_.x / 2
    #define MID_Y RES_.y / 2
    #define V_MID_X (sfView_getSize(VIEW_).x / 2)
    #define V_MID_Y (sfView_getSize(VIEW_).y / 2)
    #define SCALE_ ((float)PLAYER_PX_SIZE / 32)
    #define CELL_SCALE_ (SCALE_ * CELL_SIZE_MULTI)
    #define MARGE_X(nb) ((nb * PLAYER_PX_SIZE *  0.15) + MIN(1, 60 / FPS_))
    #define MARGE_Y (1 + 60 / FPS_)
    #define MAP_IMAGE ((DEBUG_) ? LEVEL_->hitboxes : LEVEL_->map)
    #define TILESIZE (PLAYER_PX_SIZE * CELL_SIZE_MULTI)
    #define SF_GREY sfColor_fromRGB(100, 100, 100)
    #define SF_DGREY sfColor_fromRGB(50, 50, 50)
    #define SF_PAUSED sfColor_fromRGBA(0, 0, 0, 200)
    #define P_PX_SIZE PLAYER_PX_SIZE
    #define V_CO_X(nb) (VGS(VIEW_).x / 1920.f * nb)
    #define V_CO_Y(nb) (VGS(VIEW_).y / 1080.f * nb)
    #define V_PO_X(nb) (VGC(VIEW_).x - VGS(VIEW_).x / 2) + (V_CO_X(nb))
    #define V_PO_Y(nb) (VGC(VIEW_).y - VGS(VIEW_).y / 2) + (V_CO_Y(nb))
    #define V_SCA_X(nb) (sfView_getSize(VIEW_).x / 1920 * nb)
    #define V_SCA_Y(nb) (sfView_getSize(VIEW_).y / 1080 * nb)
    #define KEY_(arg) (IS_K_EV && event->key.code == arg)
    #define GSTATE_(arg) gstruct->gamestate == arg
    #define UISTATE_(arg) gstruct->uistate == arg
    #define UI_ gstruct->ui
    #define CLOCK_GETTIME(clock) sfClock_getElapsedTime(clock).microseconds
    #define EVT_TYPE(evt) (event->type == evt)
    #define IS_K_EV EVT_TYPE(sfEvtKeyPressed)
    #define EVT_MOUSE_CLICK EVT_TYPE(sfEvtMouseButtonPressed)
    #define BUTTON_CLICKED(but) (but->state == CLICKED && EVT_MOUSE_CLICK)
    #define BUTTON_SELECT(but) (BUTTON_CLICKED(but) && but->state != SELECT)
    #define MOUSE_PRESS(but) (EVT_MOUSE_CLICK && sfMouse_isButtonPressed(but))
    #define WS WALK_SPEED
    #define __SPRINT__ (STATS_->is_sprinting == sfTrue)
    #define SPEED_ (__SPRINT__ ? WS * PSTATS_->agility / (BASE_AGI - 2) : WS)
    #define HB_PLAYER(nb) test_hb(nb, gstruct, PLAYER_->stats->coords)
    #define HB_KNIFE(nb) test_hb(nb, gstruct, PLAYER_->stats->coords)
    #define HB_MOB(nb, mob) test_hb(nb, gstruct, mob->stats->coords)
    #define STRE_ "strenght"
    #define DEXT_ "dexterity"
    #define AGIL_ "agility"
    #define DEF_ "resistance"
    #define HP_ "endurance"
    #define A_EQUAL(var, nb) (var > nb - 5 && var < nb + 5)
    #define X_P PLAYER_->stats->coords.x
    #define Y_P PLAYER_->stats->coords.y
    #define X_M mob->stats->coords.x
    #define Y_M mob->stats->coords.y
    #define S_X_M mob->stats->spawn.x
    #define S_Y_M mob->stats->spawn.y
    #define DIR_ STATS_->dir
    #define DOWN 1
    #define LEFT 2
    #define RIGHT 3
    #define UP 4

    enum gamestates {
    start,
    in_game,
    paused,
    gameover,
    end,
};

    enum ui_states {
    game_ui,
    esc_ui,
    set_ui,
    inv_ui,
    start_ui,
    wanna_quit,
    gameover_ui,
};

    #define MAPS_ gstruct->maps
typedef struct maps_s {
    int id;
    char *name;
    char **tiles;
    char **hitboxes;
}maps_t;

    #define PSTATS_ gstruct->player->physical_stats
    struct pstats_s {
    int strenght;
    int dexterity;
    int agility;
    int defense;
    int health;
    int max_stam;
};

    #define STATS_ gstruct->player->stats
    #define COORDS_ STATS_->coords
    struct stats_s {
    int stats_points;
    float level;
    float current_health;
    float current_stam;
    int armor;
    sfBool is_sprinting;
    int has_attacked;
    sfFloatRect atk_zone;
    int skin;
    char *skin_path;
    int dir;
    int iswalking;
    float fstate;
    sfVector2f coords;
    sfClock *attack_cd;
};

    #define KNIFE_ gstruct->player->stats
    struct knif_s {
    sfSprite *sp_player;
    sfTexture *playertex;
    sfIntRect texture_rect;
    sfClock *tex_clock;
};

    #define AUDIO_ gstruct->player->audio
    struct audio_s {
    sfSoundBuffer *knife_au_b;
    sfSoundBuffer *dash_au_b;
    sfSound *knife_au;
    sfSound *dash_au;
    sfMusic *music;
};

    #define PLAYER_ gstruct->player
    #define P_ gstruct->player
    struct player_s {
    struct pstats_s *physical_stats;
    struct stats_s *stats;
    struct audio_s audio;
    sfSprite *sp_player;
    sfTexture *playertex;
    sfIntRect texture_rect;
    sfClock *tex_clock;
};

    enum mob_type {
    phantom,
    zombie,
};

    #define MOB_STATS(nb) LEVEL_->mob[nb].stats
    struct mstats_s {
    float current_health;
    int dir;
    int iswalking;
    int approach;
    float fstate;
    sfBool isalive;
    sfVector2f coords;
    sfVector2f spawn;
    sfClock *attack_cd;
};

    #define MOB_PSTATS(nb) LEVEL_->mob[nb].physical_stats
    struct mpstats_s {
    int damages;
    int atk_speed;
    int speed;
    int max_hp;
};

    #define MOB_(nb) LEVEL_->mob[nb]
typedef struct ennemy_s {
    struct mpstats_s *pstats;
    struct mstats_s *stats;
    sfSprite *sp_mob;
    sfTexture *mobtex;
    sfRectangleShape *hp;
    sfRectangleShape *max_hp;
    sfIntRect texture_rect;
    sfClock *tex_clock;
}ennemy_t;


    #define LEVEL_ gstruct->current_level
    struct level_s {
    int map_id;
    sfBool firstlevel;
    sfBool completed;
    sfVector2f spawn;
    int mobs;
    ennemy_t *mob;
    sfSprite *sp_tilemap;
    sfTexture *maptex;
    sfRectangleShape *background;
    sfImage *map;
    sfImage *hitboxes;
    sfImage *buffer;
    sfFont *font;
};

    #define RES_ gstruct->gameinfo->resolution
    #define FPS_ gstruct->gameinfo->truefps
    #define DEBUG_ gstruct->gameinfo->debug_mode
    #define ZOOM_ gstruct->gameinfo->zoom
    #define INFO_ gstruct->gameinfo
    struct info_s {
    sfVector2f resolution;
    int fps;
    int truefps;
    int debug_mode;
    float zoom;
    float aspect_ratio;
    sfBool isfullscreen;
    sfBool weird_ui;
    sfBool autoresize;
    int map_completed;
};

    enum button_state {
    NONE,
    HOVER,
    CLICKED,
    PAST_CLICKED,
    SELECT
};

typedef struct button_s {
    sfRectangleShape *button;
    sfIntRect texture_rect;
    sfTexture *button_tex;
    enum button_state state;
    sfText *name;
    sfVector2f pos;
    sfVector2f size;
    sfFont *font;
    sfClock *clic_clock;
}button_t;

    #define ESC_ UI_->esc_ui
    struct esc_ui_s {
    sfSprite *menu;
    sfTexture *menu_tex;
    sfRectangleShape *box;
    button_t *but_inv;
    button_t *but_save;
    button_t *but_load;
    button_t *but_settings;
    button_t *but_back;
    sfVector2f pos;
};

    #define GUI_ UI_->game_ui
    struct game_ui_s {
    sfRectangleShape *box;
    sfRectangleShape *profile;
    sfRectangleShape *max_hp;
    sfRectangleShape *current_hp;
    sfRectangleShape *max_st;
    sfRectangleShape *current_st;
    sfIntRect texture_rect;
    sfVector2f pos;
    button_t *but_esc;
};

    #define SET_ UI_->set_ui
    struct set_ui_s {
    sfSprite *menu;
    sfTexture *menu_tex;
    sfRectangleShape *box;
    sfRectangleShape *box_set;
    sfRectangleShape *box_fps;
    sfRectangleShape *box_res;
    sfText *fps_text;
    sfText *res_text;
    sfFont *font;
    button_t *but_fps30;
    button_t *but_fps60;
    button_t *but_fps120;
    button_t *but_fullscreen;
    button_t *but_auto;
    button_t *but_res2;
    button_t *but_res3;
    button_t *but_res4;
};

typedef struct stat_box_s {
    sfRectangleShape *box;
    button_t *plus;
    sfText *stat_text;
    char *stat_name;
    int *stat;
    sfVector2f pos;
    sfVector2f size;
}stat_box_t;

    #define INV_ UI_->inv_ui
    struct inv_ui_s {
    sfSprite *menu;
    sfTexture *menu_tex;
    sfRectangleShape *box;
    sfRectangleShape *stats_box;
    sfText *inv_text;
    sfFont *font;
    stat_box_t *b_strenght;
    stat_box_t *b_dexterity;
    stat_box_t *b_agility;
    stat_box_t *b_defense;
    stat_box_t *b_endurance;
    char *stats_string;
    sfRectangleShape *skin_box;
    button_t *but_p_armor;
    button_t *but_p_skin;
    button_t *but_m_armor;
    button_t *but_m_skin;
    sfRectangleShape *arrows;
    sfTexture *arrows_tex;
    sfIntRect arrows_tr;
};

    #define START_UI UI_->start_ui
    struct start_ui_s {
    sfSprite *menu;
    sfTexture *menu_tex;
    sfRectangleShape *box;
    button_t *but_start;
    button_t *but_set;
    button_t *but_load;
    button_t *but_quit;
    sfText *no_save;
};

    #define QUIT_UI UI_->quit_ui
    struct quit_ui_s {
    sfRectangleShape *quit_box;
    sfText *wanna_quit;
    button_t *quit_yes;
    button_t *quit_no;
    enum ui_states ui_to_load;
    enum gamestates game_to_load;
    enum gamestates game_while;
};

    #define PAUSED_UI UI_->paused_ui
    struct paused_ui_s {
    sfRectangleShape *box;
};

    struct ui_s {
    struct paused_ui_s *paused_ui;
    struct start_ui_s *start_ui;
    struct game_ui_s *game_ui;
    struct quit_ui_s *quit_ui;
    struct esc_ui_s *esc_ui;
    struct set_ui_s *set_ui;
    struct inv_ui_s *inv_ui;
};

    struct settings_s {
    sfBool weird_ui;
    sfBool autoresize;
};

    #define VIEW_ gstruct->view
typedef struct gamestruct {
    struct player_s *player;
    struct ui_s *ui;
    maps_t *maps;
    struct level_s *current_level;
    sfView *view;
    sfClock *gameclock;
    sfClock *fpsclock;
    sfClock *windowclock;
    enum gamestates gamestate;
    enum ui_states uistate;
    struct settings_s *settings;
    sfBool save;
    struct info_s *gameinfo;
    sfBool close_game;
}gstruct_t;

#endif /* !STRUCT_H_ */
