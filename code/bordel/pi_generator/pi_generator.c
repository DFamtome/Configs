#include <stdio.h>

double __pi_generator(int acc, int precision)
{
    if (acc >= precision)
    {
        return 1;
    }

    return 1 + (acc / (2.0 * acc + 1) * __pi_generator(acc + 1, precision));
}

double pi_generator(int precision)
{
    if (precision <= 0)
    {
        return 2;
    }

    return 2 * __pi_generator(1, precision);
}
