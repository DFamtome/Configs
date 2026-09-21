#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "io_count_words.c"

Test(test1, formatig_test)
{
	int expected = 3;
	int actual = count_words("test.txt");

	cr_expect(actual == expected, "Expected %d, Receive %d.", expected, actual);
}
