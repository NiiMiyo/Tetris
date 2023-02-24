#include "SDL2/SDL.h"
#include "game.h"
#include "game_data.h"

int game_loop(struct GameData *GAME_DATA) {
	if (GAME_DATA == NULL)
		return BREAK_GAME_LOOP;

	SDL_Event event;
	if (!SDL_PollEvent(&event))
		return CONTINUE_GAME_LOOP;

	if (should_quit(&event))
		return BREAK_GAME_LOOP;

	// TODO: game loop

	return CONTINUE_GAME_LOOP;
}

int should_quit(SDL_Event *e) {
	return
		( e->type == SDL_QUIT )
		|| ( e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE );
}
