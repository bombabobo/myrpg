/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** create_gamescene
*/

#include "../../include/my.h"

/// @brief set player physical stats
/// @param gstruct_t *gstruct
static void set_pstats(gstruct_t *gstruct)
{
    PSTATS_ = malloc(sizeof(struct pstats_s));
    PSTATS_->strenght = BASE_STRENGHT;
    PSTATS_->dexterity = BASE_DEXT;
    PSTATS_->agility = BASE_AGI;
    PSTATS_->health = BASE_HP;
    PSTATS_->defense = BASE_DEFENSE;
    PSTATS_->max_stam = BASE_ST;
}

/// @brief set player non physical stats
/// @param gstruct_t *gstruct
static void set_stats(gstruct_t *gstruct)
{
    STATS_ = malloc(sizeof(struct stats_s));
    STATS_->current_stam = BASE_ST;
    STATS_->current_health = BASE_HP;
    STATS_->stats_points = 0;
    STATS_->dir = 0;
    STATS_->fstate = 0;
    STATS_->armor = BASE_ARMOR;
    STATS_->skin = BASE_SKIN;
    STATS_->skin_path = malloc(50);
    sprintf(STATS_->skin_path, "ressources/Player/Character%d.png",
        STATS_->skin);
    STATS_->is_sprinting = sfFalse;
    STATS_->iswalking = 0;
}

/// @brief create all sounds
/// @param gstruct_t *gstruct
void set_audio(gstruct_t *gstruct)
{
    AUDIO_.dash_au = sfSound_create();
    AUDIO_.dash_au_b = sfSoundBuffer_createFromFile(DASH_AU);
    sfSound_setBuffer(AUDIO_.dash_au, AUDIO_.dash_au_b);
    AUDIO_.knife_au = sfSound_create();
    AUDIO_.knife_au_b = sfSoundBuffer_createFromFile(KNIFE_AU);
    sfSound_setBuffer(AUDIO_.knife_au, AUDIO_.knife_au_b);
    AUDIO_.music = sfMusic_createFromFile(MUSIC_AU);
    sfMusic_setLoop(AUDIO_.music, sfTrue);
    sfMusic_play(AUDIO_.music);
}

/// @brief init Player
/// @param gstruct_t *gstruct
static void create_player(gstruct_t *gstruct)
{
    set_audio(gstruct);
    set_stats(gstruct);
    set_pstats(gstruct);
    PLAYER_->sp_player = sfSprite_create();
    PLAYER_->playertex = sfTexture_createFromFile(STATS_->skin_path, NULL);
    PLAYER_->tex_clock = sfClock_create();
    PLAYER_->texture_rect = (sfIntRect){0, 0, 32, 32};
    STATS_->coords = LEVEL_->spawn;
    sfSprite_setPosition(PLAYER_->sp_player, STATS_->coords);
    sfSprite_setTexture(PLAYER_->sp_player, PLAYER_->playertex, sfTrue);
    sfSprite_setTextureRect(PLAYER_->sp_player, PLAYER_->texture_rect);
    sfSprite_setScale(PLAYER_->sp_player, V2F {SCALE_, SCALE_});
}

/// @brief recreate a level with pos and random control
/// @param gstruct_t *gstruct
/// @param sfVector2f pos
/// @param int rand
void recreate_level(gstruct_t *gstruct, sfVector2f pos, int rand)
{
    LEVEL_->firstlevel = sfFalse;
    sfTexture_destroy(LEVEL_->maptex);
    free_mobs(gstruct);
    map_create(gstruct, rand);
    LEVEL_->maptex = sfTexture_createSrgbFromImage(MAP_IMAGE, NULL);
    sfTexture_setRepeated(LEVEL_->maptex, sfTrue);
    sfSprite_setTexture(LEVEL_->sp_tilemap, LEVEL_->maptex, sfFalse);
    STATS_->coords = (pos.x > -1) ? pos : LEVEL_->spawn;
}

/// @brief init level
/// @param gstruct_t *gstruct
void create_level(gstruct_t *gstruct, int nb)
{
    LEVEL_->firstlevel = sfTrue;
    LEVEL_->completed = sfFalse;
    LEVEL_->sp_tilemap = sfSprite_create();
    LEVEL_->background = sfRectangleShape_create();
    sfRectangleShape_setSize(LEVEL_->background, sfView_getSize(VIEW_));
    sfRectangleShape_setFillColor(LEVEL_->background, BG_COLOR);
    sfRectangleShape_setOrigin(LEVEL_->background, V2F {V_MID_X, V_MID_Y});
    LEVEL_->buffer = sfImage_createFromFile(TILES_);
    LEVEL_->map = sfImage_createFromColor(IMG_SIZE_X, IMG_SIZE_Y,
        sfTransparent);
    LEVEL_->hitboxes = sfImage_createFromColor(IMG_SIZE_X, IMG_SIZE_Y,
        sfTransparent);
    map_create(gstruct, nb);
    LEVEL_->maptex = sfTexture_createSrgbFromImage(MAP_IMAGE, NULL);
    sfTexture_setRepeated(LEVEL_->maptex, sfTrue);
    sfSprite_setScale(LEVEL_->sp_tilemap, V2F {CELL_SCALE_, CELL_SCALE_});
    sfSprite_setTexture(LEVEL_->sp_tilemap, LEVEL_->maptex, sfFalse);
    sfSprite_setPosition(LEVEL_->sp_tilemap, (sfVector2f){0, 0});
}

/// @brief to clean
/// @param gstruct_t *gstruct
void create_gamescene(gstruct_t *gstruct)
{
    create_level(gstruct, -1);
    create_player(gstruct);
}
