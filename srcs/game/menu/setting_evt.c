/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** setting event
*/

#include "proto.h"

void reduce_sound(game_obj *obj, sfEvent event, set_t *set)
{
    if (event.type == sfEvtMouseButtonPressed
        && sfMouse_getPositionRenderWindow(obj->sys->win).x >= 650
        && sfMouse_getPositionRenderWindow(obj->sys->win).x <= 700
        && sfMouse_getPositionRenderWindow(obj->sys->win).y >= 350
        && sfMouse_getPositionRenderWindow(obj->sys->win).y <= 400) {
        set->vol_mus = sfMusic_getVolume(obj->sound->music);
        (set->vol_mus - 10 > 0) ? set->vol_mus -= 10 : 0;
        sfMusic_setVolume(obj->sound->music, set->vol_mus);
    }
    if (event.type == sfEvtMouseButtonPressed
        && sfMouse_getPositionRenderWindow(obj->sys->win).x >= 650
        && sfMouse_getPositionRenderWindow(obj->sys->win).x <= 700
        && sfMouse_getPositionRenderWindow(obj->sys->win).y >= 650
        && sfMouse_getPositionRenderWindow(obj->sys->win).y <= 700) {
        set->vol_sou = sfMusic_getVolume(obj->sound->click);
        (set->vol_sou - 10 > 0) ? set->vol_sou -= 10 : 0;
        sfMusic_setVolume(obj->sound->click, set->vol_sou);
    }
}

void rise_sound(game_obj *obj, sfEvent event, set_t *set)
{
    if (event.type == sfEvtMouseButtonPressed
        && sfMouse_getPositionRenderWindow(obj->sys->win).x >= 1200
        && sfMouse_getPositionRenderWindow(obj->sys->win).x <= 1250
        && sfMouse_getPositionRenderWindow(obj->sys->win).y >= 650
        && sfMouse_getPositionRenderWindow(obj->sys->win).y <= 700) {
        set->vol_sou = sfMusic_getVolume(obj->sound->click);
        (set->vol_sou + 10 < 101) ? set->vol_sou += 10 : 0;
        sfMusic_setVolume(obj->sound->click, set->vol_sou);
    }
    if (event.type == sfEvtMouseButtonPressed
        && sfMouse_getPositionRenderWindow(obj->sys->win).x >= 1200
        && sfMouse_getPositionRenderWindow(obj->sys->win).x <= 1250
        && sfMouse_getPositionRenderWindow(obj->sys->win).y >= 350
        && sfMouse_getPositionRenderWindow(obj->sys->win).y <= 400) {
        set->vol_mus = sfMusic_getVolume(obj->sound->music);
        (set->vol_mus + 10 < 101) ? set->vol_mus += 10 : 0;
        sfMusic_setVolume(obj->sound->music, set->vol_mus);
    }
}

void setting_evt(game_obj *obj, sfEvent event, int *setting, set_t *set)
{
    if (event.type == sfEvtMouseButtonPressed
        && sfMouse_getPositionRenderWindow(obj->sys->win).x >= 820
        && sfMouse_getPositionRenderWindow(obj->sys->win).x <= 1020
        && sfMouse_getPositionRenderWindow(obj->sys->win).y >= 800
        && sfMouse_getPositionRenderWindow(obj->sys->win).y <= 900) {
        *setting = 0;
    }
    reduce_sound(obj, event, set);
    rise_sound(obj, event, set);
}
