#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "structs.h"
#include "menu.h"
#include "nodes.h"
#include "helptofunc.h"
#include "DoubleLinkedList.h"

void menu() //меню выбора программы
{
    char mas[2][30], button;
    int i;
    point a = {0, 0};

    do
    {
        sprintf(mas[0], " Polynomials                ");
        sprintf(mas[1], " Sentences                  ");

        mas[a.y][a.x] = '>';
        system("cls");

        printf("Choose what you want to do(to choose press E):\n");

        for (i = 0; i < 2; i++)
            printf("%s\n", mas[i]);

        button = getch();

        if ((button == 'w') && (a.y == 0))
            a.y = 1;

        else if (button == 'w')
                  a.y--;

        if ((button == 's') && (a.y == 1))
            a.y = 0;

        else if (button == 's')
            a.y++;
    }
    while (button != 'e');

    if (a.y == 0)
    {
        SingleLinked * ListOne = InitializeSingleList();
        SingleLinked * ListTwo = InitializeSingleList();
        SingleLinked * ListThree = InitializeSingleList();
        int * degrees1 = (int *) malloc(10 * sizeof(int));
        int * degcounter1 = (int *) malloc(10 * sizeof(int));
            * degcounter1 = 0;
        int * degrees2 = (int *) malloc(10 * sizeof(int));
        int * degcounter2 = (int *) malloc(10 * sizeof(int));
            * degcounter2 = 0;
            system("cls");
            printf("Enter list one:\n");
        InitializePolinoms(ListOne, degrees1, degcounter1);
        BubbleSort(ListOne);
            system("cls");
            printf("Enter list two:\n");
        InitializePolinoms(ListTwo, degrees2, degcounter2);
        BubbleSort(ListTwo);
            system("cls");
            printf("First polynomial is: ");
        PrintList(*ListOne);
            printf("Second polynomial is: ");
        PrintList(*ListTwo);
            printf("The result is: ");
        InitializeThird(ListTwo,ListThree,degrees1, degcounter1);
        PrintList(*ListThree);
            free(degrees1);
            free(degcounter1);
            free(degrees2);
            free(degcounter2);
        DeleteList(&ListOne);
        DeleteList(&ListTwo);
        DeleteList(&ListThree);
        printf("Press E to get back to menu");
        do
            button = getch();
        while (button != 'e');
        menu();
    }
    else
    {
        int ret;
        char button;
        DoubleLinked * List = InitializeDoubleList();
        system("cls");
        printf("Enter string:\n");
        char * s = ReadList(1);
        ParseString(List ,s);
        PrintListDouble(*List);
        RunList(&List);
        PrintListDouble(*List);
        DeleteDoubleList(&List);
        printf("Press E to get back to menu");
        do
            button = getch();
        while (button != 'e');
        scanf("%d", &ret);
        menu();
    }
}

