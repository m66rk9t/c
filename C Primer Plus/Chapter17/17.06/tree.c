/* tree.c -- 二叉查找树接口的实现*/
#include <string.h>
#include <stdio.h>  //提供strcmp()原型
#include <stdlib.h> //提供malloc()和free()原型
#include "tree.h"   //包含接口文件

/*局部数据类型*/
typedef struct pair{
    Trnode *parent; //指向含待查项节点的父节点
    Trnode *child;  //指向含待查项的节点
} Pair;

/*内部链接函数原型*/
static Trnode *MakeNode(const Item *pi);
static bool ToLeft(const Item *i1, const Item *i2);
static bool ToRight(const Item *i1, const Item *i2);
static void AddNode(Trnode *new_node, Trnode *root);
static void InOrder(const Trnode *root, void (*pfun)(Item item));
static Pair SeekItem(const Item *pi, const Tree *ptree);
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode *ptr);

/*接口函数定义*/
/*初始化二叉树*/
void InitializeTree(Tree *ptree)
{
    ptree->root = NULL; //将二叉树根节点初始化为NULL
    ptree->size = 0;    //将二叉树节点/项数量初始化为0
}

/*检测二叉树是否为空*/
bool TreeIsEmpty(const Tree *ptree)
{
    /*判断根节点指针是否为空*/
    if (ptree->root == NULL)
        return true;
    else
        return false;
}

/*检测二叉树是否已满*/
bool TreeIsFull(const Tree *ptree)
{
    /*与二叉树节点/项数明示常量进行比较*/
    if (ptree->size == MAXITEMS)
        return true;
    else
        return false;
}

/*统计二叉树中节点/项的数量*/
int TreeItemCount(const Tree *ptree)
{
    return ptree->size; //返回二叉树结构中节点/项数成员值
}

/*在二叉树中添加一项*/
bool AddItem(const Item *pi, Tree *ptree)
{
    Trnode *new_node; //指向新节点的指针

    /*判断二叉树是否已满，如果已满则返回false表示添加失败*/
    if (TreeIsFull(ptree))
    {
        fprintf(stderr, "Tree is full\n");
        return false;
    }

    /*检测是否为重复项，如果是重复项则返回false表示添加失败*/
    if (SeekItem(pi, ptree).child != NULL)
    {
        fprintf(stderr, "Attempted to add duplicate item\n");
        return false;
    }

    new_node = MakeNode(pi); //二叉树未满且待添加项不是重复项，则初始化一个节点

    /*判断初始化节点是否成功*/
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node\n");
        return false;
    }

    ptree->size++; //初始化成功，二叉树节点/项数+1

    if (ptree->root == NULL) //如果二叉树是空树，将新节点设置为整个二叉树的根节点
        ptree->root = new_node;
    else //否则就将新节点添加到子树中合适的位置
        AddNode(new_node, ptree->root);

    return true; //成功添加一项
}

