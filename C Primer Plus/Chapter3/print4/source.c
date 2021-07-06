/*打印特殊字符*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char a,b,c,d,e,f,g;
    a='"';      //普通字符
    b=34;       //ASCII码值
    c='\"';     //转义序列
    d='\042';   //转义序列八进制ASCII码值
    e='\x22';   //转义序列十六进制ASCII码值
    f=042;      //八进制值
    g=0x22;     //十六进制值

    //打印
    printf("%c\n",a);
    printf("%c\n",b);
    printf("%c\n",c);
    printf("%c\n",d);
    printf("%c\n",e);
    printf("%c\n",f);
    printf("%c\n",g);

    system("pause");
    return 0;
}