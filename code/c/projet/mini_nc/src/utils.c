#define _POSIX_C_SOURCE 200112L
#include "utils.h"

#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int parse_flag(char *flag, enum flag *flag_r)
{
    if (strcmp(flag, "--send") == 0)
    {
        *flag_r = SEND;
        return 0;
    }
    if (strcmp(flag, "--half") == 0)
    {
        *flag_r = HALF;
        return 0;
    }
    if (strcmp(flag, "--select") == 0)
    {
        *flag_r = SELECT;
        return 0;
    }

    return -1;
}

int parse_args(char **argv, char **port, char **host, enum flag *flag)
{
    int i_p = 0;
    int i_h = 0;
    int i_f = 0;

    if (argv[1][0] == '-')
    {
        i_f = 1;
        i_h = 2;
        i_p = 3;
    }
    else if (argv[2][0] == '-')
    {
        i_f = 2;
        i_h = 1;
        i_p = 3;
    }
    else if (argv[3][0] == '-')
    {
        i_f = 3;
        i_h = 1;
        i_p = 2;
    }

    if (i_f == 0)
    {
        return -1;
    }

    if (parse_flag(argv[i_f], flag) == -1)
    {
        return -1;
    }

    *host = argv[i_h];
    *port = argv[i_p];

    return 0;
}

int creat_socket(char *host, char *port)
{
    struct addrinfo infos = { 0 };

    memset(&infos, 0, sizeof(struct addrinfo));

    infos.ai_family = AF_INET;
    infos.ai_socktype = SOCK_STREAM;

    struct addrinfo *res;

    if (getaddrinfo(host, port, &infos, &res) != 0)
    {
        return 1;
    }

    int result = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    if (result == -1)
    {
        return 1;
    }

    if (connect(result, res->ai_addr, res->ai_addrlen) != 0)
    {
        return 1;
    }

    freeaddrinfo(res);

    return result;
}
