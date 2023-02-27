#include <stdlib.h>

#include "tetramino.h"
#include "constants.h"

SDL_Point block_position(Tetramino *tetramino, int block, SDL_Point tetramino_position) {
	SDL_Point b = tetramino->blocks[block];

	return (SDL_Point){
		.x = b.x + tetramino_position.x,
		.y = b.y + tetramino_position.y
	};
}

Tetramino *POSSIBLE_TETRAMINOES[] = {
	&TETRAMINO_O,
	&TETRAMINO_J,
	&TETRAMINO_L,
	&TETRAMINO_S,
	&TETRAMINO_T,
	&TETRAMINO_Z,
	&TETRAMINO_I
};
const int QUANT_TETRAMINOES = sizeof(POSSIBLE_TETRAMINOES) / sizeof(Tetramino *);

Tetramino random_tetramino() {
	return *(POSSIBLE_TETRAMINOES[rand() % QUANT_TETRAMINOES]);
}

SDL_Point spawn_offset(Tetramino *tetramino) {
	if (!tetramino)
		return (SDL_Point){0,0};

	int y = 0, min_x = 0, max_x = 0;
	for (int i = 0; i < 4; i++) {
		SDL_Point b = tetramino->blocks[i];

		if (b.y < y)
			y = b.y;

		if (b.x < min_x)
			min_x = b.x;

		else if (b.x > max_x)
			max_x = b.x;
	}

	return (SDL_Point) {
		.x = -((max_x - min_x) / 2) - 1,
		.y = -y
	};
}

Tetramino TETRAMINO_O = {
	.blocks = { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } },
	.rotatesInto = &TETRAMINO_O
};

Tetramino TETRAMINO_I = {
	.blocks = { {0, 1}, {1, 1}, {2, 1}, {3, 1} },
	.rotatesInto = &(Tetramino) {
		.blocks = { {2, 0}, {2, 1}, {2, 2}, {2, 3} },
		.rotatesInto = &(Tetramino) {
			.blocks = { {0, 2}, {1, 2}, {2, 2}, {3, 2} },
			.rotatesInto = &(Tetramino) {
				.blocks = { {1, 0}, {1, 1}, {1, 2}, {1, 3 } },
				.rotatesInto = &TETRAMINO_I
			},
		}
	}
};

Tetramino TETRAMINO_J = {
	.blocks = { {0, 0}, {0, 1}, {1, 1}, {2, 1} },
	.rotatesInto = &(Tetramino) {
		.blocks = { {1, 0}, {2, 0}, {1, 1}, {1, 2} },
		.rotatesInto= &(Tetramino) {
			.blocks = { {0, 1}, {1, 1}, {2, 1}, {2, 2} },
			.rotatesInto = &(Tetramino) {
				.blocks = { {1, 0}, {1, 1}, {1, 2}, {0, 2} },
				.rotatesInto = &TETRAMINO_J
			}
		}
	}
};

Tetramino TETRAMINO_L = {
	.blocks = { {0, 1}, {1, 1}, {2, 1}, {2, 0} },
	.rotatesInto = &(Tetramino){
		.blocks = { {1, 0}, {1, 1}, {1, 2}, {2, 2} },
		.rotatesInto = &(Tetramino){
			.blocks = { {0, 1}, {1, 1}, {2, 1}, {0, 2} },
			.rotatesInto = &(Tetramino){
				.blocks = { {0, 0}, {1, 0}, {1, 1}, {1, 2} },
				.rotatesInto = &TETRAMINO_L
			}
		}
	}
};

Tetramino TETRAMINO_S = {
	.blocks = { {1, 0}, {2, 0}, {0, 1}, {1, 1} },
	.rotatesInto = &(Tetramino) {
		.blocks = { {1, 0}, {1, 1}, {2, 1}, {2, 2} },
		.rotatesInto = &(Tetramino) {
			.blocks = { {1, 1}, {2, 1}, {0, 2}, {1, 2} },
			.rotatesInto = &(Tetramino) {
				.blocks = { {0, 0}, {0, 1}, {1, 1}, {1, 2} },
				.rotatesInto = &TETRAMINO_S
			}
		}
	}
};

Tetramino TETRAMINO_T = {
	.blocks = { {1, 0}, { 0, 1 }, { 1, 1 }, { 2, 1 } },
	.rotatesInto = &(Tetramino) {
		.blocks = { { 1, 0 }, { 1, 1 }, { 2, 1 }, { 1, 2 } },
		.rotatesInto = &(Tetramino) {
			.blocks = { { 0, 1 }, { 1, 1 }, { 2, 1 }, { 1, 2 } },
			.rotatesInto = &(Tetramino) {
				.blocks = { { 1, 0 }, { 0, 1 }, { 1, 1 }, { 1, 2 } },
				.rotatesInto = &TETRAMINO_T
			}
		}
	}
};

Tetramino TETRAMINO_Z = {
	.blocks = { {1, 0}, {0, 0}, {2, 1}, {1, 1} },
	.rotatesInto = &(Tetramino) {
		.blocks = { {2, 0}, {1, 1}, {2, 1}, {1, 2} },
		.rotatesInto = &(Tetramino) {
			.blocks = { {1, 1}, {0, 1}, {2, 2}, {1, 2} },
			.rotatesInto = &(Tetramino) {
				.blocks = { {1, 0}, {0, 1}, {1, 1}, {0, 2} },
				.rotatesInto = &TETRAMINO_Z
			}
		}
	}
};
