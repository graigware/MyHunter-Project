/*
** EPITECH PROJECT, 2024
** ducks
** File description:
** ducks with coding-style
*/
#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio.h>
#include "include/my.h"
#include <stdlib.h>

static sfVector2f get_random_position(void)
{
    sfVector2f position;

    position.x = 0;
    position.y = rand() % 980;
    return position;
}

void duck_pos(duck_t *duck)
{
    sfVector2f position;

    if (duck->is_shot == 0) {
        if (duck->x > 1920) {
            duck->x = 0;
        }
        position.x = duck->x;
        position.y = duck->y;
    } else {
        position = get_random_position();
        duck->x = 0;
        duck->y = position.y;
    }
    sfSprite_setPosition(duck->sprite, position);
}

void initialize_duck(duck_t *duck, sfTexture *my_texture)
{
    sfVector2f scale = {1, 1};

    check_texture_creation(my_texture);
    sfSprite_setTexture(duck->sprite, my_texture, sfTrue);
    sfSprite_setScale(duck->sprite, scale);
}

void update_duck_sprite(sfRenderWindow *window, sfClock *clock, duck_t *duck)
{
    check_window_creation(window);
    update_duck_frame(duck, clock);
    sfRenderWindow_drawSprite(window, duck->sprite, NULL);
}

void initialize_duck_sprite(duck_t *duck, sfTexture *my_texture)
{
    check_texture_creation(my_texture);
    initialize_duck(duck, my_texture);
    duck_pos(duck);
}

void ducks(sfRenderWindow *window, sfClock *clock, sfTexture *my_texture)
{
    static int frame = 0;
    static float elapsedTime = 0;
    static duck_t duck;

    check_window_creation(window);
    check_texture_creation(my_texture);
    if (!duck.texture)
        duck.texture =
        sfTexture_createFromFile("./hunter/dot/png/pitou.png", NULL);
    if (!duck.sprite)
        duck.sprite = sfSprite_create();
    duck.frame = &frame;
    duck.elapsedTime = &elapsedTime;
    initialize_duck_sprite(&duck, my_texture);
    manage_mouse_click(&duck, window);
    move_duck(&duck);
    update_duck_sprite(window, clock, &duck);
    sfRenderWindow_drawSprite(window, duck.sprite, NULL);
}
