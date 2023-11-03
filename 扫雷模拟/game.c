#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
#include "initialize.h"
#include "actions.h"
#include <stdio.h>
int flag = 1;//游戏继续标志，是一个全局变量

void game() {
	printf("游戏开始！！\n");
	initializeBoard();

	int hang = 0, lie = 0;
	
	while (flag) {
		printf("\n请输入选定的坐标(行,列)>");
		scanf("%d,%d", &hang, &lie);
		fflush(stdin);//不标准的写法，稍后要改掉
		switch (check_selection(hang,lie)) {
		case 1:
			//越界
			printf("\n这个数值超过了棋盘的范围,请重新选择\n");
			break;
		case 2:
			//未挖开
			printf("\n这个格子未被进行任何操作\n");
			action(hang, lie, board[hang][lie]);
			break;
		case 3:
			//已插旗
			printf("\n这个格子已经被插上了棋子\n");
			action_flaged(hang, lie, board[hang][lie]);
			break;
		case 4:
			//已挖开
			printf("\n这个格子已经被挖开了,请重新选择\n");
			break;
		default:
			printf("error");
			break;

		}
		
	}
	



}