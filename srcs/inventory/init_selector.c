/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** create inventory selector
*/

#include <stdlib.h>
#include "proto.h"

int add_item_to_list(item_t **list, int item_id)
{
    item_t *current = *list;
    item_t *node = malloc(sizeof(item_t));
    sfVector2f pos = {(rand()%1800), (rand()%970)};
    sfTexture *texture = sfTexture_createFromFile("./assets/gui/key.png",
                                                  NULL);

    if (!node || !texture)
        return (84);
    node->sprite = sfSprite_create();
    node->item_id = item_id;
    node->next = NULL;
    sfSprite_setTexture(node->sprite, texture, sfTrue);
    sfSprite_setPosition(node->sprite, pos);
    if (!(*list)) {
        *list = node;
        return (0);
    }
    while (current->next)
        current = current->next;
    current->next = node;
    return (0);
}

item_t *init_items(size_t nb)
{
    size_t index = 0;
    item_t *dest = NULL;

    while (index < nb) {
        if (add_item_to_list(&dest, 1))
            return (NULL);
        index++;
    }
    return (dest);
}

inventory_t *init_inventory(void)
{
    inventory_t *dest = malloc(sizeof(inventory_t));
    sfVector2f size = {64, 64};
    sfVector2f pos = {640, 904};
    sfColor color = {216, 216, 216, 200};

    if (!dest || !(dest->bound = sfClock_create()) ||
        !(dest->items = init_items(5)))
        return (NULL);
    dest->cursor = 5;
    dest->item_id = 0;
    dest->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(dest->shape, size);
    sfRectangleShape_setFillColor(dest->shape, color);
    sfRectangleShape_setPosition(dest->shape, pos);
    return (dest);
}
