/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** struct for map generation
*/

#ifndef MAP_STRUCT_H_
#define MAP_STRUCT_H_

typedef struct color
{
    int tile_type;
    sfColor color;
    struct color *next;
} color_t;

typedef struct tile
{
    sfSprite *tile;
    int tile_type;
    struct tile *next;
} tile_t;

typedef struct wild
{
    sfSprite *item;
    struct wild *next;
} wild_t;

typedef struct map
{
    sfTexture *tilesheet;
    sfTexture *wildsheet;
    struct tile *tile;
    struct wild *wildlife;
} map_t;

#endif /* MAP_STRUCT_H_ */
