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

	// todo: check for block position instead of tetramino position
	if (GAME_DATA->tetramino_position.x < 0) {
		GAME_DATA->tetramino_position.x = 0;
	} else if (GAME_DATA->tetramino_position.x > GRID_WIDTH) {
		GAME_DATA->tetramino_position.x = GRID_WIDTH;
	}

	// todo: drop
}
