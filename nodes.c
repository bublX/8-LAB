#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "helptofunc.h"
#include "nodes.h"
#include "structs.h"


SingleLinked * InitializeSingleList()
{
    SingleLinked * tmp = (SingleLinked *) malloc(sizeof(SingleLinked));
    tmp -> head = tmp -> tail = NULL;
    return tmp;
}

void AddToBegin(SingleLinked * list, value NewItem)
{
    if (list == NULL)
    {
        printf("List is empty\n");
        exit(0);
    }

    Node * NewNode = (Node *) malloc(sizeof(Node));

    if (NewNode == NULL)
    {
        printf("Error");
        exit(0);
    }

    NewNode -> item = NewItem;
    NewNode -> next = list -> head;
    list -> head = NewNode;

    if (list -> tail == NULL)
    {
        list -> tail = NewNode;
    }
}

void AddToEnd(SingleLinked * list, value NewItem)
{
    if (list == NULL)
    {
        printf("List is empty\n");
        exit(0);
    }

    Node * NewNode = (Node *) malloc(sizeof(Node));

    if (NewNode == NULL)
    {
        printf("Error");
        exit(0);
    }

    if (list -> tail == NULL)
    {
        AddToBegin(list, NewItem);
    }
    else
    {
        NewNode -> item = NewItem;
        NewNode -> next = NULL;
        list -> tail -> next = NewNode;
        list -> tail = NewNode;
    }
}

void PrintList(SingleLinked list)
{
    Node * current = list.head;
    int a = 0;
    int * p = &a;
    puts("[\b");

    while (current)
    {
        PrintValue(&(current -> item), p);
        current = current -> next;
    }

    puts(" ]\n");
}

void InitializePolinoms(SingleLinked * list, int * degrees, int * degcounter)
{
    list -> head = list -> tail = NULL;
    char * string = ReadList(0);

    value result;
    char * term;
    while ((term = GetTerm(&string)) != NULL)
    {
        ParseTerm(term, &result, degrees, degcounter);
        AddToEnd(list, result);
        free(term);
    }
}

void DeleteList(SingleLinked ** list)
{
    Node * pointer = (* list)->head;
    Node * next;

    while (pointer)
    {
        next = pointer -> next;
        free(pointer);
        pointer = next;
    }

    free(* list);
    * list = NULL;
}

void InitializeThird(SingleLinked *list, SingleLinked * third, int * degrees, int * degcounter)
{
    third -> head = third -> tail = NULL;

    Node * current = list -> head;

    while (current)
    {
        if (!CompareDegree(current -> item.degree, degrees, degcounter))
            AddToEnd(third, current -> item);
        current = current -> next;
    }
}
