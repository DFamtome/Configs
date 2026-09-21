#include "my_memset.h"

void *my_memset(void *s, int c, size_t n)
{
    if (!s)
    {
        return NULL;
    }

    char *res = s;

    for (size_t i = 0; i < n; i++)
    {
        res[i] = c;
    }

    return res;
}
