/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** load_game
*/

#include "defender.h"

void load_enemy(game_t *game_obj, int nbr)
{
    game_obj->enemy_head = NULL;
    create_n_list(nbr, &game_obj->enemy_head);
    init_move(game_obj->enemy_head, game_obj->building_head);
}

void load_game(game_t *game_obj)
{
    game_obj->music = load_music("resources/MUSIC/game.ogg", sfTrue);
    sfMusic_play(game_obj->music);
    game_obj->scene = BUILDING_ROUND;
    game_obj->gold = 800;
    game_obj->rounds = 1;
    game_obj->nbr_enemy = 15;
    game_obj->dead_enemies = 0;
    game_obj->health = 1000;
    game_obj->selected_build = CASTLE;
    game_obj->pause = sfFalse;
    game_obj->filepath_bg = "resources/map/map_1.png";
    game_obj->background = init_sprite((sfVector2f){0, 0},
        (sfIntRect){-1}, game_obj->filepath_bg);
    game_obj->hud_obj = malloc(sizeof(hud_t));
    load_hud(game_obj->hud_obj);
    game_obj->building_head = NULL;
    game_obj->enemy_head = NULL;
    my_putstr("game_loaded\n");
}

int destroy_game(game_t *game_obj)
{
    if (game_obj == NULL)
        return 84;
    sfSprite_destroy(game_obj->background);
    destroy_hud(game_obj->hud_obj);
    sfMusic_setLoop(game_obj->music, sfFalse);
    sfMusic_stop(game_obj->music);
    sfMusic_destroy(game_obj->music);
    destroy_building(game_obj->building_head);
    free(game_obj);
    my_putstr("free_game\n");
}
