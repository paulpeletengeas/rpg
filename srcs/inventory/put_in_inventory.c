/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** push item into inventory
*/

#include "proto.h"

int put_in_inventory(game_obj *obj, item_t *to_copy)
{
    if (add_item_to_list(&obj->player->items,
                         to_copy->item_id)) {
        return (84);
    }
    return (0);
}
