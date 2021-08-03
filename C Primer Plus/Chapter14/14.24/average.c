#include <stdio.h>
#include <string.h>
#define CSIZE 4
#define SLEN 21
struct name
{
    char fname[SLEN];
    char lname[SLEN];
}; //结构声明，学生姓名
struct student
{
    struct name fullname;
    float grade[3];
    float average;
}; //结构声明，成绩信息
void makeinfo(struct student *);
float stdavg(struct student *);
void showinfo(struct student *);
void classavg(struct student *);
char *s_gets(char *st, int n);

int main(void)
{
    struct student students[CSIZE]; //声明student类型结构数组

    /*完善学生信息*/
    printf("Enter studens\' information.\n");
    for (int i = 0; i < CSIZE; i++)
    {
        printf("Student %d:\n", i + 1);
        makeinfo(&students[i]);
        students[i].average = stdavg(&students[i]);
    }
    /*打印学生信息*/
    printf("\nHere are students' information:");
    showinfo(students);
    /*计算并打印全班成绩*/
    classavg(students);
    puts("Done!");

    return 0;
}

/*完善学生姓名及成绩*/
void makeinfo(struct student *info)
{
    /*提示输入姓名*/
    printf("Please enter first name:");
    s_gets(info->fullname.fname, SLEN);
    printf("Please enter last  name:");
    s_gets(info->fullname.lname, SLEN);

    /*提示输入语文、数学、英语三科成绩*/
    for (int i = 0; i < 3; i++)
    {
        printf("Enter the grade of course %d:", i + 1);
        scanf("%f", &info->grade[i]);
        while (getchar() != '\n') //清理输入行
            continue;
    }
}

/*计算并返回学生平均成绩*/
float stdavg(struct student *info)
{
    return (info->grade[0] + info->grade[1] + info->grade[2]) / 3;
}

/*打印学生信息*/
void showinfo(struct student *info)
{
    for (int i = 0; i < CSIZE; info++, i++)
    {
        printf("\nName:%s, %s\nGrade:", info->fullname.lname, info->fullname.fname);
        for (int i = 0; i < 3; i++)
            printf("%f ", info->grade[i]);
        printf("\nAverage:%f\n", info->average);
    }
}

/*计算并打印全班成绩*/
void classavg(struct student *info)
{
    float class_average = 0.0F;

    for (int i = 0; i < CSIZE; info++, i++)
        for (int j = 0; j < 3; j++)
            class_average += info->grade[j];

    printf("\nClass Average:%f\n", class_average / (CSIZE * 3));
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