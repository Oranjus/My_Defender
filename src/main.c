/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** main
*/

#include "defender.h"

int launch_game(void)
{
    sfRenderWindow *window = load_window();
    game_object_t *game_asset = load_asset(game_asset);

    while (sfRenderWindow_isOpen(window)) {
        switch (game_asset->scene) {
            case MENU:
                menu_loop(game_asset, window);
                break;
            case GAME:
                game_loop(game_asset, window);
                break;
            case QUIT:
                close_window(window);
                break;
        }
    }
    destroy_asset(game_asset);
    sfRenderWindow_destroy(window);
}

int verificator(int ac, char **av, char **env)
{
    if (*env == NULL || env[50] == NULL)
        return 84;
    else if (ac > 2) {
        my_putstr(" retry with -h\n");
        return 84;
    } else
        return 0;
}

int main(int ac, char **av, char **env)
{
    if (verificator(ac, av, env) == 84)
        return 84;
    else if (my_strcmp(av[1], "-h") == 0)
        get_help();
    else
        launch_game();
    return 0;
}
