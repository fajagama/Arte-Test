#pragma once

#include "Position.h"

class Transform
{
public:
	Transform();
	Transform(Position position);
	~Transform();
	Position getPosition();
private:
	Position position;
};
