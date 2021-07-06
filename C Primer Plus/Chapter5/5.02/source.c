/*除法中的截断现象*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    printf("integer division:  5/4     is %d\n",5/4);
    printf("integer division:  6/3     is %d\n",6/3);
    printf("integer division:  7/4     is %d\n",7/4);
    printf("floatint division: 7.0/4.0 is %-.2f\n",7.0/4.0);
    printf("mixed division:    7.0/4   is %-.2f\n",7.0/4);

    system("pause");
    return 0;
}