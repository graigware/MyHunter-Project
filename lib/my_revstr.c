/*
** EPITECH PROJECT, 2024
** my_revstr
** File description:
** reverse les caras d'une string
*/

#include "my.h"

char *my_revstr(char *str)
{
    int len_de_str = my_strlen(str);
    int reverse;
    int last_cara = len_de_str - 1;
    int i = 0;

    while (i < last_cara) {
        reverse = str[i];
        str[i] = str[last_cara];
        str[last_cara] = reverse;
        i++;
        last_cara--;
    }
    return str;
}
