/*list.c -- 支持链表操作的函数定义文件*/
#include <stdio.h>
#include <stdlib.h> //提供malloc()和free()原型
#include "list.h"   //包含头文件

/*具有内部链接的拷贝节点的函数原型*/
static void CopyToNode(Item item, Node *pnode);

/*接口函数*/
/*将链表设置为空*/
void InitializeList(List *plist)
{
    *plist = NULL; //将指向链表中第一个节点的指针设置为NULL
}

/*如果链表为空则返回true，否则返回false*/
bool ListIsEmpty(const List *plist)
{
    if (*plist == NULL)
        return true;
    else
        return false;
}

/*如果链表已满则返回true，否则返回false*/
bool ListIsFull(const List *plist)
{
    Node *pt;
    bool full;

    pt = (Node *)malloc(sizeof(Node)); //尝试分配内存
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt); //释放内存，保险操作

    return full;
}

/*返回节点的数量*/
unsigned int ListItemCount(const List *plist)
{
    unsigned int count = 0;
    Node *pnode = *plist; //设置链表的开始

    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->next; //指向链表中的下一个节点
    }

    return count;
}

/*创建新节点，并将其添加至由plist指向的链表结尾*/
bool AddItem(Item item, List *plist)
{
    Node *pnew;          //指向新节点的指针
    Node *scan = *plist; //指向链表第一个节点的指针

    pnew = (Node *)malloc(sizeof(Node)); //为储存新节点分配内存
    if (pnew == NULL)
        return false; //分配失败就退出函数

    CopyToNode(item, pnew); //将内容拷贝到新节点中
    pnew->next = NULL;      //设置该节点为最后一个
    if (scan == NULL)       //如果是空链表就将其该新节点设置为第一个
        *plist = pnew;
    else
    {
        while (scan->next != NULL) //定位至链表当前的最后一个节点
            scan = scan->next;
        scan->next = pnew; //将该节点其设置为最后一个节点
    }

    return true;
}

/*访问每个节点并指向pfun指向的函数*/
void Traverse(const List *plist, void (*pfun)(Item item))
{
    Node *pnode = *plist; //设置链表的开始

    while (pnode != NULL)
    {
        (*pfun)(pnode->item); //把函数应用于链表中的节点
        pnode = pnode->next;  //指向链表中的下一节点
    }
}

/*释放由malloc()分配的内存，设置链表指针为NULL*/
void EmptyTheList(List *plist)
{
    Node *psave;

    while (*plist != NULL)
    {
        psave = (*plist)->next; //保存下一节点的地址
        free(*plist);           //释放当前节点
        *plist = psave;         //定位至下一个节点
    }
}

/*局部函数定义，把一个项的内容拷贝到新节点中*/
static void CopyToNode(Item item, Node *pnode)
{
    pnode->item = item; /* structure copy */
}
