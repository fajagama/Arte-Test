#pragma once
#include <SDL.h>

class Time
{
public:
	Time();
	~Time();

	static int GetDeltaTime();
	static int GetTime();
	static void FrameStart();
	static void FrameEnd();
private:
	static int frame_start;
	static int frame_end;
	static int time_start;
};
