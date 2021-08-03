/* names3.c -- 使用指针和malloc() */
#include <stdio.h>
#include <string.h> //提供strcpy()、strlen()
#include <stdlib.h> //提供malloc()、free()
#define SLEN 81
struct namect
{
    char *fname; //指针变量
    char *lname;
    int letters;
}; //结构声明

void getinfo(struct namect *); //分配内存
void makeinfo(struct namect *);
void showinfo(const struct namect *);
void cleanup(struct namect *); //释放内存
char *s_gets(char *st, int n);

int main(void)
{
    struct namect person; //声明namect类型的结构变量

    /*参数都是指向结构的指针*/
    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person); //释放内存

    return 0;
}

/*分配内存并读取输入内容*/
void getinfo(struct namect *pst)
{
    char temp[SLEN];
    printf("Please enter your first name.\n");
    s_gets(temp, SLEN);
    pst->fname = (char *)malloc(strlen(temp) + 1); //分配内存以储存名字符串
    strcpy(pst->fname, temp);                      //将名字符串拷贝到动态分配的内存中
    printf("Please enter your last name.\n");
    s_gets(temp, SLEN);
    pst->lname = (char *)malloc(strlen(temp) + 1); //分配内存以储存姓字符串
    strcpy(pst->lname, temp);                      //将姓字符串拷贝到动态分配的内存中
}

void makeinfo(struct namect *pst)
{
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect *pst)
{
    printf("%s %s, your name contains %d letters.\n",
           pst->fname, pst->lname, pst->letters);
}

/*释放内存*/
void cleanup(struct namect *pst)
{
    free(pst->fname);
    free(pst->lname);
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