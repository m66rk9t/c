/*国王与小麦——while循环*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void)
#define SQUARES 64  //符号常量，棋盘格数
{
    const double CROP=2E16; //世界小麦年产谷粒数
    int count=1;
    double index,current,total=0.0;  //index为指数，current为当前格子中的数量，total为当前总数量
    printf("square\t\tgrains\t\ttotal\t\tfarctiom of\n");
    printf("      \t\tadded\t\tgrains\t\tworld total\n");
    while(count<=SQUARES)
    {
        index=(float)count-1.0;
        current=pow(2.0,index);
        total=total+current;
        printf("%6d %18.2e %15.2e %15.2e\n",count,current,total,total/CROP);
        count=count+1;
    }
    printf("Taht's all.\n");

    system("pause");
    return 0;
}