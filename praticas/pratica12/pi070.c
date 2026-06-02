#include "binaryTree.h"

int numberLeafs(BTNode *n)
{
    if (n == NULL)
    {
        return 0;
    }
    else
    {
        int lala = (n->right == NULL && n->left == NULL);
        return lala + numberLeafs(n->right) + numberLeafs(n->left);
    }
}

int numberTLeafs(BTree *t)
{

    return numberLeafs(t->root);
}