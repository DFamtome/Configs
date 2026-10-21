#include <criterion/criterion.h>
#include <string.h>

Test(not_null, test_malloc)
{
    void *ptr = malloc(12);
    cr_assert(ptr != NULL);
    free(ptr);
}

Test(stockage, test_malloc)
{
    char *str = malloc(5);
    str[0] = 'h';
    str[1] = 'e';
    str[2] = 'l';
    str[3] = 'l';
    str[4] = 0;

    cr_assert(strcmp(str, "hell") == 0, "Expected 'hel', Receive %s", str);
    free(str);
}
