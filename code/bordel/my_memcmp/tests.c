#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "my_memcmp.h"

Test(test_diff, formatig_test)
{
    int data1[] = { 0, 2, 3, 4 };
    int data2[] = { 1, 2, 3, 3 };
    int expected = 0;
    int actual = my_memcmp(data1, data2, 0);
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}
