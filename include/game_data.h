#ifndef NII_TETRIS_GAMEDATA
#define NII_TETRIS_GAMEDATA

#include "SDL2/SDL_video.h"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_stdinc.h"
#include "constants.h"
#include "tetramino.h"

/**
 * Holds information on current game data and variables used during the game execution.
 */
typedef struct GameData {
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_bool grid[GRID_WIDTH][GRID_HEIGHT];

	Tetramino *current_tetramino;
	SDL_Point tetramino_position;
} GameData;

/**
 * Initializes, logs errors and returns initial game data.
 * Returns NULL if something fails.
 */
GameData *init();

/**
 * Closes and frees resources.
 */
void close(GameData *GAME_DATA);

/**
 * Returns 1 if GAME_DATA->grid[x][y] is 0 and the position is inside the grid.
 * Otherwise returns 0
 */
SDL_bool valid_grid_position(GameData *GAME_DATA, int x, int y);

#endif
