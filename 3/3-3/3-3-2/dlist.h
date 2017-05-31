#ifndef _DLIST_NODE
typedef struct DNode{
    char *s;
    struct DNode *next;
    struct DNode *prev;
}DNode, * PDNode;

PDNode create(char *s);
void insert(char *s,PDNode );
void printDlist(PDNode);
#endif // _DLIST_NODE
