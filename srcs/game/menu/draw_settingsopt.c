/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** draw setting options
*/

#include "proto.h"

void draw_settingopt(game_obj *obj, set_t set)
{
    sfRenderWindow_drawText(obj->sys->win, set.volmusic, NULL);
    sfRenderWindow_drawText(obj->sys->win, set.volsound, NULL);
    sfRenderWindow_drawSprite(obj->sys->win, set.close, NULL);
    sfRenderWindow_drawSprite(obj->sys->win, set.moins, NULL);
    sfRenderWindow_drawSprite(obj->sys->win, set.moins2, NULL);
    sfRenderWindow_drawSprite(obj->sys->win, set.plus, NULL);
    sfRenderWindow_drawSprite(obj->sys->win, set.plus2, NULL);
    sfRenderWindow_drawText(obj->sys->win, set.music_txt, NULL);
    sfRenderWindow_drawText(obj->sys->win, set.sound_txt, NULL);
}