#include "my_strstr.h"

int my_strstr(const char *haystack, const char *needle)
{
    if (!haystack || !needle)
    {
        return -1;
    }

    if (needle[0] == 0 || haystack[0] == 0)
    {
        return 0;
    }

    for (int i = 0; haystack[i] != 0; i++)
    {
        if (haystack[i] == needle[0])
        {
            int j = 0;
            for (; haystack[i + j] != 0 && needle[j] != 0
                 && haystack[i + j] == needle[j];
                 j++)
                ;

            if (needle[j] == 0)
            {
                return i;
            }
        }
    }

    return -1;
}
