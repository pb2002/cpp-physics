#include <pch.h>
#include "layerStack.h"

LayerStack::LayerStack() {
	m_layers = std::vector<Object*>();
}

void LayerStack::push(Object* layer) {
	this->m_layers.push_back(layer);

}

void LayerStack::pop(Object* layer) {
	auto it = std::find(m_layers.begin(), m_layers.end(), layer);
	if (it != m_layers.end())
		m_layers.erase(it);
}

void LayerStack::pop(int index) {
	log_assert(index < m_layers.size(), "Index is out of range.");
	m_layers.erase(m_layers.begin() + index);
}

void LayerStack::on_event(SDL_Event* e) {
	for (Object* l : m_layers) l->on_event(e);
}

void LayerStack::on_update() {
	for (Object* l : m_layers) l->on_update();
}

void LayerStack::on_render() {
	for (Object* l : m_layers) l->on_render();
}
