#include<stdio.h>
static int count=0;/*静态内部链接变量*/
int ct_call(void);/*函数原型*/
int main(void)
{
    int ct,input;
    printf("Please enter some integers \
(press Ctrl+Z on a new line to quit):\n");
    while(scanf("%d",&input)!=EOF)
        ct=ct_call();
    printf("ct_call() was called %d times.\n",ct);

    return 0;
}

int ct_call(void)/*函数定义*/
{
    return ++count;
}