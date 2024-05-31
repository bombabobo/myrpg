/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <fcntl.h>
    #include <unistd.h>
    #include <string.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include "struct.h"
    #include "init.h"
    #include <sys/stat.h>
    #include <dirent.h>
    #include <math.h>
    #include <time.h>

typedef const char cc_t;
typedef unsigned int ui_t;
typedef sfVector2f v2f_t;
typedef sfVector2u v2u_t;

void analyse_events(sfRenderWindow *window, sfEvent *event,
    gstruct_t *gstruct);
void upd_game(gstruct_t *gst, sfRenderWindow *window);
void upd_all(gstruct_t *gstruct, sfRenderWindow *window);
void upd_ui(gstruct_t *gstruct, sfRenderWindow *window);
void create_structs(gstruct_t *gstruct, int debug, int start);
char *recup_file_str(char const *nmfich);
char **creat_tab(char *str);
void map_create(gstruct_t *gstruct, int map_nb);
int test_hb(int nb, gstruct_t *gstruct, sfVector2f coords);
int blue_collision(gstruct_t *gstruct);
void create_level(gstruct_t *gstruct, int nb);
void free_level(gstruct_t *gstruct);
void create_gamescene(gstruct_t *gstruct);
void change_health(gstruct_t *gstruct, float nb);
void is_clicked(button_t *button, sfEvent *event);
void is_hover(button_t *but, sfRenderWindow *window, gstruct_t *gstruct_t,
    int update);
void recreate_level(gstruct_t *gstruct, sfVector2f pos, int rand);
void set_skin(gstruct_t *gstruct, int skin_id);
void create_ui(gstruct_t *gstruct);
button_t *create_button(sfVector2f pos, sfVector2f size, int large);
void create_string(sfText *text, cc_t *string, ui_t size);
void create_ingame_ui(gstruct_t *gstruct);
void free_struct(gstruct_t *gstruct, int end);
void free_ui(gstruct_t *gstruct);
void free_ingame_ui(gstruct_t *gstruct);
void free_button(button_t *but);
void save_struct(gstruct_t *gstruct);
void load_struct(gstruct_t *gstruct);
void no_save_found(gstruct_t *gstruct, sfRenderWindow *window, sfVector2f pos);
void upd_button(gstruct_t *gstruct, button_t *but, sfRenderWindow *window,
    int enabled);
void no_save_found(gstruct_t *gstruct, sfRenderWindow *window, sfVector2f pos);
void upd_ingame_ui(gstruct_t *gstruct, sfRenderWindow *window);
void upd_paused_ui(gstruct_t *gstruct, sfRenderWindow *window);
void upd_set(gstruct_t *gstruct, sfRenderWindow *window);
void set_stat(int *stat, int *stats_points, int value);
void wanna_quit_events(gstruct_t *gstruct, sfEvent *event);
void start_events(gstruct_t *gstruct, sfEvent *event);
void inv_events(gstruct_t *gstruct, sfEvent *event);
void esc_events(gstruct_t *gstruct, sfEvent *event);
void set_events(gstruct_t *gstruct, sfEvent *event, sfRenderWindow *window);
void upd_inv(gstruct_t *gstruct, sfRenderWindow *window);
void upd_profile(gstruct_t *gstruct, sfVector2f pos, sfVector2f size,
    sfRenderWindow *window);
void free_mobs(gstruct_t *gstruct);
void upd_mobs(gstruct_t *gstruct, sfRenderWindow *window);
int anim(float fstate);
void player_events(gstruct_t *gstruct, sfEvent *event,
    sfRenderWindow *window);
void upd_gameover(gstruct_t *gstruct, sfRenderWindow *window);
void set_fullscreen(gstruct_t *gstruct, sfRenderWindow *window);
void set_windowed(gstruct_t *gstruct, sfRenderWindow *window, int def_style);
int is_fs(gstruct_t *gstruct, sfRenderWindow *win, int def_style);
void upd_wanna_quit(gstruct_t *gstruct, sfRenderWindow *window);
void draw_dbrect(gstruct_t *gstruct, sfFloatRect rect_to_draw,
    sfRenderWindow *win, sfColor c);
void draw_atrect(sfFloatRect rect_to_draw, sfRenderWindow *win, sfColor c);
void upd_player(gstruct_t *gstruct, sfRenderWindow *window);
int compare(sfColor c1, sfColor c2);

#endif /* !MY_H_ */
