/*使用bool类型求和*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main(void)
{
    long input,sum=0;
    bool TRUE_OR_FALSE;

    printf("Please enter an integer number:");
    TRUE_OR_FALSE=(scanf("%ld",&input)==1);
    while(TRUE_OR_FALSE)
    {
        sum+=input;
        printf("Please enter an integer number(enter 'q' to quit):");
        TRUE_OR_FALSE=(scanf("%ld",&input)==1);
    }
    printf("Done! The sum of the integers entered is %ld.\n",sum);

    system("pause");
    return 0;
}