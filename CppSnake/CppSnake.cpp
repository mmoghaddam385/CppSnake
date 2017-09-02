// CppSnake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Console/console.h"
#include "Game/SnakeGame.h"
#include <iostream>
#include <Windows.h>

int main()
{
	Console* console = Console::get_instance();
	if (!console || !console->test_console())
	{
		return 1;
	}

	console->reset_screen();

	std::cout << console->read_char();

	SnakeGame game = SnakeGame(console);
	game.start();
		
	system("pause");
    return 0;
}

