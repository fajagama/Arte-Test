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
