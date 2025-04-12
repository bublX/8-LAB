#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

typedef struct //��� ����
{
    int x;
    int y;
}point;

typedef struct //�������� � ������
{
    char sign;
    int coefficient;
    char x;
    int degree;
}value;

typedef struct Node //���� ������������ ������
{
    value item;
    struct Node * next;
}Node;

typedef struct SingleLinked //����������� ������
{
     Node *head;
     Node *tail;
} SingleLinked;

typedef struct NodeDouble//���� ����������� ������
{
    char s[30];
    struct NodeDouble * next;
    struct NodeDouble * prev;
}NodeDouble;

typedef struct DoubleLinked //���������� ������
{
    int sizelist;
    NodeDouble * head;
    NodeDouble * tail;
}DoubleLinked;
#endif // STRUCTS_H_INCLUDED
