#include "Console.h"
#include <iostream>

// be sure that defined WIN32 means windows
#if (defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)) && !defined(WIN32)
#define WIN32
#endif

std::shared_ptr<Console> Console::get_instance()
{
#ifdef WIN32
	return std::shared_ptr<Console>(new Win32Console());
#else
	std::cout << "Platform not supported :(" << std::endl;
	return NULL;
#endif
}

void Console::reset_screen()
{
	this->clear_screen();
	this->gotoxy(0, 0);

	std::cout << TOP_ROW << std::endl;

	for (int y = 1; y < MIN_CONSOLE_HEIGHT - 1; y++)
	{
		std::cout << MID_ROW << std::endl;
	}

	std::cout << TOP_ROW << std::endl;
}
