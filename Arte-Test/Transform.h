#pragma once

#include "Position.h"
#include <SDL.h>

class Transform
{
public:
	Transform();
	Transform(Position position);
	~Transform();
	Position getPosition();
	SDL_Point getStartPoint();
private:
	Position position;
};
