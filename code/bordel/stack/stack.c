#include "stack.h"

#include <stddef.h>
#include <stdlib.h>

struct stack *stack_push(struct stack *s, int e)
{
    struct stack *n = malloc(sizeof(struct stack));
    if (!n)
    {
        return s;
    }

    n->data = e;
    n->next = NULL;

    if (!s)
    {
        return n;
    }

    n->next = s;
    return n;
}

struct stack *stack_pop(struct stack *s)
{
    if (!s)
    {
        return NULL;
    }

    struct stack *l = s->next;

    free(s);

    return l;
}

int stack_peek(struct stack *s)
{
    return s->data;
}
