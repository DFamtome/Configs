#include "my_memmove.h"

void *my_memmove(void *dest, const void *src, size_t n)
{
    const char *s = src;
    char *dst = dest;

    char mult;
    size_t i;
    if (s < dst)
    {
        mult = -1;
        i = n - 1;
    }
    else
    {
        mult = 1;
        i = 0;
    }

    for (; i < n; i += mult)
    {
        dst[i] = s[i];
    }

    return dest;
}
