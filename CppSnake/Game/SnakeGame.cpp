#include "SnakeGame.h"
#include <iostream>

void SnakeGame::start()
{
	menu();
}

void SnakeGame::menu()
{
	m_console->gotoxy(1, 1);
	std::cout << R"(    _____            ____          __      )"; m_console->gotoxy(1, 2);
	std::cout << R"(   / ___/__  ___    / __/__  ___ _/ /_____ )"; m_console->gotoxy(1, 3);
	std::cout << R"!(  / /__/ _ \/ _ \  _\ \/ _ \/ _ `/  '_/ -_))!"; m_console->gotoxy(1, 4);
	std::cout << R"(  \___/ .__/ .__/ /___/_//_/\_,_/_/\_\\__/ )"; m_console->gotoxy(1, 5);
	std::cout << R"(     /_/  /_/)";

	m_console->gotoxy(5, 10);
	std::cout << "Start Game?";
}