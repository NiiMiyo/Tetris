#include <SDL2/SDL.h>

int should_quit(SDL_Event *e) {
	return (*e).type == SDL_QUIT;
}
