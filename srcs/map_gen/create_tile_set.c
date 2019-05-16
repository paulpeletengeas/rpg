/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** create tile set
*/

#include <stdlib.h>
#include "proto.h"

void check_x_y(float *x, float *y)
{
    if (*x >= 1920.0) {
        *x = 0.0;
        *y += 80.0;
    }
}

tile_t *create_tile(sfVector2f pos, int type, sfTexture *texture)
{
    tile_t *node = NULL;
    sfVector2f scale = {1.25, 1.25};

    if (!(node = malloc(sizeof(tile_t))))
        return (NULL);
    node->tile_type = type;
    node->tile = sfSprite_create();
    sfSprite_setTexture(node->tile, texture, sfTrue);
    sfSprite_setTextureRect(node->tile, get_tile_rect(node->tile_type));
    sfSprite_setScale(node->tile, scale);
    sfSprite_setPosition(node->tile, pos);
    node->next = NULL;
    return (node);
}

int add_tile(tile_t **list, int tile_type, sfTexture *texture)
{
    tile_t *current = (*list);
    tile_t *node = NULL;
    static float x = 0.0;
    static float y = 0.0;
    sfVector2f pos = {x, y};

    if (y > 1080.0)
        return (1);
    x += 80.0;
    check_x_y(&x, &y);
    if (!(node = create_tile(pos, tile_type, texture)))
        return (84);
    if (!(*list)) {
        (*list) = node;
        return (0);
    }
    while (current->next)
        current = current->next;
    current->next = node;
    return (0);
}
