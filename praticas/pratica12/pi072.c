#include "binaryTree.h"
int height2(BTNode *r)
{
    if (r == NULL)
        return -1;
    int lh = height(r->left);
    int rh = height(r->right);
    return 1 + (lh > rh ? lh : rh);
}
BTNode *findNode(BTNode *n, NodeInfo val)
{
    if (n == NULL)
    {
        return NULL;
    }
    if (n->val == val)
    {
        return n;
    }
    if (n->val > val)
    {
        return findNode(n->left, val);
    }
    else
    {
        return findNode(n->right, val);
    }
}

int nodeBalance(BTNode *n, NodeInfo val)
{
    BTNode *l = findNode(n, val);
    if (l == NULL)
    {
        return 0;
    }
    return height2(l->right) - height2(l->left);
}

int treeBalance(BTree *t, NodeInfo val)
{
    return nodeBalance(t->root, val);
}