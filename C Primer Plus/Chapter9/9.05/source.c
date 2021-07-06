/*按指定的行列打印字符*/
#include<stdio.h>
#include<stdlib.h>
void chline(char chara, int row, int column);                   /*函数原型*/
int main(void)
{
    char ch;                                                    /*待打印的字符*/
    int row,column;                                             /*待打印的行数和列数*/

    printf("Please enter a character and two integers,\n");     /*文字说明*/
    printf("Press Ctrl+Z to quit:\n");                          /*文字说明*/
    while(scanf("%c",&ch)!=-1)                                  /*重复输入指导遇到文件结尾结束循环*/
    {
        if(scanf("%d %d",&row,&column)!=2)                      /*如果输入的不是两个数就结束循环*/
            break;
        chline(ch,row,column);                                  /*函数表达式语句*/
        while (getchar()!='\n')                                 /*跳过无用字符*/
            continue;
        /*文字说明*/
        printf("Now enter another character and two integers,\n");
        printf("Press enter to quit:\n");
    }
    printf("Done!\n");

    system("pause");
    return 0;
}

void chline(char chara, int row, int column)                    /*函数定义*/
{
    for (int r = 0; r < row; r++)                               /*外层循环控制行数*/
    {
        for (int c = 0; c < column; c++)                        /*内层循环控制列数*/
        {
            putchar(chara);                                     /*打印指定字符*/
        }
        putchar('\n');                                          /*打印完一行打印换行符开始新行*/
    }
}