#ifndef _LIST_L1
typedef struct NodeP{
    int x;
    struct NodeP * next;
}NodeP, *PNodeP;

typedef struct NodeL{
    char *s;
    struct NodeL * next;
}NodeL, *PNodeL;



PNodeP pCreate(int i);
void pInsert(int i, PNodeP L);

PNodeL lCreate(char *s);
void lInsert(char *s, PNodeL L);

#endif // _LIST_L1
