#include "SDL2/SDL.h"
#include "tetramino.h"
#include "constants.h"

const struct Tetramino TETRAMINO_O = {
	.blocks = { { 0, 0 },
		         { 0, 1 },
		         { 1, 0 },
		         { 1, 1 } },
	.rotatesInto = &TETRAMINO_O
};

SDL_Point grid_to_screen(SDL_Point grid_position) {
	return (SDL_Point){
		grid_position.x * BLOCK_SIZE + (grid_position.x * GRID_GAP),
		grid_position.y * BLOCK_SIZE + (grid_position.y * GRID_GAP)
	};
}

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

SDL_Point block_global_position(
	const struct Tetramino *tetramino,
	int block_index,
	SDL_Point grid_position
) {
	return (SDL_Point){
		.x = grid_position.x + tetramino->blocks[block_index].x,
		.y = grid_position.y + tetramino->blocks[block_index].y
	};
}

void draw_tetramino(
	const struct Tetramino *tetramino,
	SDL_Point position,
	SDL_Renderer *renderer
) {
	for (char i = 0; i < 4; i++) {
		// todo: check errors
		draw_block(block_global_position(tetramino, i, position), renderer);
	}
}
