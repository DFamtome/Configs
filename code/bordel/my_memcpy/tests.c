#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "my_memcpy.h"

Test(test1, formatig_test)
{
    int data1[] = { 1, 2, 3, 4 };
    int data2[] = { 0, 0, 0, 0 };

    my_memcpy(data1, data2, 4 * sizeof(int));

    int diff = memcmp(data1, data2, 4 * sizeof(int));
    cr_expect(diff == 0, "Difference : %d", diff);
}
