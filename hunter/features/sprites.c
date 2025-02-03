/*
** EPITECH PROJECT, 2024
** sprites
** File description:
** sprites' game
*/
#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio.h>
#include "include/my.h"

int map(sfRenderWindow *window)
{
    sfVector2f my_position = {0, 0};
    sfVector2f scale = {1, 1.1};
    sfTexture *my_texture =
        sfTexture_createFromFile("./hunter/dot/png/boom.png", NULL);
    sfSprite *my_map = sfSprite_create();

    check_window_creation(window);
    check_texture_creation(window, my_texture);
    spricr(window, my_map, my_texture);
    sfSprite_setScale(my_map, scale);
    sfSprite_setPosition(my_map, my_position);
    sfSprite_setTexture(my_map, my_texture, sfFalse);
    sfRenderWindow_drawSprite(window, my_map, NULL);
    sfTexture_destroy(my_texture);
    sfSprite_destroy(my_map);
    return 0;
}
