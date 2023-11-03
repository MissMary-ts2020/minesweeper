#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
#include "initialize.h"
#include "actions.h"
#include <stdio.h>


void dig(int hang, int lie) {
	if ('0' != mengban[hang][lie]||mengban[hang][lie]=='F') {
		//已经挖开或插旗，跳过
		return;
	}
	mengban[hang][lie] = board_forgame[hang][lie];//先显示中心格子
	if (0 != board[hang][lie]) {
		//如果第一个格子就是数字，那就不再探查了
		return;
	}
	int i = hang - 1, j = lie - 1;
	for (i = hang - 1; i <= hang + 1; i++) {
		for (j = lie - 1; j <= lie - 1; j++) {
			//开挖标准，只要不是雷或者是旗子就要显示出来
			if (j<0 || i<0 || j>WIDTH - 1 || i>HEIGHT - 1||(hang==i&&lie==j)) {
				continue;//若格子在棋盘外则跳过
				//以及若是中心格子就跳过
			}
			
			if (mengban[i][j] = board_forgame[i][j] == ' '&&mengban[i][j]!='F'&&board[i][j]!=9) {
				//挖到的部分是空格且没有被插旗,甚至不是雷
				dig(i, j);//对于这个空格格子进行一次开挖，递归
			}
		}
	}
}

void action(int hang, int lie) {
	show_selection(hang, lie);
	//打印选择菜单
	print_actionMenu(1);
	char The_action = '0';
	while ('1' != The_action && '2' != The_action && '3' != The_action) {
		The_action = getchar();
		fflush(stdin);
		if ('1' != The_action && '2' != The_action && '3' != The_action) {
			//提示错误信息
			printf("选择错误，请重新选择\n");
			print_actionMenu(1);
		}
	}
	switch (The_action) {
	case '1':
		//挖开格子
		if (9 == board[hang][lie]) {
			//游戏结束
			flag_end = 0;
			win_end = 0;
		}
		else {
			//这里是比较复杂的开挖过程,放在了外面的函数内
			dig(hang, lie);

		}
		//每次安全地挖完格子后，需要检查游戏是否胜利
		//胜利条件为蒙版内除了雷以外的格子都被挖开
		//没赢的条件为：有不是雷的格子没有被挖开
		int i = 0, j = 0;
		int flag_tmp = 1;
		for (i = 0; i < HEIGHT; i++) {
			for (j = 0; j < WIDTH; j++) {
				if (9 != board[i][j] && '0' == mengban[i][j]) {
					flag_tmp = 0;
					break;
				}
			}
			if (!flag_tmp) {
				break;
			}
		}
		if (flag_tmp) {
			flag_end = 0;
			win_end = 1;//胜利
		}
		break;
	case '2':
		//插旗
		mengban[hang][lie]='F';
		break;
	case '3':
		printf("取消选中，好的\n");

		break;
	default:
		printf("error");
		break;


	}
	//各项操作结束

	
	return;
}

void action_flaged(int hang, int lie){
	show_selection(hang, lie);
	//打印选择菜单
	print_actionMenu(2);
	char The_action = '0';

	while ('1' != The_action && '2' != The_action) {
		The_action = getchar();
		fflush(stdin);
		if ('1' != The_action && '2' != The_action) {
			//提示错误信息
			printf("选择错误，请重新选择\n");
			print_actionMenu(2);
		}
	}
	return;
}

void show_selection(int hang,int lie) {
	char mengban_tmp = mengban[hang][lie];
	mengban[hang][lie] = '@';
	printBoard(mengban);
	printf("@为你所选择的格子，为第%d行第%d列。\n", hang, lie);
	mengban[hang][lie] = mengban_tmp;

}

void print_actionMenu(int action_type) {
	switch (action_type) {
	case 1:
		//未挖开
		printf("你有三个选项:\n");
		printf("1.挖开这个格子\n");
		printf("2.插旗\n");
		printf("3.取消选中\n");
		printf("请选择动作(菜单2)>");
		break;
	case 2:
		//已插旗
		printf("你有三个选项:\n");
		printf("1.取消插旗\n");
		printf("2.取消选中\n");
		printf("请选择动作(菜单3)>");
		break;
	default:
		printf("error");
		break;
	}
}

int check_selection(int hang,int lie) {
	if (!(hang >= 0 && hang < HEIGHT && lie >= 0 && lie < WIDTH)) {
		return 1;//越界
	}
	switch (mengban[hang][lie]) {
		//通过蒙版状况的检查，来反馈
	case '0':
		//未挖开
		return 2;
		break;
	case 'F':
		//已插旗
		return 3;
		break;
	default:
		//已挖开
		return 4;
		break;
	}
}

