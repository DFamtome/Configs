#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "string_replace.h"

Test(test1, formatig_test)
{
    char *expected = "booboo";
    char *actual = string_replace('o', "bobo", "oo");
    cr_expect(strcmp(expected, actual) == 0, "Expected %d, Receive %d.",
              expected, actual);

    free(actual);
}
