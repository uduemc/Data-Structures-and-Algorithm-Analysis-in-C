#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXINT 10240

void s_sort(int *, int);
void i_sort(int *, int);

int main()
{
    int i,N,nu[MAXINT+1],nu2[MAXINT+1];
    clock_t start;
    srand (110) ;
    for(i=0;i<MAXINT+1;++i)
        nu2[i] = nu[i] = rand();
    N = MAXINT/2;

    start = clock();

    s_sort(nu, MAXINT+1);
    printf("----------------------------------\n");
    printf("| k: %-8d| time: %-12f|\n",nu[N], (double)(clock()-start));

    start = clock();

    i_sort(nu2, MAXINT+1);
    printf("----------------------------------\n");
    printf("| k: %-8d| time: %-12f|\n",nu2[N], (double)(clock()-start));
    printf("----------------------------------\n");

    return 0;
}

void i_sort(int num[], int len)
{
    int i,j,tmp;
    for(i=1;i<len;i++){
        tmp = num[i];
        for(j=i-1;j>=0;j--){
            if(num[j]<tmp)
                num[j+1] = num[j];
            else
                break;
        }
        num[j+1] = tmp;
    }
}

void s_sort(int num[], int len)
{
    int i,j;
    int tmp;
    for(i=0;i<len-1;i++){
        for(j=i;j<len;j++){
            if(num[i]<num[j]){
                tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
        }
    }
}
