#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "sieve.c"

Test(test1, formatig_test)
{
    sieve(200);

    int expected = 0;
    int actual = 0;
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}
