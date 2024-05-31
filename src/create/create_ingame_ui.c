/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** create_ui
*/

#include "../../include/my.h"

/// @brief init game user interface
/// @param gstruct_t *gstruct
static void create_gui(gstruct_t *gstruct)
{
    GUI_->max_hp = sfRectangleShape_create();
    sfRectangleShape_setFillColor(GUI_->max_hp, sfRed);
    GUI_->current_hp = sfRectangleShape_create();
    sfRectangleShape_setFillColor(GUI_->current_hp, sfGreen);
    GUI_->current_st = sfRectangleShape_create();
    sfRectangleShape_setFillColor(GUI_->current_st, sfBlue);
    GUI_->max_st = sfRectangleShape_create();
    sfRectangleShape_setFillColor(GUI_->max_st, sfYellow);
    GUI_->box = sfRectangleShape_create();
    sfRectangleShape_setSize(GUI_->box, V2F {400, 100});
    sfRectangleShape_setFillColor(GUI_->box, SF_GREY);
    GUI_->profile = sfRectangleShape_create();
    GUI_->texture_rect = (sfIntRect){0, 0, 32, 32};
    sfRectangleShape_setTexture(GUI_->profile, PLAYER_->playertex, sfFalse);
    sfRectangleShape_setTextureRect(GUI_->profile, GUI_->texture_rect);
    sfRectangleShape_setSize(GUI_->profile, V2F {32, 32});
    GUI_->but_esc = create_button(V2F {20, 20}, V2F {300, 100}, 1);
    sfText_setString(GUI_->but_esc->name, "Menu");
}

/// @brief init all buttons in echap menu
/// @param gstruct_t *gstruct
static void create_esc_buttons(gstruct_t *gstruct)
{
    ESC_->but_inv = create_button(V2F {810, 400}, V2F {300, 100}, 1);
    ESC_->but_load = create_button(V2F {810, 520}, V2F {300, 100}, 1);
    ESC_->but_save = create_button(V2F {810, 640}, V2F {300, 100}, 1);
    ESC_->but_settings = create_button(V2F {810, 760}, V2F {300, 100}, 1);
    ESC_->but_back = create_button(V2F {20, 20}, V2F {300, 100}, 1);
    sfText_setString(ESC_->but_inv->name, "inventory");
    sfText_setString(ESC_->but_load->name, "load game");
    sfText_setString(ESC_->but_save->name, "save game");
    sfText_setString(ESC_->but_settings->name, "settings");
    sfText_setString(ESC_->but_back->name, "Quit");
}

/// @brief init echap menu
/// @param gstruct_t *gstruct
void create_esc(gstruct_t *gstruct)
{
    ESC_->menu = sfSprite_create();
    ESC_->menu_tex = sfTexture_createFromFile(MENU_TITLE, NULL);
    sfSprite_setTexture(ESC_->menu, ESC_->menu_tex, sfFalse);
    sfSprite_setScale(ESC_->menu, V2F {0.8, 0.8});
    sfSprite_setOrigin(ESC_->menu, V2F {274.5, 83.5});
    sfSprite_setColor(ESC_->menu, SF_DGREY);
    ESC_->box = sfRectangleShape_create();
    sfRectangleShape_setFillColor(ESC_->box, SF_GREY);
    create_esc_buttons(gstruct);
}

/// @brief create a single inventory stat box
/// @param s_box pointer to the box to create
/// @param pos position of the box (latter with V_PO_)
/// @param name name for the string of the box
static void create_box(stat_box_t *s_box, sfVector2f pos, char *name,
    int *stat)
{
    s_box->stat_name = strdup(name);
    s_box->stat = stat;
    s_box->box = sfRectangleShape_create();
    sfRectangleShape_setFillColor(s_box->box, SF_GREY);
    s_box->plus = create_button(V2F {1525, pos.y + 25}, V2F {150, 50}, 1);
    sfText_setString(s_box->plus->name, "Add 1");
    s_box->stat_text = sfText_create();
    sfText_setString(s_box->stat_text, name);
    sfText_setFont(s_box->stat_text, s_box->plus->font);
    sfText_setColor(s_box->stat_text, sfWhite);
    sfText_setCharacterSize(s_box->stat_text, 68);
    s_box->pos = pos;
    s_box->size = V2F {450, 100};
}

