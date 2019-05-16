/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** check if enemy is still alive
*/

#include <stdlib.h>
#include "proto.h"

void free_node(enemy_t *node)
{
    sfSprite_destroy(node->sprite);
    sfClock_destroy(node->clock);
    free(node->life);
    free(node);
}

void delete_enemy(enemy_t **list, size_t cursor)
{
    enemy_t *temp = *list;
    enemy_t *prev = NULL;
    size_t index = 0;

    if (temp && !cursor){
        *list = temp->next;
        free_node(temp);
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
    free_node(temp);
}

int check_enemy_life(game_obj *obj)
{
    size_t list_cursor = 0;
    enemy_t *current = obj->enemy;

    while (current) {
        if (current->life->health <= 0) {
            delete_enemy(&obj->enemy, list_cursor++);
            return (0);
        }
        list_cursor++;
        current = current->next;
    }
    return (0);
}