#include <stdlib.h>
#include "structs.h"
#include "nodes.h"
void Swap(Node* prev, Node* first, Node* second, SingleLinked* list)
{
    if (!first || !second || first == second)
        return;

    if (first -> next != second)
        return;

    first -> next = second -> next;
    second -> next = first;

    if (prev)
        prev -> next = second;
    else
        list -> head = second;

    if (first -> next == NULL)
        list -> tail = first;
}

int CompareDegrees(Node * current, Node * next)
{
    if (current -> item.degree < next -> item.degree)
        return 1;
    return 0;
}

void BubbleSort(SingleLinked* list)
{
    if (list == NULL || list->head == NULL || list->head->next == NULL)
        return;

    int flag = 1;
    Node* last = NULL;

    do
    {
        flag = 0;
        Node* current = list->head;
        Node* prev = NULL;

        while (current != NULL && current->next != last)
        {
            if (CompareDegrees(current, current->next))
            {
                Node* next = current->next;

                if (prev != NULL)
                    prev->next = next;
                else
                    list->head = next;

                current->next = next->next;
                next->next = current;

                if (current->next == NULL)
                    list->tail = current;

                flag = 1;
                prev = next;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
        last = current;
    }
    while (flag);
}
