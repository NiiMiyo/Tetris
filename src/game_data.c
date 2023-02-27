#include <stdio.h>
#include "SDL2/SDL.h"
#include "constants.h"
#include "game_data.h"


GameData data;

GameData *init() {
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
	data.window = window;

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL) {
		printf("error creating renderer for window: %s\n", SDL_GetError());
		return NULL;
	}
	data.renderer = renderer;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	return &data;
}

void close(GameData *GAME_DATA) {
	SDL_DestroyRenderer(GAME_DATA->renderer);
	SDL_DestroyWindow(GAME_DATA->window);
	SDL_Quit();
}

SDL_bool valid_grid_position(SDL_bool grid[GRID_WIDTH][GRID_HEIGHT], int x, int y) {
	return
		x >= 0
		&& x < GRID_WIDTH
		&& y >= 0
		&& y < GRID_HEIGHT
		&& !grid[x][y];
}

SDL_bool tetramino_can_move_to(Tetramino *tetramino, SDL_Point relative, SDL_Point current, SDL_bool grid[GRID_WIDTH][GRID_HEIGHT]) {
	for (int i = 0; i < 4; i++) {
		SDL_Point block_on_grid = block_position(tetramino, i, current);
		block_on_grid.x += relative.x;
		block_on_grid.y += relative.y;

		if (!valid_grid_position(grid, block_on_grid.x, block_on_grid.y))
			return SDL_FALSE;
	}

	return SDL_TRUE;
}

void fill_grid(Tetramino *tetramino, SDL_Point position, SDL_bool grid[GRID_WIDTH][GRID_HEIGHT]) {
	for (int i = 0; i < 4; i++) {
		SDL_Point b = block_position(tetramino, i, position);
		grid[b.x][b.y] = SDL_TRUE;
	}
}

SDL_bool full_line(SDL_bool grid[GRID_WIDTH][GRID_HEIGHT], int line) {
		int filled = 0;

		for (int column = 0; column < GRID_WIDTH; column++) {
			filled += grid[column][line];
		}

		return filled == GRID_WIDTH;
}

void clear_line(SDL_bool grid[GRID_WIDTH][GRID_HEIGHT], int line) {
	for (int y = line; y > 0; y--) {
		for (int x = 0; x < GRID_WIDTH; x++) {
			grid[x][y] = grid[x][y-1];
		}
	}

	for (int x = 0; x < GRID_WIDTH; x++) {
		grid[x][0] = SDL_FALSE;
	}
}

void clear_full_lines(SDL_bool grid[GRID_WIDTH][GRID_HEIGHT]) {
	for (int line = 0; line < GRID_HEIGHT; line++) {
		if (full_line(grid, line))
			clear_line(grid, line);
	}
}
