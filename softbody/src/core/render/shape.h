#pragma once
#include <pch.h>
#include <core/math/math.h>
#include <core/render/renderer.h>

class Shape {
public:
	Shape() {}
	Shape(std::vector<vec2*> &points) { m_points = std::vector<vec2*>(points); }
	vec2 getSupport(const vec2& dir) {
		double best_proj = -DBL_MAX;
		vec2 best_vertex;
		for (int i = 0; i < m_points.size(); i++) {
			vec2 v = *m_points[i];
			double proj = vec2::dot(v, dir);
			if (proj > best_proj) {
				best_vertex = v;
				best_proj = proj;
			}
		}
		return best_vertex;
	}
	void draw(vec2& position, float rotation) {
		auto c = calculate_center();
		
		for (int i = 0; i < m_points.size(); i++) {
			auto a = *m_points[i] - c;
			a.rotate(rotation);
			a += position;
			auto b = *m_points[(i + 1) % m_points.size()] - c;
			b.rotate(rotation);
			b += position;
			Renderer::instance->draw_triangle(
				a, 
				b, 
				position);
		}
	}
	std::vector<vec2*> m_points;

	// Finds the vertex of shape A that 
	static double find_axis_least_penetration(unsigned int* index, Shape* A, Shape* B) {

		double best_dist = -DBL_MAX;
		unsigned int best_index = -1;

		for (unsigned int i = 0; i < A->m_points.size(); ++i) {
			// Retrieve a face normal from A
			vec2 n = A->

			// Retrieve support point from B along -n
			vec2 s = B->getSupport(-n);

			// Retrieve vertex on face from A, transform into
			// B's model space
			vec2 v = *A->m_points[i];

			// Compute penetration distance (in B's model space)
			double d = vec2::dot(n, s - v);

			// Store greatest distance
			if (d > best_dist) {
				best_dist = d;
				best_index = i;
			}
		}

		*index = best_index;
		return best_dist;
	}
private:
	vec2& calculate_center() {
		vec2 center = vec2(0,0);
		for (auto point : m_points) {
			center = center + *point;
		}
		center /= m_points.size();
		return center;
	}
};