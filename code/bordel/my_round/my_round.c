float my_abs(float f)
{
    if (f < 0)
    {
        return -f;
    }

    return f;
}

int my_round(float n)
{
    int tr = n;

    if (my_abs(n - tr) >= 0.5)
    {
        if (n < 0)
        {
            tr--;
        }
        else
        {
            tr++;
        }
    }

    return tr;
}
