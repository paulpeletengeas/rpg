/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_attack
*/

#include "proto.h"
#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>

fire_t    *set_fire_rect(fire_t *fire_list)
{
    fire_list->rect.left = 0;
    fire_list->rect.top = 0;
    fire_list->rect.height = 62;
    fire_list->rect.width = 64;
    fire_list->offset = 64;
    return (fire_list);
}

fire_t    *init_attack(void)
{
    fire_t *fire_list = malloc(sizeof(fire_t));
    sfTexture *texture;
    sfVector2f origin = {31, 31};

    if (!(texture = sfTexture_createFromFile("./assets/fire/fireball.png",
                                            NULL)))
        return (NULL);
    fire_list->sprite = sfSprite_create();
    fire_list = set_fire_rect(fire_list);
    fire_list->clock = sfClock_create();
    fire_list->range = 200;
    sfSprite_setOrigin(fire_list->sprite, origin);
    sfSprite_setTexture(fire_list->sprite, texture, sfTrue);
    sfSprite_setTextureRect(fire_list->sprite, fire_list->rect);
    fire_list->next = NULL;
    return (fire_list);
}
