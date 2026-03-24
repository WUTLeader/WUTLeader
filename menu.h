//防止头文件的内容被重复包含导致定义错误
#ifndef MENU_H

#define MENU_H

void outputMenu(void);//该函数是用来输出菜单
void query();//输出查询卡菜单名称
int getSize(const char* pInfo);//计算输入卡号密码有多少位
void add();//声明添加卡函数
void exitAPP();//退出时调用releaseCardList函数,释放卡信息链表

#endif // !MENU_H
