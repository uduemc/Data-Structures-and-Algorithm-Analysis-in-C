#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char puzzle[4][4] = {
    {'t','h','i','s'},
    {'w','a','t','s'},
    {'o','a','h','g'},
    {'f','g','g','t'}
};

char *dict[4] = {"this","two","fat","that"};

int wordExist(int x, int y, int dir, int strlen, char *word, int (*position)[2]);

int main(void)
{
    char word[5];
    int position[4][2];
    int x, y, dir, strlen;

    for(x=0;x<4;x++){
        for(y=0;y<4;y++){
            for(dir=0;dir<8;dir++){
                for(strlen=2;strlen<5;strlen++){
                    // ���� x y
                    // ���� dir
                    // ���ʳ��ȴ�2��ʼ
                    if(wordExist(x, y, dir, strlen, word, position) == 1){
                        printf("word: %s\n",word);
                        break;
                    }
                }
            }
        }
    }

    return 0;
}

int wordExist(int x, int y, int dir, int strlen, char *word, int position[][2])
{
    char sword[5];
    int i = 0, j;
    while(i < strlen){
        position[i][0] = x;
        position[i][1] = y;
        sword[i++] = puzzle[x][y];
        sword[i] = '\0';
        for(j=0;j<4;j++){
            if(strcmp(sword,dict[j]) == 0){
                strcpy(word,dict[j]);
                return 1;
            }
        }

        switch (dir){
            case 0:        //������
                y++;
                break;
            case 1:        //���ҵ���
                y--;
                break;
            case 2:        //���ϵ���
                x++;
                break;
            case 3:        //���µ���
                x--;
                break;
            case 4:        //�����ϵ�����
                x++;
                y++;
                break;
            case 5:        //�����µ�����
                x--;
                y--;
                break;
            case 6:        //�����µ�����
                x--;
                y++;
                break;
            case 7:        //�����ϵ�����
                x++;
                y--;
                break;
            default:
                puts("Direction error.");
                return 0;
         }
         if(x < 0 || y < 0)
            return 0;
    }
    return 0;
}
