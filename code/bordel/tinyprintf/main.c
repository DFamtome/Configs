#include <stdio.h>

#include "src/tinyprintf.h"

int main(void)
{
    int a = tinyprintf("Hello [%u] World!\n", 42);

    printf("%d\n", a);

    tinyprintf("%%s\n", "in your head\n");

    tinyprintf("Good morning ACU! %t Tinyprintf is cool\n", 12);

    tinyprintf("%c%c is %s... %d too.\n", '4', '2', "the answer", '*');

    return 0;
}
