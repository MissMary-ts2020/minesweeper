#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "game.h"
void printmenu() {
	
	printf("####################\n");
	printf("######扫雷游戏######\n");
	printf("####################\n");
	printf("1.开始游戏\n");
	printf("2.结束游戏\n");
	printf("请选择>");


	return;
}


int main() {
	//扫雷程序正式开始编写，2023年11月2日16点43分
	
	int selection = 0;
	while (2 != selection) {//第一次进入为0，会进入的
		printmenu();
		scanf("%d", &selection);
		fflush(stdin);//暂时这样处理，等下记得改掉
		switch (selection) {
		case 1:
			//开始游戏
			game();
			break;
		case 2:
			//结束游戏
			printf("游戏结束");
			break;
		default:
			//输入错误
			printf("输入错误，请重新输入\n");
			break;
		}
	}
	


	return NULL;
}