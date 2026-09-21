unsigned long fibo_iter(unsigned long n)
{
    if (n <= 1)
    {
        return n;
    }

    unsigned long f1 = 0;
    unsigned long f2 = 1;

    for (unsigned long i = 2; i <= n; i++)
    {
        unsigned long tmp = f1 + f2;
        f1 = f2;
        f2 = tmp;
    }

    return f2;
}
