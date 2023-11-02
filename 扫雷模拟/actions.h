#pragma once

typedef struct selection_result {
	int hang;
	int lie;//坐标位置
	int isSafe;//是否安全
	int ingredient;//存放读取的地图信息
	char ingredient_game;//同上，存放的是字符化的信息
	char mengban_ingredient;//存放蒙版信息，以判断该格子目前的状况

}selection_result;

selection_result* select(int, int, selection_result*);

int checkifsafe(int hang, int lie);
