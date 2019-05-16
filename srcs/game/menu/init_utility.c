/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init utility
*/

#include "proto.h"
#include <stdlib.h>

use_t *init_utility(void)
{
    use_t *use = malloc(sizeof(use_t));

    if (!use)
        return NULL;
    use->strt_menu = 1;
    use->begin = 1;
    use->pause = 0;
    use->str_pause = 0;
    use->help = 0;
    return use;
}