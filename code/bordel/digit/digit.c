int my_pow(int n, int p)
{
    int result = 1;
    for (int i = 0; i < p; i++)
    {
        result *= n;
    }

    return result;
}

unsigned int digit(int n, int k)
{
    if (n <= 0 || k <= 0)
    {
        return 0;
    }

    return (n / my_pow(10, k - 1)) % 10;
}
