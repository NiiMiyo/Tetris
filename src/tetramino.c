#include "tetramino.h"
#include "constants.h"

const Tetramino TETRAMINO_O = {
	.blocks = { { 0, 0 },
		         { 0, 1 },
		         { 1, 0 },
		         { 1, 1 } },
	.rotatesInto = &TETRAMINO_O
};
