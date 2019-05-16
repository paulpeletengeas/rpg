/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** create music and sound design
*/

#include <stdlib.h>
#include "proto.h"

sound_t *create_sound(void)
{
    sound_t *dest = malloc(sizeof(sound_t));

    if (!dest ||
        !(dest->music = sfMusic_createFromFile("./assets/music/music.ogg")) ||
        !(dest->click = sfMusic_createFromFile("./assets/music/click.wav")))
        return (NULL);
    dest->bound = sfClock_create();
    sfMusic_play(dest->music);
    sfMusic_setLoop(dest->music, sfTrue);
    return (dest);
}
