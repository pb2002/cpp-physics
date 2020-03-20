#pragma once
#include <pch.h>
#include "Layer.h"

#include <core/object/object.h>

class ObjectLayer : public Object {
public:
	ObjectLayer();

	virtual inline Object* operator[](int i) { return m_objects[i]; }
	
	std::vector<Object*>::iterator begin() { return m_objects.begin(); }
	std::vector<Object*>::iterator end() { return m_objects.end(); }
	std::vector<Object*>::const_iterator begin() const { return m_objects.begin(); }
	std::vector<Object*>::const_iterator end() const { return m_objects.end(); }

	virtual void push(Object* obj);
	virtual void remove(Object* obj);
	virtual void remove(int index);

	virtual void on_event(SDL_Event* e) override;
	virtual void on_update() override;
	virtual void on_render() override;

protected:
	std::vector<Object*> m_objects;
};