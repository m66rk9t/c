#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 3
#define LEN 21
#define SIZE 12
struct seat{
    char num[NUM];
    bool reserved;
    char fname[LEN];
    char lname[LEN];
}; //结构声明，座位信息
struct seat seats[SIZE] = {
    {"1A", false},{"1B", false},{"1C", false},
    {"2A", false},{"2B", false},{"2C", false},
    {"3A", false},{"3B", false},{"3C", false},
    {"4A", false},{"4B", false},{"4C", false}
}; //初始化结构数组
char showmenu(void);
void eatline(void);
void show_nums(void);
void show_list(void);
void alph_list(void);
void assign(void);
void delete (void);
void reserve(void (*pfun)(void));
char *s_gets(char *st, int n);

int main(void)
{
    char choice;        //储存选项
    void (*pfun)(void); //函数指针

    while ((choice = showmenu()) != 'f')
    {
        switch (choice)
        {
        case 'a':pfun = show_nums;break;
        case 'b':pfun = show_list;break;
        case 'c':pfun = alph_list;break;
        case 'd':pfun = assign;   break;
        case 'e':pfun = delete;   break;
        }
        reserve(pfun);
    }
    puts("Done!");

    return 0;
}

/*显示菜单并返回输入的选项*/
char showmenu(void)
{
    char ans; //储存选项字符

    /*打印菜单*/
    puts("To choose a funciton, enter its letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment\nf) Quit");

    /*读取输入选项字符*/
    ans = tolower(getchar());
    eatline();
    
    /*判断是否符合输入要求*/
    while (strchr("abcedf", ans) == NULL)
    {
        puts("Please enter a, b, c, d, e or f:");
        ans = tolower(getchar());
        eatline();
    }

    return ans;
}

/*清理输入行*/
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

void show_nums(void)
{
    int numbers = 0; //储存未预订座位的数量

    /*遍历数组，判断是否被预订*/
    for (int i = 0; i < SIZE; i++)
        if (!(seats[i].reserved))
            numbers++;
    printf("%d seats have not been reserved.\n", numbers); //输出未预订座位的数量
}

void show_list(void)
{
    printf("Not reserved:\n");
    /*遍历数组，判断是否被预订*/
    for (int i = 0; i < SIZE; i++)
        if (!(seats[i].reserved))
            printf("%s ", seats[i].num);
    putchar('\n');
}

void alph_list(void)
{
    int numbers = 0;
    struct seat tempp;

    /*遍历数组，判断是否被预订*/
    for (int i = 0; i < SIZE; i++)
        if (!(seats[i].reserved))
            numbers++;
    struct seat temp[numbers];//变长数组
    
    for (int i = 0, j = 0; i < SIZE; i++)
        if (!(seats[i].reserved))
            temp[j++] = seats[i];

    for (int i = 0; i < numbers-1; i++)
    {
        for (int j = i+1; j < numbers; j++)
        {
            if (temp[i].num[1] > temp[j].num[1])
            {
                tempp = temp[i];
                temp[i] = temp[j];
                temp[j] = tempp;
            }
        }
    }

    puts("Not reserved:");
    for (int i = 0; i < numbers; i++)
        printf("%s ", temp[i].num);
    putchar('\n');
}

void assign(void)
{
    char input[NUM];       //储存输入的座位号
    bool is_exist = false; //输入的座位号是否有效
    int i;

    printf("Enter the number that you wannna to reserve:");
    while (s_gets(input, NUM) != NULL)
    {
        input[1] = toupper(input[1]); //把座位号的字母字符转换成大写的
        for (i = 0; i < SIZE; i++)
        {
            /*判断输入的座位号是否存在*/
            if (strstr(input, seats[i].num))
            {
                is_exist = true;
                break;
            }
        }
        if (!is_exist) //不存在，重新输入
        {
            printf("Please enter correct number:");
            continue;
        }
        else if (seats[i].reserved) //被预定，重新输入
        {
            printf("Sorry, this seat has been reserved, please enter another one:");
            continue;
        }
        else //未被预定
        {
            seats[i].reserved = true;
            break;
        }
    }

    /*输入姓名*/
    printf("Please enter your first name:");
    s_gets(seats[i].fname, LEN);
    printf("Please enter your last  name:");
    s_gets(seats[i].lname, LEN);
    puts("Succeed, you\'re Welcome! This is your ticket:");
    printf("Seat number:%-s\n", seats[i].num);
    printf("Name:%s %s\n", seats[i].fname, seats[i].lname);
}

void delete (void)
{
    struct seat del_seat = {.reserved = true};
    int fnlen = 0;
    int lnlen = 0;
    int i;
    bool is_exist = false;

    /*取消预定*/
    while (del_seat.reserved)
    {
        /*输入姓名以及座位号*/
        printf("Please enter your first name (empty line to quit):");
        s_gets(del_seat.fname, LEN);
        if (del_seat.fname[0] == '\0')
            break;
        printf("Please enter your last  name:");
        s_gets(del_seat.lname, LEN);
        printf("Please enter your seat number:");
        s_gets(del_seat.num, NUM);
        del_seat.num[1] = toupper(del_seat.num[1]); //把座位号的字母字符转换成大写的
        
        /*该座位是否存在*/
        for (i = 0; i < SIZE; i++)
        {
            if (strstr(del_seat.num, seats[i].num) &&
                strstr(del_seat.fname, seats[i].fname) &&
                strstr(del_seat.lname, seats[i].lname))
            {
                is_exist = true;
                break;
            }
        }

        if (is_exist)
        {
            seats[i].reserved = false;
            del_seat.reserved = false;
            fnlen = strlen(seats[i].fname);
            lnlen = strlen(seats[i].lname);
            for (int j = 0; j < fnlen; j++)
                seats[i].fname[j] = '\0';
            for (int k = 0; k < fnlen; k++)
                seats[i].lname[k] = '\0';
        }
        else
        {
            printf("The information you entered is invalid, please re-enter！\n");
            is_exist = false;
            continue;
        }        
    }
    printf("Unsubscribe successfully!\n");
}

void reserve(void (*pfun)(void))
{
    (*pfun)();
}

/*读取收入字符串*/
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