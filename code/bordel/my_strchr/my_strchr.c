#include "my_strchr.h"

char *my_strchr(char *s, int c)
{
    char *r = s;

    for (; *r != c && *r != 0; r++)
        ;

    return *r == c ? r : 0;
}
