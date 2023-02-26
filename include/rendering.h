#ifndef NII_TETRIS_RENDERING
#define NII_TETRIS_RENDERING

#include "tetramino.h"
#include "game_data.h"

/**
 * Clears window
 */
void clean_window(GameData *GAME_DATA);

/**
 * Draws the grid blocks already positioned
 */
void draw_grid(GameData *GAME_DATA);

/**
 * Draws a tetramino on the given position on the grid
 * 
 * \param tetramino the tetramino to be drawn
 * \param position the position on the grid to draw the tetramino
 * \param renderer the renderer to be used to draw the tetramino
 */
void draw_tetramino(
	const Tetramino *tetramino,
	SDL_Point position,
	SDL_Renderer *renderer
);

/**
 * Draws the current tetramino at the current position
 */
void draw_current_tetramino(GameData *GAME_DATA);

#endif
