/*按指定的行列打印字符*/
#include<stdio.h>
#include<stdlib.h>
void Display(char ch, int row, int column);  //按指定行列打印字符的函数原型
int main(void)
{
    char ch;
    int row,column;

    printf("Please enter a character and two integers,\n");
    printf("Press enter to quit:\n");
    while((ch=getchar())!='\n')
    {
        if(scanf("%d %d",&row,&column)!=2)
            break;
        Display(ch,row,column); //函数表达式语句
        while (getchar()!='\n') //跳过无用字符
            continue;
        printf("Now enter another character and two integers,\n");
        printf("Press enter to quit:\n");
    }
    printf("Done!\n");

    system("pause");
    return 0;
}

void Display(char ch, int row, int column)  //按指定行列打印字符的函数
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            putchar(ch);
        }
        putchar('\n');
    }

}