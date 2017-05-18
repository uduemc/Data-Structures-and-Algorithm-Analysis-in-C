#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct has{
    char *name;
    struct has * next;
};

struct has * hasharr[101];

unsigned hash(char *s)
{
    unsigned hashval;
    for(hashval = 0; *s != '\0'; s++){
        hashval = *s + 31*hashval;
    }
    return hashval % 101;
}

int isHashHas(struct has *p, char *s)
{
    if(p != NULL){
        if(strcmp(p->name, s) == 0){
            return 1;
        }
        if(p->next != NULL){
            return isHashHas(p->next, s);
        }
    }
    return 0;
}

int hashArrayFind(char *s)
{
    struct has *p = hasharr[hash(s)];
    if(p == NULL)
        return 0;
    return isHashHas(p, s);
}

void hashAdd(char *s)
{
    int i = hash(s);
    if(hasharr[i] == NULL){
        hasharr[i] = malloc(sizeof(struct has));
        hasharr[i]->name = malloc(sizeof(char)*strlen(s));

        if(hasharr[i]->name == NULL || hasharr[i] == NULL){
            printf("malloc error: %s",s);
            exit(1);
        }
        strcpy(hasharr[i]->name, s);
        hasharr[i]->next = NULL;
    }else{
        hashAdd(s);
    }
}

void freeHash(struct has *p)
{
    if(p->next != NULL){
        freeHash(p->next);
    }
    free(p->name);
    free(p);
}

void clear()
{
    int i,len = 101;
    for(i=0;i<len;i++){
        if(hasharr[i] == NULL)
            continue;
        freeHash(hasharr[i]);
        hasharr[i]= NULL;
    }
}

void printh(struct has *p)
{
    if(p == NULL)
        return ;

    printf("%s\n",p->name);
    printh(p->next);
}

void printHash()
{
    int i,len = 101;
    for(i=0;i<len;i++){
        if(hasharr[i] == NULL)
            continue;
        printh(hasharr[i]);
    }
}

int main(int argc, char **argv)
{
    // 通过fopen打开文件 #include filename 获取文件名字的方式略
    // 定义如下数组
    char *file1[3] = {
        "file",
        "file2",
        "file3",
    };
    char *file2[3] = {
        "file",
        "file1",
        "file3",
    };
    char *file3[3] = {
        "file",
        "file1",
        "file2",
    };

    int i;

    for(i=0;i<3;i++){
        if(hashArrayFind(file1[i]) == 0)
            hashAdd(file1[i]);

        if(hashArrayFind(file2[i]) == 0)
            hashAdd(file2[i]);

        if(hashArrayFind(file3[i]) == 0)
            hashAdd(file3[i]);
    }

    printHash();
    clear();
    return 0;
}


/**
提供如下类型的语句

    #include filename

它读入文件filename并插入到include语句处。include语句可以嵌套，换句话说，文件filename还可以包含include语句。
但是显然一个文件在任何链接中都不能包含它自己。编写一个程序，使它读入被include语句修饰的一个文件并输出这个文件。

首先先到的就是使用递归来进入一个个获取文件中的内容，但是会存在重复进入相同的文件情况，所以需要有一个东西存储
已经执行过的文件名字。第一个想到的是 hash 。
*/
