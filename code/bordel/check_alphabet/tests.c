#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "check_alphabet.h"

Test(test_false, formatig_test)
{
    int expected = 0;
    int actual = check_alphabet("bonbon", "bonk");
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(test_true, formatig_test)
{
    int expected = 1;
    int actual = check_alphabet("bonk", "bonk");
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}
