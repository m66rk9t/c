#include <stdio.h>
#include <string.h>
#define MAXTITL 41
#define MAXAUTL 31
#define MAXBKS 100
char *s_gets(char *st, int n);
struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
}; // 结构说明

int main(void)
{
    struct book library[MAXBKS]; //声明book类型的结构数组
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL); //输入作者名
        printf("Now enter the value.\n");       //输入价格
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue; //清理输入行
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }
    if (count > 0)
    {
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                   library[index].author, library[index].value);
    }
    else
        printf("No books? Too bad.\n");
    return 0;
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