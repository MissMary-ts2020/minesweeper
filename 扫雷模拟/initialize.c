#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
#include "initialize.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void putBombs2() {
	//放雷函数
	//放雷前，先清空棋盘
	int i = 0, j = 0;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			board[i][j] = 0;
		}
	}
	//生成一串坐标数值
	int positions[BOMBS][2];
	//[x][0]为行数，[x][1]为列数
	
	int k = 0;
	//总循环BOMBS次
	for (; k < BOMBS; k++) {
		srand(time(0));
		int flag = 1;//是否需要重来的标记
		int hang = 0, lie = 0;
		while (flag) {
			flag = 0;//设生成的就是未重复的数对
			
			hang = rand() % HEIGHT;
			lie = rand() % WIDTH;
			//此时是第k个坐标数对
			int a = 0;//检查临时标记
			for (; a < k; a++) {
				//执行检查
				if (positions[a][0] == hang && positions[a][1] == lie) {
					flag = 1;
				}
			}
		}
		//执行写入
		positions[k][0] = hang, positions[k][1] = lie;
	}
	for (k = 0; k < BOMBS; k++) {
		//写入棋盘
		int hang_write = positions[k][0], lie_write = positions[k][1];
		board[hang_write][lie_write] = 9;
	}


}
/*-----------------------------
* 这个算法太烂了
* 
void putBombs() {
	//放雷函数
	//放雷前，先清空棋盘
	int i = 0, j = 0;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			board[i][j] = 0;
		}
	}

	//清空完毕，初始化一遍
	i = 0, j = 0;
	int bombs_already = 0;
	while (bombs_already < BOMBS) {
		for (i = 0; i < HEIGHT; i++) {
			//按行遍历，即每一行
			for (j = 0; j < WIDTH; j++) {
				//遍历每一个格子，处理的格子为[i][j]
				//概率为（总雷数-已经埋了的雷数）/（格子数-已经埋了的雷数）
				if (bombs_already >= BOMBS) {
					return;//减少最后一次遍历的次数
				}
				if (9 == board[i][j] || bombs_already >= BOMBS) {
					//已经放置雷或雷数已满，则跳过这个格子
					continue;
				}
				srand(time(0));
				//生成的数值范围为分母
				int randomrange = HEIGHT * WIDTH - bombs_already;
				//若落在分子以内，则放雷；反之，不放雷
				int conditionrange = BOMBS - bombs_already;//为了避免概率为0，若确实为0则改为1,纯粹用于规避bug
				int random_number = rand() % randomrange;
				//小于就放置一个雷，大于就不放置
				if (random_number <= conditionrange) {
					board[i][j] = 9;//放置
					bombs_already++;
					continue;
				}
			}
		}
	}

}
----------------------------------*/
void putnumbers() {
	int i = 0, j = 0;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			if (9 == board[i][j]) {
				continue;//遇到雷就跳过
			}
			//从该格子的左上角开始，选取9个格子
			int a = i - 1, b = i - 1, count = 0;
			for (a = i - 1; a <= i + 1; a++) {
				for (b = j - 1; b <= j + 1; b++) {
					//出现[a][b]这个格子在棋盘外面的话，就不考虑这种情况。
					if (a < 0 || b < 0 || a >= HEIGHT || b >= WIDTH) {
						continue;
					}
					if (9 == board[a][b]) {
						count++;
					}
				}
			}
			board[i][j] = count;


		}
	}
}
void charize() {
	//字符化
	int i = 0, j = 0;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			if (9 == board[i][j]) {
				board_forgame[i][j] = 'B';
				continue;
			}
			else if (0 == board[i][j]) {
				board_forgame[i][j] = ' ';
			}
			else {
				//1-8的数字
				switch (board[i][j]) {
				
				case 1:
					board_forgame[i][j] = '1';
					break;
				case 2:
					board_forgame[i][j] = '2';
					break;
				case 3:
					board_forgame[i][j] = '3';
					break;
				case 4:
					board_forgame[i][j] = '4';
					break;
				case 5:
					board_forgame[i][j] = '5';
					break;
				case 6:
					board_forgame[i][j] = '6';
					break;
				case 7:
					board_forgame[i][j] = '7';
					break;
				case 8:
					board_forgame[i][j] = '8';
					break;
				}
			}
		}
	}
}
void mengban_initialize() {
	int i = 0, j = 0;
	for (; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			mengban[i][j] = '0';
		}
	}
}

void initializeBoard() {//棋盘初始化
	//首先确定雷的位置
	//需要随机生成BOMBS对
	printf("正在初始化棋盘.........");

	//放置雷，雷是9
	putBombs2();
	//放置数字
	putnumbers();
	//字符化
	charize();
	//蒙版初始化
	mengban_initialize();

	printf("ok\n棋盘初始化成功！\n");
	//仅供测试时使用，正式游戏的时候要注释掉，否则答案就显示了
	printBoard(board_forgame);
	printBoard(mengban);

}
void printBoard(char beprinted_board[HEIGHT][WIDTH]) {//蒙版打印
	printf("\n********************************\n");
	int i = 0, j = 0, k = 0;
	for (i = 0; i < HEIGHT; i++) {
		/*
		knk|knk|knk
		----------- 4
		*/
		for (j = 0; j < WIDTH; j++) {
			printf(" %c ", beprinted_board[i][j]);
			if (WIDTH - 1 != j) {
				printf("|");//不是最后一列都要打印一个分隔符
			}
		}
		printf("\n");//换行，开始打印横线

		if (HEIGHT - 1 != i) {//不是最后一行都要打印一行横线
			for (k = 0; k < WIDTH * 4 - 1; k++) {
				printf("-");//共4倍宽度-1跟横线
			}
		}

		printf("\n");

	}
	printf("\n********************************\n");

}
