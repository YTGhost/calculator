#ifndef CHARSTACK_H
#define CHARSTACK_H
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define INITSIZE 500
typedef struct
{
    char *base;
    int top;
    int stacksize;
} sqcharstack;

void initCharStack(sqcharstack *S)
{
    S->base = (char *)malloc(INITSIZE * sizeof(char));
    if(!S->base)
    {
        printf("OVERFLOW!");
        exit(1);
    }
    S->top = 0;
    S->stacksize = INITSIZE;
}

int getLenCharStack(sqcharstack *S)
{
    return (S->top);
}

char getCharTop(sqcharstack *S)
{
    return S->base[S->top - 1];
}

int pushChar(sqcharstack *S, char x)
{
    if(S->top >= S->stacksize)
    {
        S->base = (char *)realloc(S->base, (S->stacksize + 1) * sizeof(char));
        if(!S->base)
        {
            printf("OVERFLOW!");
            return 0;
        }
        S->stacksize++;
    }
    S->base[S->top++] = x;
    return 1;
}

char popChar(sqcharstack *S)
{
    return S->base[--S->top];
}

int emptyCharStack(sqcharstack *S)
{
    return (S->top == 0 ? 1 : 0);
}

//void outputCharStack(sqcharstack *S)
//{
//    int i = 0;
//    while(i <= S->top-1)
//    {
//        printf("%4s ", S->base[i]);
//        i++;
//    }
//    printf("\n");
//}

void destroyCharStack(sqcharstack *S)
{
    free(S->base);
}

#endif // CHARSTACK_H
