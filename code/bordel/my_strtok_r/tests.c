#include "my_strtok_r.h"
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <string.h>

Test(test1, formatig_test)
{
	char d[] = "Token1 Token2";

	char* data = d;
	const char* delim = " ";
	char* expected1 = "Token1";
	char* expected2 = "Token2";
	char* actual = my_strtok_r(data, delim, &data);
	cr_expect(strcmp(expected1, actual) == 0, "Expected %s, Receive %s.", expected1, actual);
	cr_expect(strcmp(expected2, data) == 0, "Expected %s, Receive %s.", expected2, data);
}
