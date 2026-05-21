

// -------------------------------------------------
// ProgramaÃ§Ã£o Imperativa (CC1003)
// Implementation of an array based stack
// Interface functions
// Fernando Silva, DCC/FCUP
// -------------------------------------------------

#include "stack.h"

// make the stack empty
void empty(Stack *s)
{
    s->top = 0;
}
// verify if stack is empty
bool isEmpty(Stack *s)
{
    return (s->top == 0);
}
// verify if stack is full
bool isFull(Stack *s)
{
    return (s->top >= MAXNODES);
}
// insert a new node to top of stack
void push(Stack *s, NodeInfo val)
{
    if (isFull(s))
    {
        printf("Stack is full\n");
        exit(1);
    }
    s->nodes[s->top] = val;
    s->top++;
}
// remove the top node from stack
NodeInfo pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty\n");
        exit(1);
    }
    s->top--;
    return s->nodes[s->top];
}
// inspect top node at stack, but do not remove it
NodeInfo top(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty\n");
        exit(1);
    }
    return s->nodes[s->top - 1];
}