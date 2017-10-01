#include <SDL.h>


int main(int argc, char **argv)
{
	SDL_Window* screen = NULL;

	//Start SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	screen = SDL_CreateWindow("Test", 0, 0, 640, 480, SDL_WINDOW_SHOWN);

	//Quit SDL
	SDL_Quit();

	return 0;
}