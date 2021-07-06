/*EOF与统计大小写字母*/
#include<ctype.h>           //提供isspace()函数原型
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int input;
    int num_lower,num_upper;
    num_lower=num_upper=0;

    printf("Please enter some characters for analysis(press ctrl+z to quit):\n");
    while((input=getchar())!=EOF)
    {
        if(isalpha(input))
        {
            if(islower(input))
                num_lower++;
            if(isupper(input))
                num_upper++;
        }
    }
    printf("There are %d lower case letters and %d uppercase letter.\n",num_lower,num_upper);
    system("pause");
    return 0;
}