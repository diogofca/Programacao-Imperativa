#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stack.h>

int wordlengh(char *word)
{
    int to_return = 0;
    while (*word != '\0')
    {
        word += 1;
        to_return += 1;
    }
    return to_return;
}

bool balanced(char *string)
{
    Stack myStack;
    myStack.top = 0;
    int a = wordlengh(string);
    for (int i = 0; i < a; i++)
    {
        char c = string[i];
        if (c == '(' || c == '[')
        {
            push(&myStack, c);
        }
        else if (c == ')')
        {
            if (isEmpty(&myStack))
            {
                return false;
            }
            char poped = top(&myStack);
            pop(&myStack);
            if (poped != '(')
            {
                return false;
            }
        }
        else if (c == ']')
        {
            if (isEmpty(&myStack))
            {
                return false;
            }
            char poped = top(&myStack);
            pop(&myStack);
            if (poped != '[')
            {
                return false;
            }
        }
    }

    if (!isEmpty(&myStack))
    {
        return false;
    }
    return true;
}