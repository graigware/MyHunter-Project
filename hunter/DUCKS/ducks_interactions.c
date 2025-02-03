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

void move_duck(duck_t *duck)
{
    if (duck->is_shot == 0) {
        duck->x += 13;
        if (duck->x > 1920) {
            duck->x = 0;
        }
    }
    if (duck->x == 0 && duck->is_shot == 1) {
        duck->is_shot = 0;
    }
}

int shooduck_t(duck_t *duck, sfRenderWindow *window)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(duck->sprite);
    sfVector2i position = sfMouse_getPositionRenderWindow(window);

    check_window_creation(window);
    return (sfFloatRect_contains(&bounds, position.x, position.y));
}

int click_duck(duck_t *duck, sfRenderWindow *window)
{
    check_window_creation(window);
    return (sfMouse_isButtonPressed(sfMouseLeft)) && shooduck_t(duck, window);
}

int manage_mouse_click(duck_t *duck, sfRenderWindow *window)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(duck->sprite);
    sfVector2i mouse_position = sfMouse_getPositionRenderWindow(window);

    check_window_creation(window);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfFloatRect_contains(&bounds,
            mouse_position.x, mouse_position.y)) {
            duck->is_shot = 1;
        }
    }
    return 0;
}

void update_duck_frame(duck_t *duck, sfClock *clock)
{
    float frameDuration = 0.1f;
    sfIntRect rect = {1, 1, 110, 110};

    *duck->elapsedTime += sfTime_asSeconds(sfClock_getElapsedTime(clock));
    if (*duck->elapsedTime >= frameDuration) {
        rect.left = *duck->frame * 110;
        sfSprite_setTextureRect(duck->sprite, rect);
        *duck->frame = (*duck->frame + 2) % 3;
        sfClock_restart(clock);
        *duck->elapsedTime = 1;
    }
}
