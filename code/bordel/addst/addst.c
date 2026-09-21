#include "addst.h"

int height(const struct binary_tree *tree)
{
    if (tree == 0)
    {
        return -1;
    }

    int l = height(tree->left);
    int r = height(tree->right);

    return 1 + (l < r ? r : l);
}

void delete_tree(struct binary_tree *tree)
{
    if (tree == 0)
    {
        return;
    }

    delete_tree(tree->left);
    delete_tree(tree->right);

    free(tree);
}

void __addst(struct binary_tree *a, struct binary_tree *b)
{
    a->data += b->data;

    if (a->left == 0 && b->left != 0)
    {
        a->left = b->left;
    }
    else if (a->left != 0 && b->left != 0)
    {
        __addst(a->left, b->left);
    }

    if (a->right == 0 && b->right != 0)
    {
        a->right = b->right;
    }
    else if (a->right != 0 && b->right != 0)
    {
        __addst(a->right, b->right);
    }
}

void addst(struct binary_tree **a, struct binary_tree **b)
{
    if (a == 0 && *a == 0)
    {
        b = a;
        free(*b);
        return;
    }
    if (b == 0)
    {
        return;
    }

    int diff_height = height(*a) - height(*b);
    if ((diff_height < 0 ? -diff_height : diff_height) > 1)
    {
        delete_tree(*a);
        delete_tree(*b);
        return;
    }
    if (*b == 0)
    {
        return;
    }

    __addst(*a, *b);

    delete_tree(*b);
}
