/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** create window
*/

#include <stdlib.h>
#include <time.h>
#include "proto.h"

sys_t *create_sys(void)
{
    sys_t *new_sys = malloc(sizeof(sys_t));
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode,
                                                   "RPG",
                                                   sfResize | sfClose,
                                                   NULL);

    if (!window)
        return (NULL);
    new_sys->win = window;
    new_sys->clock = sfClock_create();
    new_sys->view = 0;
    sfRenderWindow_setFramerateLimit(new_sys->win, 30);
    srand(time(NULL));
    return (new_sys);
}
