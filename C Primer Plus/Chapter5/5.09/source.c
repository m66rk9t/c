/*完成副作用2*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int x=5,n=10,k=4,m;
    int a=10,b=12,c=4,d=5,q=100,p;
    printf("x=%d,n=%d,k=%d\n",x,n,k);
    printf("a=%d,b=%d,c=%d,d=%d,q=%d\n",a,b,c,d,q);
    x--;    //--x、x=x-1、x-=1
    printf("Now x is %d\n",x);
    m=n%k;
    printf("Now m is %d\n",m);
    p=q/(b-a);
    printf("Now p is %d\n",p);
    x=(a+b)/(c*d);
    printf("Now x is %d\n",x);
    
    system("pause");
    return 0;
}