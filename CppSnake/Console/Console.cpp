#include "Console.h"
#include <iostream>

// be sure that defined WIN32 means windows
#if (defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)) && !defined(WIN32)
#define WIN32
#endif

Console* Console::get_instance()
{
#ifdef WIN32
	static Win32Console instance = Win32Console();
	return &instance;
#else
	std::cout << "Platform not supported :(" << std::endl;
	return NULL;
#endif

}
