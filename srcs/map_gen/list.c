/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** create the map linked list
*/

#include <stdio.h>
#include <stdlib.h>
#include "proto.h"

void display_map(game_obj *obj)
{
    tile_t *current_tile = obj->map->tile;
    wild_t *current_wild = obj->map->wildlife;

    while (current_tile) {
        sfRenderWindow_drawSprite(obj->sys->win, current_tile->tile, NULL);
        current_tile = current_tile->next;
    }
    while (current_wild) {
        sfRenderWindow_drawSprite(obj->sys->win, current_wild->item, NULL);
        current_wild = current_wild->next;
    }
}

map_t *create_map(void)
{
    map_t *dest = malloc(sizeof(map_t));
    int ret = 0;
    int *tile_type = randomize_biome((rand() % 4) + 1);
    int index = 0;

    if (!dest || !tile_type ||
        !(dest->tilesheet = sfTexture_createFromFile("./assets/tiles/tile.png",
                                                     NULL)) ||
        !(dest->wildsheet = sfTexture_createFromFile("./assets/tiles/wild.png",
                                                     NULL)))
        return (NULL);
    dest->tile = NULL;
    while (!ret) {
        if ((ret =
             add_tile(&dest->tile, tile_type[index++], dest->tilesheet)) == 84)
            return (NULL);
    }
    if (!(dest->wildlife = create_wildlife((rand()%31)+10, dest->wildsheet)))
        return (NULL);
    return (dest);
}

void anim_hide(tile_t *map)
{
    tile_t *current = map;
    sfVector2f scale;

    while (current) {
        scale = sfSprite_getScale(current->tile);
        scale.x -= 0.1 * (rand()%5);
        scale.y -= rand()%5;
        sfSprite_setScale(current->tile, scale);
        current = current->next;
    }
}

int reload_map(game_obj *obj)
{
    int *tile_type = randomize_biome((rand() % 4) + 1);
    tile_t *current = obj->map->tile;
    int index = 0;

    if (!tile_type)
        return (84);
    reset_player_pos(obj);
    while (current) {
        sfSprite_setTextureRect(current->tile,
                                get_tile_rect(tile_type[index++]));
        current = current->next;
    }
    free_wildlife(obj->map->wildlife);
    if (!(obj->map->wildlife =
          create_wildlife((rand()%31) + 10, obj->map->wildsheet)))
        return (84);
    return (0);
}
