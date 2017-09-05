#include "SnakeGame.h"
#include "../UI/Menu.h"

#include <iostream>
#include <vector>

bool callback()
{
	std::cout << "Button Pressed";
	return false;
}

void SnakeGame::start()
{
	menu();
}

void SnakeGame::menu()
{
	// print banner
	m_console->gotoxy(1, 1);
	std::cout << R"(    _____            ____          __      )"; m_console->gotoxy(1, 2);
	std::cout << R"(   / ___/__  ___    / __/__  ___ _/ /_____ )"; m_console->gotoxy(1, 3);
	std::cout << R"!(  / /__/ _ \/ _ \  _\ \/ _ \/ _ `/  '_/ -_))!"; m_console->gotoxy(1, 4);
	std::cout << R"(  \___/ .__/ .__/ /___/_//_/\_,_/_/\_\\__/ )"; m_console->gotoxy(1, 5);
	std::cout << R"(     /_/  /_/)";

	// set up menu
	std::vector<std::unique_ptr<MenuItem>> menu_items;

	menu_items.push_back(std::make_unique<MenuButton>(MenuButton(3, 10, "Start game", callback)));
	menu_items.push_back(std::make_unique<MenuButton>(MenuButton(3, 12, "Options", [&] { this->options(); return true; } )));
	menu_items.push_back(std::make_unique<MenuButton>(MenuButton(3, 14, "Quit", [] {return true; })));

	auto menu = Menu(m_console, menu_items);
	menu.capture_input();
	
}

void SnakeGame::options()
{
	m_console->reset_screen();

	std::vector<std::string> head_options {"A", "B", "C", "D"};

	// set up options menu
	std::vector<std::unique_ptr<MenuItem>> menu_items;

	menu_items.push_back(std::make_unique<MenuSpinner>(MenuSpinner(3, 3, "Head Character", head_options)));
	menu_items.push_back(std::make_unique<MenuButton>(MenuButton(3, 14, "Quit", [] {return true; })));

	Menu(m_console, menu_items).capture_input();
}