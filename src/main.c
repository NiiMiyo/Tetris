#include <stdlib.h>
#include <time.h>
#include "game_data.h"
#include "game.h"

int main(int argc, char *argv[]) {
	srand(time(NULL));
	GameData *GAME_DATA = init();

	while (game_loop(GAME_DATA));

	close(GAME_DATA);
	return 0;
}
