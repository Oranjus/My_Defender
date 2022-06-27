/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** hud
*/

#ifndef HUD_H_
    #define HUD_H_
    #include "defender.h"
typedef struct game_object game_object_t;
typedef struct game game_t;
typedef struct button button_t;

typedef struct hud {
    button_t *button_list;
    sfSprite *coin;
    sfSprite *health;
    sfSprite *health_bar;
    sfSprite *visualisation;
    sfText *nb_gold;
    sfBool loose;
    sfText *loose_text;
    sfText *info_text;
    int couldown_text;
} hud_t;

//load
void load_hud(hud_t *hud_obj);
void destroy_hud(hud_t *hud);

//display
void display_hud(sfRenderWindow *window, hud_t *hud);

//update
void pop_up_text(char *message, int time, hud_t *hud_obj);
void update_hud(game_t *game_obj, sfClock *clock);

//method
void close_game_mtd(game_object_t *game_asset);
void go_to_menu(game_object_t *game_asset);
void launch_assault(game_object_t *game_asset);
void set_pause(game_object_t *game_asset);
void next_visualisation(game_object_t *game_asset);
void previous_visualisation(game_object_t *game_asset);

#endif /* !HUD_H_ */
