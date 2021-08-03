/* Social Security Number.c -- 打印个人社保信息*/
#include <stdio.h>
#include <string.h> //提供strlen()原型
struct fullname
{
    char fname[10];
    char lname[10];
    char midname[10];
};//结构声明，个人姓名
struct ssn
{
    unsigned long int num;
    struct fullname name;
};//结构声明，社保信息
void show_info(struct ssn); //结构作参数的函数原型

int main(void)
{
    struct ssn ssns[5] = {
        {302039823UL, {"Flossie", "Dribble", "Mock"}},
        {693993751UL, {"Stephen", "Prata"}},
        {307816628UL, {"Yifan", "Li"}},
        {793238462UL, {"James", "Jones", "Earl"}},
        {280348253UL, {"Mark", "Hamill"}}}; //声明并初始化ssn结构数组

    /*遍历数组*/
    for (int i = 0; i < 5; i++)
        show_info(ssns[i]);
    puts("Done!");

    return 0;
}

/*函数定义*/
void show_info(struct ssn info)
{
    printf("%s, %s ", info.name.lname, info.name.fname);
    if (strlen(info.name.midname) > 0)
        printf("%c. ", info.name.midname[0]);
    printf("-- %lu\n", info.num);
}