#include "str_revert.h"

void str_revert(char str[])
{
    int len = 0;

    for (; str[len] != 0; len++)
        ;

    int start = 0;
    int end = len - 1;

    while (start < end)
    {
        char tmp = str[start];

        str[start++] = str[end];
        str[end--] = tmp;
    }
}
