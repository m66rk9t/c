/*输入一个数打印从该数到比该数大10的所有数*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int input;

    printf("Please enter an integer nubmer:\n");
    scanf("%d",&input);
    const int i=input+10;
    while(input<=i)
    {
        printf("%d ",input);
        input++;
    }
    printf("\n");

    system("pause");
    return 0;
}