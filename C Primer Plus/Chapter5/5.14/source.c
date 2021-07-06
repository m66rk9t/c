/*while迭代求和*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int i=1,sum=1;
    int input;
    
    printf("Please enter an integer number:\n");
    scanf("%d",&input);
    while(i++<input)
    {
        sum=sum+i;
    }
    printf("The sum of 1~%d is %d.\n",input,sum);

    system("pause");
    return 0;
}