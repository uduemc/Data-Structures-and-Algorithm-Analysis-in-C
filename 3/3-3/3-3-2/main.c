#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dlist.h"

PDNode changDoublePosition(char *s, PDNode);

int main()
{
    PDNode header;
    header = create("first");
    insert("second",header);
    insert("third",header);
    insert("fourth",header);
    insert("fifth",header);

    printDlist(header);

    printf("-----------------------------\n");

    header = changDoublePosition("fourth",header);

    printDlist(header);

    return 0;
}

PDNode changDoublePosition(char *s, PDNode header)
{
    PDNode al,tmp,pal,ll;
    al = pal = NULL;
    tmp = header;
    while(tmp != NULL){
        if(strcmp(tmp->s, s) == 0){
            al = tmp;
            break;
        }
        pal = tmp;
        tmp = tmp->next;
    }
    if(al == NULL){
        printf("Can't find \"%s\"",s);
        exit(1);
    }
    if(al == header){
        pal = header->next;
        tmp = pal->next;
        pal->prev = NULL;
        pal->next = al;
        al->prev = pal;
        al->next = tmp;
        return pal;
    }else if(al->next == NULL){

    }else{
        ll = al->next;
        tmp = ll->next;
        pal->next = ll;
        ll->next = al;
        ll->prev = pal;
        al->next = tmp;
        al->prev = ll;
    }
    return header;
}
