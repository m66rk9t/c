/*读取小数，并以浮点数格式和指数计数法格式打印*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    float fp_num;
    
    printf("Please enter a floating-point number:\n");
    scanf("%f",&fp_num);
    printf("The input is %.1f or %.1e\n",fp_num,fp_num);
    printf("The input is %+.3f or %.3E\n",fp_num,fp_num);

    system("pause");
    return 0;
}