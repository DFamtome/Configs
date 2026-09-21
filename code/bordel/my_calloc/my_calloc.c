#include "my_calloc.h"

void *my_calloc(size_t n, size_t size)
{
    char *t = malloc(n * size);

    if (!t)
    {
        return NULL;
    }

    for (size_t i = 0; i < n * size; i++)
    {
        t[i] = 0;
    }

    return t;
}
