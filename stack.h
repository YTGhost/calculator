#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>

#define INITSIZE 500
typedef double ElemType;
typedef struct
{
    ElemType *base;
    int top;
    int stacksize;
} sqstack;

void initStack(sqstack *S)
{
    S->base = (ElemType *)malloc(INITSIZE * sizeof(ElemType));
    if(!S->base)
    {
        printf("OVERFLOW!");
        exit(1);
    }
    S->top = 0;
    S->stacksize = INITSIZE;
}

int getLenStack(sqstack *S)
{
    return (S->top);
}

double getTop(sqstack *S)
{
    return S->base[S->top - 1];
}
ElemType push(sqstack *S, ElemType x)
{
    if(S->top >= S->stacksize)
    {
        S->base = (ElemType *)realloc(S->base, (S->stacksize + 1) * sizeof(ElemType));
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

ElemType pop(sqstack *S)
{
    return S->base[--S->top];
}

int emptyStack(sqstack *S)
{
    return (S->top == 0 ? 1 : 0);
}

void outputStack(sqstack *S)
{
    int i = 0;
    while(i <= S->top-1)
    {
        printf("%4lf ", S->base[i]);
        i++;
    }
    printf("\n");
}

void destroyStack(sqstack *S)
{
    free(S->base);
}

#endif // STACK_H
