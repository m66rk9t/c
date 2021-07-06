/*花式填充数组*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    double first[8],second[8];
    int i;
    printf("Please fill the first array:");
    //填充第一个数组
    for(i=0;i<8;i++)
    {
        scanf("%lf",&first[i]);
    }
    //填充第二个数组
    for(second[0]=first[0],i=1;i<8;i++)
    {
        second[i]=second[i-1]+first[i];
    }

    //显示两个数组的内容
    printf("The first array: ");
    for(i=0;i<8;i++)
    {
        printf("%lf\t",first[i]);
    }
    printf("\nThe second array:");
    for(i=0;i<8;i++)
    {
        printf("%lf\t",second[i]);
    }
    printf("\nDone!\n");
    system("pause");
    return 0;
}