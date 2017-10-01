#pragma once
#include <SDL.h>

class Time
{
public:
	Time();
	~Time();

	static unsigned int GetDeltaTime();
	static unsigned int GetTime();
	static void FrameStart();
	static void FrameEnd();
private:
	static unsigned int frame_start;
	static unsigned int frame_end;
	static unsigned int time_start;
};
