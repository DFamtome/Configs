#ifndef UTILS_H
#define UTILS_H
enum flag
{
    SEND,
    HALF,
    SELECT,
};

int parse_args(char **argv, char **port, char **host, enum flag *flag);
int creat_socket(char *host, char *port);
#endif /* ! UTILS_H */
