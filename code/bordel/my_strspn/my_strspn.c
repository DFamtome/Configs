#include "my_strspn.h"

size_t my_strspn(const char *s, const char *accept)
{
    if (!s || !accept)
    {
        return 0;
    }

    size_t res = 0;

    for (int i = 0; s[i] != 0; i++)
    {
        int j = 0;
        for (; accept[j] != 0 && accept[j] != s[i]; j++)
            ;

        if (accept[j] != 0)
        {
            res++;
        }
        else
        {
            return res;
        }
    }

    return res;
}
