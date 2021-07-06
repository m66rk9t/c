/*输入验证程序示例*/
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
/*函数原型，验证输入*/
long Get_Num(void);
/*函数原型，验证极限*/
bool Verify_Limits(long begin, long end, long low, long high);
/*函数原型，求平方和*/
double Square_Nums(long begin, long end);
int main(void)
{
    const long MIN=-10000000L;  //最小极限
    const long MAX=+10000000L;  //最大极限
    long begin,end;             //用户指定的最小值和最大值
    double result;                //求值结果

    printf("Please enter a range, which must be within the specified range.\n");
    printf("Min:%+ld\nMax:%+ld\n",MIN,MAX);
    printf("Please enter the limits(enter 0 for both to quit):\n");
    printf("Lower limit:");
    begin=Get_Num();
    printf("Higher limit:");
    end=Get_Num();
    while(begin!=0||end!=0)
    {
        if(Verify_Limits(begin,end,MIN,MAX))
            printf("Please try again!\n");
        else
        {
            result=Square_Nums(begin,end);
            printf("The sum of the squares of %ld to %ld is %f\n",begin,end,result);
        }
        printf("Enter the limits(enter 0 for both to quit):\n");
        printf("Lower limit:");
        begin=Get_Num();
        printf("Higher limit:");
        end=Get_Num();
    }
    printf("Done!\n");

    system("pause");
    return 0;
}

//该函数用于验证输入的内容是否为整数
long Get_Num(void)
{
    long input;
    char ch;

    while (scanf("%ld",&input)!=1)  //读取内容不是整数时进入外层循环
    {
        while ((ch=getchar())!='\n')    //跳过空格和换行符
            putchar(ch);
        printf(" is not an integer.\nPlease enter an integer such as 17,-203 and 0:");
    }
    
    return input;
}

//验证区间
bool Verify_Limits(long begin, long end, long low, long high)
{
    bool verify=false;

    if(begin>=end)  //验证输入的最小值是否大于最大值
    {
        printf("%ld is bigger than %ld.\n",begin,end);
        verify=true;
    }
    if(begin<low||end<low)  //验证输入的区间是否比指定范围小
    {
        printf("Warning: below the lower limit.\n");
        verify=true;
    }
    if(end>high||begin>high)    //验证输入的区间是否超过指定范围
    {
        printf("Warning: limit exceeded.\n");
        verify=true;
    }

    return verify;
}

//求平方和
double Square_Nums(long begin, long end)
{
    double result=0;

    for (int i = begin; i <= end; i++)
    {
        result+= (double)i*(double)i;
    }
    
    return result;
}