/*
** EPITECH PROJECT, 2024
** music
** File description:
** game's music
*/
#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <event.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include "include/my.h"

int music(sfRenderWindow *window)
{
    static sfMusic *song = NULL;

    if (song == NULL) {
        song = sfMusic_createFromFile("./hunter/dot/ogg/ost.ogg");
        check_song_creation(window, song);
        sfMusic_play(song);
    }
    return 0;
}
