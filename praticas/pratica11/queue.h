#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXNODES 100
#define NodeInfo char *
typedef struct
{
    int first;                // refers to position of first node
    int last;                 // refers to position of last node
    int size;                 // number of nodes in the queue
    NodeInfo nodes[MAXNODES]; // the nodes data
} Queue;
// prototypes
void initQueue(Queue *);         // make queue empty
bool isEmpty(Queue *);           // verifies if queue is empty
bool isFull(Queue *);            // verifies if queue is full
void addLast(Queue *, NodeInfo); // add new node (enqueue)
NodeInfo removeFirst(Queue *);   // remove node (dequeue)
NodeInfo first(Queue *);