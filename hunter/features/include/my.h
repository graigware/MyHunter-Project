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
#include <SFML/Audio.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window.h>
#ifndef MY_H
    #define MY_H

int start(sfRenderWindow *window);

int menu(sfRenderWindow *window);

int click_start(sfEvent event);

int manage_menu_click(sfRenderWindow *window, sfEvent event);

int music_menu(sfRenderWindow *window);

int start(sfRenderWindow *window);

int menu(sfRenderWindow *window);

int key_close(sfRenderWindow *window, sfEvent event);

int check_song_creation(sfRenderWindow *window, sfMusic *song);

int check_texture_creation(sfRenderWindow *window, sfTexture *my_texture);

int spricr(sfRenderWindow *window, sfSprite *my_sprite, sfTexture *my_texture);

int check_window_creation(sfRenderWindow *window);

int shoot(sfRenderWindow *window);

int clock_shoot(sfRenderWindow *window, sfSprite *my_sprite);

int cowboy(sfRenderWindow *window);

int map(sfRenderWindow *window);

int music(sfRenderWindow *window);

int manage_menu_click(sfRenderWindow *window, sfEvent event);

int close_window(sfRenderWindow *window);

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

char *my_strncat(char *dest, char const *src, int nb);

int my_put_nbr(int nb);

char *my_strcpy(char *dest, char const *src);

char *my_strncpy(char *dest, char const *src, int n);

char *my_revstr(char *str);

#endif
