#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

typedef struct //для меню
{
    int x;
    int y;
}point;

typedef struct //значение в ячейке
{
    char sign;
    int coefficient;
    char x;
    int degree;
}value;

typedef struct Node //узел односвязного списка
{
    value item;
    struct Node * next;
}Node;

typedef struct SingleLinked //односвязный список
{
     Node *head;
     Node *tail;
} SingleLinked;

typedef struct NodeDouble//узел двусвязного списка
{
    char s[30];
    struct NodeDouble * next;
    struct NodeDouble * prev;
}NodeDouble;

typedef struct DoubleLinked //двусвязный список
{
    int sizelist;
    NodeDouble * head;
    NodeDouble * tail;
}DoubleLinked;
#endif // STRUCTS_H_INCLUDED
