/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** create life linked list
*/

#include <stdlib.h>
#include "proto.h"

void display_life(game_obj *obj)
{
    life_t *current = obj->hud->life;
    int nb_heart = (int)obj->player->life;
    int index = 0;

    while (current) {
        sfRenderWindow_drawSprite(obj->sys->win, current->container, NULL);
        if (index < nb_heart)
            sfRenderWindow_drawSprite(obj->sys->win, current->heart, NULL);
        current = current->next;
        index++;
    }
}

sfIntRect get_heart_rect(int type)
{
    sfIntRect rect = {0, 31, 8, 8};

    if (type == 1)
        return (rect);
    if (!type) {
        rect.left = 9;
        rect.top = 39;
        rect.width = 9;
        rect.height = 10;
        return (rect);
    }
    return (rect);
}

life_t *create_heart(sfTexture *texture)
{
    sfVector2f scale = {4.0, 4.0};
    static int x = 575;
    sfVector2f pos_container = {x += 40, 825};
    sfVector2f pos_heart = {pos_container.x, 829};
    life_t *node = malloc(sizeof(life_t));

    if (!node)
        return (NULL);
    node->container = sfSprite_create();
    node->heart = sfSprite_create();
    sfSprite_setTexture(node->heart, texture, sfTrue);
    sfSprite_setTexture(node->container, texture, sfTrue);
    sfSprite_setTextureRect(node->heart, get_heart_rect(1));
    sfSprite_setTextureRect(node->container, get_heart_rect(0));
    sfSprite_setScale(node->heart, scale);
    sfSprite_setScale(node->container, scale);
    sfSprite_setPosition(node->heart, pos_heart);
    sfSprite_setPosition(node->container, pos_container);
    node->next = NULL;
    return (node);
}

int add_heart(life_t **list, sfTexture *texture)
{
    life_t *current = *list;
    life_t *node = NULL;

    if (!(node = create_heart(texture)))
        return (84);
    node->state = 1.0;
    if (!(*list)) {
        *list = node;
        return (0);
    }
    while (current->next)
        current = current->next;
    current->next = node;
    return (0);
}

life_t *create_life(sfTexture *texture)
{
    life_t *head = NULL;
    int index = 0;

    while (index < 10) {
        if (add_heart(&head, texture))
            return (NULL);
        index++;
    }
    return (head);
}
