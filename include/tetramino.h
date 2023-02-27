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
 * Gets the grid position of a block on the tetramino
 */
SDL_Point block_position(Tetramino *tetramino, int block, SDL_Point tetramino_position);

/**
 * Returns a random tetramino from the possibles tetraminoes
 */
Tetramino random_tetramino();

/**
 * Returns offset to correct spawn point of the tetramino
 */
SDL_Point spawn_offset(Tetramino *tetramino);

/**
 * The O-shaped tetramino
 */
extern Tetramino TETRAMINO_O;

/**
 * The I-shaped tetramino
 */
extern Tetramino TETRAMINO_I;

/**
 * The J-shaped tetramino
 */
extern Tetramino TETRAMINO_J;

/**
 * The L-shaped tetramino
 */
extern Tetramino TETRAMINO_L;

/**
 * The S-shaped tetramino
 */
extern Tetramino TETRAMINO_S;

/**
 * The T-shaped tetramino
 */
extern Tetramino TETRAMINO_T;

/**
 * The Z-shaped tetramino
 */
extern Tetramino TETRAMINO_Z;

#endif
