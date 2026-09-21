#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "my_strchr.h"

Test(test1, formatig_test)
{
    char data[] = "abc";
    char *expected = data;
    char *actual = my_strchr(data, 'a');
    cr_expect(actual == expected, "Expected %c, Receive %c.", *expected,
              *actual);
}
