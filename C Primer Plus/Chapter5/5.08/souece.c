/*完成副作用1*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int x=0,a=1,b=2,c;

    printf("x=%d\n",x);
    x=x+10;
    printf("x+10=%d\n",x);
    x++;    //++x
    printf("after x++,x=%d\n",x);
    c=2*(a+b);
    printf("c=%d\n",c);
    c=2*a+2*b;
    printf("c=%d\n",c);

    system("pause");
    return 0;
}