#include <linkedList.h>

void duplicate(LinkedList *list);

void duplicate(LinkedList *list)
{
    if (isEmpty(list))
    {
        return;
    }
    Node *pointer = list->first;
    while (pointer != NULL)
    {
        Node *newpointer = pointer->next;
        Node *middle = newNode(pointer->val, newpointer);
        pointer->next = middle;
        pointer = newpointer;
    }

    list->size *= 2;
}

void removeAll(NodeInfo value, LinkedList *list)
{
    addFirst(list, 0);
    Node *pointer = list->first;
    while (pointer->next != NULL)
    {
        if (pointer->next->val != value)
        {
            pointer = pointer->next;
        }
        else
        {
            pointer->next = pointer->next->next;
            list->size -= 1;
        }
    }
    NodeInfo temp;
    removeFirst(list, &temp);
}
