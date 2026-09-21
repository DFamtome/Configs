#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "my_itoa_base.h"

Test(test1, formatig_test)
{
	char* expected = "FF";
	char actual[3] = { 0 };

	my_itoa_base(255, actual, "0123456789ABCDEF");

	cr_expect(strcmp(expected, actual) == 0, "Expected %s, Receive %s.", expected, actual);
}

Test(imaginary_base, formatig_test)
{
	char* expected = "OZ";
	char actual[3] = { 0 };

	my_itoa_base(2, actual, "ZO");

	cr_expect(strcmp(expected, actual) == 0, "Expected %s, Receive %s.", expected, actual);
}
