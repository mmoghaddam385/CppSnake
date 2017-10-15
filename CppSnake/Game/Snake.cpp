#include "Snake.h"

Snake::Snake(Vec2f head_pos, int len)
{
	m_cur_direction = LEFT;
	m_head_pos = head_pos;

	// initialize the rest of the body to the right of the head
	for (int n = 1; n <= len; n++) {
		m_body.push_back(Vec2f(m_head_pos.x + n, m_head_pos.y));
	}
}

Vec2f Snake::peek_move(Direction dir)
{
	Vec2f head = Vec2f(m_head_pos);

	// don't allow turning around
	if (m_cur_direction == -dir) {
		return head;
	}	

	switch (dir) {
		case UP: 	head.y--; break;
		case DOWN: 	head.y++; break;
		case LEFT:	head.x--; break;
		case RIGHT:	head.x++; break;
	}

	return head;
}

void Snake::move(Direction dir, bool expand) 
{
	// don't allow turning around
	if (m_cur_direction == -dir) {
		return;
	}

	m_body.insert(m_body.begin(), m_head_pos);

	if (!expand) {
		m_body.pop_back();
	}

	m_head_pos = this->peek_move(dir);
}

bool Snake::is_alive(Vec2f min_bounds, Vec2f max_bounds)
{
	// check if head is in bounds
	if (m_head_pos.x <= min_bounds.x || m_head_pos.x >= max_bounds.x) {
		return false;
	}
	if (m_head_pos.y <= min_bounds.y || m_head_pos.y >= max_bounds.y) {
		return false;
	}

	// check if snake is eating itself
	for (int n = 0; n < m_body.size(); n++) {
		if (m_head_pos == m_body[n]) {
			return false;
		}
	}

	return true;
}
