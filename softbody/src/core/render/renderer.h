#pragma once
#include <pch.h>
#include <core/math/math.h>
#include <SDL.h>

class Renderer {
public:
	static void init(SDL_Window* w) {		
		instance = new Renderer();
		instance->m_renderer = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED);
	}
	
	void set_color(int r, int g, int b, int a = 255) {
		SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
	}
	void fill(int r, int g, int b, int a = 255) {
		SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
		SDL_RenderClear(this->m_renderer);
	}
	void draw_triangle(vec2& v1, vec2& v2, vec2& v3) {
		SDL_RenderDrawLine(m_renderer, 
						   w2s_x(v1.x), w2s_y(v1.y), 
						   w2s_x(v2.x), w2s_y(v2.y));
		SDL_RenderDrawLine(m_renderer,
						   w2s_x(v2.x), w2s_y(v2.y),
						   w2s_x(v3.x), w2s_y(v3.y));
		SDL_RenderDrawLine(m_renderer,
						   w2s_x(v3.x), w2s_y(v3.y),
						   w2s_x(v1.x), w2s_y(v1.y));
	}
	void flip() {
		SDL_RenderPresent(m_renderer);
	}

	static Renderer* instance;

private:
	SDL_Renderer* m_renderer;

};


