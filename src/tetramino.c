#include "tetramino.h"
#include "constants.h"

Tetramino TETRAMINO_O = {
	.blocks = { { 0, 0 },
		         { 0, 1 },
		         { 1, 0 },
		         { 1, 1 } },
	.rotatesInto = &TETRAMINO_O
};

SDL_Point block_position(Tetramino *tetramino, int block, SDL_Point tetramino_position) {
	SDL_Point b = tetramino->blocks[block];

	return (SDL_Point){
		.x = b.x + tetramino_position.x,
		.y = b.y + tetramino_position.y
	};
}
