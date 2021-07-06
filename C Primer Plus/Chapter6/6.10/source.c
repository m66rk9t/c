/*for嵌套循环打印图案1*/
#include<stdio.h>
#include<stdlib.h>
#define ROW 4
#define COLUMN 8
int main(void)
{
    int row,column;

    for (row = 0; row < ROW; row++)
    {
        for (column = 0; column < COLUMN; column++)
        {
            printf("$");
        }
        printf("\n");
    }
    
    system("pause");
    return 0;
}