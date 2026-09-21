#include "check_alphabet.h"

int check_alphabet(const char *str, const char *alphabet)
{
    if (!alphabet)
    {
        return 1;
    }

    for (int i = 0; alphabet[i] != 0; i++)
    {
        char c = alphabet[i];
        int j = 0;
        for (; str[j] != 0 && str[j] != c; j++)
            ;

        if (str[j] == 0)
        {
            return 0;
        }
    }

    return 1;
}
