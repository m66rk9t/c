/* binbit.c -- 使用位操作显示二进制 */
#include <stdio.h>
#include <limits.h> //提供CHAR_BIT定义，CHAR_BIT表示每字节的位数
char *itobs(int, char *);
void show_bstr(const char *);

int main(void)
{
    char bin_str[CHAR_BIT * sizeof(int) + 1]; //储存二进制位字符
    int number;                               //输入的数

    puts("Enter integers and see them in binary.");
    puts("Non-numeric input terminates program.");
    while (scanf("%d", &number) == 1)
    {
        itobs(number, bin_str);
        printf("%d is ", number);
        show_bstr(bin_str);
        putchar('\n');
    }
    puts("Bye!");

    return 0;
}

/*将整数转换成二进制字符*/
char *itobs(int n, char *ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int); //只读静态无链接变量

    /*每次循环都将一个二进制字符放入数组的指定元素*/
    /*每次循环都会更新n的值，使n中的所有位向右移动1个位置*/
    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0'; //0+'0'或1+'0'，结果要么是48要么是49，分别对应字符'0'和'1'
    ps[size] = '\0';            //最后一个元素是'\0'

    return ps;
}

/*输出二进制字符*/
void show_bstr(const char *str)
{
    int i = 0;

    /*不是空字符时进行循环*/
    while (str[i])
    {
        putchar(str[i]);
        /*每4个字符输出一个空格*/
        if (++i % 4 == 0 && str[i])
            putchar(' ');
    }
}
