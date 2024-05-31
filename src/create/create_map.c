/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** create_struct
*/

#include "../../include/my.h"

/// @brief set all of the pixels of an image in another
/// @param sfImage* source
/// @param sfImage* dest
/// @param int destX
/// @param int destY
void reset_image(sfImage *map)
{
    for (unsigned int x = 0; x < IMG_SIZE_X; ++x)
        for (unsigned int y = 0; y < IMG_SIZE_Y; ++y)
            sfImage_setPixel(map, x, y, sfTransparent);
}

/// @brief set all of the pixels of an image in another
/// @param sfImage* source
/// @param sfImage* dest
/// @param int destX
/// @param int destY
void copyimagepixels(sfImage *source, sfImage *dest, sfVector2i destpos,
    sfIntRect rect)
{
    unsigned int width = rect.width;
    unsigned int height = rect.height;
    sfColor pixelColor;

    for (unsigned int x = 0; x < width; ++x) {
        for (unsigned int y = 0; y < height; ++y) {
            pixelColor = sfImage_getPixel(source, rect.left + x, rect.top + y);
            sfImage_setPixel(dest, destpos.x + x, destpos.y + y, pixelColor);
        }
    }
}

/// @brief get the rect.left for the TextureRect
/// @param char c
/// @return rect.left for the right tile
static int calc_tile(char c)
{
    switch (c) {
    case '#':
        return 0;
    case 'G':
        return 32;
    case ' ':
        return 64;
    case 'D':
        return 128;
    case 'V':
        return 192;
    default:
        return 192;
    }
}

/// @brief get the rect.left for the hitbox TextureRect
/// @param char c
/// @return rect.left for the right hitbox tile
static int calc_hb(char c)
{
    switch (c) {
    case '#':
        return 0;
    case 'P':
        return 32;
    case 'S':
        return 64;
    case 'M':
        return 96;
    default:
        return 192;
    }
}

/// @brief add a tile block to the sfimage hitboxes
/// @param gstruct_t *gstruct
/// @param int i
/// @param int j
static void addblock(gstruct_t *gstruct, int i, int j)
{
    sfIntRect rect = (sfIntRect){0, 0, 32, 32};
    sfVector2i destpos = (sfVector2i){j * 32, i * 32};

    rect.left = calc_tile(MAPS_[LEVEL_->map_id].tiles[i][j]);
    copyimagepixels(LEVEL_->buffer, LEVEL_->map, destpos, rect);
}

/// @brief add a hitbox block to the sfimage hitboxes
/// @param gstruct_t *gstruct
/// @param int i
/// @param int j
static void addblock_hb(gstruct_t *gstruct, int i, int j)
{
    sfIntRect rect = (sfIntRect){0, 32, 32, 32};
    sfVector2i destpos = (sfVector2i){j * 32, i * 32};

    rect.left = calc_hb(MAPS_[LEVEL_->map_id].hitboxes[i][j]);
    copyimagepixels(LEVEL_->buffer, LEVEL_->hitboxes, destpos, rect);
    if (MAPS_[LEVEL_->map_id].hitboxes[i][j] == 'S')
        LEVEL_->spawn = V2F {j * 108, i * 108};
    if (MAPS_[LEVEL_->map_id].hitboxes[i][j] == 'M'){
        MOB_STATS(LEVEL_->mobs)->coords = V2F {j * 108, i * 108};
        MOB_STATS(LEVEL_->mobs)->spawn = V2F {j * 108, i * 108};
        LEVEL_->mobs++;
    }
}

/// @brief count the 'M' on the map
/// @param gstruct_t *gstruct
/// @param int map_id
/// @return the nb of mobs
int count_mobs(gstruct_t *gstruct, int map_id)
{
    int mobs = 0;

    for (int i = 0; MAPS_[map_id].hitboxes[i]; i++)
        for (int j = 0; MAPS_[map_id].hitboxes[i][j]; j++)
            mobs += (MAPS_[map_id].hitboxes[i][j] == 'M') ? 1 : 0;
    return mobs;
}

/// @brief set enemy stats (ratio to level)
/// @param ennemy_t *mob
static void set_stats(gstruct_t *gstruct, ennemy_t *mob)
{
    mob->pstats = malloc(sizeof(struct mpstats_s));
    if (LEVEL_->firstlevel){
        mob->pstats->max_hp = 25;
        mob->pstats->atk_speed = 2;
        mob->pstats->speed = 3;
        mob->pstats->damages = 5;
    } else {
        mob->pstats->max_hp = 25 * (1 + STATS_->level / 10.f);
        mob->pstats->max_hp = 25 * (1 + STATS_->level / 10.f);
        mob->pstats->atk_speed = 2 * (1 + STATS_->level / 10.f);
        mob->pstats->speed = 3 * (1 + STATS_->level / 10.f);
        mob->pstats->damages = 5 * (1 + STATS_->level / 10.f);
    }
    mob->stats = malloc(sizeof(struct mstats_s));
    mob->stats->attack_cd = sfClock_create();
    mob->stats->current_health = mob->pstats->max_hp;
    mob->stats->approach = rand() % 60;
    mob->stats->isalive = 1;
}

/// @brief create a ghost
/// @param ennemy_t pointer to the mob to create mob
void create_mob(gstruct_t *gstruct, ennemy_t *mob)
{
    set_stats(gstruct, mob);
    mob->sp_mob = sfSprite_create();
    mob->mobtex = sfTexture_createFromFile(GHOST_, NULL);
    mob->tex_clock = sfClock_create();
    mob->hp = sfRectangleShape_create();
    sfRectangleShape_setFillColor(mob->hp, sfGreen);
    mob->max_hp = sfRectangleShape_create();
    sfRectangleShape_setFillColor(mob->max_hp, sfRed);
    mob->texture_rect = (sfIntRect){0, 0, 36, 36};
    sfSprite_setPosition(mob->sp_mob, mob->stats->coords);
    sfSprite_setTexture(mob->sp_mob, mob->mobtex, sfTrue);
    sfSprite_setTextureRect(mob->sp_mob, mob->texture_rect);
    sfSprite_setScale(mob->sp_mob, V2F {3, 3});
}

/// @brief create an image of the map mab_nb from a file
/// @param gstruct_t *gstruct
/// @param int map_nb
void map_create(gstruct_t *gstruct, int map_nb)
{
    if (map_nb < 0){
        while (map_nb == LEVEL_->map_id || map_nb < 0)
            map_nb = rand() % NB_MAPS;
    }
    LEVEL_->mobs = 0;
    LEVEL_->mob = malloc(sizeof(ennemy_t) *
        count_mobs(gstruct, map_nb));
    for (int i = 0; i < count_mobs(gstruct, map_nb); i++)
        create_mob(gstruct, &MOB_(i));
    reset_image(LEVEL_->map);
    reset_image(LEVEL_->hitboxes);
    LEVEL_->map_id = map_nb;
    for (int i = 0; MAPS_[LEVEL_->map_id].tiles[i]; i++)
        for (int j = 0; MAPS_[LEVEL_->map_id].tiles[i][j]; j++){
            addblock_hb(gstruct, i, j);
            addblock(gstruct, i, j);
        }
}
