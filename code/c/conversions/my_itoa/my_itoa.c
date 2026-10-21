#include "my_itoa.h"

void revert_string(char *str)
{
    int s = 0;
    int e = 0;
    int len = 0;
    while (str[++len] != 0)
        ;
    e = len - 1;
    while (s < e)
    {
        char tmp = str[s];
        str[s++] = str[e];
        str[e--] = tmp;
    }

    str[len] = 0;
}

char *my_itoa(int value, char *s)
{
    if (!s)
    {
        return 0;
    }

    int val = value < 0 ? -value : value;

    if (val == 0)
    {
        s[0] = '0';
        s[1] = 0;
        return s;
    }

    int i = 0;

    for (; val > 0; i++)
    {
        s[i] = (val % 10) + '0';
        val /= 10;
    }

    if (value < 0)
    {
        s[i++] = '-';
    }

    s[i] = 0;

    revert_string(s);

    return s;
}
