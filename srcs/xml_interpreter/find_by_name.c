/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** search width height x and y by name
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "proto.h"

char *get_name(char *line)
{
    char *dest = NULL;
    int index = 0;
    int cursor = 0;
    int size = 0;

    while (line[index] && line[index++] != '"');
    cursor = index;
    while (line[index] && line[index] != '"') {
        size++;
        index++;
    }
    if (!(dest = malloc(sizeof(char) * (size + 1)))) return (NULL);
    index = 0;
    while (index < size) {
        dest[index++] = line[cursor++];
    }
    dest[index] = '\0';
    return (dest);
}

xml_obj *get_xml(char *filepath, char *name)
{
    FILE *file = NULL;
    char *line = NULL;
    char *tmp = NULL;
    xml_obj *ret_struct = NULL;
    size_t n = 0;
    int ret = 0;

    if (!(file = fopen(filepath, "r"))) return (NULL);
    while (getline(&line, &n, file) > 0 &&
           (ret = compare((tmp = get_name(line)), name)) != 0) {
        free(tmp);
    }
    if (tmp)
        free(tmp);
    if (ret == 1 || !(ret_struct = get_values(line))) return (NULL);
    free(line);
    fclose(file);
    return (ret_struct);
}
