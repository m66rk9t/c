/*ifdef.c -- 使用条件编译*/
#include <stdio.h>
#define JUST_CHECKING //空宏
#define LIMIT 4       //类对象宏

int main(void)
{
    int i;
    int total = 0;

    for (i = 1; i <= LIMIT; i++)
    {
        total += 2 * i * i + 1;
#ifdef JUST_CHECKING //如果定义了JUST_CHECKING，就执行下面这行代码
        printf("i=%d, running total = %d\n", i, total);
#endif //结束标记
    }
    printf("Grand total = %d\n", total);

    return 0;
}
