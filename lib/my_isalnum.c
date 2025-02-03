/*
** EPITECH PROJECT, 2024
** my_isalnum
** File description:
** savoir si un caractere est alphanumerique  ou non
*/

#include "my.h"

int my_isalnum(char c)
{
    return ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z'));
}
