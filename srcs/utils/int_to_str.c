/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** convert int into string
*/

#include <stdlib.h>
#include "proto.h"

int int_len(int nb)
{
    int res = 0;

    while (nb > 0) {
        nb = nb / 10;
        res++;
    }
    return (res);
}

char *int_to_str(int score)
{
    int index = int_len(score);
    char *dest = malloc(sizeof(char) * (index + 1));
    dest[index] = '\0';

    if (!dest)
        return (NULL);
    dest[index--] = '\0';
    if (!score) {
        dest[0] = '0';
        return (dest);
    }
    while (index >= 0) {
        dest[index] = (score % 10) + 48;
        score /= 10;
        index--;
    }
    return (dest);
}
