#include"model.h"
#include<string.h>
#include"global.h"
#include<stdlib.h>

Card aCard[50];//全局结构体数组,保存添加卡的信息
int nCount = 0;

lpCardNode cardList = NULL;//定义全局头指针(会一直记住它),可以通过它来找到头节点,一边访问整个链表

//编写初始化链表函数
int initInitCardList()
{
    lpCardNode head = NULL;  // 定义指针,head是指针,它指向头节点
    head = (lpCardNode)malloc(sizeof(CardNode));//申请一块内存用来给head
    if (head == NULL) {
        return FALSE;
    }
    if (head != NULL)//检查内存是否分配成功
    {
        head->next = NULL;
        cardList = head;  // 让 cardList 指向头结点
        return TRUE;
    }
}

//释放卡信息链表
void releaseCardList(){
    if (cardList == NULL) {
        return;//链表未初始化直接返回
    }
    lpCardNode p = cardList;  // p 指向头结点
    lpCardNode temp;

    // 遍历释放所有节点（包括头结点）
    while (p != NULL)
    {
        temp = p;           // temp保存当前节点地址
        p = p->next;        // p直接指向下一个节点
        free(temp);         // 释放当前节点
    }
    cardList = NULL;        // 释放后将头指针置空

}


int addCard(Card card) {
    // 1. 申请新节点接受卡信息
    lpCardNode cur = (lpCardNode)malloc(sizeof(CardNode));
    if (cur == NULL) {  
        return FALSE;
    }

    // 2. 填充数据
    cur->data = card;
    cur->next = NULL;

    // 3. 找到链表尾部（带头结点，从 cardList 开始遍历）
    lpCardNode p = cardList;
    while (p->next != NULL) {
        p = p->next;
    }

    // 4. 把新节点挂到尾部
    p->next = cur;

    return TRUE;
}

//精确查询
Card* queryCard(const char* pName) {
    if (cardList == NULL) {
        return NULL;
    }
    // 跳过头结点，从第一个数据节点开始
    lpCardNode p = cardList->next;

    while (p != NULL) {
        // 比较卡号是否匹配
        if (strcmp(p->data.aName, pName) == 0) {
            return &(p->data);  // 返回卡信息的指针
        }
        p = p->next;  // 移动到下一个节点
    }

    return NULL;  // 未找到，返回NULL
}

//模糊查询
Card* queryCards(const char* pName, int* pIndex) {
    // 1. 参数检查
    if (pIndex == NULL) {
        return NULL;
    }
    *pIndex = 0;

    // 2. 检查链表是否初始化
    if (cardList == NULL || cardList->next == NULL) {
        return NULL;
    }

    // 3. 初始分配内存
    Card* pCard = (Card*)malloc(sizeof(Card));
    if (pCard == NULL) {
        return NULL;
    }

    // 4. 跳过头结点开始遍历
    lpCardNode p = cardList->next;

    while (p != NULL) {
        if (strstr(p->data.aName, pName) != NULL) {
            // 存储匹配的卡信息
            pCard[*pIndex] = p->data;
            (*pIndex)++;

            // 重新分配内存（预留下一个位置）
            Card* newCard = (Card*)realloc(pCard, ((*pIndex) + 1) * sizeof(Card));
            if (newCard == NULL) {
                // realloc 失败，原 pCard 仍然有效，返回已找到的结果
                return pCard;
            }
            pCard = newCard;
        }
        p = p->next;
    }

    // 如果没有找到任何卡，释放内存并返回 NULL
    if (*pIndex == 0) {
        free(pCard);
        return NULL;
    }

    return pCard;
}