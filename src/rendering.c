#include "SDL2/SDL_rect.h"
#include "SDL2/SDL_render.h"
#include "rendering.h"
#include "tetramino.h"
#include "constants.h"

const SDL_Rect LEFT_WALL = {
	.x = GRID_START_X - (GRID_GAP * 2),
	.y = GRID_START_Y - GRID_GAP,
	.h = GRID_HEIGHT_PIXELS,
	.w = GRID_WALL_WIDTH
};
const SDL_Rect RIGHT_WALL = {
	.x = GRID_START_X + GRID_WIDTH_PIXELS,
	.y = GRID_START_Y - GRID_GAP,
	.h = GRID_HEIGHT_PIXELS,
	.w = GRID_WALL_WIDTH
};
const SDL_Rect FLOOR = {
	.x = GRID_START_X - (GRID_GAP * 2),
	.y = GRID_START_Y - GRID_GAP + GRID_HEIGHT_PIXELS,
	.w = GRID_WIDTH_PIXELS + (GRID_GAP * 2) + GRID_WALL_WIDTH,
	.h = GRID_WALL_WIDTH
};

/**
 * Converts a point in the grid to a point in the window
 */
SDL_Point grid_to_screen(SDL_Point grid_position) {
	return (SDL_Point){
		grid_position.x * BLOCK_SIZE + (grid_position.x * GRID_GAP) + GRID_START_X,
		grid_position.y * BLOCK_SIZE + (grid_position.y * GRID_GAP) + GRID_START_Y
	};
}

/**
 * Draws a single block at a position on the grid
 */
int draw_block(SDL_Point position, SDL_Renderer *renderer, SDL_Color color) {
	SDL_Point screen_position = grid_to_screen(position);
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

	const SDL_Rect fill_rect = {
		.x = screen_position.x,
		.y = screen_position.y,
		.w = BLOCK_SIZE,
		.h = BLOCK_SIZE
	};

	return SDL_RenderFillRect(renderer, &fill_rect);
}

void draw_tetramino(
	Tetramino *tetramino,
	SDL_Point position,
	SDL_Renderer *renderer
) {
	if (!tetramino)
		return;

	for (char i = 0; i < 4; i++) {
		// todo: check errors
		draw_block(block_position(tetramino, i, position), renderer, tetramino->color);
	}
}

void draw_grid(SDL_Color grid[GRID_WIDTH][GRID_HEIGHT], SDL_Renderer *renderer) {
	for (size_t x = 0; x < GRID_WIDTH; x++) {
		for (size_t y = 0; y < GRID_HEIGHT; y++) {
			if (!valid_grid_position(grid, x, y)) {
				draw_block((SDL_Point){x,y}, renderer, grid[x][y]);
			}
		}
	}

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(renderer, &LEFT_WALL);
	SDL_RenderDrawRect(renderer, &RIGHT_WALL);
	SDL_RenderDrawRect(renderer, &FLOOR);
}

void clean_window(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}
