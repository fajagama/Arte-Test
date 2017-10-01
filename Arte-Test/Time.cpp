#include "Time.h"

int unsigned Time::frame_start = 0;
int unsigned Time::frame_end = 0;
int unsigned Time::time_start = 0;

Time::Time()
{
}

Time::~Time()
{
}

int unsigned Time::GetDeltaTime() {
	return frame_end - frame_start;
}

int unsigned Time::GetTime() {
	return SDL_GetTicks() - time_start;
}

void Time::FrameStart() {
	frame_start = SDL_GetTicks();
}

void Time::FrameEnd() {
	frame_end = SDL_GetTicks();
}