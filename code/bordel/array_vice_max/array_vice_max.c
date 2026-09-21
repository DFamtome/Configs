#include "array_vice_max.h"

int array_vice_max(const int array[], size_t size)
{
    if (size == 0)
    {
        return 0;
    }

    if (size == 1)
    {
        return array[0];
    }

    int max;
    int vice_max;

    if (array[0] > array[1])
    {
        max = array[0];
        vice_max = array[1];
    }
    else
    {
        max = array[1];
        vice_max = array[0];
    }

    for (size_t i = 2; i < size; ++i)
    {
        int v = array[i];

        if (v > max)
        {
            vice_max = max;
            max = v;
        }
        else if (v > vice_max)
        {
            vice_max = v;
        }
    }

    return vice_max;
}
