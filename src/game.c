#include "SDL2/SDL.h"
#include "game.h"
#include "game_data.h"
#include "tetramino.h"

SDL_bool should_quit(SDL_Event *e) {
	return ( e->type == SDL_QUIT )
		|| ( e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE );
}

void clean_window(struct GameData *GAME_DATA) {
	SDL_Renderer *clear_renderer = SDL_CreateRenderer(GAME_DATA->window, 0, 0);

	SDL_SetRenderDrawColor(clear_renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(clear_renderer, NULL);

	SDL_DestroyRenderer(clear_renderer);
}

SDL_bool game_loop(struct GameData *GAME_DATA) {
	if (GAME_DATA == NULL)
		return SDL_FALSE;

	SDL_Event event;
	if (!SDL_PollEvent(&event))
		return SDL_TRUE;

	if (should_quit(&event))
		return SDL_FALSE;

	clean_window(GAME_DATA);
	// TODO: game loop

	// testing drawing
	draw_tetramino(&TETRAMINO_O, (SDL_Point){1, 1}, GAME_DATA->renderer);

	SDL_RenderPresent(GAME_DATA->renderer);
	return SDL_TRUE;
}
