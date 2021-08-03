/* names2.c -- 传递并返回结构 */
#include <stdio.h>
#include <string.h>

#define NLEN 31 //名字字符最大长度+1
struct namect
{
    char fname[NLEN];
    char lname[NLEN];
    int letters;
}; //结构声明

struct namect getinfo(void);
struct namect makeinfo(struct namect);
void showinfo(struct namect);
char *s_gets(char *st, int n);

int main(void)
{
    struct namect person; //声明一个namect类型的结构变量

    person = getinfo();        //返回值是一个结构
    person = makeinfo(person); //返回值和参数都是结构
    showinfo(person);          //参数是结构

    return 0;
}

struct namect getinfo(void)
{
    struct namect temp;
    printf("Please enter your first name.\n");
    s_gets(temp.fname, NLEN);
    printf("Please enter your last name.\n");
    s_gets(temp.lname, NLEN);

    return temp;
}

struct namect makeinfo(struct namect info)
{
    info.letters = strlen(info.fname) + strlen(info.lname);

    return info;
}

void showinfo(struct namect info)
{
    printf("%s %s, your name contains %d letters.\n",
           info.fname, info.lname, info.letters);
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // 查找换行符
        if (find)                // 如果地址不是 NULL，
            *find = '\0';        // 在此处放置一个空字符
        else
            while (getchar() != '\n')
                continue; // 处理输入行中剩余的字符
    }
    return ret_val;
}