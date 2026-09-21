#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "assignment_operator.c"

Test(test1, formatig_test)
{
    int data1 = 10;
    int data2 = 2;

    int expected = 0;
    int actual = div_equal(&data1, &data2);
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
    cr_expect(5 == data1, "Expected 5, Receive %d.", data1);
}
