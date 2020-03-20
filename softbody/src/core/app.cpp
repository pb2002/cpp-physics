#include <pch.h>
#include "app.h"

Renderer* Renderer::instance;

void App::init(const char* title, int x, int y, int w, int h, bool fullscreen) {
	this->m_layerStack = new LayerStack();
	log_trc("Initializing SDL...");
	log_assert(!SDL_Init(SDL_INIT_EVERYTHING),
	   "SDL raised an error whilst initializing: " << SDL_GetError());
	log_trc("Creating SDL Window...");
	
	this->m_window = SDL_CreateWindow(title, x, y, w, h,
		SDL_WINDOW_ALLOW_HIGHDPI | (fullscreen ? SDL_WINDOW_FULLSCREEN : 0));
	log_assert(m_window, "Failed to create SDL window: " << SDL_GetError());
	Renderer::init(m_window);

	this->m_running = true;
	log_inf("Successfully initialized application.");
}

void App::on_event() {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
			case SDL_QUIT:
				this->m_running = false;
				break;
			default:
				break;
		}
		m_layerStack->on_event(&e);
	}
}

void App::on_update() {
	m_layerStack->on_update();
}

void App::on_render() {
	Renderer::instance->fill(255, 255, 255);
	m_layerStack->on_render();
	Renderer::instance->flip();
}

void App::quit() {}
