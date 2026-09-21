#include "poland_revert.h"

int operation(char operation, int *stack, int *p)
{
    if (*p < 2)
    {
        return 2;
    }

    switch (operation)
    {
    case '+':
        stack[*p - 2] += stack[*p - 1];
        *p -= 1;
        break;
    case '-':
        stack[*p - 2] -= stack[*p - 1];
        *p -= 1;
        break;
    case '%': {
        if (stack[*p - 1] == 0)
        {
            return 3;
        }
        stack[*p - 2] %= stack[*p - 1];
        *p -= 1;
        break;
    }
    case '/': {
        if (stack[*p - 1] == 0)
        {
            return 3;
        }
        stack[*p - 2] /= stack[*p - 1];
        *p -= 1;
        break;
    }

    case '*':
        stack[*p - 2] *= stack[*p - 1];
        *p -= 1;
        break;
    case '^':
        stack[*p - 2] = my_pow(stack[*p - 2], stack[*p - 1]);
        *p -= 1;
        break;
    default:
        return 1;
    }

    return 0;
}

int parse(char *word, int *i, int *stack, int *p)
{
    char c = word[*i];
    if (c == '+' || c == '-' || c == '%' || c == '*' || c == '^' || c == '/')
    {
        int r = operation(c, stack, p);
        if (r != 0)
        {
            return r;
        }
    }

    else if ('0' <= c && c <= '9')
    {
        stack[*p] = my_atoi(word, i);
        *p += 1;
    }
    else if (c == ' ' || c == '\n')
        ;

    else
    {
        return 1;
    }

    return 0;
}

int poland_reverse(char *word, int len)
{
    int *stack = calloc((len / 2) + 1, sizeof(int));
    int p = 0;

    if (!stack)
    {
        return 4;
    }

    for (int i = 0; word[i] != 0; i++)
    {
        int err = parse(word, &i, stack, &p);

        if (err != 0)
        {
            free(stack);
            return err;
        }
    }

    if (p == 0)
    {
        free(stack);
        return 0;
    }
    if (p != 1)
    {
        free(stack);
        return 2;
    }

    printf("%d\n", stack[p - 1]);

    free(stack);
    return 0;
}
