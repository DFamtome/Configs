#include "element_count.h"

size_t element_count(int *begin, int *end)
{
    if (begin == end)
    {
        return 0;
    }

    size_t result = 0;

    for (int *p = begin; p++ != end; result++)
        ;

    return result;
}