/// @brief init the boxs from the inventory menu
/// @param gstruct_t *gstruct
static void create_boxs(gstruct_t *gstruct)
{
    INV_->stats_string = malloc(20);
    INV_->b_strenght = malloc(sizeof(stat_box_t));
    INV_->b_dexterity = malloc(sizeof(stat_box_t));
    INV_->b_agility = malloc(sizeof(stat_box_t));
    INV_->b_defense = malloc(sizeof(stat_box_t));
    INV_->b_endurance = malloc(sizeof(stat_box_t));
    create_box(INV_->b_strenght, V2F {1255, 350}, STRE_, &PSTATS_->strenght);
    create_box(INV_->b_dexterity, V2F {1255, 470}, DEXT_, &PSTATS_->dexterity);
    create_box(INV_->b_agility, V2F {1255, 590}, AGIL_, &PSTATS_->agility);
    create_box(INV_->b_defense, V2F {1255, 710}, DEF_, &PSTATS_->defense);
    create_box(INV_->b_endurance, V2F {1255, 830}, HP_, &PSTATS_->health);
    INV_->stats_box = sfRectangleShape_create();
    sfRectangleShape_setFillColor(INV_->stats_box, SF_DGREY);
    INV_->skin_box = sfRectangleShape_create();
    sfRectangleShape_setFillColor(INV_->skin_box, SF_PAUSED);
}

/// @brief create skin seletion buttons
/// @param gstruct_t *gstruct
void create_skin_buttons(gstruct_t *gstruct)
{
    INV_->but_p_armor = create_button(V2F {975, 410.5}, V2F {190, 190}, 0);
    INV_->but_p_skin = create_button(V2F {975, 619.5}, V2F {190, 190}, 0);
    INV_->but_m_armor = create_button(V2F {345, 410.5}, V2F {190, 190}, 0);
    INV_->but_m_skin = create_button(V2F {345, 619.5}, V2F {190, 190}, 0);
    INV_->arrows_tex = sfTexture_createFromFile(ARROWS_, NULL);
    INV_->arrows = sfRectangleShape_create();
    sfRectangleShape_setTexture(INV_->arrows, INV_->arrows_tex, sfFalse);
    INV_->arrows_tr = (sfIntRect) {0, 0, 100, 100};
}

/// @brief init inventory menu
/// @param gstruct_t *gstruct
static void create_inv(gstruct_t *gstruct)
{
    INV_->box = sfRectangleShape_create();
    sfRectangleShape_setFillColor(INV_->box, SF_GREY);
    INV_->menu = sfSprite_create();
    INV_->menu_tex = sfTexture_createFromFile(INVENTORY_TITLE, NULL);
    sfSprite_setTexture(INV_->menu, INV_->menu_tex, sfFalse);
    sfSprite_setScale(INV_->menu, V2F {0.7, 0.7});
    sfSprite_setColor(INV_->menu, SF_DGREY);
    INV_->font = sfFont_createFromFile(FONT_PATH(font2));
    INV_->inv_text = sfText_create();
    sfText_setFont(INV_->inv_text, INV_->font);
    sfText_setColor(INV_->inv_text, sfWhite);
    sfText_setCharacterSize(INV_->inv_text, 100);
    create_boxs(gstruct);
    create_skin_buttons(gstruct);
}

/// @brief init all UI parts
/// @param gstruct_t *gstruct
void create_ingame_ui(gstruct_t *gstruct)
{
    create_gui(gstruct);
    create_esc(gstruct);
    create_inv(gstruct);
    PAUSED_UI->box = sfRectangleShape_create();
    sfRectangleShape_setFillColor(PAUSED_UI->box, SF_PAUSED);
}
