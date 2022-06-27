/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** load_text
*/

#include "defender.h"

void custom_text(sfText *text, sfVector2f pos, char *string)
{
    sfText_setString(text, string);
    sfText_setPosition(text, pos);
}

sfText *init_text(sfVector2f pos, int char_size, char *string)
{
    sfText *text = sfText_create();
    sfText_setString(text, string);
    sfText_setCharacterSize(text, char_size);
    sfText_setFont(text, sfFont_createFromFile("resources/FONT/Roboto.ttf"));
    sfText_setPosition(text, pos);
}
