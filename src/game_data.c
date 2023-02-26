#include <stdio.h>
#include "SDL2/SDL.h"
#include "constants.h"
#include "game_data.h"

GameData *init() {
	GameData *data = calloc(1, sizeof(GameData));
	if (data == NULL) {
		printf("error allocating memory for game data\n");
		return NULL;
	}

	if (SDL_Init(SDL_INIT_EVENTS) != 0) {
		printf("error initializing SDL: %s\n", SDL_GetError());
		free(data);
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
		free(data);
		return NULL;
	}
	data->window = window;

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL) {
		printf("error creating renderer for window: %s\n", SDL_GetError());
		free(data);
		return NULL;
	}
	data->renderer = renderer;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	return data;
}

void close(GameData *GAME_DATA) {
	SDL_DestroyRenderer(GAME_DATA->renderer);
	SDL_DestroyWindow(GAME_DATA->window);
	SDL_Quit();

	free(GAME_DATA);
}

SDL_bool valid_grid_position(GameData *GAME_DATA, int x, int y) {
	return
		x >= 0
		&& x < GRID_WIDTH
		&& y >= 0
		&& y < GRID_WIDTH
		&& !GAME_DATA->grid[x][y];
}
