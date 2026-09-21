#include "array_max_min.h"

void array_max_min(int tab[], size_t len, int *max, int *min)
{
    if (!tab && !len)
    {
        return;
    }
    if (len == 1)
    {
        *max = *min = tab[0];
        return;
    }

    if (tab[0] > tab[1])
    {
        *max = tab[0];
        *min = tab[1];
    }
    else
    {
        *max = tab[1];
        *min = tab[0];
    }

    for (size_t i = 2; i < len; i++)
    {
        int nb = tab[i];

        if (nb > *max)
        {
            *max = nb;
        }
        else if (nb < *min)
        {
            *min = nb;
        }
    }
}
