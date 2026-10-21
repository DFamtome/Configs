#include "my_atoi.h"

int is_start_number(char c)
{
    return ('0' <= c && c <= '9') || c == '+' || c == '-';
}

int my_atoi(const char *str)
{
    int i = 0;
    int negatif = 1;
    for (; str[i] == ' '; i++)
        ;

    if (!is_start_number(str[i]))
    {
        return 0;
    }

    if (str[i] == '-')
    {
        negatif = -1;
        i++;
    }
    else if (str[i] == '+')
    {
        i++;
    }

    int result = 0;

    for (; ('0' <= str[i]) && (str[i] <= '9'); i++)
    {
        result *= 10;
        result += str[i] - '0';
    }

    if (str[i] != 0)
    {
        return 0;
    }

    result *= negatif;

    return result;
}
