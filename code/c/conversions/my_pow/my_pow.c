int my_pow(int a, unsigned long b)
{
    if (b == 0)
    {
        return 1;
    }

    int result = 1;
    while (b > 0)
    {
        if ((b & 1) == 0)
        {
            a *= a;
            b >>= 1;
        }
        else
        {
            result *= a;
            b--;
        }
    }

    return result;
}
