/* enum.c -- 使用枚举类型的值 */
#include <stdio.h>
#include <string.h>            //提供strcmp()和strchr()原型
#include <stdbool.h>           //提供bool类型
char *s_gets(char *st, int n); //读取输入字符串的函数原型

enum spectrum
{
    red,
    orange,
    yellow,
    green,
    blue,
    violet
}; //枚举声明
const char *colors[] = {"red", "orange", "yellow",
                        "green", "blue", "violet"}; //只读字符串数组
#define LEN 30                                      //字符串长度上限+1

int main(void)
{
    char choice[LEN];            //储存输入的字符串
    enum spectrum color;         //声明枚举变量
    bool color_is_found = false; //声明布尔变量

    puts("Enter a color (empty line to quit):");
    while (s_gets(choice, LEN) != NULL && choice[0] != '\0')
    {
        for (color = red; color <= violet; color++)
        {
            /*将读取的字符串同字符数组中的元素比较*/
            if (strcmp(choice, colors[color]) == 0)
            {
                color_is_found = true;
                break;
            }
        }
        /*找到该字符串就进行匹配*/
        if (color_is_found)
            switch (color)
            {
            case red:
                puts("Roses are red.");
                break;
            case orange:
                puts("Poppies are orange.");
                break;
            case yellow:
                puts("Sunflowers are yellow.");
                break;
            case green:
                puts("Grass is green.");
                break;
            case blue:
                puts("Bluebells are blue.");
                break;
            case violet:
                puts("Violets are violet.");
                break;
            }
        else
            printf("I don't know about the color %s.\n", choice);
        color_is_found = false; //每次迭代都要重新设置bool值
        puts("Next color, please (empty line to quit):");
    }
    puts("Goodbye!");

    return 0;
}

/*读取输入字符串的函数定义*/
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // 查找换行符
        if (find)                // 如果地址不是 NULL，
            *find = '\0';        // 在此处放置一个空字符
        else
            while (getchar() != '\n')
                continue; // 处理输入行中剩余的字符
    }
    return ret_val;
}