#include <stdio.h>
#include <stdlib.h> //提供exit()原型
#include <string.h> //提供strlen()原型
#define MEMBERS 19  //0~18号
#define NAMELEN 21  //姓、名字符上限+1
#define DATANUM 4   //数据元素个数
struct player{
    int num;
    char fname[NAMELEN];
    char lname[NAMELEN];
    int data[DATANUM]; /*储存数据的数组，元素依次表示
    上场次数（GP）、击中数（AB）、走垒数（TB）以及打点（RBI）*/
    float hit;//安打率
};                     //结构声明，球员信息
struct player players[MEMBERS] = {
    {.num = -1, .data = {0, 0, 0, 0}, 0.0F}, {.num = -1, .data = {0, 0, 0, 0}, 0.0F}, {.num = -1, .data = {0, 0, 0, 0}, 0.0F}, 
    {.num = -1, .data = {0, 0, 0, 0}, 0.0F}, {.num = -1, .data = {0, 0, 0, 0}, 0.0F}, {.num = -1, .data = {0, 0, 0, 0}, 0.0F}, 
    {.num = -1, .data = {0, 0, 0, 0}, 0.0F}, {.num = -1, .data = {0, 0, 0, 0}, 0.0F}, {.num = -1, .data = {0, 0, 0, 0}, 0.0F}, 
    {.num = -1, .data = {0, 0, 0, 0}, 0.0F}, {.num = -1, .data = {0, 0, 0, 0}, 0.0F}, {.num = -1, .data = {0, 0, 0, 0}, 0.0F}, 
    {.num = -1, .data = {0, 0, 0, 0}, 0.0F}, {.num = -1, .data = {0, 0, 0, 0}, 0.0F}, {.num = -1, .data = {0, 0, 0, 0}, 0.0F}, 
    {.num = -1, .data = {0, 0, 0, 0}, 0.0F}, {.num = -1, .data = {0, 0, 0, 0}, 0.0F}, {.num = -1, .data = {0, 0, 0, 0}, 0.0F}
}; //结构数组，储存队员信息
int readinfo(FILE *pt, struct player *temp);

int main(void)
{
    struct player temp;     //临时结构
    struct player *pt_temp; //结构指针
    FILE *fp;               //FILE指针

    pt_temp = &temp; //使指针指向临时结构temp

    /*打开文件，打开失败则提示错误并异常结束程序*/
    if ((fp = fopen("games", "rb")) == NULL)
    {
        fprintf(stderr, "Can't open file.\n");
        exit(EXIT_FAILURE);
    }

    /*读取数据并初始化结构数组的成员*/
    while (readinfo(fp, pt_temp) == 0)
    {
        /*只初始化一次的内容*/
        if (players[temp.num].num = -1 &&
            strlen(players[temp.num].fname) == 0 && strlen(players[temp.num].lname) == 0)
        {
            players[temp.num].num=temp.num;
            strcpy(players[temp.num].fname, temp.fname);
            strcpy(players[temp.num].lname, temp.lname);
        }

        /*上场数据需要累加*/
        players[temp.num].data[0] += temp.data[0];
        players[temp.num].data[1] += temp.data[1];
        players[temp.num].data[2] += temp.data[2];
        players[temp.num].data[3] += temp.data[3];
    }

    /*输出队员信息*/
    for (int i = 0; i < MEMBERS; i++)
    {
        printf("%2d ", players[i].num);
        printf("%10s ", players[i].fname);
        printf("%12s ", players[i].lname);
        for (int j = 0; j < DATANUM; j++)
            printf("%d ", players[i].data[j]);
        /*计算安打率并输出*/
        players[i].hit = (float)players[i].data[1]/(float)players[i].data[0];
        printf("%-f\n", players[i].hit);
    }

    /*收尾*/
    fclose(fp);

    return 0;
}

/*从文件中读取一行数据并写入临时结构*/
int readinfo(FILE *pt, struct player *temp)
{
    int is_EOF = 0; //标记变量，是否读到文件结尾

    /*判断是否读到文件结尾*/
    if (getc(pt) == EOF)
        return (1);
    else
    {
        /*定位文件位置*/
        fseek(pt, -1, SEEK_CUR);

        /*读取球员号和姓名*/
        fscanf(pt, " %d", &temp->num); //跳过换行符读取
        fscanf(pt, "%s", &temp->fname);
        fscanf(pt, "%s", &temp->lname);

        /*读取上场数据*/
        for (int i = 0; i < DATANUM; i++)
        {
            getc(pt); //清理空格
            fscanf(pt, "%d", &temp->data[i]);
        }

        getc(pt);/*清理每行后面的回车*/
    }

    return 0;
}