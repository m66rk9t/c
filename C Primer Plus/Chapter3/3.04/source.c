/*计算年龄对应的秒数，1y=3.156x10⁷secs*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int age;
    float result;

    printf("Please enter your age\n");
    scanf("%d",&age);
    result=(float)age*3.156e7;
    printf("The secs for your age %d are %f\n",age,result);

    system("pause");
    return 0;
}