/*某项是否在二叉树中*/
bool InTree(const Item *pi, const Tree *ptree)
{ /*SeekItem()与条件表达式搭配使用*/
    return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

/*删除指定项*/
bool DeleteItem(const Item *pi, Tree *ptree)
{
    Pair look; //声明特定的查找项结构

    look = SeekItem(pi, ptree); //查找

    /*如果未找到则退出函数并返回false，表示二叉树中没有待删项，删除失败*/
    if (look.child == NULL)
        return false;
    /*如果待删项存在于二叉树中*/
    if (look.parent == NULL)                  //如果待删项是根节点中的项
        DeleteNode(&ptree->root);             //删除根节点
    else if (look.parent->left == look.child) //判断包含待删项的节点是左还是右子节点
        DeleteNode(&look.parent->left);       //删除节点
    else
        DeleteNode(&look.parent->right); //删除节点
    ptree->size--;                       //二叉树节点/项数-1

    return true; //成功删除指定项
}

/*将指定的函数应用于二叉树中的每一项*/
void Traverse(const Tree *ptree, void (*pfun)(Item item))
{

    if (ptree != NULL)
        InOrder(ptree->root, pfun);
}

/*清空二叉树*/
void DeleteAll(Tree *ptree)
{
    if (ptree != NULL)               //如果不是空树
        DeleteAllNodes(ptree->root); //删除所有节点
    ptree->root = NULL;              //重置二叉树根节点指针
    ptree->size = 0;                 //重置二叉树节点/项数
}

/*内部链接函数定义*/
/*处理二叉树中的每个节点*/
static void InOrder(const Trnode *root, void (*pfun)(Item item))
{
    if (root != NULL)               //判断是否为空树
    {                               /*递归调用*/
        InOrder(root->left, pfun);  //处理左子树
        (*pfun)(root->item);        //处理项
        InOrder(root->right, pfun); //处理右子树
    }
}

/*删除二叉树中的所有节点*/
static void DeleteAllNodes(Trnode *root)
{
    Trnode *pright; //临时变量，储存该树的右子节点的地址

    if (root != NULL)               //判断是否为空
    {                               /*递归调用*/
        pright = root->right;       //将右子节点的地址赋给临时变量
        DeleteAllNodes(root->left); //处理左子树
        free(root);                 //释放该树的根节点
        DeleteAllNodes(pright);     //处理右子树
    }
}

/*将节点添加至二叉树中合适的位置*/
static void AddNode(Trnode *new_node, Trnode *root)
{
    if (ToLeft(&new_node->item, &root->item)) //是否添加到左子树中
    {
        if (root->left == NULL)    //如果左子树为空
            root->left = new_node; //将该节点设置为左子树的根节点
        else
            AddNode(new_node, root->left); //否则递归调用，处理左子树
    }
    else if (ToRight(&new_node->item, &root->item)) //是否添加到右子树中
    {
        if (root->right == NULL)    //如果右子树为空
            root->right = new_node; //将该节点设置为右子树的根节点
        else
            AddNode(new_node, root->right); //否则递归调用，处理右子树
    }
    else //重复项，输出错误信息并异常结束程序
    {
        fprintf(stderr, "location error in AddNode()\n");
        exit(1);
    }
}

/*处理左子树*/
static bool ToLeft(const Item *i1, const Item *i2)
{
    int comp1;

    if ((comp1 = strcmp(i1->petname, i2->petname)) < 0) //比较名
        return true;
    else if (comp1 == 0 &&
             strcmp(i1->petkind, i2->petkind) < 0) //比较品种
        return true;
    else
        return false;
}

/*处理右子树*/
static bool ToRight(const Item *i1, const Item *i2)
{
    int comp1;

    if ((comp1 = strcmp(i1->petname, i2->petname)) > 0) //比较名
        return true;
    else if (comp1 == 0 &&
             strcmp(i1->petkind, i2->petkind) > 0) //比较品种
        return true;
    else
        return false;
}

/*初始化一个节点*/
static Trnode *MakeNode(const Item *pi)
{
    Trnode *new_node; //指向新节点的指针

    new_node = (Trnode *)malloc(sizeof(Trnode)); //为新节点分配动态内存
    if (new_node != NULL)                        //判断是否分配成功
    {
        new_node->item = *pi;   //设置新节点的项
        new_node->left = NULL;  //设置左子节点
        new_node->right = NULL; //设置右子节点
    }

    return new_node; //返回指向新节点的指针
}

/*查找指定项*/
static Pair SeekItem(const Item *pi, const Tree *ptree)
{
    Pair look;                //声明特定的待查项的结构
    look.parent = NULL;       //从整个二叉树的根节点开始，根节点是没有父节点的
    look.child = ptree->root; //将指向可能含待查项的节点的指针初始化为二叉树的根节点

    /*判断二叉树是否为空*/
    if (look.child == NULL)
        return look;
    /*二叉树不为空*/
    while (look.child != NULL) //子节点不为空时循环查找
    {
        if (ToLeft(pi, &(look.child->item))) //处理左子树
        {
            look.parent = look.child;      //设置父节点
            look.child = look.child->left; //设置子节点
        }
        else if (ToRight(pi, &(look.child->item))) //处理左子树
        {
            look.parent = look.child;       //设置父节点
            look.child = look.child->right; //设置子节点
        }
        else       //如果前两种情况都不满足，则必定是相等的情况
            break; //退出循环，表示当前节点为含有待查项的节点
    }

    return look; //成功查找到指定项
}

/*删除一个节点*/
static void DeleteNode(Trnode **ptr)
{                 /*ptr是指向目标节点的父节点的指针成员的地址，不能是指向目标节点的指针的地址*/
    Trnode *temp; //临时变量

    if ((*ptr)->left == NULL) //待删节点的左子树为空
    {
        temp = *ptr;          //将待删节点的地址赋给临时变量
        *ptr = (*ptr)->right; //将待删节点的父节点的指针成员重置为右子树的地址
        free(temp);           //释放节点空间
    }
    else if ((*ptr)->right == NULL) //待删节点的右子树为空
    {
        temp = *ptr;         //将待删节点的地址赋给临时变量
        *ptr = (*ptr)->left; //将待删节点的父节点的指针成员重置为左子树的地址
        free(temp);          //释放节点空间
    }
    else //待删节点有两个子节点
    {
        /*找到重新链接右子树的位置*/
        for (temp = (*ptr)->left; temp->right != NULL;
             temp = temp->right)
            continue;
        temp->right = (*ptr)->right; //将待删节点的右子树链接到左子树中合适的位置
        temp = *ptr;                 //将待删节点的地址赋给临时变量
        *ptr = (*ptr)->left;         //将待删节点的父节点的指针成员重置为右子树的地址
        free(temp);                  //释放节点空间
    }
}