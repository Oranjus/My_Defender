/*
** EPITECH PROJECT, 2021
** LIBRARY
** File description:
** header lib
*/

#ifndef MY_H
    #define MY_H
    #include <stdlib.h>

void my_putchar(char c);
void my_isneg(int nb);
void my_put_nbr(int nb);
void my_swap(int *a, int *b);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_get_nbr(char const *str);
void my_sort_int_array(int i);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *str1, char const *str2);
int my_strncmp(char const *str1, char const *str2, int limit);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(int i);
int my_showmem(int i);
char *nbr_to_str(int nb);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
char **str_to_word(char *str, char *separator);
void my_putstr_error(char *message);
int free_arr(char **arr);
int len_arr(char **arr);
char **cpy_array(char **dest, char **src);
#endif /* mt.h */
