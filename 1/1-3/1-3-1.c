#include <stdio.h>

void PrintDigit(double , int);

int main(int argc, char **argv)
{

    PrintDigit(12.123456,7);
    putchar('\n');

    return 0;
}

void PrintDigit(double num, int len)
{
    if(num < 0){
        num = -num;
        putchar('-');
    }
    int n = (int) num;
    int i=0;
    printf("%d",n);

    num = num - n;
    while(num > 0 && i < len){
        if (i == 0){
            // 由于double小数存储方式并非确定值，而是一个近似值所以采用这种方式
            double add = 0.5;
            int j;
            for (j=0; j<len; j++) {
                add /= 10;
            }
            num+=add;
            putchar('.');
        }
        num = num * 10;
        n = (int) (num);
        printf("%d",n);
        num = num - n;
        i++;
    }

}

