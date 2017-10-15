#pragma once

#include <vector>
#include "../Util/Vec.h"

enum Direction {
	UP = 1,
	DOWN = -1,
	LEFT = 2,
	RIGHT = -2
};

class Snake
{
	public:
		Snake(Vec2f head_pos, int len);

		// doesn't actually move the snake, returns the head pos after moving the given direction
		Vec2f peek_move(Direction dir);

		void move(Direction dir, bool expand);
		bool is_alive(Vec2f min_bounds, Vec2f max_bounds);

	private:
		Direction m_cur_direction;
		Vec2f m_head_pos;
		std::vector<Vec2f> m_body;
};