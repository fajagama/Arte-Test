#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Renderer
{
public:
	Renderer();
	Renderer(std::string image);
	~Renderer();
	SDL_Surface getSurface();
private:
	SDL_Surface loadedSurface;
};
