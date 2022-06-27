/*
** EPITECH PROJECT, 2022
** menu
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_
    #include "defender.h"
    #define BTN_LIST 4

typedef struct game_object game_object_t;
typedef struct button button_t;

typedef enum {
    MAIN,
    MAP_SC,
} scene_menu;

typedef enum {
    PLAY_B,
    QUIT_B,
    SETTINGS_B,
    SCORE_B
} button_name;

typedef struct menu {
    sfText *title;
    sfSprite *background;
    button_t *button_list;
    scene_menu scene;
}menu_t;

//menu_loop
void method_btn(game_object_t *obj);
int menu_loop(game_object_t *game_asset, sfRenderWindow *window);

//display_menu
void display_menu(sfRenderWindow *window, menu_t *menu_obj,
game_object_t *game_asset);

//sub menu
void map_select(game_object_t *game_asset, sfRenderWindow *window,
menu_t *menu_obj);
void trophea(game_object_t *game_asset, sfRenderWindow *window,
menu_t *menu_obj);
void info(game_object_t *game_asset, sfRenderWindow *window,
menu_t *menu_obj);

//event menu
void analyse_events_menu(sfRenderWindow *window, sfEvent event,
menu_t *menu_obj, game_object_t *game_asset);

//load_menu
int load_menu(menu_t *menu_obj);
int free_menu(menu_t *menu_obj);
void load_text(menu_t *menu_obj);

//button
void load_button(menu_t *menu_obj);

//method_btn
void launch_game_btn(game_object_t *game);
void go_back_scene(game_object_t *game);
void close_game(game_object_t *game);
void go_to_info(game_object_t *game);
void map_selector(game_object_t *game);
void go_to_trophea(game_object_t *game);
#endif /* !MENU_H_ */
