/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** create user interface in game
*/

#include <stdlib.h>
#include "proto.h"

void display_items(game_obj *obj)
{
    item_t *current = obj->hud->selector->items;

    while (current) {
        sfRenderWindow_drawSprite(obj->sys->win, current->sprite, NULL);
        current = current->next;
    }
}

void display_hud(game_obj *obj)
{
    display_life(obj);
    display_gold(obj);
    display_items(obj);
    sfRenderWindow_drawSprite(obj->sys->win, obj->hud->inventory, NULL);
    draw_selector(obj);
    display_items_in_inventory(obj);
}

sfSprite *create_inventory(sfTexture *texture)
{
    sfSprite *dest = sfSprite_create();
    sfVector2f scale = {4.0, 4.0};
    sfVector2f pos = {612, 872};
    sfIntRect rect = {0, 0, 174, 31};

    sfSprite_setTexture(dest, texture, sfTrue);
    sfSprite_setTextureRect(dest, rect);
    sfSprite_scale(dest, scale);
    sfSprite_setPosition(dest, pos);
    return (dest);
}

hud_t *create_hud(void)
{
    hud_t *dest = malloc(sizeof(hud_t));

    if (!dest ||!(dest->texture =
                  sfTexture_createFromFile("./assets/gui/gui.png", NULL)) ||
        !(dest->selector = init_inventory()))
        return (NULL);
    dest->inventory = create_inventory(dest->texture);
    dest->gold = create_gold();
    dest->life = create_life(dest->texture);
    return (dest);
}
