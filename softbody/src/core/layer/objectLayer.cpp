#include <pch.h>
#include "objectLayer.h"

ObjectLayer::ObjectLayer() {
	m_objects = std::vector<Object*>();
}

void ObjectLayer::push(Object* obj) { 
	m_objects.push_back(obj); 
}

void ObjectLayer::remove(Object* obj) {
	auto it = std::find(m_objects.begin(), m_objects.end(), obj);
	if (it != m_objects.end()) m_objects.erase(it);
}

void ObjectLayer::remove(int index) { 
	m_objects.erase(begin() + index); 
}

void ObjectLayer::on_event(SDL_Event* e) {
	for (Object* obj : m_objects) {
		obj->on_event(e);
	}
}
void ObjectLayer::on_update() {
	for (Object* obj : m_objects) {
		obj->on_update();
	}
}

void ObjectLayer::on_render() {
	for (Object* obj : m_objects) {
		obj->on_render();
	}
}
