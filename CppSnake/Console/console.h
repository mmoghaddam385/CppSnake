#pragma once

#define MIN_CONSOLE_HEIGHT 30
#define MIN_CONSOLE_WIDTH 80

class Console
{
	public:
		static Console* get_instance(); // get a system dependant implementation of the console class

		virtual bool test_console(); // check if the console is valid to run in

		virtual void reset_screen() = 0; // reset the screen with a border and nothingness
		virtual void gotoxy(int x, int y) = 0; // set the console cursor position
};

// win32 implementations of the console namespace
class Win32Console : public Console
{
	public:
		bool test_console();

		void reset_screen();
		void gotoxy(int x, int y);

};
