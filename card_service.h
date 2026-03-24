#ifndef CARD_SERVICE_H
#define CARD_SERVICE_H
#include"model.h"

int addCard(Card card);//将添加卡的卡信息放到该结构体数组中,便于查询卡
Card* queryCard(const char* pName);//该函数用来获取查询到的卡信息
int initInitCardList();////编写初始化链表函数
void releaseCardList();//该函数用来释放卡信息链表
Card* queryCard(const char* pName);//精准查询
Card* queryCards(const char* pName, int* pIndex);//模糊查询
#endif // !CARD_SERVICE_H
