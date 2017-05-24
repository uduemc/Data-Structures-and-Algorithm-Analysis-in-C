#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node;
typedef struct Node * PNode;
typedef PNode List;

struct Node{
    char *name;
    List next;
};

char *mName(char *name){
    char *c;
    c = malloc(sizeof(char) * strlen(name));
    if(c == NULL){
        printf("Out of space");
        exit(1);
    }
    strcpy(c,name);
    return c;
}

List create(char *name)
{
    List L = (List) malloc(sizeof(struct Node));
    L->name = mName(name);
    L->next = NULL;
    return L;
}

void InsertLast(char *name, List L)
{
    char *c = mName(name);
    while(L->next){
        L = L->next;
    }
    L->next = (List) malloc(sizeof(struct Node));
    L = L->next;
    L->name = c;
    L->next = NULL;

}

void PrintfList(List L)
{
    while(L){
        printf("%s\n",L->name);
        L = L->next;
    }
}

void delete( List L )
{
    free(L->name);
    free(L);
}

void Clear(List L)
{
    List tmp;
    while(L){
        tmp = L->next;
        delete(L);
        L = tmp;
    }
}

int main()
{
    List header;
    header = create("first");
    InsertLast("second", header);
    InsertLast("third", header);
    InsertLast("fourth", header);

    PrintfList(header);
    Clear(header);
    return 0;
}
