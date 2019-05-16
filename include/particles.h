/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** particles
*/

#ifndef PARTICLES_H_
    #define PARTICLES_H_

#include <stdlib.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/System/Vector2.h>

typedef struct s_part {
    int nb;
    sfColor color;
    sfVertex *array;
    sfClock *clock;
    sfVertexArray *vertex;
} part_t;


#endif /* !PARTICLES_H_ */