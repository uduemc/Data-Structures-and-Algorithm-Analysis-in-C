#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    PNodeP P,tmp;
    PNodeL L,tml;

    int index;

    P = pCreate(1);
    pInsert(3,P);
    pInsert(5,P);

    L = lCreate("first");
    lInsert("second",L);
    lInsert("third",L);
    lInsert("fourth",L);
    lInsert("fifth",L);

    index = 1;
    tmp = P;
    tml = L;

    // O(N)
    while(tmp){
        if(tmp->x == index++){
            printf("%s\n",tml->s);
            tmp = tmp->next;
        }
        tml = tml->next;
    }

    return 0;
}
