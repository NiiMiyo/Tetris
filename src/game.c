#include <sys/time.h>

#include "SDL2/SDL_stdinc.h"
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_render.h"
#include "game.h"
#include "game_data.h"
#include "tetramino.h"
#include "rendering.h"
#include "controls.h"
#include "constants.h"

SDL_bool should_quit(SDL_Event *e) {
	return ( e->type == SDL_QUIT )
		|| ( e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE );
}

time_t next_drop = 0;
void handle_auto_drop(Tetramino **tetramino, SDL_Point *position, SDL_Color grid[GRID_WIDTH][GRID_HEIGHT]) {
	if(!*tetramino)
		return;

	struct timeval current_time;
	gettimeofday(&current_time, NULL);

	int64_t current_ms =
		(int64_t)(current_time.tv_sec) * 1000
		+ (current_time.tv_usec / 1000);

	if (current_ms >= next_drop) {
		next_drop = current_ms + DROP_TIME_MS;
		handle_drop(tetramino, position, grid);
	}
}

SDL_bool game_loop(GameData *GAME_DATA) {
	if (GAME_DATA == NULL)
		return SDL_FALSE;

	SDL_Event event;
	if (SDL_PollEvent(&event) && should_quit(&event))
			return SDL_FALSE;

	if (!GAME_DATA->tetramino) {
		Tetramino t = random_tetramino();
		GAME_DATA->tetramino = &t;

		SDL_Point offset = spawn_offset(GAME_DATA->tetramino);
		GAME_DATA->position = (SDL_Point) {
			.x = (GRID_WIDTH / 2) + offset.x,
			.y = offset.y
		};

		SDL_bool canSpawn = tetramino_can_move_to(GAME_DATA->tetramino, (SDL_Point){0, 0}, GAME_DATA->position, GAME_DATA->grid);
		if (!canSpawn)
			return SDL_FALSE;
	}

	clean_window(GAME_DATA->renderer);
	draw_grid(GAME_DATA->grid, GAME_DATA->renderer);

	handle_input(&event, &GAME_DATA->tetramino, &GAME_DATA->position, GAME_DATA->grid);
	handle_auto_drop(&GAME_DATA->tetramino, &GAME_DATA->position, GAME_DATA->grid);
	draw_tetramino(GAME_DATA->tetramino, GAME_DATA->position, GAME_DATA->renderer);

	clear_full_lines(GAME_DATA->grid);

	SDL_RenderPresent(GAME_DATA->renderer);
	return SDL_TRUE;
}
