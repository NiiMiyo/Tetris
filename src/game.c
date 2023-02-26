#include "SDL2/SDL_stdinc.h"
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_render.h"
#include "game.h"
#include "game_data.h"
#include "tetramino.h"
#include "rendering.h"
#include "controls.h"

SDL_bool should_quit(SDL_Event *e) {
	return ( e->type == SDL_QUIT )
		|| ( e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE );
}

SDL_bool game_loop(GameData *GAME_DATA) {
	if (GAME_DATA == NULL)
		return SDL_FALSE;

	SDL_Event event;
	if (!SDL_PollEvent(&event))
		return SDL_TRUE;

	if (should_quit(&event))
		return SDL_FALSE;

	if (GAME_DATA->current_tetramino == NULL) {
		// todo: randomize
		GAME_DATA->current_tetramino = &TETRAMINO_O;
		GAME_DATA->tetramino_position = (SDL_Point){ 0, 0 };
	}

	clean_window(GAME_DATA);
	draw_grid(GAME_DATA);

	move_tetramino(&event, GAME_DATA);
	draw_current_tetramino(GAME_DATA);
	// TODO: game loop

	SDL_RenderPresent(GAME_DATA->renderer);
	return SDL_TRUE;
}
