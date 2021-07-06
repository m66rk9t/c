/*整数溢出*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int x = 2147483647;
    unsigned int y = 4294967295;

    //打印
    printf("%d  %d  %d\n",x,x+1,x+2);
    printf("%u  %u  %u\n",y,y+1,y+2);

    system("pause");
    return 0;
}