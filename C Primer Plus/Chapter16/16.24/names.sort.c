#include <stdio.h>
#include <stdlib.h> //提供qsort()原型
#include <string.h> //提供strcmp()原型
#define FSLEN 21    //名字符串长度+1
#define LSLEN 11    //姓字符串长度+1
#define NSIZE 5     //结构数组大小
typedef struct name{
    char fname[FSLEN];
    char lname[LSLEN];
} NAME; //定义结构模板
NAME names[NSIZE] = {
    {"Yifan", "Li"},
    {"Xinyu", "Liu"},
    {"Ziting", "Miao"},
    {"Shan", "Li"},
    {"Huijing", "Zhu"}};               //声明并初始化结构数组
int mycmp(const void *, const void *); //比较两项大小的函数原型
void showname(const NAME *);           //打印结构数组的内容的函数原型

int main(void)
{
    printf("Original:\n");
    showname(names);
    qsort(names, NSIZE, sizeof(NAME), mycmp); //使用快速排序法
    printf("\nSorted:\n");
    showname(names);

    return 0;
}

/*比较两项大小的函数定义*/
int mycmp(const void *first, const void *second)
{
    /*初始化两个结构*/
    const NAME *name1 = (const NAME *)first;
    const NAME *name2 = (const NAME *)second;
    int res;

    /*比较姓名，首先比较姓*/
    res = strcmp(name1->lname, name2->lname);
    if (res != 0)
        return res;
    else //姓一致时比较名
        return strcmp(name1->fname, name2->fname);
}

/*打印结构数组的内容的函数定义*/
void showname(const NAME *ns)
{
    for (int i = 0; i < NSIZE; i++)
        printf("%s %s\n", ns[i].lname, ns[i].fname);
}