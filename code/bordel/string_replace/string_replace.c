#include "string_replace.h"

char *string_replace(char c, const char *str, const char *pattern)
{
    if (!str)
    {
        return NULL;
    }

    size_t p_len = 0;

    if (pattern != NULL)
    {
        for (; pattern[p_len] != 0; p_len++)
            ;
    }

    size_t occ_patern = 0;
    size_t s_len = 0;

    for (; str[s_len] != 0; s_len++)
    {
        if (str[s_len] == c)
        {
            occ_patern++;
        }
    }

    size_t n_len = s_len + occ_patern * p_len - occ_patern;

    char *res = calloc(n_len, sizeof(char));

    if (!res)
    {
        return NULL;
    }

    int j = 0;

    for (int i = 0; str[i] != 0; i++)
    {
        if (str[i] == c)
        {
            for (int k = 0; pattern[k] != 0; k++)
            {
                res[j] = pattern[k];
                j++;
            }
        }
        else
        {
            res[j] = str[i];
            j++;
        }
    }

    return res;
}
