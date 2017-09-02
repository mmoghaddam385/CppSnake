// CppSnake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Console/console.h"
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

	system("pause");
    return 0;
}

