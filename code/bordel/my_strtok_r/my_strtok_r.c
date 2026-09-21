#include "my_strtok_r.h"

int include(char c, const char *dico)
{
    if (!dico)
    {
        return 0;
    }

    int i = 0;

    for (; dico[i] != 0 && dico[i] != c; i++)
        ;

    return dico[i] == c;
}

char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    char *data = str;

    if (!data)
    {
        data = *saveptr;

        if (!data)
        {
            return NULL;
        }
    }

    int i = 0;

    for (; data[i] != 0 && include(data[i], delim); i++)
        ;

    char *w = data + i;

    for (; data[i] != 0 && !include(data[i], delim); i++)
        ;

    if (data[i] != 0)
    {
        data[i] = 0;
        i++;
    }

    *saveptr = data + i;

    return w;
}
