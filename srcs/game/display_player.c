/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** displayer player
*/

#include "proto.h"

void refresh_mana(game_obj *obj)
{
    sfVector2f mana_size;
    float i = 1000000.0;

    if (sfClock_getElapsedTime(obj->fire->clock).microseconds / i >= 0.1 &&
        obj->player->mana->qt_mana < 100) {
        obj->player->mana->qt_mana += 1;
    }
    mana_size.x = 7.5;
    mana_size.y = (75 * obj->player->mana->qt_mana / 100);
    sfRectangleShape_setSize(obj->player->mana->disp_mana, mana_size);
}

void display_player(game_obj *obj)
{
    refresh_mana(obj);
    sfRenderWindow_drawRectangleShape(obj->sys->win,
                                      obj->player->mana->disp_mana,
                                      NULL);
    sfRenderWindow_drawSprite(obj->sys->win, obj->player->sprite, NULL);
}
