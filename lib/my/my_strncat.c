/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** my_strncat
*/

char *my_strncat(char *dest, char *src, int nb)
{
    int i = 0;
    int j = 0;

    while (dest[i] != 0)
        i += 1;
    while (src[j] != 0 && nb > 0) {
        dest[i + j] = src[j];
        j += 1;
        nb -= 1;
    }
    dest[i + j] = 0;
    return dest;
}
