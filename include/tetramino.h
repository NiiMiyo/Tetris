#ifndef NII_TETRIS_TETRAMINO
#define NII_TETRIS_TETRAMINO

#include "SDL2/SDL.h"

/**
 * Represents a single Tetramino with 4 blocks with relative position to the tetramino.
 */
struct Tetramino {
	/**
	 * The relative position of the four blocks the compose the tetramino
	 */
	const SDL_Point blocks[4];

	/**
	 * The tetramino this tetramino becomes when rotated
	 */
	const struct Tetramino *rotatesInto;
};

/**
 * Draws a tetramino on the given position on the grid
 * 
 * \param tetramino the tetramino to be drawn
 * \param position the position on the grid to draw the tetramino
 * \param renderer the renderer to be used to draw the tetramino
 */
void draw_tetramino(
	const struct Tetramino *tetramino,
	SDL_Point position,
	SDL_Renderer *renderer
);

/**
 * The O-shaped tetramino
 */
extern const struct Tetramino TETRAMINO_O;

#endif
