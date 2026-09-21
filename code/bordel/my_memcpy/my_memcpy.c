#include "my_memcpy.h"

void *my_memcpy(void *dest, const void *src, size_t n)
{
    char *dst = dest;
    const char *s = src;

    for (size_t i = 0; i < n; i++)
    {
        dst[i] = s[i];
    }

    return dest;
}
