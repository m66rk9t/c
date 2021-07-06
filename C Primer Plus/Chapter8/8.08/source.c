/*加减乘除菜单*/
#include<stdio.h>
#include<stdlib.h>
void Show_Menu(void);   //函数原型，显示菜单
char Get_Choice(void);  //函数原型，选择选项
float Get_Num(void);    //函数原型，读取浮点值
void Add(void);         //函数原型，加法求和
void Subtract(void);    //函数原型，减法求差
void Multiply(void);    //函数原型，乘法求积
void Divide(void);      //函数原型，除法求商
int main(void)
{
    char  choice;           //待选择选项

    Show_Menu();            //函数表达式语句，调用显示菜单函数
    while ((choice=Get_Choice())!='q')
    {
        switch (choice)
        {
            case 'a':
                Add();
                break;
            case 's':
                Subtract();
                break;
            case 'm':
                Multiply();
                break;
            case 'd':
                Divide();
                break;
            default:
                printf("Wrong input!Please respond with a, s, m, d or q.\n");
                break;
        }
        Show_Menu();
    }
    printf("Done!\n");

    system("pause");
    return 0;
}

/*显示菜单*/
void Show_Menu(void)
{
    printf("Enter the operation of your choice:\n");
    printf("a. add\t\ts. subtract\n");
    printf("m. multiply\td. divide\n");
    printf("q.quit\n");
}

/*选择选项*/
char Get_Choice(void)
{
    char input=getchar();

    /*丢弃无效字符*/
    while (getchar()!='\n')
        continue;

    return input;
}

/*读取float类型数值*/
float Get_Num(void)
{
    float input;
    char ch;
    while (scanf("%f",&input)!=1)   //处理错误输入
    {
        while ((ch=getchar())!='\n')
            putchar(ch);
        printf(" is not a floating-point number, please enter again:");
    }

    while ((ch=getchar())!='\n')    //丢弃无效字符
        continue;
    return input;
}

/*加法求和*/
void Add(void)
{
    float lvalue,rvalue;    //左值、右值
    float result=0.0;       //求值结果
    printf("Enter left  value:");
    lvalue=Get_Num();
    printf("Enter right value:");
    rvalue=Get_Num();
    printf("%f + %f = %f\n",lvalue,rvalue,lvalue+rvalue);
}

/*减法求差*/
void Subtract(void)
{
    float lvalue,rvalue;    //左值、右值
    float result=0.0;       //求值结果
    printf("Enter left  value:");
    lvalue=Get_Num();
    printf("Enter right value:");
    rvalue=Get_Num();
    printf("%f - %f = %f\n",lvalue,rvalue,lvalue-rvalue);
}

/*乘法求积*/
void Multiply(void)
{
    float lvalue,rvalue;    //左值、右值
    float result=0.0;       //求值结果
    printf("Enter left  value:");
    lvalue=Get_Num();
    printf("Enter right value:");
    rvalue=Get_Num();
    printf("%f x %f = %f\n",lvalue,rvalue,lvalue*rvalue);
}

/*除法求商*/
void Divide(void)
{
    float lvalue,rvalue;    //左值、右值
    float result=0.0;       //求值结果
    printf("Enter left  value:");
    lvalue=Get_Num();
    printf("Enter right value:");
    while ((rvalue=Get_Num())==0)
    {
        printf("Please enter a number other than 0:");
    }
    printf("%f / %f = %f\n",lvalue,rvalue,lvalue/rvalue);
}