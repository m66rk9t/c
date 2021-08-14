/* preproc.c -- 简单的预处理示例 */
#include <stdio.h>
#define TWO 2        /*类对象宏，可以在预处理指令后面使用注释*/
#define OW "Consistency is the last refuge of the unimagina\
tive. - Oscar Wilde" /*类对象宏，反斜杠把该定义延续到下一行*/
#define FOUR  TWO*TWO/*类对象宏，嵌套宏*/
#define PX printf("X is %d.\n", x)/*类函数宏*/
#define FMT  "X is %d.\n"

int main(void)
{
    int x = TWO;
    
    PX;
    x = FOUR;
    printf(FMT, x);
    printf("%s\n", OW);
    printf("TWO: OW\n");
    
    return 0;
}
