#pragma once

#include "../Console/console.h"

class SnakeGame
{
	public:
		SnakeGame(Console* console) : m_console(console) { }

		void start();

	private:
		Console* m_console;

		void menu();
};