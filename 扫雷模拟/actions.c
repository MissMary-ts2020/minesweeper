#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
#include "initialize.h"
#include "actions.h"

selection_result* select(int hang, int lie,selection_result * selection) {
	if (checkifsafe(hang, lie)) {
		//写入selection
		selection->hang = hang;
		selection->lie = lie;
		selection->ingredient = board[hang][lie];
		selection->isSafe = 1;
		selection->ingredient_game = board_forgame[hang][lie];
		selection->mengban_ingredient = mengban[hang][lie];

	}
	else {
		//越界情况
		selection->isSafe = 0;
	}
	return selection;


}
int checkthisselection(selection_result* selection) {
	

}

void doingwithselection(const selection_result* selection) {


}

int checkifsafe(int hang,int lie) {
	if (hang >= 0 && hang < HEIGHT && lie >= 0 && lie < WIDTH) {
		return 1;
	}
	else {
		return 0;
	}
}

