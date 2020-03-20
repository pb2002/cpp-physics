#pragma once
#include <core/math/math.h>
#include "object.h"

// Rigidbody class
class Rigidbody : public Object {
public:
	Rigidbody(double mass, vec2 position);

	// Inherited via Object
	virtual void on_event(SDL_Event* e) override;
	virtual void on_update() override;
	virtual void on_render() override;

	double m_mass; // mass
	double m_gravityScale; // size of gravity accelleration vector;

	vec2 m_position; // position
	vec2 m_velocity; // velocity
	vec2 m_acceleration = vec2(); // accelleration
	double m_rotation; // rotation
	double m_angularVelocity; // angular velocity
	double m_torque = 0; // torque
};

