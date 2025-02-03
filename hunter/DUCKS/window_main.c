/*
** EPITECH PROJECT, 2024
** main
** File description:
** main's game
*/
#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <event.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include "include/my.h"

sfSprite* sprite(sfTexture* texture)
{
    sfSprite* sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

void setup_window(sfRenderWindow* window,
    sfSprite* my_sprite, sfVector2f original_position)
{
    check_window_creation(window);
    sfSprite_setPosition(my_sprite, original_position);
    sfRenderWindow_setFramerateLimit(window, 60);
}

void close_menu(sfRenderWindow* window, sfEvent* event)
{
    check_window_creation(window);
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}
