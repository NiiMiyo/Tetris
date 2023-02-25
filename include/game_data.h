#ifndef NII_TETRIS_GAMEDATA
#define NII_TETRIS_GAMEDATA

#include "SDL2/SDL.h"
#include "constants.h"

/**
 * Holds information on current game data and variables used during the game execution.
 */
struct GameData {
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_bool grid[GRID_WIDTH][GRID_HEIGHT];
};

/**
 * Initializes, logs errors and returns initial game data.
 * Returns NULL if something fails.
 */
struct GameData *init();

/**
 * Closes and frees resources.
 */
void close(struct GameData *GAME_DATA);

#endif
