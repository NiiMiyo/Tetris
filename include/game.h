#ifndef NII_TETRIS_GAME
#define NII_TETRIS_GAME

#include "SDL2/SDL_stdinc.h"
#include "game_data.h"

/**
 * Runs game logic.
 * Returns SDL_FALSE if game loop ended. Returns SDL_TRUE otherwise.
 */
SDL_bool game_loop(GameData *GAME_DATA);

#endif
