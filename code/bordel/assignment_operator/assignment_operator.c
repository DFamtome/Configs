void plus_equal(int *a, int *b)
{
    if (!a || !b)
    {
        return;
    }

    *a += *b;
}

void minus_equal(int *a, int *b)
{
    if (!a || !b)
    {
        return;
    }
    *a -= *b;
}

void mult_equal(int *a, int *b)
{
    if (!a || !b)
    {
        return;
    }

    *a *= *b;
}

int div_equal(int *a, int *b)
{
    if (!a || !b)
    {
        return 0;
    }

    if (*b == 0)
    {
        return 0;
    }
    int res = *a % *b;
    *a /= *b;

    return res;
}
