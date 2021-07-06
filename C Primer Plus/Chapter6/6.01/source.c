/*输入整数求和，通过scanf()函数判断真假*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    long input,sum=0;

    printf("Please enter an integer number:");
    while(scanf("%ld",&input)==1)
    {
        sum+=input;
        printf("Please enter an integer number(enter 'q' to quit):");
    }
    printf("Done! The sum of the integers entered is %ld.\n",sum);

    system("pause");
    return 0;
}