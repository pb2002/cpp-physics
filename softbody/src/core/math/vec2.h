#pragma once
// 2 dimensional vector class (based off https://gist.github.com/acidleaf/8957147)

class vec2 {
public:
	double x, y;

	vec2() :x(0), y(0) {}
	vec2(double x, double y) : x(x), y(y) {}
	vec2(const vec2& v) : x(v.x), y(v.y) {}

	inline vec2& operator=(const vec2& v) { x = v.x; y = v.y; return *this; }
	
    inline vec2 operator+(vec2& v) const { return vec2(x + v.x, y + v.y); }
	inline vec2 operator-(vec2& v) const { return vec2(x - v.x, y - v.y); }
	inline vec2 operator*(double s) const { return vec2(x * s, y * s); }
	inline vec2 operator/(double s) const { return vec2(x / s, y / s); }

	inline vec2 operator-() const { return vec2(-x, -y); }

	vec2& operator+=(vec2 const& v) { x += v.x; y += v.y; return *this; }
	vec2& operator-=(vec2 const& v) { x -= v.x; y -= v.y; return *this; }
	vec2& operator*=(double s) { x *= s; y *= s; return *this; }
	vec2& operator/=(double s) { x /= s; y /= s; return *this; }

	inline void set(double x, double y) { this->x = x; this->y = y; }

	void rotate(double deg) {
		double c = cos(M_PI * deg / 180.0); double s = sin(M_PI * deg / 180.0);
		double tx = x * c - y * s; double ty = x * s + y * c;
		x = tx; y = ty;
	}

	vec2& normalize() {
		if (length() > 0) *this *= (1.0 / length());
		return *this;
	}

	float dist(vec2 v) const {
		vec2 d(v.x - x, v.y - y);
		return d.length();
	}
	float length() const {
		return std::sqrt(x * x + y * y);
	}
	void truncate(double length) {
		double angle = atan2f(y, x);
		x = length * cos(angle);
		y = length * sin(angle);
	}
	
	vec2 ortho() const {
		return vec2(y, -x);
	}
    static double dot(vec2 v1, vec2 v2) { return v1.x * v2.x + v1.y * v2.y; }
    static double cross(vec2 v1, vec2 v2) { return (v1.x * v2.y) - (v1.y * v2.x); }

};
