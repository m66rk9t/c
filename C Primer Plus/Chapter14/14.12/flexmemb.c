/* flexmemb.c -- 使用伸缩型数组成员（C99新增特性） */
#include <stdio.h>
#include <stdlib.h>

struct flex
{
    size_t count;
    double average;
    double scores[]; //伸缩型数组成员
};                   //结构声明

void showFlex(const struct flex *p); //参数是指向结构的指针

int main(void)
{
    struct flex *pf1, *pf2; //声明两个指向flex类型的结构的指针
    int n = 5;
    int i;
    int tot = 0;

    pf1 = malloc(sizeof(struct flex) + n * sizeof(double)); //分配存储空间
    pf1->count = n;
    for (i = 0; i < n; i++) //初始化伸缩型数组成员
    {
        pf1->scores[i] = 20.0 - i;
        tot += pf1->scores[i];
    }
    pf1->average = tot / n;
    showFlex(pf1);

    n = 9;
    tot = 0;
    pf2 = malloc(sizeof(struct flex) + n * sizeof(double)); //分配存储空间
    pf2->count = n;
    for (i = 0; i < n; i++) //初始化伸缩型数组成员
    {
        pf2->scores[i] = 20.0 - i / 2.0;
        tot += pf2->scores[i];
    }
    pf2->average = tot / n;
    showFlex(pf2);

    /*释放内存*/
    free(pf1);
    free(pf2);

    return 0;
}

void showFlex(const struct flex *p)
{
    int i;
    printf("Scores : ");
    for (i = 0; i < p->count; i++)
        printf("%g ", p->scores[i]);
    printf("\nAverage: %g\n", p->average);
}
