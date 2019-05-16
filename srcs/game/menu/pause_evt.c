/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** pause event
*/

#include "proto.h"

int second_pausevt(game_obj *obj, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyB)) {
        obj->use->pause = 0;
        return 0;
    }
    if (event.type == sfEvtMouseButtonPressed
        && sfMouse_getPositionRenderWindow(obj->sys->win).x >= 800
        && sfMouse_getPositionRenderWindow(obj->sys->win).x <= 1100
        && sfMouse_getPositionRenderWindow(obj->sys->win).y >= 700
        && sfMouse_getPositionRenderWindow(obj->sys->win).y <= 800) {
        if (settings_option(obj, event))
            return 1;
    }
    return 0;
}

int pause_menuevt(game_obj *obj, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed
        && sfMouse_getPositionRenderWindow(obj->sys->win).x >= 200
        && sfMouse_getPositionRenderWindow(obj->sys->win).x <= 500
        && sfMouse_getPositionRenderWindow(obj->sys->win).y >= 500
        && sfMouse_getPositionRenderWindow(obj->sys->win).y <= 600) {
        obj->use->pause = 0;
        obj->use->begin = 1;
        obj->use->strt_menu = 1;
    }
    if (event.type == sfEvtMouseButtonPressed
        && sfMouse_getPositionRenderWindow(obj->sys->win).x >= 1500
        && sfMouse_getPositionRenderWindow(obj->sys->win).x <= 1800
        && sfMouse_getPositionRenderWindow(obj->sys->win).y >= 500
        && sfMouse_getPositionRenderWindow(obj->sys->win).y <= 600) {
        obj->use->pause = 0;
        kill_game_obj(obj);
        return 1;
    }
    if (second_pausevt(obj, event))
        return 1;
    return 0;
}
