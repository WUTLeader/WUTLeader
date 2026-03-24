#include<stdio.h>
#include"menu.h"//自定义文件头文件用""
#include"model.h"




int main() {
	//必须调用这个函数,才能进入到这个链表中
	if (!initInitCardList()) {
		printf("链表初始化失败，程序无法继续！\n");
		return 1; // 初始化失败直接退出
	}
	int choice;
	printf("欢迎进入计费管理系统\n");
	do {
		printf("----------菜单----------\n");
		outputMenu();
		scanf_s("%d", &choice);
		printf("\n\n");
		switch (choice) {
		case 1:
			add();
			break;
		case 2:
			query();
			break;
		case 3:printf("您选择了:上机");
			break;
		case 4:printf("您选择了:下机");
			break;
		case 5:printf("您选择了:充值");
			break;
		case 6:printf("您选择了:退费");
			break;
		case 7:printf("您选择了:查询统计");
			break;
		case 8:printf("您选择了:注销卡");
			break;
		case 0:
			exitAPP();
			printf("您选择了:退出\n感谢使用本计费管理系统,欢迎下次使用!");
			break;
		default:printf("您输入的菜单项有问题,请再次输入\n");
			break;
		}
		printf("\n\n\n");
	} while (choice != 0);
	return 0;
}

