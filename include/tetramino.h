#ifndef NII_TETRIS_TETRAMINO
#define NII_TETRIS_TETRAMINO

#include "SDL2/SDL_rect.h"

/**
 * Represents a single Tetramino with 4 blocks with relative position to the tetramino.
 */
typedef struct Tetramino {
	/**
	 * The relative position of the four blocks the compose the tetramino
	 */
	const SDL_Point blocks[4];

	/**
	 * The tetramino this tetramino becomes when rotated
	 */
	const struct Tetramino *rotatesInto;
} Tetramino;

/**
 * The O-shaped tetramino
 */
extern const Tetramino TETRAMINO_O;

#endif
