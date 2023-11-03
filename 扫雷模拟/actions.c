#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
#include "initialize.h"
#include "actions.h"

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

