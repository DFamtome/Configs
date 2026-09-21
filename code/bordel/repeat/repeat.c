#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        return 1;
    }

    char *word = argv[1];
    int nb = argv[2][0] - '0';

    for (int i = 0; i < nb; i++)
    {
        puts(word);
    }

    return 0;
}
