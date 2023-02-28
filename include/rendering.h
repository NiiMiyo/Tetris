#ifndef NII_TETRIS_RENDERING
#define NII_TETRIS_RENDERING

#include "SDL2/SDL_render.h"
#include "tetramino.h"
#include "game_data.h"

/**
 * Clears window
 */
void clean_window(SDL_Renderer *renderer);

/**
 * Draws the grid blocks already positioned
 */
void draw_grid(SDL_Color grid[GRID_WIDTH][GRID_HEIGHT], SDL_Renderer *renderer);

/**
 * Draws a tetramino on the given position on the grid
 * 
 * \param tetramino the tetramino to be drawn
 * \param position the position on the grid to draw the tetramino
 * \param renderer the renderer to be used to draw the tetramino
 */
void draw_tetramino(
	Tetramino *tetramino,
	SDL_Point position,
	SDL_Renderer *renderer
);

#endif
