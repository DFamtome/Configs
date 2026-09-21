#include "my_strspn.h"
#include <criterion/criterion.h>
#include <criterion/new/assert.h>

Test(no_result, formatig_test)
{
	size_t expected = 0;
	size_t actual = my_strspn(NULL, NULL);
	cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(test_simple, formatig_test)
{
	size_t expected = 3;
	size_t actual = my_strspn("ABC", "ABC");
	cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(test_imaginaire, formatig_test)
{
	size_t expected = 5;
	size_t actual = my_strspn("banana", "an");
	cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}

Test(test_deplace, formatig_test)
{
	size_t expected = 3;
	size_t actual = my_strspn("banana", "bn");
	cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}
