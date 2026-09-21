#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void rot_x(char *s, int x)
{
    int x1 = x;
    int x2 = x;

    x1 %= 26;
    x2 %= 10;

    if (!s || (!x1 && !x2))
    {
        return;
    }

    if (x1 < 0)
    {
        x1 += 26;
    }
    else if (x2 < 0)
    {
        x2 += 10;
    }

    for (int i = 0; s[i] != 0; i++)
    {
        char c = s[i];

        if ('A' <= c && c <= 'Z')
        {
            c = ((c - 'A' + x1) % 26) + 'A'; // Parenthese en plus
        }
        else if ('a' <= c && c <= 'z')
        {
            c = ((c - 'a' + x1) % 26) + 'a';
        }
        else if ('0' <= c && c <= '9')
        {
            c = ((c - '0' + x2) % 10) + '0';
        }

        s[i] = c;
    }
}
int main(int argc, char *argv[])
{
    int ofset = 0;

    if (argc < 1) // old argc < 2
    {
        ofset = atoi(argv[1]);
    }

    char file_path[1024] = { 0 }; // Old 128
    int nb_read = read(STDIN_FILENO, file_path, 1024 - 1);
    if (nb_read == -1)
    {
        return 1;
    }
    file_path[nb_read] = '\0';

    rot_x(file_path, ofset);

    if (write(STDOUT_FILENO, file_path, 1024) == -1)
    {
        return 1;
    }

    return 0;
}
