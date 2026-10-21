#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "poland_revert.h"

Test(basic, add)
{
    int expected = 3;
    int actual = poland_reverse("1 2 +", 5);
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(basic, div)
{
    int expected = 2;
    int actual = poland_reverse("4 2 /", 5);
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(avanced, pow)
{
    int expected = 100;
    int actual = poland_reverse("10 2 ^", 6);
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(avanced, chained)
{
    int expected = 2;
    int actual = poland_reverse("15 10 - 1 + 3 /", 15);
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(err, lexic)
{
    int expected = 1;
    int actual = poland_reverse("a 6 +", 5);
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(err, syntaxe)
{
    int expected = 2;
    int actual = poland_reverse("6 +", 5);
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(err, aritmetique)
{
    int expected = 3;
    int actual = poland_reverse("1 0 /", 5);
    cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}
