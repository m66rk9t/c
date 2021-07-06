/*区间求平方和*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int lower,upper,sum;

    printf("Please enter lower and upper integer limits:");
    scanf("%d %d",&lower,&upper);
    while(lower!=upper)
    {
        int lower_power=lower*lower;
        for (sum=0;lower<=upper;lower++)
        {
            sum+=lower*lower;
        }
        printf("The sums of the squares from %d to %d is %d.\n",lower_power,upper*upper,sum);
        printf("Now enter next set of limits:");
        scanf("%d %d",&lower,&upper);
    }
    printf("Done!\n");

    system("pause");
    return 0;
}