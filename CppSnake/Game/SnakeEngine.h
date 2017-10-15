#pragma once

#include "../Console/Console.h"
#include "../Util/Vec.h"

class Settings
{
	public:
		Settings() { }
		Settings(Vec2f start_pos, long turn_length, long snake_len) 
			: m_start_pos(start_pos), m_turn_length(turn_length), m_snake_len(snake_len) { }

		Vec2f m_start_pos;
		long m_turn_length;
		long m_snake_len;
};

const Settings EASY_SETTINGS(Vec2f(30, 40), 100, 5);

class SnakeEngine 
{
	public:
		SnakeEngine(std::shared_ptr<Console> console) : m_console(console) { }

		void start(Settings start_settings);

	private:
		void draw_bounds();

		long m_cur_turn_length;
		Settings m_settings;
		std::shared_ptr<Console> m_console;
};