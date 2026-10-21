#ifndef ADDST_H
#define ADDST_H

#include <stdlib.h>
struct binary_tree
{
    int data;
    struct binary_tree *left;
    struct binary_tree *right;
};

/*
** Returns the height of tree.
*/
int height(const struct binary_tree *tree);

/*
** Frees the given tree.
*/
void delete_tree(struct binary_tree *tree);

/*
** Adds B into A in place. At every position held by both trees, the subtrees
** there must have heights differing by at most 1.
** If the rules holds, delete only B, otherwise delete A as well.
*/
void addst(struct binary_tree **a, struct binary_tree **b);

#endif /* ! ADDST_H */
