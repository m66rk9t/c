/*何为真？何为假？*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int x=3;

    while(x)
    {
        printf("%2d is true\n",x);
        x--;
    }
    printf("%2d is false\n",x);

    x=-3;
    while(x)
    {
        printf("%2d is true\n",x);
        x++;
    }
    printf("%2d is false\n",x);

    system("pause");
    return 0;
}