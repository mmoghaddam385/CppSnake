#include "Menu.h"
#include <iostream>

void MenuButton::draw(std::shared_ptr<Console> console)
{
	console->gotoxy(this->m_x, this->m_y);

	// leave room for the '>' selector
	std::cout << "  " << this->m_txt;
}

void MenuButton::activate(std::shared_ptr<Console> console)
{
	console->gotoxy(this->m_x, this->m_y);
	std::cout << ">";
}

void MenuButton::deactivate(std::shared_ptr<Console> console)
{
	console->gotoxy(this->m_x, this->m_y);
	std::cout << " ";
}

bool MenuButton::handle_input(std::shared_ptr<Console> console, int input_key)
{
	if (input_key == ENTER_KEY)
	{
		return this->m_callback();
	}

	return false;
}
