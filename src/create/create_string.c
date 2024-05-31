/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-marin.lagie
** File description:
** create_string.c
*/
#include "../../include/my.h"

void create_string(sfText *text, cc_t *string, ui_t size)
{
    sfText_setString(text, string);
    sfText_setCharacterSize(text, size);
}
