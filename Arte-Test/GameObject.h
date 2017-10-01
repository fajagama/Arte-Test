#pragma once

#include "Transform.h"
#include "Renderer.h"
#include <SDL.h>

//p�edelat na komponenty
class GameObject
{
public:
	GameObject();
	GameObject(Transform transform, Renderer renderer);
	~GameObject();
	Transform getTransform();
	Renderer getRenderer();
	SDL_Rect getRect();

private:
	Renderer renderer;
	Transform transform;
	SDL_Rect rect;
};
