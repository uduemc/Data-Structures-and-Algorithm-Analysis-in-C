#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dlist.h"

char *mName(char *s)
{
    char *c = malloc(sizeof(char) * strlen(s));
    if(c == NULL){
        printf("Out of space!");
        exit(1);
    }
    strcpy(c,s);
    return c;
}

PDNode create(char *s)
{
    PDNode header = malloc(sizeof(DNode));
    if(header == NULL){
        printf("Out of space!");
        exit(1);
    }
    header->prev = NULL;
    header->next = NULL;
    header->s = mName(s);
    return header;
}
void insert(char *s,PDNode header)
{
    PDNode last;
    PDNode node = create(s);
    last = header;
    while(last->next != NULL)
        last = last->next;
    last->next = node;
    node->prev = last;
}
void printDlist(PDNode header)
{
    while(header != NULL){
        printf("%s\n",header->s);
        header = header->next;
    }
}
