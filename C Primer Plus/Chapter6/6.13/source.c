/*for嵌套循环打印图案4*/
#include<stdio.h>
#include<stdlib.h>
#define ROW 6
int main(void)
{
    int row,column;
    char ch='A';
    for(row=0;row<ROW;row++)
    {
        for(column=0;column<=row;ch++,column++)
        {
            printf("%c",ch);
        }
        printf("\n");
    }

    system("pause");
    return 0;
}