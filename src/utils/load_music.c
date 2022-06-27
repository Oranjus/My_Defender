/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-lucas.brahimi
** File description:
** load_music
*/

#include "defender.h"

sfMusic *load_music(char *filename, sfBool bool)
{
    sfMusic *music = sfMusic_createFromFile(filename);
    sfMusic_setLoop(music, bool);
    return music;
}
