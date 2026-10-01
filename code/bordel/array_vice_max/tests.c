#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "array_vice_max.c"

Test(test1, formatig_test)
{
    int arr[] = { 1, 2, 3, 4, 5 };

    int expected = 4;
    int actual = 0;
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}
