#include <stdio.h>
#include <stdlib.h> /*提供rand()原型*/
int *value;

static int rollem(int sides) /*静态函数，本文件私有*/
{
    int roll; /*储存点数*/

    roll = rand() % sides + 1; /*生成点数*/

    return roll;
}

int *roll_n_dice(int dice, int sides, int sets)
{
    int d;
    int total = 0; /*储存每个骰子的点数总和*/
    value = (int *)malloc(sets * sizeof(int));

    /*生成点数并统计点数之和*/
    for (int i = 0; i < sets; i++)
    {
        for (d = 0; d < dice; d++)
            total += rollem(sides);
        value[i] = total;
        total=0;
    }

    return value;
}