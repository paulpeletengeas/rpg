/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** reverse a string
*/

#include <unistd.h>
#include "my.h"

char *my_revstr(char *str)
{
    char tmp;
    int cursor_to_right;
    int cursor_to_left;

    tmp = *str;
    cursor_to_right = my_strlen(str) - 1;
    cursor_to_left = 0;
    while (cursor_to_left < cursor_to_right){
        tmp = str[cursor_to_left];
        str[cursor_to_left] = str[cursor_to_right];
        str[cursor_to_right] = tmp;
        cursor_to_left++;
        cursor_to_right--;
    }
    return (str);
}
