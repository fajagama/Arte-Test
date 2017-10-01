#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"
#include <list>

using namespace std;

class Core
{
public:
	Core(char* window_name);
	~Core();
	void run(); 
	void addGameObject(GameObject go);
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

	list<GameObject> game_objects;
};
