/*简单的菜单程序*/
#include<stdio.h>
#include<stdlib.h>
char Get_Choice(void);  //函数原型，显示菜单选择选项
char Get_First(void);   //函数原型，读取输入的第一个字符
void Count(void);       //函数原型，用于打印0~输入的数字内的所有整数
int Get_Int(void);      //函数原型，读取一个整型数值
int main(void)
{
    char choice;

    while((choice=Get_Choice())!='q')
    {
        switch (choice)
        {
            case 'a':
                printf("Buy low, sell high.\n");
                break;
            case 'b':
                printf("\b");   //打印退格
                break;
            case 'c':
                Count();
                break;
            default:
                printf("Program error!\n");
                break;
        }
    }
    printf("Done!\n");

    system("pause");
    return 0;
}

/*显示菜单，选择选项*/
char Get_Choice(void)
{
    char input;

    printf("Enter the letter of your choice:\n");
    printf("a. advice\t\tb. bell\n");
    printf("c. count\t\tq. quit\n");
    input=Get_First();
    while ((input<'a'||input>'c')&&input!='q')
    {
        printf("Please respond with a, b, c or q.\n");
        input=Get_First();
    }
    
    return input;
}

/*读取输入行中的第一个字符，丢弃剩余字符*/
char Get_First(void)
{
    char input;
    
    input=getchar();    //读取要返回的输入行中的第一个字符
    while (getchar()!='\n')    //丢弃剩余无效字符
        continue;
    
    return input;
}

/*打印0~输入整形数值内所有整数*/
void Count(void)
{
    int input;

    printf("Count how far?Enter an integer:");
    input=Get_Int();    //读取一个整形数值
    /*for循环打印0~输入整形数值内所有整数*/
    for (int i = 0; i <= input; i++)
        printf("%d\n",i);
    while(getchar()!='\n')  //丢弃剩余无效字符
        continue;
}

/*读取一个整形值*/
int Get_Int(void)
{
    int input;
    char ch;

    /*处理错误输入*/
    while(scanf("%d",&input)!=1)
    {
        while((ch=getchar())!='\n')
            putchar(ch);
        printf(" is not an integer,please enter an integer:");
    }

    return input;
}