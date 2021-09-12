/*petclub.c -- 使用二叉查找树*/
/*与tree.c一起编译*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h" //包含二叉树接口文件

/*函数原型*/
char menu(void);
void addpet(Tree *pt);
void droppet(Tree *pt);
void showpets(const Tree *pt);
void findpet(const Tree *pt);
void printitem(Item item);
void uppercase(char *str);
char *s_gets(char *st, int n);

int main(void)
{
    Tree pets;   //声明一个二叉树
    char choice; //储存选项字符

    InitializeTree(&pets); //初始化二叉树
    /*显示菜单，读取选项*/
    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
        case 'a':
            addpet(&pets); //添加
            break;
        case 'l':
            showpets(&pets); //显示项
            break;
        case 'f':
            findpet(&pets); //查找
            break;
        case 'n':
            printf("%d pets in club\n",
                   TreeItemCount(&pets)); //统计项数
            break;
        case 'd':
            droppet(&pets); //删除项
            break;
        default:
            puts("Switching error");
        }
    }
    DeleteAll(&pets); //清空树
    puts("Bye.");

    return 0;
}

/*显示菜单并返回选择的选项字符*/
char menu(void)
{
    int ch;

    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to your choice:");
    puts("a) add a pet          l) show list of pets");
    puts("n) number of pets     f) find pets");
    puts("d) delete a pet       q) quit");
    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n') //清理输入行
            continue;
        ch = tolower(ch);
        if (strchr("alrfndq", ch) == NULL)
            puts("Please enter an a, l, f, n, d, or q:");
        else
            break;
    }
    if (ch == EOF) //读取到EOF也返回'q'
        ch = 'q';

    return ch;
}

/*添加项*/
void addpet(Tree *pt)
{
    Item temp;

    if (TreeIsFull(pt)) //检查树是否已满
        puts("No room in the club!");
    else
    {
        puts("Please enter name of pet:");
        s_gets(temp.petname, SLEN); //输入宠物名
        puts("Please enter pet kind:");
        s_gets(temp.petkind, SLEN); //输入宠物品种
        uppercase(temp.petname);
        uppercase(temp.petkind);
        AddItem(&temp, pt); //将新项添加至二叉树中
    }
}

/*显示二叉树中的每一项*/
void showpets(const Tree *pt)
{
    if (TreeIsEmpty(pt)) //检查树是否为空
        puts("No entries!");
    else
        Traverse(pt, printitem);
}

/*打印项*/
void printitem(Item item)
{
    printf("Pet: %-19s  Kind: %-19s\n", item.petname,
           item.petkind);
}

/*查找项*/
void findpet(const Tree *pt)
{
    Item temp;

    if (TreeIsEmpty(pt)) //检查树是否为空
    {
        puts("No entries!");
        return;
    }

    puts("Please enter name of pet you wish to find:");
    s_gets(temp.petname, SLEN); //输入待查项的名
    puts("Please enter pet kind:");
    s_gets(temp.petkind, SLEN); //输入待查项的品种
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s the %s ", temp.petname, temp.petkind);
    if (InTree(&temp, pt)) //查找项，返回值为true或false
        printf("is a member.\n");
    else
        printf("is not a member.\n");
}

/*删除指定项*/
void droppet(Tree *pt)
{
    Item temp;

    if (TreeIsEmpty(pt)) //检查树是否为空
    {
        puts("No entries!");
        return;
    }

    puts("Please enter name of pet you wish to delete:");
    s_gets(temp.petname, SLEN); //输入待删项的名
    puts("Please enter pet kind:");
    s_gets(temp.petkind, SLEN); //输入待删项的品种
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s the %s ", temp.petname, temp.petkind);
    if (DeleteItem(&temp, pt)) //删除指定项，返回值为true或false
        printf("is dropped from the club.\n");
    else
        printf("is not a member.\n");
}

/*将小写字母转换成大写字母*/
void uppercase(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

/*读取输入字符串*/
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