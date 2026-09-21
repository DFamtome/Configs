#include "my_atoi_base.h"

int my_pow(int n, int p)
{
    int result = 1;

    for (int i = 0; i < p; i++)
    {
        result *= n;
    }

    return result;
}

int my_atoi_base(const char *str, const char *base)
{
    int i = 0;

    for (; str[i] == ' '; i++)
        ;

    int fact = 1;

    if (str[i] == '-')
    {
        fact = -1;
        i++;
    }
    else if (str[i] == '+')
    {
        i++;
    }

    int len_base = 0;

    for (; base[len_base] != 0; len_base++)
        ;

    int result = 0;

    int len_word = 0;
    for (; str[len_word] != 0; len_word++)
        ;

    for (; i < len_word; i++)
    {
        int v = 0;

        for (; base[v] != str[i] && base[v] != 0; v++)
            ;

        if (base[v] == 0)
        {
            // val str non dans base
            return 0;
        }

        result += v * my_pow(len_base, len_word - i - 1);
    }

    return fact * result;
}
