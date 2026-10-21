#include "libstream.h"

int __fflush_read(struct stream *s)
{
    if (!s)
    {
        return -1;
    }

    int res = 0;

    if (s->already_read - s->buffered_size != 0)
    {
        res = lseek(s->fd, s->already_read - s->buffered_size, SEEK_CUR);
    }

    s->already_read = s->buffered_size = 0;

    if (res == -1)
    {
        s->error = 1;
    }

    return res == -1 ? 1 : 0;
}

int __fflush_write(struct stream *s)
{
    if (!s)
    {
        return -1;
    }

    int res = write(s->fd, s->buffer, s->buffered_size - 1);

    s->buffered_size = s->already_read = 0;

    if (res == -1)
    {
        s->error = 1;
    }

    return res == -1 ? 1 : 0;
}

int lbs_fflush(struct stream *stream)
{
    if (!stream)
    {
        return -1;
    }

    if (stream->io_operation == STREAM_READING)
    {
        return __fflush_read(stream);
    }

    return __fflush_write(stream);
}
