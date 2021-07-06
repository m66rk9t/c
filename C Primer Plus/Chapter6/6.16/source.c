/*倒序打印单词*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char word[5];
    int i;
    printf("Please enter a word:");
    //读入单词
    for(i=0;i<5;i++)
    {
        scanf("%c",&word[i]);
    }
    //倒序打印
    printf("Reverse output:");
    for(i=4;i>=0;i--)
    {
        printf("%c",word[i]);
    }
    printf("\nDone!\n");

    system("pause");
    return 0;
}