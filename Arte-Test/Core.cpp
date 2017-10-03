#include "Core.h"
#include "Time.h"
#include <iostream>

Core::Core(char* window_name)
{
	init(window_name);
	this->game_objects = list<GameObject>();
	current_FPS = max_FPS;
}

Core::~Core()
{
	clean();
}

void Core::run()
{
	while (this->running) {
		Time::FrameStart();

		handleEvents();
		update();
		render();

		Time::FrameEnd();
		if (Time::GetDeltaTime() < (1000.0f / this->current_FPS))
		{
			SDL_Delay((int)((1000.0f / this->current_FPS) - Time::GetDeltaTime()));
		}
	}
}

void Core::addGameObject(GameObject go)
{
	this->game_objects.push_back(go);
}

void Core::init(char* window_name)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		this->window = SDL_CreateWindow(window_name, 50, 50, 640, 480, SDL_WINDOW_SHOWN);
	}
	if (this->window != 0)
	{
		this->renderer = SDL_CreateRenderer(this->window, -1, 0);

		running = true;

	}
	IMG_Init(IMG_INIT_PNG);

	SDL_RendererInfo rendererInfo;
	SDL_GetRendererInfo(renderer, &rendererInfo);

	std::cout << "Renderer: " << rendererInfo.name << std::endl;
}

void Core::render()
{
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.h = 480;
	rect.w = 640;

	for (list<GameObject>::iterator it = this->game_objects.begin(); it != this->game_objects.end(); ++it) {
		//kreslim to co vidím
		//TODO vyladit a dodelat
		if (SDL_PointInRect(&it->getTransform().getStartPoint(), &rect)){
			SDL_Texture* texture = NULL;
			texture = SDL_CreateTextureFromSurface(this->renderer, &it->getRenderer().getSurface());
			SDL_RenderCopy(renderer, texture, NULL, &it->getRect());
			SDL_DestroyTexture(texture);
		}
	}

	SDL_RenderPresent(this->renderer);
}

void Core::update()
{
}

void Core::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			running = false;
			break;
		default:
			break;
		}
		if (event.type == SDL_WINDOWEVENT) {
			switch (event.window.event) {
				case SDL_WINDOWEVENT_FOCUS_LOST:
					this->current_FPS = this->backgrounf_FPS;
					break;
				case SDL_WINDOWEVENT_FOCUS_GAINED:
					this->current_FPS = this->max_FPS;
					break;
			}
		}
	}
}

void Core::clean()
{
	IMG_Quit();
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
	SDL_Quit();
}
