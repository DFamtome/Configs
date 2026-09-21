#include "tinyprintf.h"

int put_nb(unsigned nb)
{
    if (nb <= 9)
    {
        putchar('0' + nb);
        return 1;
    }

    int r = 1 + put_nb(nb / 10);

    putchar('0' + nb % 10);

    return r;
}

int put_str(char *str)
{
    if (!str)
    {
        str = "(null)";
    }

    int i = 0;
    for (; str[i] != 0; i++)
    {
        putchar(str[i]);
    }

    return i;
}

int tinyprintf(const char *format, ...)
{
    va_list arg;
    va_start(arg, format);

    int nb_c = 0;

    for (int i = 0; format[i] != 0; i++)
    {
        if (format[i] == '%')
        {
            switch (format[++i])
            {
            case '%':
                putchar('%');
                nb_c++;
                break;
            case 'd': {
                int nb = va_arg(arg, int);

                if (nb < 0)
                {
                    putchar('-');
                    nb = -nb;
                }

                nb_c += put_nb(nb);
                break;
            }

            case 'u':
                nb_c += put_nb(va_arg(arg, unsigned int));
                break;
            case 'c':
                putchar(va_arg(arg, int));
                nb_c++;
                break;
            case 's':
                nb_c += put_str(va_arg(arg, char *));
                break;

            default:
                putchar('%');
                nb_c += 2;
                putchar(format[i]);
            }
        }
        else
        {
            putchar(format[i]);
            nb_c++;
        }
    }

    putchar('\0');

    va_end(arg);

    return nb_c;
}
