/*使用转移序列*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    float salary;
    printf("Please enter your desired monthly salary:");
    printf("$_______\b\b\b\b\b\b\b");
    scanf("%f",&salary);    /*Enter键使光标移至下一行起始处*/
    printf("\t$%.2f a month is $%.2f a year.",salary,salary*12.0);
    printf("\rWoo!\n");

    system("pause");
    return 0;
}