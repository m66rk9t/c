/*use_q.c -- 驱动程序测试Queue接口*/
#include <stdio.h>
#include "queue.h" //提供Queue和Item定义

int main(void)
{
    Queue line; //声明一个队列
    Item temp;  //声明一个项，储存输入的内容
    char ch;    //储存输入的选项字符

    InitializeQueue(&line); //初始化一个队列
    puts("Testing the Queue interface. Type a to add a value,");
    puts("type d to delete a value, and type q to quit.");
    while ((ch = getchar()) != 'q')
    {
        if (ch != 'a' && ch != 'd') /*忽略非法输入*/
            continue;
        if (ch == 'a')
        {
            printf("Integer to add: ");
            scanf("%d", &temp);      //输入一个项值
            if (!QueueIsFull(&line)) //判断队列是否已满
            {
                printf("Putting %d into queue\n", temp);
                EnQueue(temp, &line); //将新项添加至队列末尾
            }
            else
                puts("Queue is full!");
        }
        else
        {
            if (QueueIsEmpty(&line)) //判断队列是否为空
                puts("Nothing to delete!");
            else
            {
                DeQueue(&temp, &line); //删除队列首项
                printf("Removing %d from queue\n", temp);
            }
        }
        printf("%d items in queue\n", QueueItemCount(&line)); //输出队列中的项数
        puts("Type a to add, d to delete, q to quit:");
    }
    EmptyTheQueue(&line); //清空队列
    puts("Bye!");

    return 0;
}