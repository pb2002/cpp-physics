#pragma once
#include <core/object/object.h>
class LayerStack {
public:
	LayerStack();

	inline Object* operator[](int i) { return m_layers[i]; }

	std::vector<Object*>::iterator begin() { return m_layers.begin(); }
	std::vector<Object*>::iterator end() { return m_layers.end(); }
	std::vector<Object*>::const_iterator begin() const { return m_layers.begin(); }
	std::vector<Object*>::const_iterator end() const { return m_layers.end(); }

	void push(Object* layer);
	void pop(Object* layer);
	void pop(int index);

	void on_event(SDL_Event* e);
	void on_update();
	void on_render();
private:
	std::vector<Object*> m_layers;
};