#include <stdio.h>
#include <time.h> //提供clock()原型以及clock_t、CLOCK_PER_SEC定义
void loopinsec(double);

int main(void)
{
    clock_t first, second;
    double delay = 0.0;//延时

    first = clock();//第一次调用
    second = clock();//第二次调用
    printf("%ld\n", first);
    printf("%ld\n", second);
    delay = (double)(second-first);//计算延时
    loopinsec(delay);

    return 0;
}

/*在延时秒数内进行循环，一秒一循环*/
void loopinsec(double sec)
{
    unsigned long int count = (unsigned long)sec;
    for (unsigned long int i = 0; i < sec; i++)
    {
        printf("LOOP %d\n", i+1);
    }
    
}