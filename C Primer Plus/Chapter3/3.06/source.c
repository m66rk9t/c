/*身高厘米=>英寸换算，1英寸=2.45厘米*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int height;
    float result;

    printf("Please enter your height(cm):\n");
    scanf("%d",&height);
    result=(float)height/2.45;
    printf("Your height is %.2f inch\n",result);

    system("pause");
    return 0;
}