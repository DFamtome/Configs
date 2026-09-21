#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#include "../src/tinyprintf.h"

Test(test_simple, formatig_test)
{

    char expected[] = "Hello [42] world!";
    int expected_nb = 17;

    // Recup stdout
    int t[2];
    int res[2];

    pipe(t);
    pipe(res);

    char actual[18];

    pid_t p = fork();

    dup2(t[1], STDOUT_FILENO);

    if (p != 0)
    {
        read(t[0], actual, 18);
        wait(NULL);
    }
    else
    {
        int actual_nb_1 = tinyprintf("Hello [%d] world!", 42);

        write(res[1], &actual_nb_1, sizeof(int));

        exit(0);
    }

    int actual_nb;
    read(res[0], &actual_nb, sizeof(int));

    cr_expect(strcmp(actual, expected) == 0,
              "Expected : '%s', Receive: '%s' (%d).", expected, actual,
              strcmp(actual, expected));

	cr_expect(actual_nb == expected_nb, "Expected : '%d', Receive: '%d'.", expected_nb, actual_nb);

}

