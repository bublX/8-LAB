#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "helptofunc.h"
#include "structs.h"
#include "DoubleLinkedList.h"
int CompareDegree(int a, int * degrees, int * degcounter)
{
    for (int i = 0; i < *degcounter; i++)
        if (a == degrees[i])
            return 1;
    return 0;
}

char * GetTerm(char ** str)
{
    if (* str == NULL || ** str == '\0')
    {
        return NULL;
    }

    char * start = * str;
    char * end = start + 1;

    while ((* end != '\0') && (* end != '+') && (* end != '-'))
    {
        end++;
    }

    int term_len = end - start;

    char * term = (char *)malloc(term_len + 1);

    if (term == NULL)
    {
        printf("Error");
        return NULL;
    }

    strncpy(term, start, term_len);
    term[term_len] = '\0';

    * str = end;

    return term;
}

int ParseTerm(const char* term, value * result, int * degrees, int * degcounter)
{
    if (term == NULL || result == NULL)
    {
        return -1;
    }

    int len = strlen(term);

    if (len == 0)
    {
        return -1;
    }

    result -> sign = ' ';
    result -> coefficient = 1;
    result -> x = 'x';
    result -> degree = 1;

    int pos = 0;

    if (term[pos] == '+' || term[pos] == '-')
    {
        result -> sign = term[pos];
        pos++;
    }

    if (pos < len && isdigit(term[pos]))
    {
        char * endptr;
        result -> coefficient = (int)strtol(term + pos, &endptr, 10);
        pos = endptr - term;
    }

    if (pos < len)
    {
        result -> x = term[pos];
        pos++;

        if (pos < len && term[pos] == '^')
        {
            pos++;
            if (pos < len && isdigit(term[pos]))
            {
                char * endptr;
                result -> degree = (int)strtol(term + pos, &endptr, 10);
                degrees[*degcounter] = result -> degree;
                (*degcounter)++;
                pos = endptr - term;
            }
            else
            {
                return -1;
            }
        }
        else if (pos == len)
        {
            result -> degree = 1;
            degrees[*degcounter] = result -> degree;
            (*degcounter)++;
        }
        else
        {
            return -1;
        }
    }
    else if (pos == len)
    {
        result -> x = '\0';
        result -> degree = 0;
        degrees[*degcounter] = result -> degree;
        (*degcounter)++;
    }
    else
    {
        return -1;
    }

    return 0;
}

char * ReadList(int n)
{
    int * length = (int *) malloc(sizeof(int));
    * length = 0;
    int size = 1;
    char * s = (char *) malloc(sizeof(char));
    char a = '\n';
    char c;
    if (n == 1)
    {
        a = '.';
    }

    while ((c = getchar()) == '\n'){}

    while (c != a)
    {
        s[(* length)++] = c;

        if (* length >= size)
        {
            size *= 2;
            s = (char *) realloc(s, size * sizeof(char));
        }

        c = getchar();
    }
        s[* length] = '\0';
    return s;
}

void PrintValue(value * val, int * p)
{
    if (*p == 0 && val -> sign == '+')
    {
        printf(" ");
        *p = 1;
    }
    else if (*p == 1 && val -> sign == ' ')
    {
        printf("%c", '+');
        *p = 1;
    }
    else if (val -> sign != '\0')
    {
        printf("%c", val -> sign);
        *p = 1;
    }
    if (abs(val -> coefficient) != 1 || val -> degree == 0)
    {
        printf("%d", abs(val -> coefficient));
    }

    if (val -> degree != 0)
    {
        printf("%c", val -> x);

        if (val -> degree != 1)
        {
            printf("^%d", val -> degree);
        }
    }
}

void ParseString(DoubleLinked * list,char * str)
{
    const char delim[] = " .";

    char * p = strtok(str, delim);

    while (p != NULL)
    {
        AddToEndDouble(list, p);
        p = strtok(NULL, delim);
    }
}
