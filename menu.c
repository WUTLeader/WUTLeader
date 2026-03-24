//将一些函数写在menu.c中,而不写在main.c中,是为了便于改错时,修正代码,且能让代码更清晰

#include<stdio.h>//包含输入输出函数的头文件
#include<time.h>//导入时间头文件,包含time(NULL),可获取当前时间
#include<stdlib.h>//包含countof函数
#include"model.h"//导入结构体数据定义头文件
#include"card_service.h"
#include"menu.h"
#include"tool.h"
#include<string.h>


void outputMenu(void) {
	printf("1.添加卡\n2.查询卡\n3.上机\n4.下机\n5.充值\n6.退费\n7.查询统计\n8.注销卡\n0.退出\n");
	//提示选择菜单编号
	printf("请选择菜单项编号(0-8):");
}

void add() {
	Card card;
	char aName[32] = { '\0' };
	char aPwd[20] = { '\0' };
	int nNameSize = 0;
	int nPwdSize = 0;
	printf("----------添加卡----------\n");
	printf("请输入卡号(长度为1-18位)：");
	scanf_s("%s", aName, (unsigned)_countof(aName));  //scanf_s要求对于%s必须额外指定缓冲区大小,否则行为是未定义的
	printf("请输入密码(长度为1-8位)：");
	scanf_s("%s", aPwd, (unsigned)_countof(aPwd));
	//将card.去掉,后续用来判断卡号与密码长度,防止过长

	//判断卡号和密码长度
	nNameSize = getSize(aName);
	nPwdSize = getSize(aPwd);
	if (nNameSize > 18 || nPwdSize > 8) {
		printf("卡号或密码超过规定长度\n");
	}
	strcpy_s(card.aName, sizeof(card.aName), aName);
	strcpy_s(card.aPwd, sizeof(card.aPwd), aPwd);


	printf("请输入开卡金额：");
	scanf_s("%f", &card.fBalance);
	card.fTotalUse = card.fBalance;
	card.nUseCount = 0;
	card.nStatus = 0;
	card.nDel = 0;
	card.tStart = card.tEnd = card.tLastUse = time(NULL);//获取当前时间

	addCard(card);

	printf("添加卡信息成功!\n\n");
	printf("---添加的卡信息如下---\n");
	printf("卡号\t密码\t卡状态\t余额\n");
	printf("%s\t%s\t%d\t%.1f\n", card.aName, card.aPwd, card.nStatus, card.fBalance);

}

int getSize(const char* pInfo) {//const用来保护数据,承诺不会修改传入的数据
	int nSize = 0;
	while (*(pInfo + nSize) != '\0') {
		nSize++;
	}
	return nSize;
}


void query() {
	char aName[18] = { 0 };//用来接受用户查询卡时输入的卡号
	char aTime[20] = { 0 };//用来接受转化后的字符串
	int nIndex = 0;
	int i = 0;
	Card* pCard = NULL;
	printf("----------查询卡----------\n");
	printf("请输入您要查询的卡号:");
	scanf_s("%s", aName, (unsigned)_countof(aName));
	pCard = queryCards(aName,&nIndex);

	//显示查询到卡的信息
	if (pCard != NULL||nIndex==0) {
		for (i = 0 ; i < nIndex ; i++) {
			//将时间转换为字符串
			timeToString(pCard[i].tLastUse, aTime);//改行代码必须放在if里面,如果放在外面,如果pCard使NULL,那么该行就运行不了,系统就崩溃
			printf("卡号\t状态\t余额\t累计使用\t使用次数\t上次使用时间\n");
			printf("%s\t%d\t%.1f\t%.1f\t\t%d\t\t%s\n",
				pCard[i].aName,
				pCard[i].nStatus,
				pCard[i].fBalance,
				pCard[i].fTotalUse,
				pCard[i].nUseCount,
				aTime
			);
		}
		
	}
	else {
		printf("您查询的卡号不存在,请检查您的卡号输入是否正确\n");
	}
}

void exitAPP() {
	releaseCardList();
}


