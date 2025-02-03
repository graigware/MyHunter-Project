/*
** EPITECH PROJECT, 2024
** error_handling
** File description:
** no error only printfs
*/
#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <event.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include "my.h"

int check_window_creation(sfRenderWindow *window)
{
    if (!window) {
        my_printf("Theres is no window\n");
        return 1;
    }
    return 0;
}

int check_song_creation(sfMusic *song)
{
    if (!song) {
        my_printf("There is no banger\n");
        return 1;
    }
    return 0;
}

int check_texture_creation(sfTexture *my_texture)
{
    if (!my_texture) {
        my_printf("Failed to create the Texture\n");
        return 1;
    }
    return 0;
}

int spricr(sfSprite *my_sprite, sfTexture *my_texture)
{
    if (!my_sprite) {
        my_printf("Failed to create the Sprite\n");
        sfTexture_destroy(my_texture);
        return 1;
    }
    return 0;
}
