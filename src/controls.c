#include "SDL2/SDL_events.h"
#include "SDL2/SDL_rect.h"
#include "controls.h"

void move_tetramino(SDL_Event *event, GameData *GAME_DATA) {
	if (
		   !event
		|| event->type != SDL_KEYDOWN
		|| !GAME_DATA->current_tetramino
	) {
		return;
	}

	int movement = 0;

	for (int i; i < 4; i++) {
		SDL_Point block = GAME_DATA->current_tetramino->blocks[i];
		int x = GAME_DATA->tetramino_position.x + block.x;
		int y = GAME_DATA->tetramino_position.y + block.y;

		if (
			event->key.keysym.sym == KEY_MOVE_RIGHT
			&& valid_grid_position(GAME_DATA, x + 1, y)
		) {
			movement++;
		}

		if (
			event->key.keysym.sym == KEY_MOVE_LEFT
			&& valid_grid_position(GAME_DATA, x - 1, y)
		) {
			movement--;
		}
	}

	GAME_DATA->tetramino_position.x += movement / 4;

	if (event->key.keysym.sym == KEY_ROTATE)
		// todo: check if rotation is valid
		GAME_DATA->current_tetramino = GAME_DATA->current_tetramino->rotatesInto;

	if (event->key.keysym.sym == KEY_DROP)
		move_down(GAME_DATA);
}

void move_down(GameData *GAME_DATA) {
	if (!GAME_DATA->current_tetramino)
		return;

	SDL_bool fix_tetramino = SDL_FALSE;

	for (size_t i = 0; i < 4; i++) {
		SDL_Point block = GAME_DATA->current_tetramino->blocks[i];
		SDL_Point block_next = {
			.x = GAME_DATA->tetramino_position.x + block.x,
			.y = GAME_DATA->tetramino_position.y + block.y + 1
		};

		if (!valid_grid_position(GAME_DATA, block_next.x, block_next.y)) {
			fix_tetramino = SDL_TRUE;
			break;
		}
	}

	if (fix_tetramino) {
		for (size_t i = 0; i < 4; i++) {
			SDL_Point block = GAME_DATA->current_tetramino->blocks[i];
			int x = GAME_DATA->tetramino_position.x + block.x;
			int y = GAME_DATA->tetramino_position.y + block.y;

			GAME_DATA->grid[x][y] = SDL_TRUE;
		}

		GAME_DATA->current_tetramino = NULL;
	}

	else
		GAME_DATA->tetramino_position.y++;
}
