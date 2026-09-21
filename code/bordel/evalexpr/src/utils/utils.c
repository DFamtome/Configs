#include "utils.h"

int my_pow(int a, unsigned long b)
{
    if (b == 0)
    {
        return 1;
    }

    int result = 1;
    while (b > 0)
    {
        if ((b & 1) == 0)
        {
            a *= a;
            b >>= 1;
        }
        else
        {
            result *= a;
            b--;
        }
    }

    return result;
}

int my_atoi(char *word, int *i)
{
    int result = 0;
    for (; '0' <= word[*i] && word[*i] <= '9'; *i += 1)
    {
        result *= 10;
        result += word[*i] - '0';
    }

    return result;
}
