/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** show_pnj
*/

#include "proto.h"

void show_pnj(game_obj *obj)
{
    sfVector2f pos = {1700, 150};
    sfVector2f scale = {0.4, -0.4};

    obj->pnj->spt_pnj = create_sprite("./assets/player/pnj.png");
    sfSprite_setPosition(obj->pnj->spt_pnj, pos);
    sfSprite_setScale(obj->pnj->spt_pnj, scale);
    sfRenderWindow_drawSprite(obj->sys->win, obj->pnj->spt_pnj, NULL);
}