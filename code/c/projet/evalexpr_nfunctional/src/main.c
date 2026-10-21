#include <stdio.h>

#include "poland_revert.h"

int main(int argc, char *argv[])
{
    if (argc == 0)
    {
        argv[0] = argv[0];
    }

    char buffer[1024] = { 0 };
    size_t nb_read = fread(buffer, sizeof(char), 1024 - 1, stdin);
    buffer[nb_read] = '\0';

    if (buffer[0] == 0)
    {
        return 0;
    }

    return poland_reverse(buffer, nb_read);
}
