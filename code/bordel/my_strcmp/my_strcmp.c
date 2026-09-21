#include "my_strcmp.h"

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;

    for (; s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0; i++)
        ;

    return s1[i] - s2[i];
}
