int my_pow(int n, int p)
{
    int result = 1;

    for (int i = 0; i < p; i++)
    {
        result *= n;
    }

    return result;
}

int int_palindrome(int n)
{
    if (n < 0)
    {
        return 0;
    }

    int nb = n;

    int len = 0;

    for (; nb != 0; len++)
    {
        nb /= 10;
    }

    nb = n;

    while (len >= 2 && nb % 10 == nb / my_pow(10, len - 1))
    {
        nb %= 10;
        nb /= my_pow(10, len);
        len -= 2;
    }

    if (len >= 2)
    {
        return 0;
    }

    return 1;
}
