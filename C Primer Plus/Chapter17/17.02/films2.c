/*films2.c -- 使用结构链表*/
#include <stdio.h>
#include <stdlib.h> //提供malloc()原型
#include <string.h> //提供strcpy()原型
#define TSIZE 45    //电影名字符串长度+1
struct film{
    char title[TSIZE];
    int rating;
    struct film *next;         //指向链表中的下一个结构
};                             //结构声明，影片信息结构
char *s_gets(char *st, int n); //读取输入字符串的函数原型

int main(void)
{
    struct film *head = NULL;    //头指针，指向链表中第1个结构的指针，初始化为NULL
    struct film *prev, *current; //指向“上一个”结构的指针、指向“当前”结构的指针
    char input[TSIZE];           //临时字符串数组，储存输入的影片名

    /*读取输入的信息并储存到结构中*/
    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0') //输入影片名
    {
        current = (struct film *)malloc(sizeof(struct film)); //为新的结构分配动态内存空间
        if (head == NULL)   //使头指针指向链表中第1个结构
            head = current;
        else                //使“上一个”结构中的指针指向“当前”结构（对于“上一个”来说是“下一个”）
            prev->next = current;
        current->next = NULL;          //初始化“当前”结构的指针为NULL，表示当前结构是链表中的最后一个结构
        strcpy(current->title, input); //拷贝影片名字符串
        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating); //输入评级
        while (getchar() != '\n')      //清理输入行
            continue;
        puts("Enter next movie title (empty line to stop):");
        prev = current;
    }

    /*按顺序显示链表中各结构的信息*/
    if (head == NULL)
        printf("No data entered. ");
    else
        printf("Here is the movie list:\n");
    current = head; //定位至链表开始处的结构
    while (current != NULL)
    {
        printf("Movie: %s  Rating: %d\n",
               current->title, current->rating); //输出内容
        current = current->next;                 //使指针指向下一个结构
    }

    /*释放为链表中结构分配的动态内存空间*/
    current = head; //定位至链表开始处的结构
    while (current != NULL)
    {
        free(current);           //释放
        current = current->next; //使指针指向下一个结构
    }
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