/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** create parallax background for menu
*/

#include <stdlib.h>
#include "proto.h"

sfIntRect rect_by_xml(xml_obj *obj)
{
    sfIntRect rect;

    rect.left = obj->x;
    rect.top = obj->y;
    rect.width = obj->width;
    rect.height = obj->height;
    return (rect);
}

parallax_t **create_parallax(void)
{
    int index = -1;
    parallax_t **dest = malloc(sizeof(parallax_t *) * 5);
    sfTexture *texture = sfTexture_createFromFile("assets/menu/parallax.png",
                                                  NULL);
    char name[2] = {'X', '\0'};

    if (!dest || !texture) return (NULL);
    sfTexture_setRepeated(texture, sfTrue);
    while (++index < 4) {
        name[0] = index + 48;
        if (!(dest[index] = malloc(sizeof(parallax_t)))) return (NULL);
        dest[index]->sprite = sfSprite_create();
        dest[index]->rect = rect_by_xml(get_xml("xml/spritesheet_parallax.xml",
                                                name));
        sfSprite_setTexture(dest[index]->sprite, texture, sfTrue);
        sfSprite_setTextureRect(dest[index]->sprite, dest[index]->rect);
    }
    dest[index] = NULL;
    return (dest);
}
