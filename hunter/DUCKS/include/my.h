/*
** EPITECH PROJECT, 2024
** include
** File description:
** include
*/
#include <stdarg.h>
#include <unistd.h>
#include <sys/stat.h>
#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <event.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window.h>
#ifndef MY_H
    #define MY_H

typedef struct s_duck {
    sfSprite *sprite;
    sfTexture *texture;
    int x;
    int y;
    int is_shot;
    int *frame;
    float *elapsedTime;
} duck_t;

typedef struct {
    sfRenderWindow *window;
    sfClock *clock;
    sfEvent *event;
    sfTexture *my_texture;
    duck_t *duck;
} game_t;

void setup_window(sfRenderWindow* window,
    sfSprite* my_sprite, sfVector2f original_position);

sfSprite* sprite(sfTexture* texture);

void seduck_t_position(duck_t *duck);

void initialize_duck(duck_t *duck, sfTexture *my_texture);

void initialize_duck_sprite(duck_t *duck, sfTexture *my_texture);

void ducks(sfRenderWindow *window, sfClock *clock, sfTexture *my_texture);

void update_duck_frame(duck_t *duck, sfClock *clock);

void update_duck_sprite(sfRenderWindow *window, sfClock *clock, duck_t *duck);

int manage_mouse_click(duck_t *duck, sfRenderWindow *window);

int click_duck(duck_t *duck, sfRenderWindow *window);

void move_duck(duck_t *duck);

void close_menu(sfRenderWindow* window, sfEvent* event);

int manage_menu_click(sfRenderWindow *window, sfEvent event);

int shooduck_t(duck_t *duck, sfRenderWindow *window);

int click_start(sfEvent event);

int respawn(sfRenderWindow *window, sfSprite *my_ducks);

int start(sfRenderWindow *window);

int menu(sfRenderWindow *window);

int key_close(sfRenderWindow *window, sfEvent event);

int check_song_creation(sfRenderWindow *window, sfMusic *song);

int check_texture_creation(sfTexture *my_texture);

int spricr(sfRenderWindow *window, sfSprite *my_sprite, sfTexture *my_texture);

int check_window_creation(sfRenderWindow *window);

int shoot(sfRenderWindow *window);

int clock_shoot(sfRenderWindow *window, sfSprite *my_sprite);

int cowboy(sfRenderWindow *window);

int map(sfRenderWindow *window);

int music(sfRenderWindow *window);

int close_window(sfRenderWindow *window, sfEvent event);

void analyse_events(sfRenderWindow *window, sfEvent event);

int my_isalnum(char c);

char *my_strncpy(char *dest, char const *src, int n);

void tiret_l(char const *path);

void tiret_a(char const *path);

char *my_revstr(char *str);

int my_put_unsigned_nbr(unsigned int nb);

int handle_unsigned(va_list ap);

int handle_oct(va_list ap);

int handle_hexmaj(va_list ap);

int handle_hex(va_list ap);

int handle_char(va_list ap);

int handle_str(va_list ap);

int handle_int(va_list ap);

int percent(va_list ap);

int my_printf(char const *format, ...);

int my_strlen(char const *str);

int my_putstr(char const *str);

void my_putchar(char c);

char *my_strcat(char *dest, char const *src);

char *my_strncat(char *dest, char const *src, int nb);

int my_isneg(int nb);

int my_put_nbr(int nb);

void my_swap(int *a, int *b);

char *my_strcpy(char *dest, char const *src);

char *my_strncpy(char *dest, char const *src, int n);

char *my_revstr(char *str);

#endif
