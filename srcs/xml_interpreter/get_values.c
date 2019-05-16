/*
** EPITECH PROJECT, 2019
** defender
** File description:
** return size values
*/

#include <stdlib.h>
#include "proto.h"

int get_nb(char *line, int selector)
{
    char *dest = NULL;
    int index = 0;
    int size = 0;
    int cursor = 0;

    index = skip(selector, line);
    cursor = index;
    while (line[index] != '"') {
        size++;
        index++;
    }
    if (!(dest = malloc(sizeof(char) * (size + 1)))) return (-1);
    index = 0;
    while (index < size) {
        dest[index++] = line[cursor++];
    }
    dest[index] = '\0';
    return (my_atoi(dest));
}

xml_obj *get_values(char *line)
{
    xml_obj *dest = malloc(sizeof(xml_obj));

    if (!dest)
        return (NULL);
    if ((dest->x = get_nb(line, 1)) == -1 ||
        (dest->y = get_nb(line, 2)) == -1 ||
        (dest->width = get_nb(line, 3)) == -1 ||
        (dest->height = get_nb(line, 4)) == -1)
        return (NULL);
    return (dest);
}
