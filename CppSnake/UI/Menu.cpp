#include "Menu.h"

void Menu::capture_input()
{
	this->init_menu();

	bool quit = false;
	while (!quit)
	{
		int ch = this->m_console->read_char();

		// if its an up or down arrow
		if (ch == UP_ARROW_KEY || ch == DOWN_ARROW_KEY)
		{
			// deactivate the old item
			this->m_menu_items[this->m_active_index]->deactivate(this->m_console);

			switch (ch)
			{
				case UP_ARROW_KEY:   this->m_active_index--; break;
				case DOWN_ARROW_KEY: this->m_active_index++; break;
			}

			// wrap active index
			this->m_active_index %= this->m_menu_items.size();

			// activate the new item
			this->m_menu_items[this->m_active_index]->activate(this->m_console);
		}
		else
		{
			quit = this->m_menu_items[this->m_active_index]->handle_input(this->m_console, ch);
		}
	}

}

void Menu::init_menu()
{
	for (auto & item : this->m_menu_items)
	{
		item->draw(this->m_console);
	}

	this->m_menu_items[0]->activate(this->m_console);
	this->m_active_index = 0;
}