/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** load_struct
*/

#include "../../include/my.h"

void load_player_stats(gstruct_t *gstruct, FILE *fd)
{
    fscanf(fd, "strenght = %d\n", &PSTATS_->strenght);
    fscanf(fd, "dexterity = %d\n", &PSTATS_->dexterity);
    fscanf(fd, "agility = %d\n", &PSTATS_->agility);
    fscanf(fd, "health = %d\n", &PSTATS_->health);
    fscanf(fd, "current_health = %f\n", &STATS_->current_health);
    fscanf(fd, "max_stamina = %d\n", &PSTATS_->max_stam);
    fscanf(fd, "defense = %d\n", &PSTATS_->defense);
    fscanf(fd, "statspoints = %d\n", &STATS_->stats_points);
    fscanf(fd, "armor = %d\n", &STATS_->armor);
    fscanf(fd, "skin = %d\n", &STATS_->skin);
    fscanf(fd, "level = %f\n", &STATS_->level);
    fscanf(fd, "coords = {%f; %f}\n", &STATS_->coords.x, &STATS_->coords.y);
}

void load_level(gstruct_t *gstruct, FILE *fd)
{
    fscanf(fd, "map_id = %d\n", &LEVEL_->map_id);
    fscanf(fd, "completed = %d\n", &LEVEL_->completed);
}

void load_struct(gstruct_t *gstruct)
{
    FILE *fd = fopen("save.txt", "r");

    if (!fd){
        gstruct->save = sfFalse;
        return;
    }
    load_level(gstruct, fd);
    load_player_stats(gstruct, fd);
    recreate_level(gstruct, STATS_->coords, LEVEL_->map_id);
    set_skin(gstruct, STATS_->skin);
    gstruct->gamestate = in_game;
    gstruct->uistate = game_ui;
    START_UI->but_load->state = HOVER;
    ESC_->but_load->state = HOVER;
}
