#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
#include "initialize.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void putBombs2() {
	//���׺���
	//����ǰ�����������
	int i = 0, j = 0;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			board[i][j] = 0;
		}
	}
	//����һ��������ֵ
	int positions[BOMBS][2];
	//[x][0]Ϊ������[x][1]Ϊ����
	
	int k = 0;
	//��ѭ��BOMBS��
	for (; k < BOMBS; k++) {
		srand(time(0));
		int flag = 1;//�Ƿ���Ҫ�����ı��
		int hang = 0, lie = 0;
		while (flag) {
			flag = 0;//�����ɵľ���δ�ظ�������
			
			hang = rand() % HEIGHT;
			lie = rand() % WIDTH;
			//��ʱ�ǵ�k����������
			int a = 0;//�����ʱ���
			for (; a < k; a++) {
				//ִ�м��
				if (positions[a][0] == hang && positions[a][1] == lie) {
					flag = 1;
				}
			}
		}
		//ִ��д��
		positions[k][0] = hang, positions[k][1] = lie;
	}
	for (k = 0; k < BOMBS; k++) {
		//д������
		int hang_write = positions[k][0], lie_write = positions[k][1];
		board[hang_write][lie_write] = 9;
	}


}
/*-----------------------------
* ����㷨̫����
* 
void putBombs() {
	//���׺���
	//����ǰ�����������
	int i = 0, j = 0;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			board[i][j] = 0;
		}
	}

	//�����ϣ���ʼ��һ��
	i = 0, j = 0;
	int bombs_already = 0;
	while (bombs_already < BOMBS) {
		for (i = 0; i < HEIGHT; i++) {
			//���б�������ÿһ��
			for (j = 0; j < WIDTH; j++) {
				//����ÿһ�����ӣ�����ĸ���Ϊ[i][j]
				//����Ϊ��������-�Ѿ����˵�������/��������-�Ѿ����˵�������
				if (bombs_already >= BOMBS) {
					return;//�������һ�α����Ĵ���
				}
				if (9 == board[i][j] || bombs_already >= BOMBS) {
					//�Ѿ������׻������������������������
					continue;
				}
				srand(time(0));
				//���ɵ���ֵ��ΧΪ��ĸ
				int randomrange = HEIGHT * WIDTH - bombs_already;
				//�����ڷ������ڣ�����ף���֮��������
				int conditionrange = BOMBS - bombs_already;//Ϊ�˱������Ϊ0����ȷʵΪ0���Ϊ1,�������ڹ��bug
				int random_number = rand() % randomrange;
				//С�ھͷ���һ���ף����ھͲ�����
				if (random_number <= conditionrange) {
					board[i][j] = 9;//����
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
				continue;//�����׾�����
			}
			//�Ӹø��ӵ����Ͻǿ�ʼ��ѡȡ9������
			int a = i - 1, b = i - 1, count = 0;
			for (a = i - 1; a <= i + 1; a++) {
				for (b = j - 1; b <= j + 1; b++) {
					//����[a][b]�����������������Ļ����Ͳ��������������
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
	//�ַ���
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
				//1-8������
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

void initializeBoard() {//���̳�ʼ��
	//����ȷ���׵�λ��
	//��Ҫ�������BOMBS��
	printf("���ڳ�ʼ������.........");

	//�����ף�����9
	putBombs2();
	//��������
	putnumbers();
	//�ַ���
	charize();
	//�ɰ��ʼ��
	mengban_initialize();

	printf("ok\n���̳�ʼ���ɹ���\n");
	//��������ʱʹ�ã���ʽ��Ϸ��ʱ��Ҫע�͵�������𰸾���ʾ��
	printBoard(board_forgame);
	printBoard(mengban);

}
void printBoard(char beprinted_board[HEIGHT][WIDTH]) {//�ɰ��ӡ
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
				printf("|");//�������һ�ж�Ҫ��ӡһ���ָ���
			}
		}
		printf("\n");//���У���ʼ��ӡ����

		if (HEIGHT - 1 != i) {//�������һ�ж�Ҫ��ӡһ�к���
			for (k = 0; k < WIDTH * 4 - 1; k++) {
				printf("-");//��4�����-1������
			}
		}

		printf("\n");

	}
	printf("\n********************************\n");

}
