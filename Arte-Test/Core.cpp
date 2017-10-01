#include "Core.h"
#include "Time.h"

Core::Core(char* window_name)
{
	init(window_name);
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
		if (Time::GetDeltaTime() < DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - Time::GetDeltaTime()));
		}
	}
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
}

void Core::render()
{
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
	}
}

void Core::clean()
{
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
	SDL_Quit();
}
