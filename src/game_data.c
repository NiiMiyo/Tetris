#include <stdio.h>

#include "SDL2/SDL.h"
#include "constants.h"
#include "game_data.h"

struct GameData *init() {
	struct GameData *data = calloc(1, sizeof(struct GameData));
	if (data == NULL) {
		printf("error allocating memory for game data\n");
		return NULL;
	}

	if (SDL_Init(SDL_INIT_EVENTS) != 0) {
		printf("error initializing SDL: %s\n", SDL_GetError());
		return NULL;
	}

	SDL_Window *window = SDL_CreateWindow(
		WINDOW_TITLE,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		0
	);

	if (window == NULL) {
		printf("error creating window: %s\n", SDL_GetError());
		return NULL;
	}

	data->window = window;
	return data;
}

void close(struct GameData *GAME_DATA) {
	SDL_DestroyWindow(GAME_DATA->window);
	SDL_Quit();

	free(GAME_DATA);
}
