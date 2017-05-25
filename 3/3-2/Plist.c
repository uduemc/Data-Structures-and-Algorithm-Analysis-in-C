#include <stdio.h>
#include <stdlib.h>
#include "list.h"

PNodeP pCreate(int i)
{
    PNodeP L = (PNodeP) malloc(sizeof(struct NodeP));
    L->next = NULL;
    L->x = i;
    return L;
}

void pInsert(int i, PNodeP L)
{
    while(L->next){
        L = L->next;
    }
    L->next =(PNodeP) malloc(sizeof(struct NodeP));
    L = L->next;
    L->next = NULL;
    L->x = i;
}
