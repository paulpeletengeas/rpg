/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** get item when player pass throught
*/

#include <stdlib.h>
#include "proto.h"

void free_item(item_t *node)
{
    sfSprite_destroy(node->sprite);
    free(node);
}

void delete_item(item_t **list, size_t cursor)
{
    item_t *temp = *list;
    item_t *prev = NULL;
    size_t index = 0;

    if (temp && !cursor){
        *list = temp->next;
        free_item(temp);
        return;
    }
    while (temp && index < cursor) {
        prev = temp;
        temp = temp->next;
        index++;
    }
    if (!temp)
        return;
    prev->next = temp->next;
    free_item(temp);
}

int get_item(game_obj *obj)
{
    item_t *current = obj->hud->selector->items;
    sfVector2f player_pos = sfSprite_getPosition(obj->player->sprite);
    sfVector2f item_pos;
    size_t cursor = 0;

    while (current) {
        item_pos = sfSprite_getPosition(current->sprite);
        if (item_pos.x < player_pos.x && item_pos.x > player_pos.x - 50 &&
            item_pos.y < player_pos.y && item_pos.y > player_pos.y - 50) {
            put_in_inventory(obj, current);
            delete_item(&obj->hud->selector->items, cursor);
        }
        cursor++;
        current = current->next;
    }
    return (0);
}
