#include <stdio.h>

#include "SDL2/SDL.h"
#include "sdl_event_handler.h"

int main(int argc, char *argv[]) {
	int sdl_error = SDL_Init(SDL_INIT_EVENTS);
	if (sdl_error != 0) {
		printf("error initializing SDL: %s\n", SDL_GetError());
		return sdl_error;
	}

	SDL_Window *window = SDL_CreateWindow(
		"Tetris",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		512, 512, 0
	);

	while (1) {
		SDL_Event event;
		if (!SDL_PollEvent(&event))
			continue;

		if (should_quit(&event))
			break;
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
