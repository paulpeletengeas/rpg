/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** skip bracket
*/

int skip(int factor, char *line)
{
    int i = 0;
    int j = factor * 2 + 1;
    int index = 0;

    while (i < j) {
        while (line[index++] != '"');
        i++;
    }
    return (index);
}
