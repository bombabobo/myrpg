/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** create_ui
*/

#include "../../include/my.h"

/// @brief init any button
/// @param button_t *but
/// @param sfVector2f pos
/// @param sfVector2f size
button_t *create_button(sfVector2f pos, sfVector2f size, int large)
{
    button_t *but = malloc(sizeof(button_t));

    but->state = NONE;
    but->size = size;
    but->pos = pos;
    but->button = sfRectangleShape_create();
    but->button_tex = sfTexture_createFromFile(BUTTON_FILE(large), NULL);
    but->texture_rect = WEIRD_UI ? (sfIntRect){0, 0, 100 + 200 * large, 100} :
        (sfIntRect){0, 0, 200 + 400 * large, 200};
    sfRectangleShape_setTexture(but->button, but->button_tex, sfFalse);
    sfRectangleShape_setTextureRect(but->button, but->texture_rect);
    but->name = sfText_create();
    but->font = sfFont_createFromFile(FONT_PATH(font2));
    sfText_setFont(but->name, but->font);
    sfText_setCharacterSize(but->name, 100);
    but->clic_clock = sfClock_create();
    return but;
}

/// @brief init all buttons in start menu
/// @param gstruct_t *gstruct
static void create_start_buttons(gstruct_t *gstruct)
{
    START_UI->but_start = create_button(V2F {1200, 55}, V2F {660, 220}, 1);
    START_UI->but_load = create_button(V2F {1200, 295}, V2F {660, 220}, 1);
    START_UI->but_set = create_button(V2F {1200, 545}, V2F {660, 220}, 1);
    START_UI->but_quit = create_button(V2F {1200, 795}, V2F {660, 220}, 1);
    sfText_setString(START_UI->but_start->name, "new game");
    sfText_setString(START_UI->but_load->name, "load game");
    sfText_setString(START_UI->but_set->name, "settings");
    sfText_setString(START_UI->but_quit->name, "Quit");
}

/// @brief init all buttons in quit menu
/// @param gstruct_t *gstruct
static void create_quit_buttons(gstruct_t *gstruct)
{
    QUIT_UI->quit_yes = create_button(V2F {760, 600}, V2F {180, 60}, 1);
    QUIT_UI->quit_no = create_button(V2F {980, 600}, V2F {180, 60}, 1);
    sfText_setString(QUIT_UI->quit_yes->name, "Yes");
    sfText_setString(QUIT_UI->quit_no->name, "No");
}

static void create_fps_set(gstruct_t *gstruct)
{
    SET_->box_fps = sfRectangleShape_create();
    sfRectangleShape_setPosition(SET_->box_fps, V2F {-200, -100});
    sfRectangleShape_setFillColor(SET_->box_fps, SF_GREY);
    SET_->font = sfFont_createFromFile(FONT_PATH(font2));
    SET_->fps_text = sfText_create();
    sfText_setFont(SET_->fps_text, SET_->font);
    create_string(SET_->fps_text, "FPS", 50);
    sfText_setPosition(SET_->fps_text, V2F {-375, -230});
    SET_->but_fps30 = create_button(V2F {900, 310}, V2F {100, 60}, 1);
    SET_->but_fps60 = create_button(V2F {1010, 310}, V2F {100, 60}, 1);
    SET_->but_fps120 = create_button(V2F {1120, 310}, V2F {100, 60}, 1);
    create_string(SET_->but_fps30->name, "30", 60);
    create_string(SET_->but_fps60->name, "60", 60);
    create_string(SET_->but_fps120->name, "120", 60);
    SET_->but_fps60->state = SELECT;
}

static void create_resolution(gstruct_t *gstruct)
{
    sfRectangleShape_setFillColor(SET_->box_res, SF_GREY);
    SET_->res_text = sfText_create();
    sfText_setFont(SET_->res_text, SET_->font);
    create_string(SET_->res_text, "Resolution", 50);
    sfText_setPosition(SET_->res_text, V2F {-375, -130});
    SET_->but_fullscreen = create_button(V2F {900, 410}, V2F {100, 60}, 1);
    SET_->but_auto = create_button(V2F {1010, 410}, V2F {100, 60}, 1);
    SET_->but_res2 = create_button(V2F {1120, 410}, V2F {100, 60}, 1);
    SET_->but_res3 = create_button(V2F {1230, 410}, V2F {100, 60}, 1);
    SET_->but_res4 = create_button(V2F {1340, 410}, V2F {100, 60}, 1);
    create_string(SET_->but_fullscreen->name, "Fullscreen", 60);
    create_string(SET_->but_auto->name, "Auto", 60);
    create_string(SET_->but_res2->name, "1920x1080", 60);
    create_string(SET_->but_res3->name, "1280x720", 60);
    create_string(SET_->but_res4->name, "960x540", 60);
    SET_->but_auto->state = SELECT;
}

