#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
#include "initialize.h"
#include "actions.h"
#include <stdio.h>



void game() {
	printf("��Ϸ��ʼ����\n");
	initializeBoard();

	int hang = 0, lie = 0;
	
	while (flag_end) {
		printf("\n������ѡ��������(��,��)>");
		scanf("%d,%d", &hang, &lie);
		fflush(stdin);//����׼��д�����Ժ�Ҫ�ĵ�
		

		switch (check_selection(hang,lie)) {
		case 1:
			//Խ��
			printf("\n�����ֵ���������̵ķ�Χ,������ѡ��\n");
			break;
		case 2:
			//δ�ڿ�
			printf("\n�������δ�������κβ���\n");
			action(hang, lie);
			break;
		case 3:
			//�Ѳ���
			printf("\n��������Ѿ�������������\n");
			action_flaged(hang, lie);
			break;
		case 4:
			//���ڿ�
			printf("\n��������Ѿ����ڿ���,������ѡ��\n");
			break;
		default:
			printf("error");
			break;

		}
		
	}
	//����˴�ʱ����Ϸ�Ѿ�����
	switch (win_end) {
	case 0:
		printf("�����ˣ�\n");
		break;
	case 1:
		printf("��Ӯ�ˣ���\n");
		break;
	default:
		printf("error");
		break;
	}
	



}