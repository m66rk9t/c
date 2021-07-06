/*将用分钟表示的时间转换成用小时和分钟表示的时间*/
#include<stdio.h>
#include<stdlib.h>
#define MIN_PER_HR 60
int main(void)
{
    int input,hrs,mins;
    
    printf("Please enter the number of minutes(<=0 to quit):\n");
    scanf("%d",&input);
    while(input>0)
    {
        hrs=input/MIN_PER_HR;
        mins=input%MIN_PER_HR;
        printf("%d minutes is %d hours,%d minutes\n",input,hrs,mins);
        printf("Please enter the number of minutes(<=0 to quit):\n");
        scanf("%d",&input);
    }
    printf("Done!\n");

    system("pause");
    return 0;
}