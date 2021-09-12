/*films3.c -- 使用抽象数据类型（ADT）风格的链表*/
#include <stdio.h>
#include <stdlib.h>            //提供exit()原型
#include <string.h>            //提供strchr()原型
#include "list.h"              //提供List, Item定义
void showmovies(Item item);    //打印链表中每个节点内容的函数原型
char *s_gets(char *st, int n); //读取输入字符串的函数原型

int main(void)
{
    List movies; //声明指向链表中第一个节点的指针
    Item temp;   //声明一个Item类型变量，储存影片信息

    /*初始化链表*/
    InitializeList(&movies);
    if (ListIsFull(&movies)) //判断链表是否已满
    {
        fprintf(stderr, "No memory available! Bye!\n");
        exit(1);
    }

    /*读取输入信息并储存到节点中*/
    puts("Enter first movie title:");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0') //输入影片名字符串
    {
        puts("Enter your rating <0-10>:");
        scanf("%d", &temp.rating); //输入评级
        while (getchar() != '\n')  //清理输入行
            continue;
        if (AddItem(temp, &movies) == false) //将新项添加至节点中
        {
            fprintf(stderr, "Problem allocating memory\n");
            break;
        }
        if (ListIsFull(&movies)) //判断链表是否已满
        {
            puts("The list is now full.");
            break;
        }
        puts("Enter next movie title (empty line to stop):");
    }

    /*打印链表中各节点内容*/
    if (ListIsEmpty(&movies)) //判断是否为空链表
        printf("No data entered. ");
    else
    {
        printf("Here is the movie list:\n");
        Traverse(&movies, showmovies); //调用打印函数
    }
    printf("You entered %d movies.\n", ListItemCount(&movies)); //打印链表中节点数量

    /*释放链表内存*/
    EmptyTheList(&movies);
    printf("Bye!\n");

    return 0;
}

/*打印链表中每个节点内容的函数原型*/
void showmovies(Item item)
{
    printf("Movie: %s  Rating: %d\n", item.title,
           item.rating);
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
            while (getchar() != '\n') //处理输入行的剩余字符
                continue;
    }
    return ret_val;
}