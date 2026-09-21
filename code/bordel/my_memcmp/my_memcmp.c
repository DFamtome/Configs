#include "my_memcmp.h"

int my_memcmp(const void *s1, const void *s2, size_t num)
{
    const char *str1 = s1;
    const char *str2 = s2;

    int diff = 0;

    for (size_t i = 0; i < num && (diff = str1[i] - str2[i]) == 0; i++)
        ;

    return diff;
}
