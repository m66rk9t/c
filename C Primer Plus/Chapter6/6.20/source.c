/*取钱问题*/
#include<stdio.h>
#include<stdlib.h>
#define RATE 8.0/100.0
int main(void)
{
    int year=0;
    double account=1000000.0;
    for(;account>=0;year++)
    {
        account*=(RATE+1);
        account-=100000.0;
    }
    printf("After %d years, Chuckie Lucky can withdraw the money in the account.\n",year);

    system("pause");
    return 0;
}