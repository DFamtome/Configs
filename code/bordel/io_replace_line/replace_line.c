#define _POSIX_C_SOURCE 200809L
#include <stdio.h>

int replace_line(const char *file_in, const char *file_out, const char *content,
                 int n)

{
    if (!file_in || !file_out)
    {
        return -1;
    }

    FILE *fin = fopen(file_in, "r");
    FILE *fout = fopen(file_out, "w");

    if (!fin || !fout)
    {
        return -1;
    }

    size_t size = 1024;
    char l[1024] = { 0 };
    char *line = l;

    for (int i = 0; i < n; i++)
    {
        if (getline(&line, &size, fin) == -1)
        {
            return 1;
        }

        if (fputs(line, fout) == -1)
        {
            return -1;
        }
    }

    if (fputs(content, fout) == -1)
    {
        return -1;
    }

    while (getline(&line, &size, fin) == -1)
    {
        if (fputs(line, fout) == -1)
        {
            return -1;
        }
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
