/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** save_struct
*/

#include "../../include/my.h"

void save_player_stats(gstruct_t *gstruct, FILE *fd)
{
    fprintf(fd, "strenght = %d\n", PSTATS_->strenght);
    fprintf(fd, "dexterity = %d\n", PSTATS_->dexterity);
    fprintf(fd, "agility = %d\n", PSTATS_->agility);
    fprintf(fd, "health = %d\n", PSTATS_->health);
    fprintf(fd, "current_health = %f\n", STATS_->current_health);
    fprintf(fd, "max_stamina = %d\n", PSTATS_->max_stam);
    fprintf(fd, "defense = %d\n", PSTATS_->defense);
    fprintf(fd, "statspoints = %d\n", STATS_->stats_points);
    fprintf(fd, "armor = %d\n", STATS_->armor);
    fprintf(fd, "skin = %d\n", STATS_->skin);
    fprintf(fd, "level = %f\n", STATS_->level);
    fprintf(fd, "coords = {%f; %f}\n", STATS_->coords.x, STATS_->coords.y);
}

void save_level(gstruct_t *gstruct, FILE *fd)
{
    fprintf(fd, "map_id = %d\n", LEVEL_->map_id);
    fprintf(fd, "completed = %d\n", LEVEL_->completed);
}

void save_struct(gstruct_t *gstruct)
{
    FILE *fd = fopen("save.txt", "w");

    gstruct->save = sfTrue;
    ESC_->but_save->state = HOVER;
    save_level(gstruct, fd);
    save_player_stats(gstruct, fd);
    fflush(fd);
    gstruct->gamestate = in_game;
    gstruct->uistate = game_ui;
}
