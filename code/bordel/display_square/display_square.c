#include <stdio.h>

void display_square(int width)
{
    if (width % 2 == 0)
    {
        width++;
    }

    if (width <= 0)
    {
        putchar('\n');
        return;
    }

    int nb_rows = (width - 1) / 2;

    for (int i = 0; i < width; i++)
    {
        putchar('*');
    }

    putchar('\n');

    for (int i = 0; i < nb_rows; i++)
    {
        putchar('*');
        for (int j = 0; j < width - 2; j++)
        {
            putchar(' ');
        }
        putchar('*');
        putchar('\n');
    }

    for (int i = 0; i < width; i++)
    {
        putchar('*');
    }

    putchar('\n');
}
