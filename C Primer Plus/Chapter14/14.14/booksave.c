/* booksave.c -- 将结构的内容保存到文件中 */
#include <stdio.h>
#include <stdlib.h>            //提供exit()原型
#include <string.h>            //提供strchr()原型
#define MAXTITL 41             //书名最大长度+1
#define MAXAUTL 41             //作者名最大长度+1
#define MAXBKS 10              //书籍最大数量
char *s_gets(char *st, int n); //读取字符串的函数原型
struct book                    //book结构声明
{
    char title[MAXTITL];  //储存书名
    char author[MAXAUTL]; //储存作者名
    float value;          //书籍价格
};

int main(void)
{
    struct book library[MAXBKS];    //声明book结构数组
    int count = 0;                  //统计书籍的数量
    int index, filecount;           //
    FILE *pbooks;                   //指向FILE的指针
    int size = sizeof(struct book); //计算结构的大小

    /*以二进制附加模式打开文件，打开失败则提示错误并异常结束程序*/
    if ((pbooks = fopen("book.dat", "a+b")) == NULL)
    {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }

    rewind(pbooks); //定位至文件开始处
    /*每次迭代都把文件中的一个结构读到结构数组中，直至数组已满或读到文件结尾*/
    while (count < MAXBKS && fread(&library[count], size,
                                   1, pbooks) == 1)
    {
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2f\n", library[count].title,
               library[count].author, library[count].value); //输出每个结构的内容
        count++;
    }
    filecount = count; //记录文件中结构的数量
    /*如果数量已满则结束程序*/
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }

    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    /*读取输入，初始化结构数组中剩余的结构元素，直至数量达到上限、读取错误或停止读取*/
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
    {
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue; //清理输入行
        if (count < MAXBKS)
            puts("Enter the next title.");
    }

    /*将新的结构写入到文件中*/
    if (count > 0)
    {
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                   library[index].author, library[index].value);
        fwrite(&library[filecount], size, count - filecount,
               pbooks);//一次性写入count - filecount个数据块，每块都是一个struct book大小
    }
    else
        puts("No books? Too bad.\n");

    puts("Bye.");
    fclose(pbooks);

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