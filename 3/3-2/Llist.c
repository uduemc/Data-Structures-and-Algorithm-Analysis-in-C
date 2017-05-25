#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

char *mName(char *s)
{
    char *c;
    c = (char *)malloc(sizeof(char) *strlen(s));
    if(c == NULL){
        printf("Out of space");
        exit(1);
    }
    strcpy(c,s);
    return c;
}

PNodeL lCreate(char *s)
{
    PNodeL L = (PNodeL) malloc(sizeof(NodeL));
    L->next = NULL;
    L->s = mName(s);
    return L;
}

void lInsert(char *s, PNodeL L)
{
    while(L->next){
        L = L->next;
    }
    L->next =(PNodeL) malloc(sizeof(NodeL));
    L = L->next;
    L->s = mName(s);
    L->next = NULL;
}
