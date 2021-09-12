/* list.h -- 接口头文件，简单链表类型的头文件*/
#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>

/*特定程序的声明*/
#define TSIZE 45 //影片名字符串长度+1
struct film{
    char title[TSIZE]; //影片名字符串数组
    int rating;        //评级
};                     //结构声明，影片信息结构

/*一般类型定义*/
typedef struct film Item;
typedef struct node{
    Item item;
    struct node *next;
} Node;             //节点结构，含有影片信息以及指向下一个结构的指针
typedef Node *List; //指向节点结构的指针类型

/*函数原型*/
/*操作：初始化一个链表*/
/*前提条件：plist指向一个链表*/
/*后置条件：链表初始化为空*/
void InitializeList(List *plist);

/*操作：确定链表是否为空定义，plist指向一个已初始化的链表*/
/*后置条件：如果链表为空，该函数返回true；否则返回false*/
bool ListIsEmpty(const List *plist);

/*操作：确定链表是否已满，plist指向一个已初始化的链表*/
/*后置条件：如果链表已满，该函数返回true；否则返回false*/
bool ListIsFull(const List *plist);

/*操作：确定链表中的项数，plist指向一个已初始化的链表*/
/*后置条件：该函数返回链表中的项数*/
unsigned int ListItemCount(const List *plist);

/*操作：在链表末尾添加新项*/
/*前置条件：item是一个待添加至链表末尾的新项，plist指向一个已初始化的链表*/
/*后置条件：如果可以，该函数在链表末尾添加一个新项，且返回true；否则返回false*/
bool AddItem(Item item, List *plist);

/*操作：把函数作用于链表中的每一项，plist指向一个已初始化的链表，*/
/*pfun指向一个无返回值且接受一个Item类型参数的函数*/
/*后置条件：pufn指向的函数作用于链表中的每一项一次*/
void Traverse(const List *plist, void (*pfun)(Item item));

/*操作：释放已分配的内存（如果有的话），plist指向一个已初始化的链表*/
/*后置条件：释放了为链表分配到所有内存，链表设置为空*/
void EmptyTheList(List *plist);

#endif