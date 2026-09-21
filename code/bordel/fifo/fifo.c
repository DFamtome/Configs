#include "fifo.h"

#include <stdio.h>
#include <stdlib.h>

struct fifo *fifo_init(void)
{
    struct fifo *n = malloc(sizeof(struct fifo));

    if (!n)
    {
        return NULL;
    }

    n->head = NULL;
    n->tail = NULL;
    n->size = 0;

    return n;
}

size_t fifo_size(struct fifo *fifo)
{
    if (!fifo)
    {
        return 0;
    }

    return fifo->size;
}

void fifo_push(struct fifo *fifo, int elt)
{
    if (!fifo)
    {
        return;
    }

    struct list *n = malloc(sizeof(struct list));

    if (!n)
    {
        return;
    }

    n->data = elt;
    n->next = NULL;
    if (!fifo->head)
    {
        // Edge case not handle
        // head == NULL && tail != NULL
        // illogic and not handle

        fifo->head = n;
        fifo->tail = n;
        fifo->size += 1;
        return;
    }

    // Edge case tail == NULL : refound the tail
    // illogic : not handle

    if (!fifo->tail)
    {
        free(n);
        return;
    }

    fifo->tail->next = n;
    fifo->tail = n;

    fifo->size += 1;
}

int fifo_head(struct fifo *fifo)
{
    // No edge case
    return fifo->head->data;
}

void fifo_pop(struct fifo *fifo)
{
    if (!fifo)
    {
        return;
    }

    struct list *l = fifo->head;
    if (!l)
    {
        return;
    }

    fifo->head = l->next;

    if (fifo->head == NULL)
    {
        fifo->tail = NULL;
    }

    free(l);

    fifo->size -= 1;
}

void __fifo_clear(struct list *l)
{
    if (!l)
    {
        return;
    }

    __fifo_clear(l->next);

    free(l);
}

void fifo_clear(struct fifo *fifo)
{
    if (!fifo)
    {
        return;
    }
    __fifo_clear(fifo->head);

    fifo->tail = fifo->head = NULL;
    fifo->size = 0;
}

void fifo_destroy(struct fifo *fifo)
{
    fifo_clear(fifo);

    free(fifo);
}

void fifo_print(const struct fifo *fifo)
{
    if (!fifo)
    {
        return;
    }

    for (struct list *l = fifo->head; l != NULL; l = l->next)
    {
        printf("%d\n", l->data);
    }
}
