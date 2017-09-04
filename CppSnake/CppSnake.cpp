// CppSnake.cpp : Defines the entry point for the console application.
//

#include "Console/console.h"
#include "Game/SnakeGame.h"
#include <iostream>
#include <Windows.h>

int main()
{
	auto console = Console::get_instance();
	if (!console || !console->test_console())
	{
		return 1;
	}

	console->reset_screen();

	SnakeGame game = SnakeGame(console);
	game.start();
		
	console->clear_screen();
    return 0;
}

