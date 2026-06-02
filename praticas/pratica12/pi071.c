#include "binaryTree.h"

void sumLevels(BTNode *n, int *size, int l)
{
    if (n == NULL)
    {
        return;
    }
    size[l] += n->val;
    sumLevels(n->left, size, l + 1);
    sumLevels(n->right, size, l + 1);
}

int *sumTLevels(BTree *t, int *size)
{
    *size = treeHeight(t) + 1;
    if (*size == 0)
    {
        return NULL;
    }

    int *toReturn = calloc(*size + 1, sizeof(int));
    sumLevels(t->root, toReturn, 0);

    return toReturn;
}