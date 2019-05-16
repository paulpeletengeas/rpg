/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** display item in the inventory
*/

#include "proto.h"

int display_items_in_inventory(game_obj *obj)
{
    item_t *current = obj->player->items;
    sfVector2f pos = {651, 917};

    while (current) {
        sfSprite_setPosition(current->sprite, pos);
        pos.x += 72;
        sfRenderWindow_drawSprite(obj->sys->win, current->sprite, NULL);
        current = current->next;
    }
    return (0);
}
