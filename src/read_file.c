/*
** EPITECH PROJECT, 2024
** stumper7
** File description:
** recuptab
*/

#include "../include/my.h"

char *recup_file_str(char const *nmfich)
{
    char *str;
    int fd = open(nmfich, O_RDONLY);
    char buf[1];
    int nb_c = 0;

    if (fd == -1)
        exit(84);
    while (read(fd, buf, 1) > 0)
        nb_c++;
    close(fd);
    str = malloc(sizeof(char) * (nb_c + 1));
    fd = open(nmfich, O_RDONLY);
    read(fd, str, nb_c);
    str[nb_c] = '\0';
    close(fd);
    return str;
}

static int nb_line(char const *str)
{
    int l = 0;

    if (str[0] == '\n') {
        l++;
    }
    for (int x = 0; str[x] != '\0'; x++) {
        if (str[x] == '\n'
        && str[x + 1] != '\n') {
            l++;
        }
    }
    return l;
}

static int nb_taille(char *str)
{
    int x;

    for (x = 0; str[x] != '\n' && str[x] != '\0'; x++);
    return x;
}

char **creat_tab(char *str)
{
    char **tab = malloc(sizeof(char *) * (nb_line(str) + 2));
    int x = 0;
    int y = 0;
    int z = 0;

    for (x = 0; str[z] != '\0'; x++) {
        tab[x] = malloc(nb_taille(str) + 2);
        while (str[z] == '\n')
            z++;
        for (y = 0; str[z] != '\0' && str[z] != '\n'; y++) {
            tab[x][y] = str[z];
            z++;
        }
        tab[x][y] = '\0';
    }
    tab[x] = NULL;
    free(str);
    return tab;
}
