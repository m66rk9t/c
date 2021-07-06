/*天数转换为周数与天数的形式*/
#include<stdio.h>
#include<stdlib.h>
#define DAY_PER_WEEK 7
int main(void)
{
    int input,weeks,days;

    printf("Please enter the number of days(<=0 to quit):\n");
    scanf("%d",&input);
    while(input>0)
    {
        weeks=input/DAY_PER_WEEK;
        days=input%DAY_PER_WEEK;
        printf("%d days are %d weeks,%d days.\n",input,weeks,days);
        printf("Please enter the number of days(<=0 to quit):\n");
        scanf("%d",&input);
    }
    printf("Done!\n");

    system("pause");
    return 0;
}