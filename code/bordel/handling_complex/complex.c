#include "complex.h"

#include <stdio.h>

void print_complex(struct complex a)
{
    if (a.img < 0)
    {
        printf("complex(%.2f - %.2fi)\n", a.real, -a.img);
    }
    else
    {
        printf("complex(%.2f + %.2fi)\n", a.real, a.img);
    }
}

struct complex neg_complex(struct complex a)
{
    return (struct complex){ -a.real, -a.img };
}

struct complex add_complex(struct complex a, struct complex b)
{
    return (struct complex){ a.real + b.real, a.img + b.img };
}

struct complex sub_complex(struct complex a, struct complex b)
{
    return add_complex(a, neg_complex(b));
}

struct complex mul_complex(struct complex a, struct complex b)
{
    return (struct complex){ a.real * b.real - a.img * b.img,
                             a.real * b.img + b.real * a.img };
}

struct complex div_complex(struct complex a, struct complex b)
{
    return (struct complex){
        (a.real * b.real + a.img * b.img) / (b.real * b.real + b.img * b.img),
        (a.img * b.real - a.real * b.img) / (b.real * b.real + b.img * b.img)
    };
}
