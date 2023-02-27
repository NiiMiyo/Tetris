#ifndef NII_TETRIS_CONTROLS
#define NII_TETRIS_CONTROLS

#include "SDL2/SDL_keycode.h"
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_rect.h"
#include "game_data.h"

#define KEY_MOVE_RIGHT SDLK_RIGHT
#define KEY_MOVE_LEFT  SDLK_LEFT
#define KEY_ROTATE     SDLK_UP
#define KEY_DROP       SDLK_DOWN
#define KEY_DROP_ALL   SDLK_SPACE

/**
 * Handles user input and moves the tetramino accordingly.
 * If the tetramino should move down but can't *tetramino is set to NULL and the grid is filled.
 * 
 * \param event The event with the user input
 * \param tetramino A pointer to the pointer of the current tetramino
 * \param position The current position of the tetramino
 * \param grid The grid to check collisions
 */
void handle_input(
	SDL_Event *event,
	Tetramino **tetramino,
	SDL_Point *position,
	SDL_bool grid[GRID_WIDTH][GRID_HEIGHT]
);

/**
 * Moves the current tetramino down 1 block if possible.
 * Checks collision with floor and grid.
 * If the tetramino can't move down *tetramino is set to NULL and fills grid.
 * 
 * \param tetramino A pointer to the pointer of the current tetramino
 * \param position The current position of the tetramino
 * \param grid The grid to check collisions
 */
void handle_drop(
	Tetramino **tetramino,
	SDL_Point *position,
	SDL_bool grid[GRID_WIDTH][GRID_HEIGHT]
);

#endif
