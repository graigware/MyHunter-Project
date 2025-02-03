/*
** EPITECH PROJECT, 2024
** menu
** File description:
** start menu
*/
#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio.h>
#include "include/my.h"

int manage_menu_click(sfRenderWindow *window, sfEvent event)
{
    sfVector2i position = sfMouse_getPositionRenderWindow(window);

    check_window_creation(window);
    if (event.type == sfEvtMouseButtonPressed) {
        if (position.x >= 1150 && position.x <= 1450 &&
            position.y >= 650 && position.y <= 800) {
            return 1;
        }
    }
    return 0;
}

int menu(sfRenderWindow *window)
{
    sfTexture *menu_texture =
        sfTexture_createFromFile("./hunter/dot/png/gon_menu.png", NULL);
    sfSprite *menu_sprite = sfSprite_create();
    sfVector2f menu_position = {0, 0};
    sfVector2f scale = {1.5, 1.5};

    check_window_creation(window);
    check_texture_creation(window, menu_texture);
    sfSprite_setTexture(menu_sprite, menu_texture, sfTrue);
    sfSprite_setPosition(menu_sprite, menu_position);
    sfSprite_setScale(menu_sprite, scale);
    sfRenderWindow_drawSprite(window, menu_sprite, NULL);
    sfTexture_destroy(menu_texture);
    sfSprite_destroy(menu_sprite);
    start(window);
    return 0;
}

int start(sfRenderWindow *window)
{
    sfVector2f start_position = {1150, 633};
    sfTexture *my_texture =
        sfTexture_createFromFile("./hunter/dot/png/start.png", NULL);
    sfSprite *my_start = sfSprite_create();
    sfVector2f scale = {0.4, 0.4};

    check_window_creation(window);
    check_texture_creation(window, my_texture);
    spricr(window, my_start, my_texture);
    sfSprite_setPosition(my_start, start_position);
    sfSprite_setTexture(my_start, my_texture, sfFalse);
    sfSprite_setScale(my_start, scale);
    sfRenderWindow_drawSprite(window, my_start, NULL);
    sfTexture_destroy(my_texture);
    sfSprite_destroy(my_start);
    return 0;
}
