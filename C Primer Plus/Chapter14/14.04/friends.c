/* friends.c -- 使用指向结构的指针 */
#include <stdio.h>
#define LEN 20
struct names
{
    char first[LEN];
    char last[LEN];
}; //第一个结构声明

struct guy
{
    struct names handle; //嵌套结构
    char favfood[LEN];
    char job[LEN];
    float income;
}; //第二个结构声明

int main(void)
{
    struct guy fellow[2] = {
        {{"Ewen", "Villard"},
         "grilled salmon",
         "personality coach",
         68112.00},
        {{"Rodney", "Swillbelly"},
         "tripe",
         "tabloid editor",
         432400.00}}; //声明并初始化一个guy类型的结构数组
    struct guy *him;  //声明指向guy类型结构的指针

    printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);
    him = &fellow[0]; //指针指向第一个数组元素，即第一个guy类型结构变量
    printf("pointer #1: %p #2: %p\n", him, him + 1);
    printf("him->income is $%.2f: (*him).income is $%.2f\n",
           him->income, (*him).income);
    him++; //指针指向第二个数组元素，即第二个guy类型结构变量
    printf("him->favfood is %s:  him->handle.last is %s\n",
           him->favfood, him->handle.last);

    return 0;
}
