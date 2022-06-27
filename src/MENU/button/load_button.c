/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** load_button
*/

#include "defender.h"

void load_button(menu_t *menu_obj)
{
    menu_obj->button_list = NULL;
    add_btn(&(menu_obj->button_list), &(button_t) {
        {WD_WIDTH / 2, 200}, {64, 16, 16, 16}, {5, 5}, *launch_game_btn});
    add_btn(&(menu_obj->button_list), &(button_t) {
        {50, 50}, {0, 0, 16, 16}, {5, 5}, *close_game});
    add_btn(&(menu_obj->button_list), &(button_t) {
        {WD_WIDTH / 2, 300}, {48, 32, 16, 16}, {5, 5}, *map_selector});
    add_btn(&(menu_obj->button_list), &(button_t) {
        {WD_WIDTH / 2, 400}, {32, 48, 16, 16}, {5, 5}, *go_to_trophea});
    add_btn(&(menu_obj->button_list), &(button_t) {
        {WD_WIDTH / 2, 500}, {64, 80, 16, 16}, {5, 5}, *go_to_info});
}
