#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
#include "initialize.h"
#include "actions.h"

void action(int hang, int lie, int ingredient) {

	return;
}

void action_flaged(int hang, int lie, int ingredient){
    
	return;
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

