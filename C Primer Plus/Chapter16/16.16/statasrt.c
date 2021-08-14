/*statasrt.c -- 使用_Static_assert声明*/
#include <stdio.h>
#include <limits.h>//提供CHAR_BIT定义
_Static_assert(CHAR_BIT == 16, "16-bit char falsely assumed");
int main(void)
{
    puts("char is 16 bits.");
    return 0;
}
