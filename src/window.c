/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** window management and background
*/

#include "defender.h"

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

sfRenderWindow *load_window(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {WD_WIDTH, WD_HEIGHT, 32};

    window = sfRenderWindow_create(mode, "My defender",
        sfResize | sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfRenderWindow_setFramerateLimit(window, 60);
    if (!window) {
        return NULL;
    }
    return window;
}
