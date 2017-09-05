#pragma once

#include "../Console/console.h"

#include <memory>

class SnakeGame
{
	public:
		SnakeGame(std::shared_ptr<Console> console) : m_console(console) { }

		void start();

	private:
		std::shared_ptr<Console> m_console;

		void menu();
		void options();
};