#include <stdio.h>
#include "starfolk.h"
void show(struct bem); //函数原型，bem结构作参数

int main(void)
{
    struct bem deb = {
        6,
        {"Berbnazel", "Gwolkapwolk"},
        "Arcturan"
    }; //声明并初始化一个bem结构变量

    show(deb);

    return 0;
}
void show(struct bem para)
{
    printf("%s %s is a %d-limbed %s.\n",
           para.title.first, para.title.last, para.limbs, para.type);
}