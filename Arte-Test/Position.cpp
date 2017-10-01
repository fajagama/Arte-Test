#include "Position.h"

Position::Position()
{
	this->X = 0;
	this->Y = 0;
	this->Z = 0;
}

Position::Position(int X, int Y)
{
	this->X = X;
	this->Y = Y;
	this->Z = 0;
}

Position::Position(int X, int Y, int Z)
{
	this->X = X;
	this->Y = Y;
	this->Z = Z;
}

Position::~Position()
{
}