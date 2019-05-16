/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** compare two str
*/

int my_strlen(char *);

int compare(char *s1, char *s2)
{
    int index = 0;

    if (!s1 || !s2) return (1);
    while (s1[index] && s2[index]) {
        if (s1[index] != s2[index]) return (1);
        index++;
    }
    return ((my_strlen(s1) != my_strlen(s2)) ? 1 : 0);
}
