#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <string.h>

#include "rot_x.c"

Test(modulo, formatig_test)
{
	char* expected = "bcd";
	char actual[4] = "abc";
	
	rot_x(actual, 27);

	cr_expect(strcmp(expected, actual) == 0, "Expected %s, Receive %s.", expected, actual);
}

Test(negatif, formatig_test)
{
	char* expected = "zab";
	char actual[4] = "abc";
	
	rot_x(actual, -1);

	cr_expect(strcmp(expected, actual) == 0, "Expected %s, Receive %s.", expected, actual);
}

Test(negatif_modulo, formatig_test)
{
	char* expected = "zab";
	char actual[4] = "abc";
	
	rot_x(actual, -27);

	cr_expect(strcmp(expected, actual) == 0, "Expected %s, Receive %s.", expected, actual);
}
