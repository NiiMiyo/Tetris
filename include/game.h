#ifndef NII_TETRIS_GAME
#define NII_TETRIS_GAME

#define CONTINUE_GAME_LOOP 1
#define BREAK_GAME_LOOP    0

#include "SDL2/SDL.h"
#include "game_data.h"


/**
 * Runs game logic.
 * Returns BREAK_GAME_LOOP (expands to 0) if game loop ended.
 * Otherwise, returns CONTINUE_GAME_LOOP (expands to 1).
 */
int game_loop(struct GameData *GAME_DATA);

/**
 * Checks if the game loop should end.
 */
int should_quit(SDL_Event *e);

#endif
