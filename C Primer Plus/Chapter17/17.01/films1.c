/*films1.c -- 使用结构数组*/
#include <stdio.h>
#include <string.h>
#define TSIZE 45 //电影名字符串长度+1
#define FMAX 5   //影片数量上限
struct film{
    char title[TSIZE];             //影片名
    int rating;                    //评级
};                                 //结构声明，影片结构
char *s_gets(char str[], int lim); //读取输入字符串的函数原型

int main(void)
{
    struct film movies[FMAX]; //储存影片
    int i = 0;                //控制输入影片的数量
    int j;                    //用于控制打印影片信息的循环的变量

    /*输入影片信息并储存到结构数组中*/
    puts("Enter first movie title:");
    while (i < FMAX && s_gets(movies[i].title, TSIZE) != NULL &&
           movies[i].title[0] != '\0') //读取影片名字符串
    {
        puts("Enter your rating <0-10>:");
        scanf("%d", &movies[i++].rating); //输入评级
        while (getchar() != '\n')         //清理输入行
            continue;
        puts("Enter next movie title (empty line to stop):");
    }

    /*打印结构数组的内容*/
    if (i == 0)
        printf("No data entered. ");
    else
        printf("Here is the movie list:\n");

    for (j = 0; j < i; j++)
        printf("Movie: %s  Rating: %d\n", movies[j].title,
               movies[j].rating);
    printf("Bye!\n");

    return 0;
}

/*读取输入字符串的函数定义*/
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); //查找换行符
        if (find)                //如果地址不是NULL
            *find = '\0';        //用空字符替换换行符
        else
            while (getchar() != '\n')
                continue; //处理输入行的剩余字符
    }
    return ret_val;
}