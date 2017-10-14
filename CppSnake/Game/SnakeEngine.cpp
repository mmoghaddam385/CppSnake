#include "SnakeEngine.h"
#include <iostream>

void SnakeEngine::start(Vec2f start_pos) 
{
	this->draw_bounds();

	m_console->gotoxy(10, 10);
}

void SnakeEngine::draw_bounds()
{
	this->m_console->reset_screen();
}