/*scanf()函数使用演示*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char name[20];
    int age;
    float height;
    
    printf("Please enter your Name,Age,Height:\n");
    scanf("%s %d %f",name,&age,&height);    //字符数组不yong'&'，空格、换行符、制表符会停止读取输入
    printf("Name:%s\nAge:%d\nHeight:%.2fm\n",name,age,height);

    system("pause");
    return 0;
}