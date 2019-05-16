/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** analyse events
*/

#include "proto.h"

int analyse_event(game_obj *obj)
{
    sfEvent event;

    if (check_keyboard(obj))
        return (1);
    move_player(obj);
    while (sfRenderWindow_pollEvent(obj->sys->win, &event)) {
        if (event.type == sfEvtClosed) {
            kill_game_obj(obj);
            return (1);
        }
        check_mouse(obj, event);
    }
    return (0);
}
