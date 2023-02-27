#ifndef NII_TETRIS_TETRAMINO
#define NII_TETRIS_TETRAMINO

#include "SDL2/SDL_rect.h"

/**
 * Represents a single Tetramino with 4 blocks with relative position to the tetramino.
 */
typedef struct Tetramino {
	/**
	 * The relative position of the four blocks that compose the tetramino
	 */
	const SDL_Point blocks[4];

	/**
	 * The tetramino this tetramino becomes when rotated
	 */
	struct Tetramino *rotatesInto;
} Tetramino;

/**
 * The O-shaped tetramino
 */
extern Tetramino TETRAMINO_O;

/**
 * Gets the grid position of a block on the tetramino
 */
SDL_Point block_position(Tetramino *tetramino, int block, SDL_Point tetramino_position);

#endif
