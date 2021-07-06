//函数打印祝福
#include<stdio.h>
#include<stdlib.h>
void jolly(void);
void deny(void);
int main(void)
{
    jolly();
    deny();
    system("pause");
    return 0;
}

void jolly(void)
{
    printf("For he's a jolly good fellow!\n");
    printf("For he's a jolly good fellow!\n");
    printf("For he's a jolly good fellow!\n");
}

void deny(void)
{
    printf("Which nobody can deny!\n");
}