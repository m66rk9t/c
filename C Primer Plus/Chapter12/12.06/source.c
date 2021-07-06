#include <stdio.h>
#include <stdlib.h> /*提供rand()和srand()原型*/
#define SIZE 1000
#define SEED 10
static int seed[SEED];  /*储存种子值*/
static int count[SEED]; /*储存出现的次数*/
int main(void)
{
    int num; /*储存生成的随机数*/

    /*输入种子值*/
    printf("Please enter 10 integers as seed value:\n");
    for (int i = 0; i < SEED; i++)
        scanf("%d", &seed[i]);

    /*设置种子值、生成随机数并统计出现次数*/
    for (int i = 0, j = 0; i < SIZE; i++, j++)
    {
        if (j == 10)
            j = 0;
        srand(seed[j]);          /*重置种子值*/
        num = (rand() % 10) + 1; /*生成随机数*/
        count[num - 1]++;        /*统计该数出现的次数*/
    }

    /*打印1~10出现的次数*/
    printf("Number of occurrences of numbers 1~10:\n");
    for (int i = 0; i < SEED; i++)
        printf("%2d : %d times.\n", i + 1, count[i]);

    return 0;
}