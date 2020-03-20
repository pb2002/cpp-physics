#include <pch.h>
#include "core/core.h"
int main(int argc, char *argv[]) {

	auto layer = ObjectLayer();

	auto rigidbody = Rigidbody(1.0, vec2(0.0, 0.0));
	layer.push(&rigidbody);
	
	auto app = App();
	app.init("Test Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
							S_WIDTH, S_HEIGHT, false);
	app.push_layer(&layer);
	
	Uint64 frameStart;
	int frametime;
	while (app.is_running()) {

		frameStart = SDL_GetTicks();
		app.on_event();
		app.on_update();
		app.on_render();
		
		frametime = SDL_GetTicks() - frameStart;
		if (1000/60 > frametime) {
			SDL_Delay(1000/60 - frametime);
		}
	}
	return 0;
}