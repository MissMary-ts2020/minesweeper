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

