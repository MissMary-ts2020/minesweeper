#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
#include "initialize.h"
#include "actions.h"

int select(int hang, int lie) {

}

int checkifsafe(int hang,int lie) {
	if (hang >= 0 && hang < HEIGHT && lie >= 0 && lie < WIDTH) {
		return 1;
	}
	else {
		return 0;
	}
}

