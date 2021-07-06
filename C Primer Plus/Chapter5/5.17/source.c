/*花式求模*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int lvalue,result;
    const int rvalue;

    printf("Please enter an integer to serve as the second operand:");
    scanf("%d",&rvalue);
    printf("Now enter the first operand:");
    scanf("%d",&lvalue);
    while(lvalue>0)
    {
        result=lvalue%rvalue;
        printf("%d %% %d is %d\n",lvalue,rvalue,result);
        printf("Now enter next number for first operand(<=0 to quit):");
        scanf("%d",&lvalue);
    }
    printf("Done!\n");

    system("pause");
    return 0;
}