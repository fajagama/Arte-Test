#include "Time.h"

int Time::frame_start = 0;
int Time::frame_end = 0;
int Time::time_start = 0;

Time::Time()
{
}

Time::~Time()
{
}

int Time::GetDeltaTime() {
	return frame_end - frame_start;
}

int Time::GetTime() {
	return SDL_GetTicks() - time_start;
}

void Time::FrameStart() {
	frame_start = SDL_GetTicks();
}

void Time::FrameEnd() {
	frame_end = SDL_GetTicks();
}