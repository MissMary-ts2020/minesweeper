#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
#include "initialize.h"
#include "actions.h"
#include <stdio.h>

void game() {
	printf("��Ϸ��ʼ����\n");
	initializeBoard();

	int hang = 0, lie = 0;
	while (1) {
		printf("\n������ѡ��������(��,��)>");
		scanf("%d,%d", &hang, &lie);
		fflush(stdin);//����׼��д�����Ժ�Ҫ�ĵ�
		
		
	}
	



}