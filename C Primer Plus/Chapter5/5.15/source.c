/*while迭代求平方和*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int i=1;
    int input;
    long sum=1;

    printf("Please enter an integer number:\n");
    scanf("%d",&input);
    while(i++<input)
    {
        sum=sum+i*i;
    }
    printf("The sum of square of 1~%d is %ld.\n",input,sum);

    system("pause");
    return 0;
}