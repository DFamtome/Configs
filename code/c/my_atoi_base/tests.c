#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "my_atoi_base.h"

Test(basic, formatig_test)
{
    int expected = 2;
    int actual = my_atoi_base("10", "01");
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(negatif, formatig_test)
{
    int expected = -2;
    int actual = my_atoi_base("-10", "01");
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(space, formatig_test)
{
    int expected = 2;
    int actual = my_atoi_base("   10", "01");
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(plus, formatig_test)
{
    int expected = 2;
    int actual = my_atoi_base("+10", "01");
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(multiple_signs, formatig_test)
{
    int expected = 0;
    int actual = my_atoi_base("+-10", "01");
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(space_after_sign, formatig_test)
{
    int expected = 0;
    int actual = my_atoi_base("- 10", "01");
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(specials, formatig_test)
{
    int expected = 2;
    int actual = my_atoi_base("?!", "!?");
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(specials_negatif, formatig_test)
{
    int expected = -2;
    int actual = my_atoi_base("-?!", "!?");
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(hexa, formatig_test)
{
    int expected = 255;
    int actual = my_atoi_base("ff", "0123456789abcdef");
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}
