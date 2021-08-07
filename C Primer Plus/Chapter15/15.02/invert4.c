/* invert4.c -- 使用位操作显示二进制 */
#include <stdio.h>
#include <limits.h> //提供CHAR_BIT定义，CHAR_BIT表示每字节的位数
char * itobs(int, char *);//将十进制数转换成二进制字符串并储存到数组中
void show_bstr(const char *);//显示转换后的二进制字符串
int invert_end(int num, int bits);//切换指定位

int main(void)
{
    char bin_str[CHAR_BIT * sizeof(int) + 1];//储存二进制位字符
    
    int number;//输入的数
    
    puts("Enter integers and see them in binary.");
    puts("Non-numeric input terminates program.");
    while (scanf("%d", &number) == 1)
    {
        itobs(number,bin_str);
        printf("%d is\n", number);
        show_bstr(bin_str);
        putchar('\n');
        number = invert_end(number, 4);
        printf("Inverting the last 4 bits gives\n");
        show_bstr(itobs(number,bin_str));
        putchar('\n');
    }
    puts("Bye!");
    
    return 0;
}

/*将十进制数转换成二进制字符串并储存到数组*/
char * itobs(int n, char * ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);//只读静态无链接变量

    
    /*每次循环都将一个二进制字符放入数组的指定元素*/
    /*每次循环都会更新n的值，使n中的所有位向右移动1个位置*/
    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0'; //0+'0'或1+'0'，结果要么是48要么是49，分别对应字符'0'和'1'
    ps[size] = '\0';//最后一个元素是'\0'
    
    return ps;
}

/*示转换后的二进制字符串*/
void show_bstr(const char * str)
{
    int i = 0;

	/*不是空字符时进行循环*/
    while (str[i])
    {
        /*每4个字符输出一个空格*/
        putchar(str[i]);
        if(++i % 4 == 0 && str[i])
            putchar(' ');
    }
}

/*切换指定位*/
int invert_end(int num, int bits)
{
    int mask = 0;
    int bitval = 1;
    
    /*按指定位创建掩码*/
    while (bits-- > 0)
    {
        mask |= bitval;
        bitval <<= 1;
    }
    
    return num ^ mask;
}
