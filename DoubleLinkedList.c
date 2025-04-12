#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoubleLinkedList.h"
#include "structs.h"
DoubleLinked * InitializeDoubleList()
{
    DoubleLinked * tmp = (DoubleLinked *) malloc(sizeof(DoubleLinked));
    tmp -> sizelist = 0;
    tmp -> head = tmp -> tail = NULL;
    return tmp;
}

void DeleteDoubleList(DoubleLinked ** list)
{
    NodeDouble * next = NULL;
    NodeDouble * pointer = (*list) -> head;
    while (pointer)
    {
        next = pointer -> next;
        free(pointer);
        pointer = next;
    }
    free(* list);
    * list = NULL;
}

void AddToBeginDouble(DoubleLinked * list, char * string)
{
    if (list == NULL)
    {
        printf("List is empty\n");
        exit(0);
    }

    NodeDouble * NewNode = (NodeDouble *) malloc(sizeof(NodeDouble));

    if (NewNode == NULL)
    {
        printf("Error");
        exit(0);
    }

    strcpy(NewNode -> s, string);
    NewNode -> next = list -> head;
    NewNode -> prev = NULL;
    if (list -> head != NULL)
    {
        list -> head -> prev = NewNode;
    }
    list -> head = NewNode;

    if (list -> tail == NULL)
    {
        list -> tail = NewNode;
    }
    list -> sizelist += 1;
}

void AddToEndDouble(DoubleLinked * list, char * string)
{
    int a = 0;
    if (list == NULL)
    {
        printf("List is empty\n");
        exit(0);
    }

    NodeDouble * NewNode = (NodeDouble *) malloc(sizeof(NodeDouble));

    if (NewNode == NULL)
    {
        printf("Error");
        exit(0);
    }

    if (list -> tail == NULL)
    {
        AddToBeginDouble(list, string);
        a = 1;
    }
    else
    {
        strcpy(NewNode -> s, string);
        NewNode -> next = NULL;
        NewNode -> prev = list -> tail;
        list -> tail -> next = NewNode;
        list -> tail = NewNode;
    }
    if (a == 0)
        list -> sizelist += 1;
}

void RunList(DoubleLinked ** list)
{
    NodeDouble * pointer = (*list) -> head;
    //NodeDouble * pointerend = (*list) -> tail;
    NodeDouble * next = NULL;
    int i = (*list) -> sizelist;
    int j = 0;
    if ((*list) -> sizelist != 1)
    {
        do
        {
            if (strlen(pointer -> s) % 2 == 0)
            {
                if (pointer -> prev == NULL)
                {
                    AddToEndDouble(*list, pointer -> s);
                    (*list) -> head = pointer -> next;
                    (*list) -> head -> prev = NULL;
                    (*list) -> sizelist -= 1;
                    next = pointer -> next;
                    free(pointer);
                    pointer = next;
                }
                else
                {
                    AddToEndDouble(*list, pointer -> s);
                    pointer -> next -> prev = pointer -> prev;
                    pointer -> prev -> next = pointer -> next;
                    (*list) -> sizelist -= 1;
                    next = pointer -> next;
                    free(pointer);
                    pointer = next;
                }
            }
            else
                pointer = pointer -> next;
            j += 1;
        }
        while(j != i);
    }
}

void PrintListDouble(DoubleLinked list)
{
    NodeDouble * current = list.head;
    printf("[ ");

    while (current)
    {
        if (current -> next == NULL)
            printf(" %s.", current -> s);
        else
            printf(" %s", current -> s);
        current = current -> next;
    }
    puts(" ]\n");
}
