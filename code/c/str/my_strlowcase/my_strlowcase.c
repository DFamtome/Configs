#include "my_strlowcase.h"

void my_strlowcase(char *str)
{
    if (str == NULL)
    {
        return;
    }

    size_t i = 0;

    while (str[i] != 0)
    {
        char c = str[i];

        if ('A' <= c && c <= 'Z')
        {
            str[i] += 32;
        }

        i++;
    }
}
