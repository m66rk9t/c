/*queue.c -- Queue类型实现*/
#include <stdio.h>
#include <stdlib.h> //提供malloc()和free()原型
#include "queue.h"  //包含头文件

/*内部链接函数原型*/
static void CopyToNode(Item item, Node *pn); //将新项拷贝至节点中的函数原型
static void CopyToItem(Node *pn, Item *pi);  //将项拷贝至指定位置的函数原型

/*初始化队列的函数定义*/
void InitializeQueue(Queue *pq)
{
    pq->front = pq->rear = NULL; //初始化指向队首节点和队尾节点的指针为NULL
    pq->items = 0;               //初始化队列项的数量为0
}

/*检查队列是否已满的函数定义*/
bool QueueIsFull(const Queue *pq)
{
    return pq->items == MAXQUEUE; //比较数量
}

/*检查队列是否为空的函数定义*/
bool QueueIsEmpty(const Queue *pq)
{
    return pq->items == 0; //判断项的数量是否为0
}

/*统计队列中的项数的函数定义*/
int QueueItemCount(const Queue *pq)
{
    return pq->items; //返回队列中的项数
}

/*在队列末尾添加新项的函数定义*/
bool EnQueue(Item item, Queue *pq)
{
    Node *pnew; //声明指向新节点的指针

    if (QueueIsFull(pq)) //如果队列已满则退出函数，表示添加新项失败
        return false;
    pnew = (Node *)malloc(sizeof(Node)); //为新节点分配动态内存
    if (pnew == NULL)                    //如果分配失败则提示错误并结束程序
    {
        fprintf(stderr, "Unable to allocate memory!\n");
        exit(1);
    }
    CopyToNode(item, pnew); //将待添加的新项拷贝至新节点的项中
    pnew->next = NULL;      //设置新节点为最后一个节点
    if (QueueIsEmpty(pq))   //如果队列为空，则设置新节点为队首节点
        pq->front = pnew;
    else //如果队列不为空，则设置队尾节点中的指针指向该新节点
        pq->rear->next = pnew;
    pq->rear = pnew; //队尾节点指针指向新节点
    pq->items++;     //队列项数+1

    return true; //成功添加新项及新节点
}

/*删除队列首项的函数定义*/
bool DeQueue(Item *pitem, Queue *pq)
{
    Node *pt; //储存待删除节点地址的指针

    if (QueueIsEmpty(pq)) //如果队列为空则退出函数，表示队列已空
        return false;
    CopyToItem(pq->front, pitem); //将待删项拷贝至指定项（临时的）
    pt = pq->front;               //将待删节点地址赋给临时指针变量
    pq->front = pq->front->next;  //队首指针指向下一个节点
    free(pt);                     //释放内存
    pq->items--;                  //队列项数-1
    if (pq->items == 0)           //如果队列已空，设置队尾指针为NULL
        pq->rear = NULL;

    return true; //成功删除队列首项
}

/*清空队列的函数定义*/
void EmptyTheQueue(Queue *pq)
{
    Item dummy; //临时变量，储存待删项
    /*队列不为空就循环删除队列首项*/
    while (!QueueIsEmpty(pq))
        DeQueue(&dummy, pq);
}

/*内部链接函数定义*/

/*将新项拷贝至节点中的函数定义*/
static void CopyToNode(Item item, Node *pn)
{
    pn->item = item;
}

/*将项拷贝至指定位置的函数定义*/
static void CopyToItem(Node *pn, Item *pi)
{
    *pi = pn->item;
}