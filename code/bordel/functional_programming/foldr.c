#include "functional_programming.h"

int foldr(int *array, size_t len, int (*func)(int, int))
{
    int acc = 0;

    if (len == 0)
    {
        return 0;
    }

    for (size_t i = len - 1; i > 0; i--)
    {
        acc = func(array[i], acc);
    }

    return func(array[0], acc);
}
