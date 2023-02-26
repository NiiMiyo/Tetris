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
int draw_block(SDL_Point position, SDL_Renderer *renderer) {
	SDL_Point screen_position = grid_to_screen(position);

	const SDL_Rect fill_rect = {
		.x = screen_position.x,
		.y = screen_position.y,
		.w = BLOCK_SIZE,
		.h = BLOCK_SIZE
	};

	return SDL_RenderFillRect(renderer, &fill_rect);
}

/**
 * Gets the grid position of a block on the tetramino
 */
SDL_Point block_global_position(
	const Tetramino *tetramino,
	int block_index,
	SDL_Point grid_position
) {
	return (SDL_Point){
		.x = grid_position.x + tetramino->blocks[block_index].x,
		.y = grid_position.y + tetramino->blocks[block_index].y
	};
}

void draw_tetramino(
	const Tetramino *tetramino,
	SDL_Point position,
	SDL_Renderer *renderer
) {
	// todo: each tetramino has different color
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	for (char i = 0; i < 4; i++) {
		// todo: check errors
		SDL_Point p = block_global_position(tetramino, i, position);
		draw_block(p, renderer);
	}
}

void draw_grid(GameData *GAME_DATA) {
	for (size_t x = 0; x < GRID_WIDTH; x++) {
		for (size_t y = 0; y < GRID_HEIGHT; y++) {
			if (GAME_DATA->grid[x][y]) {
				SDL_SetRenderDrawColor(GAME_DATA->renderer, 255, 255, 255, 255);
				draw_block((SDL_Point){x,y}, GAME_DATA->renderer);
			}
		}
	}

	SDL_SetRenderDrawColor(GAME_DATA->renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(GAME_DATA->renderer, &LEFT_WALL);
	SDL_RenderDrawRect(GAME_DATA->renderer, &RIGHT_WALL);
	SDL_RenderDrawRect(GAME_DATA->renderer, &FLOOR);
}

void clean_window(GameData *GAME_DATA) {
	SDL_SetRenderDrawColor(GAME_DATA->renderer, 0, 0, 0, 255);
	SDL_RenderClear(GAME_DATA->renderer);
}

void draw_current_tetramino(GameData *GAME_DATA) {
	if (GAME_DATA->current_tetramino)
		draw_tetramino(
			GAME_DATA->current_tetramino,
			GAME_DATA->tetramino_position,
			GAME_DATA->renderer
		);
}
