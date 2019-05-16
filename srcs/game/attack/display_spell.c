/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_spell
*/

#include "proto.h"

void    set_rect(game_obj *obj)
{
    static int reset = 0;

    obj->spell->rect.left += obj->spell->offset;
    if (obj->spell->rect.left >= 432) {
        obj->spell->rect.left = 0;
        reset++;
    }
    if (reset == 2 || obj->spell->delay == 1) {
        obj->spell->delay = 0;
        obj->spell->fire = false;
        reset = 0;
    }
}

void    analyse_range(game_obj *obj)
{
    enemy_t *current = obj->enemy;
    sfVector2f pos = sfSprite_getPosition(obj->player->sprite);
    sfVector2f col;

    while (current) {
        col.x = pos.x - current->pos.x;
        col.y = pos.y - current->pos.y;
        if (vector_dist(col) < 50) {
            obj->player->gold += 10;
            current->life->health -= 50;
            obj->spell->delay = 1;
        }
        current = current->next;
    }
}

void    launch_spell(game_obj *obj)
{
    float i = 1000000.0;
    float angle = sfSprite_getRotation(obj->player->sprite);

    if (sfClock_getElapsedTime(obj->fire->clock).microseconds / i >= 0.5) {
        set_rect(obj);
        sfSprite_setRotation(obj->spell->sprite, angle);
        sfSprite_setPosition(obj->spell->sprite,
                        sfSprite_getPosition(obj->player->sprite));
        sfSprite_setTextureRect(obj->spell->sprite, obj->spell->rect);
        sfClock_restart(obj->spell->clock);
    }
    analyse_range(obj);
}

void    display_spell(game_obj *obj)
{
    if (obj->spell->fire == true) {
        launch_spell(obj);
        sfRenderWindow_drawSprite(obj->sys->win, obj->spell->sprite, NULL);
    }
}