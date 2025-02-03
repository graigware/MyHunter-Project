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

void cleanup_game(sfRenderWindow *window,
    sfClock *clock, sfTexture *my_texture, duck_t *duck)
{
    sfSprite_destroy(duck->sprite);
    sfTexture_destroy(my_texture);
    sfClock_destroy(clock);
    sfRenderWindow_destroy(window);
}

static sfRenderWindow* init_window(sfVideoMode video_mode)
{
    return sfRenderWindow_create(video_mode,
        "my_hunter", sfClose | sfResize, NULL);
}

static sfClock* init_clock(void)
{
    return sfClock_create();
}

void close_menu(sfRenderWindow* window, sfEvent* event)
{
    check_window_creation(window);
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void game_loop(game_t *game_struct)
{
    static int game_started = 0;
    static int is_shot = 0;

    if (!game_started) {
        menu(game_struct->window), music(game_struct->window);
        game_started = manage_menu_click
            (game_struct->window, *game_struct->event);
    } else {
        map(game_struct->window);
        ducks(game_struct->window,
            game_struct->clock, game_struct->my_texture);
        if (click_duck(game_struct->duck, game_struct->window)) {
            is_shot = 1;
        }
        if (is_shot) {
            is_shot = 0;
        }
        music(game_struct->window);
    }
}

void initialize_game(sfRenderWindow **window,
    sfClock **clock, sfTexture **my_texture, duck_t *duck)
{
    sfVideoMode video_mode = {1920, 1080, 32};

    *window = init_window(video_mode);
    *clock = init_clock();
    *my_texture = sfTexture_createFromFile("./hunter/dot/png/pitou.png", NULL);
    duck->texture = *my_texture;
    duck->sprite = sfSprite_create();
    duck->x = 0;
    duck->y = 0;
    duck->is_shot = 0;
    initialize_duck_sprite(duck, *my_texture);
}

static void credit(int ac, char **av)
{
    for (int i = 0; i < ac; i++) {
        if (av[i][0] == '-' && av[i][1] == 'h') {
            my_printf("Made by Grégoire Fageot\n");
                return;
        }
    }
}

int main(int ac, char **av)
{
    sfRenderWindow *window;
    sfClock *clock;
    sfTexture *my_texture;
    duck_t duck;
    game_t game_struct;
    sfEvent event;

    if (ac > 1 && av[1][0] == '-' && av[1][1] == 'h') {
    credit(ac, av);
    return 0;
    }
    initialize_game(&window, &clock, &my_texture, &duck);
    game_struct = (game_t){window, clock, &event, my_texture, &duck};
    while (sfRenderWindow_isOpen(window)) {
        close_menu(window, &event);
        game_loop(&game_struct);
        sfRenderWindow_display(window);
    }
    cleanup_game(window, clock, my_texture, &duck);
    return 1;
}
