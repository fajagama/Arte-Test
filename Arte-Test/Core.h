#pragma once
#include <SDL.h>

using namespace std;

class Core
{
public:
	Core(char* window_name);
	~Core();
	void run(); 

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool running;
	const int FPS = 60;
	const int DELAY_TIME = 1000.0f / FPS;

	void init(char* window_name);
	void render();
	void update();
	void handleEvents();
	void clean();
};
