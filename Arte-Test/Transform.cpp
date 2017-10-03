#include "Transform.h"

Transform::Transform()
{
	this->position = Position();
}

Transform::Transform(Position position)
{
	this->position = position;
}

Transform::~Transform()
{
}

Position Transform::getPosition()
{
	return this->position;
}

SDL_Point Transform::getStartPoint()
{
	SDL_Point point;
	point.x = this->position.X;
	point.y = this->position.Y;
	return point;
}
