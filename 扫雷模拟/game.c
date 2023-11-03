#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
#include "initialize.h"
#include "actions.h"
#include <stdio.h>

void game() {
	printf("游戏开始！！\n");
	initializeBoard();

	int hang = 0, lie = 0;
	while (1) {
		printf("\n请输入选定的坐标(行,列)>");
		scanf("%d,%d", &hang, &lie);
		fflush(stdin);//不标准的写法，稍后要改掉
		
		
	}
	



}