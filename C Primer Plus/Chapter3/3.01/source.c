/*输入ASCII值，输出对应的字符*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int ch;
    printf("Please enter an interger number\n");
    scanf("%d",&ch);
    printf("The character for %d is %c\n",ch,ch);

    system("pause");
    return 0;
}