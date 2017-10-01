#include "Renderer.h"

Renderer::Renderer()
{
}

Renderer::Renderer(std::string image)
{
	this->loadedSurface = *IMG_Load(image.c_str());
}

Renderer::~Renderer()
{
}

SDL_Surface Renderer::getSurface()
{
	return this->loadedSurface;
}
