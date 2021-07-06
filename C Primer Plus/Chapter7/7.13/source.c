/*找素数升级版
在大于1的自然数中，除了1和它本身以外不再有其他因数的自然数*/
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    unsigned int input;
    int prime,i;
    bool isPrime;   //true为素数，false不是素数

    printf("Please enter a positive integer:\n");
    scanf("%u",&input);
    printf("The prime numbers less than or equal to %u have:\n",input);
    for(prime=2;prime<=input;prime++)   //外层循环更新控制变量为小于等于输入的数内的所有正整数
    {
        for(i=2,isPrime=true;i<prime;i++)  //判断是否为素数
        {
            if(prime%i==0)  //成立，有约数，不是素数
            {
                isPrime=false;  //标记为false
            }
        }
        if(isPrime) //isPrime为true则为素数
            printf("%d ",prime);
    }
    printf("\nDone!\n");

    system("pause");
    return 0;
}