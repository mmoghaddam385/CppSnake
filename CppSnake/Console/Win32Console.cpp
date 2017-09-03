#include "Console.h"

#include <iostream>
#include <Windows.h>
#include <conio.h>

// get the screen size of the console
COORD get_screen_size();

bool Win32Console::test_console()
{
	COORD screen_size = get_screen_size();

	if (screen_size.X < MIN_CONSOLE_WIDTH || screen_size.Y < MIN_CONSOLE_HEIGHT)
	{
		std::cout << "Console too small; must be at least " << MIN_CONSOLE_WIDTH << "x" << MIN_CONSOLE_HEIGHT << std::endl;
		return false;
	}

	return true;
}

void Win32Console::gotoxy(int x, int y)
{
	COORD pos = { (short) x, (short) y };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}

void Win32Console::reset_screen()
{
	system("cls");
	this->gotoxy(0, 0);

	std::cout << TOP_ROW << std::endl;

	for (int y = 1; y < MIN_CONSOLE_HEIGHT - 1; y++)
	{
		std::cout << MID_ROW << std::endl;
	}

	std::cout << TOP_ROW << std::endl;

}

int Win32Console::read_char()
{
	int ch = _getch();
	
	// if the first ch is 0 or 0xE0, it's an arrow get and we need to call _getch() again for that actual value
	if (ch == 0 || ch == 0xE0)
	{
		return _getch();
	}

	return ch;
}

COORD get_screen_size()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD retval;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	retval.X = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	retval.Y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	return retval;
}