#pragma once

#define MIN_CONSOLE_HEIGHT 30
#define MIN_CONSOLE_WIDTH 80

class Console
{
	public:
		static Console* get_instance(); // get a system dependant implementation of the console class

		virtual bool test_console() = 0; // check if the console is valid to run in

		virtual void reset_screen() = 0; // reset the screen with a border and nothingness
		virtual void gotoxy(int x, int y) = 0; // set the console cursor position

		virtual int read_char() = 0; // read's a single char from stdin without echoing
};

// win32 implementations of the console namespace
class Win32Console : public Console
{
	public:
		bool test_console();

		void reset_screen();
		void gotoxy(int x, int y);

		int read_char();
};
