#pragma once

typedef struct selection_result {
	int hang;
	int lie;//����λ��
	int isSafe;//�Ƿ�ȫ
	int ingredient;//��Ŷ�ȡ�ĵ�ͼ��Ϣ
	char ingredient_game;//ͬ�ϣ���ŵ����ַ�������Ϣ
	char mengban_ingredient;//����ɰ���Ϣ�����жϸø���Ŀǰ��״��

}selection_result;

int select(int, int);

int checkifsafe(int hang, int lie);
