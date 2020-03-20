#pragma once
#include <SDL.h>
#include "layer/layer.h"
#include "render/renderer.h"

class App {
public:
	void init(const char* title,
			  int x, int y,
			  int w, int h,
			  bool fullscreen);
	void on_event();
	void on_update();
	void on_render();
	
	void push_layer(Object* layer) { m_layerStack->push(layer); }
	void pop_layer(Object* layer) { m_layerStack->pop(layer); }
	void pop_layer(int index) { m_layerStack->pop(index); }

	void quit();

	const inline bool is_running() const { return m_running; }
private:
	bool m_running;
	SDL_Window* m_window;
	LayerStack* m_layerStack;
};

