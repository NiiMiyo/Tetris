#include "SDL2/SDL_events.h"
#include "SDL2/SDL_rect.h"
#include "controls.h"

void move_tetramino(SDL_Event *event, GameData *GAME_DATA) {
	if (event->type != SDL_KEYDOWN) {
		return;
	}

	if (event->key.keysym.sym == KEY_MOVE_RIGHT) {
		GAME_DATA->tetramino_position.x++;
	}

	if (event->key.keysym.sym == KEY_MOVE_LEFT) {
		GAME_DATA->tetramino_position.x--;
	}

	if (event->key.keysym.sym == KEY_ROTATE) {
		GAME_DATA->current_tetramino = GAME_DATA->current_tetramino->rotatesInto;
	}

	for (size_t i = 0; i < 4; i++) {
		SDL_Point block = GAME_DATA->current_tetramino->blocks[i];
		int block_global_x = GAME_DATA->tetramino_position.x + block.x;

		if (block_global_x < 0)
			GAME_DATA->tetramino_position.x -= block_global_x;

		else if (block_global_x >= GRID_WIDTH)
			GAME_DATA->tetramino_position.x -= (block_global_x - GRID_WIDTH) + 1;
	}

	// todo: drop
}
