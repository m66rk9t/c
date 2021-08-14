/*varargs.c -- 使用可变参数*/
#include <stdio.h>
#include <stdarg.h>//提供va_list定义以及va_start()、va_arg()、va_end()宏
double sum(int, ...);//可变参数函数原型

int main(void)
{
    double s,t;
    
    s = sum(3, 1.1, 2.5, 13.3);
    t = sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1);
    printf("return value for "
           "sum(3, 1.1, 2.5, 13.3):                %g\n", s);
    printf("return value for "
           "sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1): %g\n", t);
    
    return 0;
}

/*可变参数函数定义*/
double sum(int lim,...)
{
    va_list ap;                    //声明一个va_list对象用于储存可变参数
    double tot = 0;
    int i;
    
    va_start(ap, lim);             //初始化va_list对象为参数列表
    for (i = 0; i < lim; i++)
        tot += va_arg(ap, double); //访问参数列表中的每一项
    va_end(ap);                    //释放储存参数列表的对象占用的内存
    
    return tot;
}
