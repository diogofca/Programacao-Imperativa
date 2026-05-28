#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define NodeInfo int
// Tree Node

// Creates a new node with the given value and NULL children

int max(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
typedef struct BTNode
{
    NodeInfo val;         // value in the node
    struct BTNode *left;  // left-child
    struct BTNode *right; // right-child
} BTNode;
// Tree
typedef struct
{
    BTNode *root; // root of the tree
} BTree;
// creating a new node
BTNode *newNode(NodeInfo val);

// Initialises an empty tree
void initTree(BTree *t);

// Inserts val into the BST t (for exercises that use BSTs)
void insertBST(BTree *t, NodeInfo val);

// Prints nodes in in-order (left–node–right)
void printInorder(BTree *t);

// Returns the total number of nodes in the tree
int numberTNodes(BTree *t);

// Frees all memory allocated by the tree (post-order)
void freeTree(BTNode *node);
BTNode *newNode(NodeInfo val)
{
    BTNode *nnode = malloc(sizeof(BTNode)); // allocate memory for new node
    nnode->val = val;
    nnode->left = NULL;
    nnode->right = NULL;
    return nnode;
}

// Método principal (público)
int numberNodes(BTNode *n)
{
    if (n == NULL)
        return 0;
    return 1 + numberNodes(n->left) + numberNodes(n->right);
}
int numberTNodes(BTree *t)
{
    return numberNodes(t->root);
}
// Método auxiliar (privado)

void initTree(BTree *t)
{
    t->root = NULL; // tree starts null
}
void inorder(BTNode *node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    printf(" %d", node->val);
    inorder(node->right);
}
// print a visit inorder
void printInosrder(BTree *t)
{
    printf(" Inorder :");
    inorder(t->root);
    printf("\n");
}
// In-order traversal left-node-right
// depth-first traversal
void insert(BTree *tree, int val)
{
    tree->root = insertNode(tree->root, val);
}

bool treeContains(BTree *t, NodeInfo value)
{
    return contains(t->root, value);
}
bool contains(BTNode *n, NodeInfo value)
{
    if (n == NULL)
        return false;
    if (n->val == value)
        return true; // assuming integers
    return contains(n->left, value) || contains(n->right, value);
}

bool treeContains(BTree *t, NodeInfo value)
{
    return contains(t->root, value);
}
bool contains(BTNode *n, NodeInfo value)
{
    if (n == NULL)
        return false;
    if (n->val == value)
        return true; // integers
    if (value < n->val)
        return contains(n->left, value);
    else
        return contains(n->right, value);
}

void insertBST(BTree *tree, NodeInfo val)
{
    tree->root = addBTNode(tree->root, val);
}
// adding a new BTNode with val
BTNode *addBTNode(BTNode *r, NodeInfo val)
{
    if (r == NULL)
        return newNode(val);
    if (val <= r->val)
        r->left = addBTNode(r->left, val);
    else
        r->right = addBTNode(r->right, val);
    return r;
}

// Free all nodes (post-order)
void freeTree(BTNode *node)
{
    if (node == NULL)
        return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int helper_height(BTNode *n)
{
    if (n == NULL)
    {
        return 0;
    }
    else
    {
        return max(helper_height(n->left), helper_height(n->right));
    }
}
int height(BTree *t)
{
    return helper_height(t->root) - 1;
}

int countLeavesHelper(BTNode *n)
{
    if (n->left == NULL && n->right == NULL)
    {
        return 1;
    }
    else if (n->left == NULL)
    {
        return countLeavesHelper(n->right);
    }
    else if (n->right == NULL)
    {
        return countLeavesHelper(n->left);
    }
    else
    {
        return countLeavesHelper(n->left) + countLeavesHelper(n->right);
    }
}

int countLeaves(BTree *t)
{
    if (t->root == NULL)
    {
        return 0;
    }
    else
    {
        return countLeavesHelper(t->root);
    }
}

bool isMirror(BTNode *a, BTNode *b)
{
    if (a == NULL && b == NULL)
    {
        return true;
    }
    if (a == NULL || b == NULL)
    {
        return false;
    }
    return isMirror(a->left, b->right) && isMirror(a->right, b->left);
}

bool isSymetric(BTree *t)
{
    if (t->root == NULL)
    {
        return true;
    }
    return isMirror(t->root->left, t->root->right);
}

void maxValueHelper(BTNode *n, int *val)
{
    if (n == NULL)
    {
        return;
    }
    if (n->val > *val)
    {
        *val = n->val;
    }
    maxValueHelper(n->right, val);
    maxValueHelper(n->left, val);
}

int maxValue(BTree *t)
{
    if (t->root == NULL)
    {
        exit(1);
    }
    int store_max = INT_MIN;
    maxValueHelper(t->root, &store_max);
    return store_max;
}

bool isBalancedHelper(BTNode *n)
{
    if (n == NULL)
    {
        return true;
    }
    if (!(helper_height(n->right) == helper_height(n->left)))
    {
        return false;
    }
    return isBalancedHelper(n->left) && isBalancedHelper(n->right);
}

int isBalenced(BTree *t)
{
    if (t->root == NULL)
    {
        return true;
    }
    return isBalancedHelper(t->root);
}

bool pathSumHelper(BTNode *t, int target)
{
    if (t == NULL)
    {
        if (target == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int node_value = target - t->val;
    return pathSumHelper(t->left, node_value) || pathSumHelper(t->right, node_value);
}
bool pathSum(BTree *t, int target)
{
    return pathSumHelper(t->root, target);
}

void depthHelper(BTNode *n, int level, int *to_return, NodeInfo val)
{
    if (n == NULL)
    {
        return;
    }
    if (n->val == val)
    {
        *to_return = level;
    }
    else
    {
        depthHelper(n->left, level + 1, to_return, val);
        depthHelper(n->right, level + 1, to_return, val);
    }
}

int depth(BTree *t, NodeInfo val)
{
    int toReturn = -1;
    depthHelper(t->root, 0, &toReturn, val);
    return toReturn;
}

int main()
{
    BTree tree;
    initTree(&tree);
    insertBST(&tree, 5);
    insertBST(&tree, 3);
    insertBST(&tree, 8);
    insertBST(&tree, 1);
    insertBST(&tree, 4);
    printf("In - order traversal : ");
    printInosrder(&tree);
    printf("\nTotal number of nodes : %d\n", numberTNodes(&tree));
    printf("Height: %d\n", height(&tree));
    freeTree(tree.root); // frees memory associated with all nodes
    return 0;
}