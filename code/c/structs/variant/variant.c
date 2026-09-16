#include "variant.h"

void variant_display(const struct variant *e)
{
    switch (e->type)
    {
    TYPE_INT:
        printf("%d\n", e->value->int_v);
        break;
    TYPE_FLOAT:
        printf("%f\n", e->value->float_v);
        break;
    TYPE_CHAR:
        printf("%c\n", e->value->char_v);
        break;
    TYPE_STRING:
        printf("%s\n", e->value->str_v);
        break;
    }
}

bool variant_equal(const struct variant *left, const struct variant *right)
{
    if (left == right)
    {
        return true;
    }

    if (!left || !right || left->type != right->type)
    {
        return false;
    }

    switch (right->type)
    {
    TYPE_INT:
        return right->value->int_v == left->value->int_v;
    TYPE_FLOAT:
        return right->value->float_v == left->value->float_v;
    TYPE_CHAR:
        return right->value->char_v == left->value->char_v;
    TYPE_STRING:
        return !strcmp(right->value->str_v, left->value->str_v);
    }
}

int variant_find(const struct variant *array, size_t len, enum type type,
                 union type_any value)

{
    for (int i = 0; i < len; i++)
    {
        int diff = -1;
        switch (array[i]->type)
        {
        TYPE_INT:
            diff = array[i]->value->int_v == value->int_v;
        TYPE_FLOAT:
            diff = array[i]->value->float_v == value->float_v;
        TYPE_CHAR:
            diff = array[i]->value->char_v == value->char_v;
        TYPE_STRING:
            diff = !strcmp(array[i]->value->str_v, value->str_v) i;
        }

        if (diff == 1)
        {
            return i;
        }
    }

    return -1;
}
