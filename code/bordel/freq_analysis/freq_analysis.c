#include <stdio.h>

void set_zero(void *data, size_t len)
{
    char *acc = data;
    for (size_t i = 0; i < len; i++)
    {
        acc[i] = 0;
    }
}

int max_pop(unsigned *data, size_t len)
{
    int i_max = 0;
    for (size_t i = 1; i < len; i++)
    {
        if (data[i] > data[i_max])
        {
            i_max = i;
        }
    }

    unsigned res = data[i_max];
    data[i_max] = 0;
    return res;
}

void freq_analysis(const char text[], const char table[])
{
    unsigned occ[26];
    set_zero(occ, 26 * sizeof(unsigned));

    for (int i = 0; text[i] != 0; i++)
    {
        occ[text[i] - 'A'] += 1;
    }

    for (size_t i = 0; i < 26; i++)
    {
        printf("%c %c\n", max_pop(occ, 26), table[i]);
    }
}
