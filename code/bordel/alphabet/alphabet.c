#include <stdio.h>

int main(void)
{
    putchar('a');
    for (char c = 'b'; c <= 'z'; c++)
    {
        putchar(' ');
        putchar(c);
    }

    putchar('\n');

    return 0;
}
