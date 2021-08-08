#include <stdio.h>
#include <limits.h>
const static unsigned int MASK = 2147483648UL;
void show_bstr(unsigned int);
unsigned int bitrotate(unsigned int, int);

int main(void)
{
    unsigned int input, result;
    int position;
    char str1[CHAR_BIT * sizeof(unsigned int) + 1];
    char str2[CHAR_BIT * sizeof(unsigned int) + 1];
    printf("Please enter an unsigned integer(\'q\' to quit):");
    while (scanf("%lu", &input) == 1)
    {
        printf("Now enter a position:");
        scanf("%d", &position);
        result = bitrotate(input, position);
        printf("Your input is %lu:\n", input);
        show_bstr(input);
        printf("After rotating is %lu:\n", result);
        show_bstr(result);
        printf("Now enter the next integer(\'q\' to quit):");
    }
    puts("Done!");

    return 0;
}

unsigned int bitrotate(unsigned int para, int pos)
{
    unsigned int is_open = 0UL;
    for (int i = 0; i < pos; i++)
    {
        is_open = para & MASK;
        para <<= 1;
        if (is_open == MASK)
            para |= 1UL;
    }

    return para;
}

/*输出二进制字符*/
void show_bstr(unsigned int para)
{
    unsigned int count = CHAR_BIT * sizeof(unsigned int);

    for (int i = 0; i < count; i++, para <<= 1)
    {
        if (i != 0 && i % 4 == 0)
            putchar(' ');
        if ((para & MASK) == MASK)
            putchar('1');
        else
            putchar('0');
    }
    putchar('\n');
}