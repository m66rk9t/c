/*for嵌套循环打印7行"ABCDEFG"*/
#include<stdio.h>
#include<stdlib.h>
#define ROW 7
#define COLUMN 'G'
int main(void)
{
    int row=1;
    char ch;

    for(;row<=ROW;row++)
    {
        for(ch='A';ch<=COLUMN;ch++)
        {
            printf("%c",ch);
        }
        printf("\n");
    }
    printf("Done!\n");

    system("pause");
    return 0;
}