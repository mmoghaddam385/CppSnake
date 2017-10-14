#pragma once

#include "../Console/Console.h"
#include "../Util/Vec2f.h"

class SnakeEngine 
{
	public:
		SnakeEngine(std::shared_ptr<Console> console) : m_console(console) { }

		void start(Vec2f start_pos);

	private:
		void draw_bounds();

		std::shared_ptr<Console> m_console;
};