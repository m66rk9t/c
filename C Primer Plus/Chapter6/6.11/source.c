/*for嵌套循环打印图案2*/
#include<stdio.h>
#include<stdlib.h>
#define ROW 5
int main(void)
{
    int row,column;

    for (row = 0; row < ROW; row++)
    {
        for (column = 0; column <= row; column++)
        {
            printf("$");
        }
        printf("\n");
    }
    
    system("pause");
    return 0;
}