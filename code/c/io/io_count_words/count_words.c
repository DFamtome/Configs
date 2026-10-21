#include <stdio.h>

int is_blanc(char c)
{
    return c == '\t' || c == '\n' || c == '\f' || c == ' ';
}

int count_words(const char *file_in)
{
    if (!file_in)
    {
        return -1;
    }

    FILE *fd = fopen(file_in, "r");

    if (!fd)
    {
        return -1;
    }

    int nb_w = 0;

    for (char c = fgetc(fd); c != EOF;)
    {
        if (is_blanc(c))
        {
            for (; c != EOF && is_blanc(c); c = fgetc(fd))
                ;
        }
        else
        {
            nb_w++;
            for (; c != EOF && !is_blanc(c); c = fgetc(fd))
                ;
        }
    }

    return nb_w;
}
