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
 * Returns the movement of the tetramino based on input
 */
void move_tetramino(SDL_Event *event, GameData *GAME_DATA);

#endif
