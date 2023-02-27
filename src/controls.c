#include "SDL2/SDL_events.h"
#include "SDL2/SDL_rect.h"
#include "controls.h"

void handle_input(SDL_Event *event, Tetramino **tetramino, SDL_Point *position, SDL_bool grid[GRID_WIDTH][GRID_HEIGHT]) {
	if (!event
		|| event->type != SDL_KEYDOWN
		|| !*tetramino
	) {
		return;
	}

	int movement = 0;

	if (event->key.keysym.sym == KEY_MOVE_RIGHT
		&& tetramino_can_move_to(*tetramino, (SDL_Point){1,0}, *position, grid)
	) {
		movement++;
	}

	if (event->key.keysym.sym == KEY_MOVE_LEFT
		&& tetramino_can_move_to(*tetramino, (SDL_Point){-1,0}, *position, grid)
	) {
		movement--;
	}

	position->x += movement;

	if (event->key.keysym.sym == KEY_ROTATE) {
		Tetramino *rotated = (*tetramino)->rotatesInto;

		if (tetramino_can_move_to(rotated, (SDL_Point){0,0}, *position, grid))
			*tetramino = rotated;
	}

	if (event->key.keysym.sym == KEY_DROP
		&& tetramino_can_move_to(*tetramino, (SDL_Point){0,1}, *position, grid)
	) {
		handle_drop(tetramino, position, grid);
	}

	if (event->key.keysym.sym == KEY_DROP_ALL)
		while(*tetramino)
			handle_drop(tetramino, position, grid);
}

void handle_drop(Tetramino **tetramino, SDL_Point *position, SDL_bool grid[GRID_WIDTH][GRID_HEIGHT]) {
	if (!*tetramino)
		return;

	if (tetramino_can_move_to(*tetramino, (SDL_Point){0,1}, *position, grid))
		position->y++;

	else {
		fill_grid(*tetramino, *position, grid);
		*tetramino = NULL;
	}
}
