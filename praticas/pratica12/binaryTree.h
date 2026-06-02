
// binaryTree.h -- Binary Tree data structures and interface functions (public)
// F. Silva 28/5/2026
//

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NodeInfo int
#define NULL_SYMBOL "N"

// Data structures

typedef struct BTNode
{
    NodeInfo val;
    struct BTNode *left;
    struct BTNode *right;
} BTNode;

typedef struct
{
    BTNode *root;
} BTree;

// Function prototypes
// some of this functions manipulate the tree by
// a calling private function (defined in binaryTree.c)
// that starts at the root of the tree

// Node creation
BTNode *newNode(NodeInfo val);

// Tree initialisation
void initTree(BTree *t);

// Binary Search Tree (BST) insertion
void insertBST(BTree *tree, int val);

// Traversals (print to stdout)
void printPreorder(BTree *t);
void printInorder(BTree *t);
void printPostorder(BTree *t);

// Tree properties
int treeNodes(BTree *t);  // number of nodes
int treeHeight(BTree *t); // height

// Search
bool treeContains(BTree *t, NodeInfo val);

// Free memory used by tree nodes
void freeTree(BTree *t);

/*-------------------------------------------------------
   TODO: functions to implement
------------------------------------------------------- */

// Returns the number of leaf nodes in the tree.
// A leaf is a node with no children.
int numberTLeafs(BTree *t);

// Returns an array (dynamically allocated) with the sum of node
// values at each level. *size is set to the number of levels.
int *sumTLevels(BTree *t, int *size);

#endif /* BINARY_TREE_H */