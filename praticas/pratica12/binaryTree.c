// binaryTree.c - Binary Tree implementation
// F. Silva 28/5/2026
//
// This follows this format
//  functionNode(BTNode *r) -- starts at root node (private to module)
//  functionTree(BTree *t) -- operates on the tree and calls functionNode(t->root)
//

#include "binaryTree.h"

// implementation of all functions

// Creates a new BTNode with a given value and children NULL
BTNode *newNode(NodeInfo val)
{
    BTNode *nnode = malloc(sizeof(BTNode)); // alocate memory for new node
    nnode->val = val;
    nnode->left = NULL;
    nnode->right = NULL;
    return nnode;
}

// initializes an empty tree
void initTree(BTree *t)
{
    t->root = NULL;
}

// Recursevely inserts val into a BST subtree rooted at r
BTNode *insertBTNode(BTNode *r, NodeInfo val)
{
    if (r == NULL)
        return newNode(val);
    if (val <= r->val)
        r->left = insertBTNode(r->left, val);
    else
        r->right = insertBTNode(r->right, val);
    return r;
}
// Inserts val into the BST tree t
void insertBST(BTree *t, int val)
{
    t->root = insertBTNode(t->root, val);
}

// Reads a single node (and its subtree) from stdin in pre-order.
//  Expects integer values; "N" represents a null node.
BTNode *readNode(void)
{
    char buffer[64];
    if (scanf("%63s", buffer) != 1)
        return NULL;
    if (strcmp(buffer, NULL_SYMBOL) == 0)
        return NULL;
    NodeInfo val = atoi(buffer);
    BTNode *n = newNode(val);
    n->left = readNode();
    n->right = readNode();
    return n;
}
// Reads a full tree from stdin given in preorder
void readTree(BTree *t)
{
    initTree(t);
    t->root = readNode();
}

// Returns number of nodes in the subtree rooted at r
int numberNodes(BTNode *r)
{
    if (r == NULL)
        return 0;
    return 1 + numberNodes(r->left) + numberNodes(r->right);
}
// count number of tree nodes
int treeNodes(BTree *t)
{
    return numberNodes(t->root);
}

// Returns the height of the subtree rooted at r (-1 for empty)
int height(BTNode *r)
{
    if (r == NULL)
        return -1;
    int lh = height(r->left);
    int rh = height(r->right);
    return 1 + (lh > rh ? lh : rh);
}
// Determines the height of tree t
int treeHeight(BTree *t)
{
    return height(t->root);
}

// Returns true if val exists in the subtree rooted at r, false otherwise
bool contains(BTNode *r, NodeInfo val)
{
    if (r == NULL)
        return false;
    if (r->val == val)
        return true; // NodeInfo as integer
    return (contains(r->left, val) || contains(r->right, val));
}
// Search if tree t cointains the value val
bool treeContains(BTree *t, NodeInfo val)
{
    return contains(t->root, val);
}

// In-order traversal: left root right
void inorder(BTNode *r)
{
    if (r == NULL)
        return;
    inorder(r->left);
    printf(" %d", r->val);
    inorder(r->right);
}
// print tree values in-order
void printInorder(BTree *t)
{
    inorder(t->root);
}

// Pre-order traversal: root left right
void preorder(BTNode *r)
{
    if (r == NULL)
        return;
    printf(" %d", r->val);
    preorder(r->left);
    preorder(r->right);
}
// print tree values pre-order
void printPreorder(BTree *t)
{
    preorder(t->root);
}

// Post-order traversal: left right root
void postorder(BTNode *r)
{
    if (r == NULL)
        return;
    postorder(r->left);
    postorder(r->right);
    printf(" %d", r->val);
}
// print tree values post-order
void printPostorder(BTree *t)
{
    postorder(t->root);
}

// Frees all nodes of subtree rooted at r
void freeTreeNodes(BTNode *r)
{
    if (r == NULL)
        return;
    freeTreeNodes(r->left);
    freeTreeNodes(r->right);
    free(r);
}

// Free all nodes (post-order)
void freeTree(BTree *t)
{
    freeTreeNodes(t->root);
}
