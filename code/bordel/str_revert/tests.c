#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "str_revert.h"

Test(test1, formatig_test)
{
    char expected[] = "CBA";
    char actual[] = "ABC";
    str_revert(actual);
    cr_expect(actual[0] == expected[0], "Expected %d, Receive %d.", expected,
              actual);
}
