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

/**
 * Moves the current tetramino based on user input
 */
void move_tetramino(SDL_Event *event, GameData *game_data);


/**
 * Moves the current tetramino down 1 block
 * Checks collision with floor and grid
 * If the tetramino can't move down GAME_DATA->current_tetramino is set to NULL and fills grid
 */
void move_down(GameData *game_data);

#endif
