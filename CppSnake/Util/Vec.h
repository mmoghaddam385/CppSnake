#pragma once

class Vec2f
{
	public:
		Vec2f(float _x, float _y) : x(_x), y(_y) { }
		Vec2f(const Vec2f& other) : Vec2f(other.x, other.y) { }
		Vec2f() : Vec2f(0, 0) { }

		bool operator==(Vec2f &other) const;

		float x, y;
};
