#pragma once

typedef struct selection_result {
	int hang;
	int lie;//����λ��
	int isSafe;//�Ƿ�ȫ
	int ingredient;//��Ŷ�ȡ�ĵ�ͼ��Ϣ
	char ingredient_game;//ͬ�ϣ���ŵ����ַ�������Ϣ
	char mengban_ingredient;//����ɰ���Ϣ�����жϸø���Ŀǰ��״��

}selection_result;



int check_selection(int, int);
void action(int, int);
void action_flaged(int, int);
void show_selection(int hang, int lie);

void print_actionMenu(int action_type);
void action_flaged(int hang, int lie);
void action(int hang, int lie);
void dig(int hang, int lie);
