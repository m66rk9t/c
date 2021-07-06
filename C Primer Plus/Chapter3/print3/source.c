/*打印unsigned、short、long、long long类型的值*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    unsigned int uni = 3000000000U;
    short sht = 200;
    long ln = 65537L;
    long long lnln =12345678909874LL;

    //打印
    printf("un = %u\n",uni);
    printf("sht = %hd\n",sht);
    printf("ln = %ld\n",ln);
    printf("lnln = %lld\n",lnln);

    system("pause");
    return 0;
}