/// @brief init setting menu
/// @param gstruct_t *gstruct
static void create_set(gstruct_t *gstruct)
{
    SET_->menu = sfSprite_create();
    SET_->menu_tex = sfTexture_createFromFile(SETTINGS_TITLE, NULL);
    sfSprite_setTexture(SET_->menu, SET_->menu_tex, sfFalse);
    sfSprite_setScale(SET_->menu, V2F {0.75, 0.75});
    sfSprite_setOrigin(SET_->menu, V2F {274.5, 83.5});
    sfSprite_setColor(SET_->menu, SF_DGREY);
    SET_->box = sfRectangleShape_create();
    sfRectangleShape_setFillColor(SET_->box, SF_GREY);
    SET_->box_set = sfRectangleShape_create();
    sfRectangleShape_setFillColor(SET_->box_set, SF_DGREY);
    create_fps_set(gstruct);
    SET_->box_res = sfRectangleShape_create();
    sfRectangleShape_setPosition(SET_->box_res, V2F {-200, -100});
    create_resolution(gstruct);
}

/// @brief init start menucreate_ingame_ui
/// @param gstruct_t *gstruct
void create_start_ui(gstruct_t *gstruct)
{
    START_UI->menu = sfSprite_create();
    START_UI->menu_tex = sfTexture_createFromFile(START_TITLE, NULL);
    sfSprite_setTexture(START_UI->menu, START_UI->menu_tex, sfFalse);
    sfSprite_setScale(START_UI->menu, V2F {1.1, 1.1});
    sfSprite_setOrigin(START_UI->menu, V2F {0, 0});
    sfSprite_setColor(START_UI->menu, SF_DGREY);
    START_UI->box = sfRectangleShape_create();
    sfRectangleShape_setFillColor(START_UI->box, SF_GREY);
    create_start_buttons(gstruct);
    START_UI->no_save = sfText_create();
    sfText_setString(START_UI->no_save, "No save was found");
    sfText_setFont(START_UI->no_save, QUIT_UI->quit_yes->font);
    sfText_setColor(START_UI->no_save, sfRed);
}

/// @brief init quit menu
/// @param gstruct_t *gstruct
void create_quit_ui(gstruct_t *gstruct)
{
    create_quit_buttons(gstruct);
    QUIT_UI->quit_box = sfRectangleShape_create();
    sfRectangleShape_setFillColor(QUIT_UI->quit_box, SF_GREY);
    QUIT_UI->wanna_quit = sfText_create();
    sfText_setFont(QUIT_UI->wanna_quit, QUIT_UI->quit_yes->font);
    sfText_setString(QUIT_UI->wanna_quit, "Do You Want\n\tTo Quit ?");
    sfText_setCharacterSize(QUIT_UI->wanna_quit, 100);
}

/// @brief malloc all UIs
/// @param gstruct_t *gstruct
void malloc_ui(gstruct_t *gstruct)
{
    GUI_ = malloc(sizeof(struct game_ui_s));
    ESC_ = malloc(sizeof(struct esc_ui_s));
    SET_ = malloc(sizeof(struct set_ui_s));
    INV_ = malloc(sizeof(struct inv_ui_s));
    START_UI = malloc(sizeof(struct start_ui_s));
    QUIT_UI = malloc(sizeof(struct quit_ui_s));
    PAUSED_UI = malloc(sizeof(struct paused_ui_s));
}

/// @brief init all UI parts
/// @param gstruct_t *gstruct
void create_ui(gstruct_t *gstruct)
{
    malloc_ui(gstruct);
    create_ingame_ui(gstruct);
    create_set(gstruct);
    create_quit_ui(gstruct);
    create_start_ui(gstruct);
}
