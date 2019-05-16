/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** create wildlife
*/

#include <stdlib.h>
#include "proto.h"

void free_wildlife(wild_t *wildlife)
{
    wild_t *current = wildlife;
    wild_t *old = NULL;

    while (current->next) {
        old = current;
        current = current->next;
        free(old->item);
        free(old);
    }
}

sfIntRect get_item_rect(void)
{
    sfIntRect rect = {
        ((((rand() % 2) + 1) == 1) ? 0 : 64),
        ((rand() % 5) * 64),
        64,
        64
    };

    return (rect);
}

sfVector2f get_item_pos(void)
{
    sfVector2f pos = {(rand() % 1831) + 20, (rand() % 1000) + 20};

    return (pos);
}

int add_wild(wild_t **list, sfTexture *texture)
{
    wild_t *current = *list;
    wild_t *node = malloc(sizeof(wild_t));

    if (!node)
        return (84);
    node->item = sfSprite_create();
    node->next = NULL;
    sfSprite_setTexture(node->item, texture, sfTrue);
    sfSprite_setTextureRect(node->item, get_item_rect());
    sfSprite_setPosition(node->item, get_item_pos());
    if (!(*list)) {
        *list = node;
        return (0);
    }
    while (current->next)
        current = current->next;
    current->next = node;
    return (0);
}

wild_t *create_wildlife(int nb, sfTexture *texture)
{
    int index = 0;
    wild_t *head = NULL;

    while (index < nb) {
        if (add_wild(&head, texture))
            return (NULL);
        index++;
    }
    return (head);
}
