#pragma once

typedef struct selection_result {
	int hang;
	int lie;//����λ��
	int isSafe;//�Ƿ�ȫ
	int ingredient;//��Ŷ�ȡ�ĵ�ͼ��Ϣ
	char ingredient_game;//ͬ�ϣ���ŵ����ַ�������Ϣ
	char mengban_ingredient;//����ɰ���Ϣ�����жϸø���Ŀǰ��״��

}selection_result;

selection_result* select(int, int, selection_result*);

int checkifsafe(int hang, int lie);
