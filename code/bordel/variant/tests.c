#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "variant.h"

Test(test1, formatig_test)
{
    int expected = 0;
    int actual = 0;
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}
