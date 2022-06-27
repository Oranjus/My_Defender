/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** help
*/

#include "defender.h"

static char *rules(char const *filepath, char *buffer)
{
    buffer = malloc(sizeof(char)*(1500));
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return NULL;
    read(fd, buffer, 1500);
    return buffer;
}

void get_help(void)
{
    char *buffer;
    rules("resources/rules_game/rules.txt", buffer);
    free(buffer);
}
