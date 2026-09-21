#include "array_max.h"

#include <limits.h>

int array_max(const int array[], size_t size)
{
    if (size == 0)
    {
        return INT_MIN;
    }

    int max = array[0];

    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}
