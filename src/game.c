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
void handle_auto_drop(GameData *GAME_DATA) {
	if(!GAME_DATA->current_tetramino)
		return;

	struct timeval current_time;
	gettimeofday(&current_time, NULL);

	int64_t current_ms =
		(int64_t)(current_time.tv_sec) * 1000
		+ (current_time.tv_usec / 1000);

	if (current_ms >= next_drop) {
		move_down(GAME_DATA);
		next_drop = current_ms + DROP_TIME_MS;
	}
}

SDL_bool game_loop(GameData *GAME_DATA) {
	if (GAME_DATA == NULL)
		return SDL_FALSE;

	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		if (should_quit(&event))
			return SDL_FALSE;
	}

	if (!GAME_DATA->current_tetramino) {
		// todo: randomize
		GAME_DATA->current_tetramino = &TETRAMINO_O;

		// todo: center tetramino
		GAME_DATA->tetramino_position = (SDL_Point){ GRID_WIDTH / 2, 0 };
	}

	clean_window(GAME_DATA);
	draw_grid(GAME_DATA);

	move_tetramino(&event, GAME_DATA);
	handle_auto_drop(GAME_DATA);
	draw_current_tetramino(GAME_DATA);

	SDL_RenderPresent(GAME_DATA->renderer);
	return SDL_TRUE;
}
