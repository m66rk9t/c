/*for嵌套循环打印图案5*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int row;
    char ch;
    char ch_A='A';
    
    printf("Please enter a letter:");
    scanf("%c",&ch);

    for(row=0;row<=ch-'A';row++)
    {
        //打印空格
        int ch_space;      
        for(ch_space=0;ch_space<(ch-'A')-row;ch_space++)
        {
            printf(" ");
        }

        char ASC_DESC;
        //升序打印字母       
        for(ASC_DESC='A';ASC_DESC<=ch_A+row;ASC_DESC++)
        {
            printf("%c",ASC_DESC);
        }
        //降序打印字母
        for(ASC_DESC-=2;ASC_DESC>='A';ASC_DESC--)
        {
            printf("%c",ASC_DESC);
        }
        printf("\n");
    }

    system("pause");
    return 0;
}