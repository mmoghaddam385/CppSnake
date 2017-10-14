#pragma once

class Vec2f
{
	public:
		Vec2f(float x, float y) : m_x(x), m_y(y) { }

		float x() { return m_x; }
		float y() { return m_y; }

	private:
		float m_x, m_y;
};