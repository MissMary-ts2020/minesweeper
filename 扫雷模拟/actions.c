#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
#include "initialize.h"
#include "actions.h"
#include <stdio.h>


void dig(int hang, int lie) {
	if ('0' != mengban[hang][lie]) {
		//�Ѿ��ڿ�������
		return;
	}
	mengban[hang][lie] = board_forgame[hang][lie];//����ʾ���ĸ���
	if (0 != board[hang][lie]) {
		//�����һ�����Ӿ������֣��ǾͲ���̽����
		return;
	}
	int i = hang - 1, j = lie - 1;
	for (i = hang - 1; i <= hang + 1; i++) {
		for (j = lie - 1; j <= lie - 1; j++) {
			//���ڱ�׼��ֻҪ�����׾�Ҫ��ʾ����
			if (j<0 || i<0 || j>WIDTH - 1 || i>HEIGHT - 1||(hang==i&&lie==j)) {
				continue;//��������������������
				//�Լ��������ĸ��Ӿ�����
			}
			
			if (mengban[i][j] = board_forgame[i][j] == ' ') {
				//�ڵ��Ĳ����ǿո�
				dig(i, j);//��������ո���ӽ���һ�ο��ڣ��ݹ�
			}
		}
	}
}

void action(int hang, int lie) {
	show_selection(hang, lie);
	//��ӡѡ��˵�
	print_actionMenu(1);
	char The_action = '0';
	while ('1' != The_action || '2' != The_action || '3' != The_action) {
		The_action = getchar();
		if ('1' != The_action || '2' != The_action || '3' != The_action) {
			//��ʾ������Ϣ
			printf("ѡ�����������ѡ��\n");
			print_actionMenu(1);
		}
	}
	switch (The_action) {
	case '1':
		//�ڿ�����
		if (9 == board[hang][lie]) {
			//��Ϸ����
			flag = 0;
			win = 0;
		}
		else {
			//�����ǱȽϸ��ӵĿ��ڹ���,����������ĺ�����
			dig(hang, lie);

		}
		//ÿ�ΰ�ȫ��������Ӻ���Ҫ�����Ϸ�Ƿ�ʤ��
		//ʤ������Ϊ�ɰ��ڳ���������ĸ��Ӷ����ڿ�

		break;
	case '2':
		//����
		mengban[hang][lie]='F';
		break;
	case '3':
		printf("ȡ��ѡ�У��õ�\n");

		break;
	default:
		printf("error");
		break;


	}
	//�����������

	
	return;
}

void action_flaged(int hang, int lie){
	show_selection(hang, lie);
	//��ӡѡ��˵�
	print_actionMenu(2);

	return;
}

void show_selection(int hang,int lie) {
	char mengban_tmp = mengban[hang][lie];
	mengban[hang][lie] = '@';
	printBoard(mengban);
	printf("@Ϊ����ѡ��ĸ��ӣ�Ϊ��%d�е�%d�С�\n", hang, lie);
	mengban[hang][lie] = mengban_tmp;

}

int print_actionMenu(int action_type) {
	switch (action_type) {
	case 1:
		//δ�ڿ�
		printf("��������ѡ��:\n");
		printf("1.�ڿ��������\n");
		printf("2.����\n");
		printf("3.ȡ��ѡ��\n");
		printf("��ѡ����(�˵�2)>");
		break;
	case 2:
		//�Ѳ���
		printf("��������ѡ��:\n");
		printf("1.ȡ������\n");
		printf("2.ȡ��ѡ��\n");
		printf("��ѡ����(�˵�3)>");
		break;
	default:
		printf("error");
		break;
	}
}

int check_selection(int hang,int lie) {
	if (!(hang >= 0 && hang < HEIGHT && lie >= 0 && lie < WIDTH)) {
		return 1;//Խ��
	}
	switch (mengban[hang][lie]) {
		//ͨ���ɰ�״���ļ�飬������
	case '0':
		//δ�ڿ�
		return 2;
		break;
	case 'F':
		//�Ѳ���
		return 3;
		break;
	default:
		//���ڿ�
		return 4;
		break;
	}
}

