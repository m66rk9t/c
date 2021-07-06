//年龄转换为天数
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int year,day;
    printf("Please enter your age:\n");
    scanf("%d",&year);
    day=year*365;
    printf("Your age is %d, You have been alive for %d days.\n",year,day);
    system("pause");
    return 0;
}