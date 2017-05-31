#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

PNodeL changeSinglePosition(char *, PNodeL header);
void printList(PNodeL header);

int main()
{
    PNodeL L;

    L = lCreate("first");
    lInsert("second",L);
    lInsert("third",L);
    lInsert("fourth",L);
    lInsert("fifth",L);

    printList(L);

    L = changeSinglePosition("fifth", L);
    printf("-----------------------------\n");
    printList(L);


    return 0;
}

// ֻ������һ���ڵ���н�����
PNodeL changeSinglePosition(char *b, PNodeL header)
{
    PNodeL al,pal,tmp,ll;
    al = pal = NULL;
    tmp = header;
    while(tmp != NULL){
        if(strcmp(tmp->s,b) == 0){
            al = tmp;
            break;
        }
        pal = tmp;
        tmp = tmp->next;
    }
    if(al == NULL){
        printf("Can't find \"%s\"",b);
        exit(1);
    }
    if(al == header){
        // ���������������ͷԪ��λ��
        pal = al->next;
        tmp = pal->next;
        pal->next = al;
        al->next = tmp;
        return pal;
    }else if(al->next == NULL){
        // �������������һ��Ԫ��λ��
    }else{
        // ��������Ԫ���������м�λ��
        ll = al->next;
        tmp = ll->next;
        pal->next = ll;
        ll->next = al;
        al->next = tmp;
    }
    return header;
}

void printList(PNodeL L)
{
    while(L){
        printf("%s\n",L->s);
        L = L->next;
    }
}
