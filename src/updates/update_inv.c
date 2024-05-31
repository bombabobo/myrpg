/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** update_inv
*/

#include "../../include/my.h"

/// @brief upd a single statistic box in the inventory UI
/// @param gstruct_t *gstruct
/// @param s_box pointer to the box
/// @param sfRenderWindow *window
void upd_box(gstruct_t *gstruct, stat_box_t *s_box, sfRenderWindow *window)
{
    char *temp_t = malloc(20);

    RECT_S_POS(s_box->box, V2F {V_PO_X(s_box->pos.x), V_PO_Y(s_box->pos.y)});
    RECT_S_SIZE(s_box->box, V2F {V_CO_X(s_box->size.x),
        V_CO_Y(s_box->size.y)});
    sfText_setPosition(s_box->stat_text, V2F {V_PO_X(1270),
        V_PO_Y(s_box->pos.y + 25)});
    sprintf(temp_t, "[%s : %d]", s_box->stat_name, *s_box->stat);
    sfText_setString(s_box->stat_text, temp_t);
    sfText_setScale(s_box->stat_text, V2F {V_SCA_X(0.5), V_SCA_Y(0.5)});
    sfRenderWindow_drawRectangleShape(window, s_box->box, 0);
    sfRenderWindow_drawText(window, s_box->stat_text, 0);
    upd_button(gstruct, s_box->plus, window, STATS_->stats_points);
}

/// @brief update the arrows from the inventory UI
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
static void upd_arrows(gstruct_t *gstruct, sfRenderWindow *window)
{
    RECT_S_SIZE(INV_->arrows, V2F {V_CO_X(190), V_CO_Y(190)});
    INV_->arrows_tr.left = 0;
    sfRectangleShape_setTextureRect(INV_->arrows, INV_->arrows_tr);
    RECT_S_POS(INV_->arrows, V2F {V_PO_X(975), V_PO_Y(410.5)});
    sfRenderWindow_drawRectangleShape(window, INV_->arrows, 0);
    RECT_S_POS(INV_->arrows, V2F {V_PO_X(975), V_PO_Y(619.5)});
    sfRenderWindow_drawRectangleShape(window, INV_->arrows, 0);
    INV_->arrows_tr.left = 100;
    sfRectangleShape_setTextureRect(INV_->arrows, INV_->arrows_tr);
    RECT_S_POS(INV_->arrows, V2F {V_PO_X(345), V_PO_Y(410.5)});
    sfRenderWindow_drawRectangleShape(window, INV_->arrows, 0);
    RECT_S_POS(INV_->arrows, V2F {V_PO_X(345), V_PO_Y(619.5)});
    sfRenderWindow_drawRectangleShape(window, INV_->arrows, 0);
}

/// @brief update the stats boxs from the inventory menu
/// @param gstruct_t *gstruct
static void upd_stats_boxs(gstruct_t *gstruct, sfRenderWindow *window)
{
    sprintf(INV_->stats_string, "points = %d", STATS_->stats_points);
    sfText_setScale(INV_->inv_text, V2F {V_SCA_X(0.5), V_SCA_Y(0.5)});
    sfText_setPosition(INV_->inv_text, V2F {V_PO_X(1350), V_PO_Y(210)});
    sfText_setString(INV_->inv_text, INV_->stats_string);
    sfRenderWindow_drawText(window, INV_->inv_text, 0);
    sfText_setPosition(INV_->inv_text, V2F {V_PO_X(610), V_PO_Y(300)});
    sfText_setString(INV_->inv_text, "change armor");
    sfRenderWindow_drawText(window, INV_->inv_text, 0);
    sfText_setPosition(INV_->inv_text, V2F {V_PO_X(630), V_PO_Y(870)});
    sfText_setString(INV_->inv_text, "change skin");
    sfRenderWindow_drawText(window, INV_->inv_text, 0);
    upd_box(gstruct, INV_->b_strenght, window);
    upd_box(gstruct, INV_->b_dexterity, window);
    upd_box(gstruct, INV_->b_agility, window);
    upd_box(gstruct, INV_->b_defense, window);
    upd_box(gstruct, INV_->b_endurance, window);
    upd_arrows(gstruct, window);
}

/// @brief update the UI box from the inventory menu (aka dir aka sfrectshape)
/// @param gstruct_t *gstruct
static void upd_boxs(gstruct_t *gstruct, sfRenderWindow *window)
{
    RECT_S_POS(INV_->box, V2F {V_PO_X(160), V_PO_Y(60)});
    RECT_S_SIZE(INV_->box, V2F {V_CO_X(1600), V_CO_Y(960)});
    sfRenderWindow_drawRectangleShape(window, INV_->box, 0);
    RECT_S_POS(INV_->stats_box, V2F {V_PO_X(1230), V_PO_Y(90)});
    RECT_S_SIZE(INV_->stats_box, V2F {V_CO_X(500), V_CO_Y(900)});
    sfRenderWindow_drawRectangleShape(window, INV_->stats_box, 0);
    RECT_S_POS(INV_->skin_box, V2F {V_PO_X(280), V_PO_Y(230)});
    RECT_S_SIZE(INV_->skin_box, V2F {V_CO_X(950), V_CO_Y(760)});
    sfRenderWindow_drawRectangleShape(window, INV_->skin_box, 0);
}

/// @brief update the inventory menu
/// @param gstruct_t *gstruct
/// @param sfRenderWindow *window
void upd_inv(gstruct_t *gstruct, sfRenderWindow *window)
{
    gstruct->gamestate = paused;
    upd_boxs(gstruct, window);
    sfSprite_setPosition(INV_->menu, V2F {V_PO_X(750), V_PO_Y(100)});
    sfSprite_setScale(INV_->menu, V2F {V_SCA_X(0.7), V_SCA_Y(0.7)});
    sfRenderWindow_drawSprite(window, INV_->menu, 0);
    upd_button(gstruct, ESC_->but_back, window, 1);
    upd_button(gstruct, INV_->but_p_armor, window, 1);
    upd_button(gstruct, INV_->but_p_skin, window, 1);
    upd_button(gstruct, INV_->but_m_armor, window, 1);
    upd_button(gstruct, INV_->but_m_skin, window, 1);
    upd_stats_boxs(gstruct, window);
    upd_profile(gstruct, V2F {V_PO_X(535), V_PO_Y(390)},
        V2F {V_CO_X(440), V_CO_Y(440)}, window);
}
