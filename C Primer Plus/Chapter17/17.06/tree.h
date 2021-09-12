/* tree.h -- 二叉查找树，树中不允许由重复的项*/
#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>
#define SLEN 20     //字符串长度上限
#define MAXITEMS 10 //二叉树中节点/项数的上限

/*类型定义*/

typedef struct item{
    char petname[SLEN];
    char petkind[SLEN];
} Item; //项结构声明

typedef struct trnode{
    Item item;            //项
    struct trnode *left;  //指向左子节点的指针
    struct trnode *right; //指向右子节点的指针
} Trnode;                 //二叉树节点结构声明

typedef struct tree{
    Trnode *root; //指向整个二叉树根节点的指针
    int size;     //二叉树中节点/项的数量
} Tree;           //二叉树结构声明

/*函数原型*/

/*操作：把二叉树初始化为空*/
/*前置条件：ptree指向一个二叉树*/
/*后置条件：二叉树被初始化为空*/
void InitializeTree(Tree *ptree);

/*操作：确定二叉树是否为空*/
/*前置条件：ptree指向一个二叉树*/
/*后置条件：如果二叉树为空，该函数返回true；否则，返回false*/
bool TreeIsEmpty(const Tree *ptree);

/*操作：确定二叉树是否已满*/
/*前置条件：ptree指向一个二叉树*/
/*后置条件：如果二叉树已满，该函数返回true；否则，返回false*/
bool TreeIsFull(const Tree *ptree);

/*操作：确定二叉树的项数*/
/*前置条件：ptree指向一个二叉树*/
/*后置条件：返回二叉树的项数*/
int TreeItemCount(const Tree *ptree);

/*操作：在二叉树中添加一个项*/
/*前置条件：pi是待添加项的地址，ptree指向一个已初始化的树*/
/*后置条件：如果可以添加，该函数将在树中添加一个项并返回true；否则，返回false*/
bool AddItem(const Item *pi, Tree *ptree);

/*操作：在二叉树中查找一个项*/
/*前置条件：pi指向一个项，ptree指向一个已初始化的二叉树*/
/*后置条件：如果在树中添加一个项，该函数返回true；否则，返回false*/
bool InTree(const Item *pi, const Tree *ptree);

/*操作：从二叉树中删除一个项*/
/*前置条件：pi是删除项的地址，ptree指向一个已初始化的二叉树*/
/*后置条件：如果从二叉树中成功删除一个项，该函数返回true；否则，返回false*/
bool DeleteItem(const Item *pi, Tree *ptree);

/*操作：把函数应用于二叉树中的每一项*/
/*前置条件：ptree指向一个二叉树，pfun指向接受一个Item类型的参数并无返回值的函数*/
/*后置条件：pfun指向的这个函数为二叉树中的每一项执行一次*/
void Traverse(const Tree *ptree, void (*pfun)(Item item));

/*操作：删除二叉树中的所有内容*/
/*前置条件：ptree指向一个已初始化的二叉树*/
/*后置条件：二叉树为空*/
void DeleteAll(Tree *ptree);

#endif