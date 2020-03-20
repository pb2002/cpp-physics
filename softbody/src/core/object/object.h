#pragma once
#include <SDL.h>
class Object {
public:
	Object() {}
	virtual void on_event(SDL_Event* e) = 0;
	virtual void on_update() = 0;
	virtual void on_render() = 0;
};