/*加减乘除求于计算器*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
char showmenu(void);                      //显示菜单的函数原型
void eatline(void);                       //清理输入行的函数原型
void addtion(int, int);                   //加法
void subtraction(int, int);               //减法
void multiplication(int, int);            //乘法
void division(int, int);                  //除法
void calculator(void (*pfun)(int first, int second), int, int);

int main(void)
{
    char choice;
    void (*pfun)(int, int);
    int first, second;
    puts("Enter a string (empty line to quit):");

    while ((choice = showmenu()) != 'e')
    {
        switch (choice)
        {
            case 'a':pfun = addtion;break;
            case 'b':pfun = subtraction;break;
            case 'c':pfun = multiplication;break;
            case 'd':pfun = division;break;
        }
        printf("Please enter the first  integer:");
        scanf(" %d", &first);
        printf("Please enter the second integer:");
        scanf(" %d", &second);
        eatline();
        calculator(pfun, first, second);
    }
    puts("Bye!");

    return 0;
}

/*显示菜单的函数定义*/
char showmenu(void)
{
    char ans; //储存菜单选项字符

    /*打印菜单*/
    puts("Enter menu choice:");
    puts("a) addition       b) subtraction");
    puts("c) multiplication d) division");
    puts("e) quit");

    ans = getchar();    //读取输入的选项字符
    ans = tolower(ans); //转换成小写字母
    eatline();          //清理输入行

    /*判断是否输入了错误选项*/
    while (strchr("abcde", ans) == NULL)
    {
        puts("Please enter a, b, c, d, or e:"); //提示错误
        ans = tolower(getchar());                 //重新读取输入
        eatline();                                //清理输入行
    }

    return ans; //返回选项字符
}

/*清理输入行的函数定义*/
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}
void addtion(int first, int second)
{
    printf("%d + %d = %d\n", first, second, first + second);
}

void subtraction(int first, int second)
{
    printf("%d - %d = %d\n", first, second, first - second);
}

void multiplication(int first, int second)
{
    printf("%d * %d = %d\n", first, second, first * second);
}

void division(int first, int second)
{
    printf("%d / %d = %d ... %d\n", first, second, first / second, first % second);
}

void calculator(void (*pfun)(int first, int second), int first, int second)
{
    (*pfun)(first, second);
}