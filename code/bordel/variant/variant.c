#include "variant.h"

#include <stdio.h>
#include <string.h>

void variant_display(const struct variant *e)
{
    switch (e->type)
    {
    case TYPE_INT:
        printf("%d\n", e->value.int_v);
        break;
    case TYPE_FLOAT:
        printf("%f\n", e->value.float_v);
        break;
    case TYPE_CHAR:
        printf("%c\n", e->value.char_v);
        break;
    case TYPE_STRING:
        printf("%s\n", e->value.str_v);
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
    case TYPE_INT:
        return right->value.int_v == left->value.int_v;
    case TYPE_FLOAT:
        return right->value.float_v == left->value.float_v;
    case TYPE_CHAR:
        return right->value.char_v == left->value.char_v;
    case TYPE_STRING:
        return !strcmp(right->value.str_v, left->value.str_v);
    default:
        return false;
    }

    return false;
}

int variant_find(const struct variant *array, size_t len, enum type type,
                 union type_any value)

{
    for (size_t i = 0; i < len; i++)
    {
        if (array[i].type == type)
        {
            int diff = -1;
            switch (type)
            {
            case TYPE_INT:
                diff = array[i].value.int_v == value.int_v;
                break;
            case TYPE_FLOAT:
                diff = array[i].value.float_v == value.float_v;
                break;
            case TYPE_CHAR:
                diff = array[i].value.char_v == value.char_v;
                break;
            case TYPE_STRING:
                diff = !strcmp(array[i].value.str_v, value.str_v);
                break;
            default:
                break;
            }

            if (diff == 1)
            {
                return i;
            }
        }
    }

    return -1;
}

float variant_sum(const struct variant *array, size_t len)
{
    float res = 0;

    for (size_t i = 0; i < len; i++)
    {
        if (array[i].type == TYPE_INT)
        {
            res += array[i].value.int_v;
        }
        else if (array[i].type == TYPE_FLOAT)
        {
            res += array[i].value.float_v;
        }
    }

    return res;
}
