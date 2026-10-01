#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "my_strstr.h"

Test(faux, formatig_test)
{
    int expected = -1;
    int actual = my_strstr("rututus", "mami");
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(vrais, formatig_test)
{
    int expected = 2;
    int actual = my_strstr("rututus", "tutu");
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(edge_end, formatig_test)
{
    int expected = 2;
    int actual = my_strstr("rututu", "tutu");
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(almost, formatig_test)
{
    int expected = -1;
    int actual = my_strstr("rututo", "tutu");
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}
