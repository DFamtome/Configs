#include "utils.h"
#define BUFFSIZE 1024
#define _POSIX_C_SOURCE 200112L
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

void _send(int socket)
{
    char buffer[128] = { 0 };
    size_t nb_read = fread(buffer, sizeof(char), 128 - 1, stdin);
    buffer[nb_read] = '\0';

    if (write(socket, buffer, nb_read) == -1)
    {
        return;
    }
}

void _half(int socket)
{
    char buffin[BUFFSIZE] = { 0 };
    size_t nb_read_in = read(STDIN_FILENO, buffin, BUFFSIZE - 1);
    buffin[nb_read_in] = '\0';

    if (write(socket, buffin, nb_read_in) == -1)
    {
        return;
    }

    char buffout[BUFFSIZE] = { 0 };
    size_t nb_read_out = read(socket, buffout, BUFFSIZE - 1);
    buffout[nb_read_out] = '\0';

    printf("%s", buffout); // old \n
}

void _select(int socket)
{
    struct timeval tv;

    fd_set in;
    fd_set out;

    do
    {
        /*
        stderr input ?
        sets
        tv_sec a reset
        */

        tv.tv_sec = 5;
        tv.tv_usec = 5;

        FD_ZERO(&in);
        FD_ZERO(&out);

        FD_SET(STDIN_FILENO, &in);
        FD_SET(socket, &out);

        select(2, &in, &out, NULL, &tv);

        if (FD_ISSET(STDIN_FILENO, &in))
        {
            char buffin[BUFFSIZE] = { 0 };
            size_t nb_read_in = read(STDIN_FILENO, buffin, BUFFSIZE - 1);
            buffin[nb_read_in] = '\0';

            // Edge case nb_read == -1

            if (write(socket, buffin, nb_read_in) == -1)
            {
                return;
            }
        }

        else if (FD_ISSET(socket, &out))
        {
            char buffout[BUFFSIZE] = { 0 };
            size_t nb_read_out = read(socket, buffout, BUFFSIZE - 1);
            buffout[nb_read_out] = '\0';

            // edge case nb_read == -1

            if (buffout[0] == EOF)
            {
                return;
            }

            printf("%s", buffout); // Old avec \n
        }

    } while (1);
}

int main(int argc, char *argv[])
{
    char *host;
    char *port;
    enum flag flag;

    if (argc != 4)
    {
        return 1;
    }

    if (parse_args(argv, &port, &host, &flag) == -1) // Old clang tidy 5 args
    {
        return 1;
    }

    int socket = creat_socket(host, port);

    if (socket == -1)
    {
        return 1;
    }

    if (flag == SEND)
    {
        _send(socket);
    }
    else if (flag == HALF)
    {
        _half(socket);
    }
    else if (flag == SELECT)
    {
        _select(socket);
    }

    close(socket);

    return 0;
}
