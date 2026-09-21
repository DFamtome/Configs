#include <stdio.h>
#include <stdlib.h>
void sieve(int n)
{
    if (n <= 2)
    {
        return;
    }

    size_t cmp = 0;

    char *tab = calloc(n - 2, 1);

    if (!tab)
    {
        return;
    }

    for (int i = 0; i < n - 2; i++)
    {
        if (tab[i] == 0)
        {
            cmp++;
            int nb = i + 2;

            for (int j = i; j < n - 2; j += nb)
            {
                tab[j] = 1;
            }
        }
    }

    free(tab);

    printf("%ld\n", cmp);
}
