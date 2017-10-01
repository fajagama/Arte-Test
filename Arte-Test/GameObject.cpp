#include "GameObject.h"

GameObject::GameObject()
{
	this->transform = Transform();
}

GameObject::GameObject(Transform transform, Renderer renderer)
{
	this->transform = transform;
	this->renderer = renderer;

	this->rect = SDL_Rect();
	this->rect.x = this->transform.getPosition().X;
	this->rect.y = this->transform.getPosition().Y;
	this->rect.h = this->renderer.getSurface().h;
	this->rect.w = this->renderer.getSurface().w;
}

GameObject::~GameObject()
{
}

Transform GameObject::getTransform()
{
	return this->transform;
}

Renderer GameObject::getRenderer()
{
	return this->renderer;
}

SDL_Rect GameObject::getRect()
{
	return this->rect;
}
