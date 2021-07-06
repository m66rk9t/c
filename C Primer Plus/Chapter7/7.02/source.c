/*判断素数*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main(void)
{
    unsigned long num;  //待测试的数
    unsigned long div;  //可能的约数
    bool isPrime;       //标记变量

    printf("Please enter an integer number for analysis(enter 'q' to quit):\n");
    while(scanf("%lu",&num)==1)
    {
        for(div=2,isPrime=true;(div*div)<=num;div++)
        {
            if(num%div==0)  //求公约数
            {
                if ((div*div)!=num)
                {
                    printf("%lu is divisible by %lu and &lu.\n",num,div,num/div);
                }
                else
                {
                    printf("%lu is divisible by &lu.\n",num,div);
                }     
                isPrime=false;  //标记设为false，不是素数
            }
        }

        if (isPrime)    //判断是否为素数
        {
            printf("%lu is prime.\n",num);
        }    
        else
        {
            printf("%lu is not prime.\n",num);
        }            
        printf("Please enter another integer number for analysis(enter 'q' to quit):\n");
    }
    printf("Done!\n");

    system("pause");
    return 0;
}