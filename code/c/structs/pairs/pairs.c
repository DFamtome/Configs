#include "pairs.h"

struct pair three_pairs_sum(const struct pair pair_1, const struct pair pair_2,
                            const struct pair pair_3)
{
    return (struct pair){
        pair_1.x + pair_2.x + pair_3.x,
        pair_1.y + pair_2.y + pair_3.y,
    };
}

struct pair pairs_sum(const struct pair pairs[], size_t size)
{
    int x = 0;
    int y = 0;

    for (size_t i = 0; i < size; i++)
    {
        x += pairs[i].x;
        y += pairs[i].y;
    }

    return (struct pair){
        x,
        y,
    };
}
