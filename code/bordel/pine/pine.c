#include <stdio.h>

int pine(unsigned n)
{
    if (n < 3)
    {
        return 1;
    }

    // Pine
    int stage = 0;
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            putchar(' ');
        }

        for (int j = 0; j < stage * 2 + 1; j++)
        {
            putchar('*');
        }
        putchar('\n');
        stage++;
    }

    // Tronc

    for (unsigned i = 0; i < n / 2; i++)
    {
        for (unsigned j = 0; j < n - 1; j++)
        {
            putchar(' ');
        }

        putchar('*');
        putchar('\n');
    }

    return 0;
}
