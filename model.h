//加上头文件保护,这样在menu.c中定义card时可以直接用"Card card",而不需要用到"struct"
//如果没有,该头文件会在多文件包含时导致typedef定义被覆盖
#ifndef MODEL_H
#define MODEL_H

#include<time.h> //提供了时间类型time_t的数据类型
//定义卡信息结构体
typedef struct Card {
	char aName[18];  //卡号
	char aPwd[8];    //密码

	int nStatus;     // 卡状态(0-未上机；1-正在上机；2-已注销；3-失效)
	float fTotalUse; // 累计金额
	int nUseCount;   // 使用次数
	float fBalance;  // 余额
	int nDel;        // 删除标识(0-未删除,1-删除)

	time_t tStart;   //开卡时间
	time_t tEnd;     //截止时间
	time_t tLastUse; //最后使用时间
}Card;

//typedef struct Card Card;使用typedef关键字将"struct Card"重命名为"Card",便于后续使用简洁方便
//也可以按照上面写法直接重命名,更加简洁


//声明卡信息链表结点类型
typedef struct CardNode {
	Card data;
	struct CardNode* next;
}CardNode,*lpCardNode;//"*lpCardNode是指向结构体的指针

#endif // !MODEL_H

