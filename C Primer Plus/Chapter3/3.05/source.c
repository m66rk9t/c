/*计算水分子的数量，
1个水分子质量约为3.0x10ˉ²³克，
1夸脱水大约是950克*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int x;
    float result;

    printf("Please enter the number of quarts of water:\n");
    scanf("%d",&x);
    result=((float)x*950.0)/(3.0e-23);
    printf("The number of water molecules is %f\n",result);

    system("pause");
    return 0;
}