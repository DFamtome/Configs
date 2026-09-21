#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "my_atoi.h"

Test(simple, formatig_test)
{
    int expected = 14;
    int actual = my_atoi("14");
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(space, formatig_test)
{
    int expected = 14;
    int actual = my_atoi("     14");
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(plus, formatig_test)
{
    int expected = 14;
    int actual = my_atoi("+14");
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(space_and_plus, formatig_test)
{
    int expected = 14;
    int actual = my_atoi("   +14");
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(minus, formatig_test)
{
    int expected = -14;
    int actual = my_atoi("   -14");
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(error, formatig_test)
{
    int expected = 0;
    int actual = my_atoi("14sd ");
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(letter, formatig_test)
{
    int expected = 0;
    int actual = my_atoi("aze14");
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(letter_end, formatig_test)
{
    int expected = 0;
    int actual = my_atoi("14fghj");
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}
