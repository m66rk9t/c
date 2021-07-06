/*hotel.h--定义符号常量以及函数原型*/
#define QUIT 5
#define HOTLE1 180.00
#define HOTLE2 225.00
#define HOTLE3 255.00
#define HOTLE4 355.00
#define DISCOUNT 0.95
#define STARS "*********************"

//显示选择列表
int showmenu(void);

//返回预定天数
int getnights(void);

//根据费率、预定天数计算费用并显示结果
void showprice(double rate, int nights);