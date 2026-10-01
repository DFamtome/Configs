#include <stdio.h>

#include "traffic_lights.c"
int main()
{
    unsigned char l1 = 2;
    unsigned char l2 = 2;

    swap(&l1, &l1);

    printf("%d, %d", l1, l2);

    return 0;
}
