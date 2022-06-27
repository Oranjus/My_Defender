/*
** EPITECH PROJECT, 2021
** bs_runner
** File description:
** runner
*/

#ifndef DEFENDER_H
    #define DEFENDER_H
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <unistd.h>
    #include "my.h"
    #include "hud.h"
    #include "menu.h"
    #include "game.h"
    #define WD_WIDTH 1280
    #define WD_HEIGHT 640
    #define ABS(x) (x < 0)? (-x):(x)

typedef enum {
    QUIT = -1,
    GAME,
    MENU,
    PAUSE,
    MAP,
    TROPHEA,
    INFO,
    ASSAULT,
    BUILD
} scene_state;

typedef struct game_object {
    scene_state scene;
    sfMusic *music;
    sfMusic *music_click;
    game_t *game_obj;
    sfSprite *cursor;
    int i_cursor;
    int state_click;
} game_object_t;

typedef struct button {
    sfVector2f position;
    sfIntRect size;
    sfVector2f scale;
    void (*method_event)(game_object_t *);
    void (*method_event_reset)(game_object_t *);
    button_t *next;
    sfSprite *button;
} button_t;

//main
int launch_game(void);
int verificator(int ac, char **av, char **env);

//window
sfRenderWindow *load_window(void);
void close_window(sfRenderWindow *window);

//load_object
game_object_t *load_asset(game_object_t *game_asset);
void destroy_asset(game_object_t *game_asset);

//event
void analyse_events(sfRenderWindow *window, sfEvent event,
game_object_t *game_asset);

//utils
sfSprite *load_cursor(char *filepath);
void change_cursor(game_object_t *game_asset, int dir);
int check_hitbox(sfSprite *sprite, sfVector2f pos_onclick);
void get_help(void);
sfSprite *init_sprite(sfVector2f pos, sfIntRect size, char *filepath);
sfMusic *load_music(char *filename, sfBool bool);
sfText *init_text(sfVector2f pos, int char_size, char *string);
void custom_text(sfText *text, sfVector2f pos, char *string);

//utils/button
void display_btn(sfRenderWindow *window,button_t *button_list);
static button_t *init_button(button_t *button_obj);
void add_btn(button_t **head, button_t *button_obj);
int destroy_btn(button_t *button_list);
int listen_event_btn(sfVector2f pos_onclick, game_object_t *game_asset,
button_t *button_head);
button_t *reset_button(button_t *button_obj);
void anim_sprite(sfSprite *sprite, sfIntRect offset_rect, sfIntRect last);
void change_sprite_btn(sfSprite *sprite, sfVector2f pos, sfIntRect size);
void disappear_btn(button_t *button_list);
void reset_button_list(button_t *button_list);

#endif /* !DEFENDER_H */
