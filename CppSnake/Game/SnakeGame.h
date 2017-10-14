#pragma once

#include "../Console/console.h"


class SnakeGame
{
	public:
		SnakeGame(std::shared_ptr<Console> console) : m_console(console) { }

		void start();

	private:
		std::shared_ptr<Console> m_console;

		void menu();
		void options();
		void play();

		char m_head_up_char = '^';
		char m_head_down_char = 'v';
		char m_head_left_char = '<';
		char m_head_right_char = '>';

		char m_body_vert_char = '\xB0';
		char m_body_hor_char = '\xB0';
		char m_body_top_left_char = '\xB0';
		char m_body_top_right_char = '\xB0';
		char m_body_bot_left_char = '\xB0';
		char m_body_bot_right_char = '\xB0';
};