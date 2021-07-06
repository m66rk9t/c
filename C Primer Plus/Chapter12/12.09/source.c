#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int j = 0;
static char **words;  /*指向指针的指针*/
static char str[100]; /*自动变量，储存输入字符串*/
static int count;     /*输入的单词数量*/
int main(void)
{
    printf("How many words do you wish to enter? ");
    scanf("%d", &count);      /*输入待读取的单词数量*/
    while (getchar() != '\n') /*处理多余输入字符*/
        continue;
    words = (char **)malloc(count * sizeof(char *)); /*分配存储空间*/

    printf("Enter %d words now:\n", count);
    fgets(str, 100, stdin);         /*读取输入字符串，填充数组*/

    for (int i = 0; i < count; i++) /*外循环控制拷贝单词的数量*/
    {
        char temp_str[100];                                /*临时数组，储存字符串中的单词*/
        char *temp_ptr;                                    /*临时指针，指向单词副本*/
        int k = 0;                                         /*控制拷贝字符的数量*/
        for (; str[j] != '\n' && str[j] != '\0'; j++, k++) /*内循环控制拷贝字符的数量*/
        {
            if (str[j] == ' ') /*如果是空字符就退出循环并进行拷贝操作*/
            {
                j++;
                break;
            }
            temp_str[k] = str[j]; /*拷贝字符*/
        }
        temp_ptr = (char *)malloc((k + 1) * sizeof(char)); /*分配临时空间用于储存单词副本*/
        strncpy(temp_ptr, temp_str, k + 1);                /*拷贝*/
        temp_ptr[k] = '\0';                                /*将每个字符串数组末尾元素设置为空字符*/
        words[i] = temp_ptr;                               /*将单词副本的地址赋给指针数组对应的元素*/
    }

    printf("Here are your words:\n");
    for (int i = 0; i < count; i++) /*每行输出一个单词*/
        puts(words[i]);
    free(words); /*释放内存*/

    return 0;
}