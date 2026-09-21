#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <stdlib.h>

#include "my_memmove.h"

Test(test1, formatig_test)
{
    char *data = malloc(9);

    for (int i = 0; i < 10; i++)
    {
        data[i] = 0;
    }

    data[2] = 0;
    data[3] = 1;
    data[4] = 2;
    data[5] = 3;

    char *src = data + 2;
    char *dst = data;

    my_memmove(dst, src, 4);
    for (int i = 0; i < 4; i++)
    {
        cr_expect(i == dst[i], "Expected %d, Receive %d.", i, dst[i]);
    }
}
