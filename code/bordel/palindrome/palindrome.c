#include <stdio.h>

int palindrome(const char *s)
{
    if (!s)
    {
        return 0;
    }

    if (*s == 0)
    {
        return 1;
    }

    int len = 0;

    for (; s[len] != 0; len++)
        ;

    int d = -1;
    int f = len;

    do
    {
        d++;
        f--;
        while (d < f
               && !(('a' <= s[d] && s[d] <= 'z') || ('A' <= s[d] && s[d] <= 'Z')
                    || ('0' <= s[d] && s[d] <= '9')))
        {
            d++;
        }

        while (d < f
               && !(('a' <= s[f] && s[f] <= 'z') || ('A' <= s[f] && s[f] <= 'Z')
                    || ('0' <= s[f] && s[f] <= '9')))
        {
            f--;
        }

    } while (d < f && s[d] == s[f]);

    return d >= f;
}
