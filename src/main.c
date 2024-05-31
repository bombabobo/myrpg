/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** myradar
*/

#include "../include/my.h"

/// @brief hash a string into an integer
/// @param key the string to hash
/// @return the hashed integer
int hash(char *key)
{
    int len = strlen(key);
    int hash = 0;

    for (int i = 0; i < len; ++i){
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return (hash > 0) ? hash : -hash;
}

/// @brief display help message
/// @return 0
int display_help(void)
{
    printf("Forbidden Ruins\n\nUsage: ./my_rpg\n\n");
    printf("Voic les différens contrôle du jeu\n");
    printf("  - ZQSD pour se déplacer vous pouvez utiliser");
    printf("les flèches directionnel\n");
    printf("  - Clique gauche ou droite pour dash et attaquer\n");
    printf("  - E permet d'ouvrir l'inventaire\n");
    printf("  - Echap pour acceder au menu en jeu\n");
    printf("  - Alt + F4 pour quitter le jeu\n");
    return 0;
}

/// @brief to remake
/// @param sfRenderWindow *window
/// @return window
sfRenderWindow *create_render_window(void)
{
    sfVideoMode video_mode = {V_MODE};
    sfImage *icon = sfImage_createFromFile(LOGO);
    sfVector2u iconSize = sfImage_getSize(icon);
    const sfUint8 *pixels = sfImage_getPixelsPtr(icon);
    sfRenderWindow *window = sfRenderWindow_create(video_mode, TITLE,
        sfDefaultStyle, NULL);

    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setKeyRepeatEnabled(window, sfFalse);
    sfRenderWindow_setIcon(window, iconSize.x, iconSize.y, pixels);
    sfImage_destroy(icon);
    return window;
}

/// @brief commented everything to do
/// @param gstruct_t *gstruct
void my_rpg(gstruct_t *gstruct)
{
    sfRenderWindow *window = create_render_window();
    sfEvent event;

    upd_all(gstruct, window);
    while (!(GSTATE_(end)) && gstruct->close_game != sfTrue){
        sfRenderWindow_clear(window, sfWhite);
        FPS_ = (1000000 / sfClock_restart(gstruct->fpsclock).microseconds);
        analyse_events(window, &event, gstruct);
        upd_all(gstruct, window);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_close(window);
    free_struct(gstruct, 1);
    sfRenderWindow_destroy(window);
}

int main(int ac, char **av)
{
    gstruct_t gstruct;
    int debug = 0;

    if (ac > 1)
        debug = (hash(av[1]) == PASSWORD_HASH) ? 1 : 0;
    if (ac > 1 && !debug)
        return display_help();
    create_structs(&gstruct, debug, 1);
    my_rpg(&gstruct);
    return 0;
}
