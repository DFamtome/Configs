int int_sqrt(int n)
{
    if (n < 0)
    {
        return -1;
    }

    int r = 2;
    int nb = n / r;

    while (nb != r)
    {
        nb = n / r;
        r = (r + nb) / 2;
    }

    return r;
}
