#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "game.h"
void printmenu() {
	
	printf("####################\n");
	printf("######ɨ����Ϸ######\n");
	printf("####################\n");
	printf("1.��ʼ��Ϸ\n");
	printf("2.������Ϸ\n");
	printf("��ѡ��>");


	return;
}


int main() {
	//ɨ�׳�����ʽ��ʼ��д��2023��11��2��16��43��
	
	int selection = 0;
	while (2 != selection) {//��һ�ν���Ϊ0��������
		printmenu();
		scanf("%d", &selection);
		fflush(stdin);//��ʱ�����������¼ǵøĵ�
		switch (selection) {
		case 1:
			//��ʼ��Ϸ
			game();
			break;
		case 2:
			//������Ϸ
			printf("��Ϸ����");
			break;
		default:
			//�������
			printf("�����������������\n");
			break;
		}
	}
	


	return NULL;
}