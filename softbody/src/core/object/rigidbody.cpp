#include <pch.h>
#include "rigidbody.h"
#include <core/render/shape.h>

Rigidbody::Rigidbody(double mass, vec2 position) : m_mass(mass), m_position(position)
{
	m_velocity = vec2();
	m_gravityScale = 1;
	m_rotation = 45;
	m_angularVelocity = 0;
}

void Rigidbody::on_event(SDL_Event* e) {}
void Rigidbody::on_update() {
	m_velocity += vec2(0, -m_gravityScale) * DELTA_TIME;
	m_position += m_velocity * DELTA_TIME;
}

void Rigidbody::on_render() {
	Shape s = Shape();
	s.m_points.push_back(&vec2(-0.5, 0.5));
	s.m_points.push_back(&vec2(1, 1));
	s.m_points.push_back(&vec2(0.5, -0.5));
	s.m_points.push_back(&vec2(-0.5, -0.5));
	Renderer::instance->set_color(255, 0, 255);
	s.draw(m_position, m_rotation);
}
