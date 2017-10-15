#include "SnakeEngine.h"
#include <iostream>

void SnakeEngine::start(Settings start_settings) 
{
	this->m_settings = Settings(start_settings);
	this->m_cur_turn_length = this->m_settings.m_turn_length;

	this->draw_bounds();

	m_console->gotoxy(10, 10);
}

void SnakeEngine::draw_bounds()
{
	this->m_console->reset_screen();
}