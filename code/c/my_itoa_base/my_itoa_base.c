#include "my_itoa_base.h"

void str_revert(char *str, unsigned len)
{
    unsigned s = 0;
    unsigned f = len;

    while (s < f)
    {
        char tmp = str[s];
        str[s++] = str[f];
        str[f--] = tmp;
    }
}

char *my_itoa_base(int n, char *s, const char *base)
{
    int len_base = 0;

    for (; base[len_base] != 0; len_base++)
        ;

    if (len_base < 2)
    {
        return s;
    }

    long nb = n;
    char negatif = 0;
    if (n < 0)
    {
        nb = -nb;
        negatif = 1;
    }
    int i = 0;
    for (; nb >= len_base; i++)
    {
        int unit = nb % len_base;

        s[i] = base[unit];

        nb /= len_base;
    }

    s[i] = base[nb];

    if (negatif)
    {
        s[++i] = '-';
    }

    str_revert(s, i);

    s[++i] = 0;

    return s;
}
