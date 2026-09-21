unsigned int greatest_divisor(unsigned int n)
{
    if (n == 1)
    {
        return 1;
    }
    unsigned i = n - 1;
    for (; i > 1 && n % i != 0; i--)
        ;

    return i;
}
