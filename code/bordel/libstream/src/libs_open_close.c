#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "libstream.h"

int flag_parse(const char *sflag, int *f)
{
    if (!f)
    {
        return -1;
    }
    if (!strcmp(sflag, "r"))
    {
        *f = O_RDONLY;
    }
    else if (!strcmp(sflag, "r+"))
    {
        *f = O_RDWR;
    }
    else if (!strcmp(sflag, "w+"))
    {
        *f = O_RDWR | O_TRUNC | O_CREAT;
    }
    else if (!strcmp(sflag, "w"))
    {
        *f = O_WRONLY | O_CREAT | O_TRUNC;
    }
    else if (!strcmp(sflag, "a"))
    {
        *f = O_APPEND | O_WRONLY | O_CREAT;
    }
    else if (!strcmp(sflag, "a+"))
    {
        *f = O_APPEND | O_RDWR | O_CREAT;
    }
    else
    {
        return -1;
    }

    return 0;
}

struct stream *lbs_fdopen(int fd, const char *mode)
{
    if (!mode)
    {
        return NULL;
    }

    int f = -1;

    if (flag_parse(mode, &f) == -1)
    {
        return NULL;
    }

    enum stream_buffering bmod;

    if (isatty(fd))
    {
        bmod = STREAM_LINE_BUFFERED;
    }
    else if (errno == EBADF)
    {
        return NULL;
    }
    else
    {
        bmod = STREAM_BUFFERED;
    }

    struct stream *n = malloc(sizeof(struct stream));

    if (!n)
    {
        return NULL;
    }

    n->flags = f;
    n->error = 0;
    n->fd = fd;
    n->io_operation = STREAM_READING;
    n->buffering_mode = bmod;
    n->buffered_size = 0;
    n->already_read = 0;

    return n;
}

struct stream *lbs_fopen(const char *path, const char *mode)
{
    if (!path || !mode)
    {
        return NULL;
    }

    int f = -1;

    if (flag_parse(mode, &f) == -1)
    {
        return NULL;
    }

    int fd = open(path, f);

    return lbs_fdopen(fd, mode);
}

int lbs_fclose(struct stream *stream)
{
    if (!stream)
    {
        return -1;
    }

    int fd = stream->fd;

    lbs_fflush(stream);

    free(stream);

    return close(fd);
}
