#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "fact.c"

Test(fact_3, formatig_test)
{
    int actual = factorial(3);
    int expected = 6;
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(fact_10, formatig_test)
{
    int actual = factorial(10);
    int expected = 3628800;
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}
