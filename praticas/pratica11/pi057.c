#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <queue.h>

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

void process(Queue *q, Queue *a, Queue *b)
{
    int in_a = 0;
    int in_b = 0;
    while (!isEmpty(q))
    {
        char *name = removeFirst(q);
        char *category = removeFirst(q);
        char cat = category[0];
        if (cat == 'A')
        {
            addLast(a, name);
            in_a++;
        }
        else if (cat == 'B')
        {
            addLast(b, name);
            in_b++;
        }
        else
        {
            if (in_a < in_b)
            {

                addLast(a, name);
                in_a++;
            }
            else if (in_b < in_a)
            {

                addLast(b, name);
                in_b++;
            }
        }
    }
}