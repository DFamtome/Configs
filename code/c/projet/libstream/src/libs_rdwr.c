#include "libstream.h"

int lbs_fputc(int c, struct stream *stream)
{
    if (!stream)
    {
        return -1;
    }

    if (stream->io_operation == STREAM_READING
        || stream->buffered_size == LBS_BUFFER_SIZE
        || stream->buffering_mode == STREAM_UNBUFFERED)
    {
        if (lbs_fflush(stream) != 0)
        {
            return -1;
        }
    }

    stream->io_operation = STREAM_WRITING;

    stream->buffer[stream->buffered_size++] = c;

    if (stream->buffering_mode == STREAM_LINE_BUFFERED && c == '\n')
    {
        if (lbs_fflush(stream) != 0)
        {
            return -1;
        }
    }

    return c;
}

int __refile(struct stream *s)
{
    if (!s)
    {
        return -1;
    }

    ssize_t read_c = read(s->fd, &s->buffer, LBS_BUFFER_SIZE);

    s->already_read = 0;

    if (read_c == -1)
    {
        return -1;
    }
    else if (read_c == 0)
    {
        s->error = 1;
        return -1;
    }

    s->buffered_size = read_c;

    return 0;
}

int lbs_fgetc(struct stream *stream)
{
    if (!stream)
    {
        return -1;
    }

    if ((stream->flags & O_RDONLY) != O_RDONLY)
    {
        return -1;
    }

    if (stream->io_operation == STREAM_WRITING
        || stream->already_read == stream->buffered_size)
    {
        if (lbs_fflush(stream) != 0)
        {
            return -1;
        }
    }

    stream->io_operation = STREAM_READING;

    if (stream->buffered_size == 0)
    {
        if (__refile(stream) == -1)
        {
            return -1;
        }
    }

    int c = stream->buffer[stream->already_read++];

    return c;
}

int lbs_fseek(struct stream *stream, long offset, int whence)
{
    if (!stream)
    {
        return -1;
    }

    lbs_fflush(stream);

    return lseek(stream->fd, offset, whence) == -1 ? -1 : 0;
}

long lbs_ftell(struct stream *stream)
{
    if (!stream)
    {
        return -1;
    }

    return stream_positioning(stream)
        - (stream->buffered_size - stream->already_read);
}

int lbs_setbufmode(struct stream *stream, enum stream_buffering mode)
{
    if (!stream)
    {
        return -1;
    }

    stream->buffering_mode = mode;

    return 0;
}
