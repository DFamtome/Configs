#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <string.h>

#include "my_itoa.h"

Test(test1, formatig_test)
{
    char *expected = "0";
    char actual[2];
    my_itoa(0, actual);
    cr_expect(strcmp(expected, actual) == 0, "Expected %s, Receive %s.",
              expected, actual);
}

Test(real_number, formatig_test)
{
    char *expected = "100";
    char actual[4];
    my_itoa(100, actual);
    cr_expect(strcmp(expected, actual) == 0, "Expected %s, Receive %s.",
              expected, actual);
}

Test(negative, formatig_test)
{
    char *expected = "-234567";
    char actual[8];
    my_itoa(-234567, actual);
    cr_expect(strcmp(expected, actual) == 0, "Expected %s, Receive %s.",
              expected, actual);
}
