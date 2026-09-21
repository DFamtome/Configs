#include <fcntl.h>
#include <unistd.h>

int create_file_755(const char *path)
{
    int res = open(path, O_CREAT, 493);

    if (res == -1)
    {
        return 1;
    }

    close(res);

    return 0;
}
