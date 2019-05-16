/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** string lenght
*/

int my_strlen(char *str)
{
    int index = 0;

    if (!str)
        return (0);
    while (str[index++]);
    return (index);
}
