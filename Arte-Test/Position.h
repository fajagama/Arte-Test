#pragma once

class Position
{
public:
	int X;
	int Y;
	int Z;

	Position();
	Position(int X, int Y);
	Position(int X, int Y, int Z);

	~Position();
};
