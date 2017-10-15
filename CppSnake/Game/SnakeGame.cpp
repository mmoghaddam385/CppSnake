#include "SnakeGame.h"
#include "SnakeEngine.h"
#include "../UI/Menu.h"

#include <iostream>
#include <vector>

void SnakeGame::start()
{
	menu();
}

void SnakeGame::play()
{
	auto engine = SnakeEngine(this->m_console);
	engine.start(EASY_SETTINGS);
}

void SnakeGame::menu()
{
	m_console->reset_screen();

	// print banner
	m_console->gotoxy(1, 1);
	std::cout << R"(    _____            ____          __      )"; m_console->gotoxy(1, 2);
	std::cout << R"(   / ___/__  ___    / __/__  ___ _/ /_____ )"; m_console->gotoxy(1, 3);
	std::cout << R"!(  / /__/ _ \/ _ \  _\ \/ _ \/ _ `/  '_/ -_))!"; m_console->gotoxy(1, 4);
	std::cout << R"(  \___/ .__/ .__/ /___/_//_/\_,_/_/\_\\__/ )"; m_console->gotoxy(1, 5);
	std::cout << R"(     /_/  /_/)";

	// set up menu
	std::vector<std::unique_ptr<MenuItem>> menu_items;

	menu_items.push_back(std::make_unique<MenuButton>(MenuButton(3, 10, "Start game", [&] { this->play(); return true; } )));
	menu_items.push_back(std::make_unique<MenuButton>(MenuButton(3, 12, "Options", [&] { this->options(); return true; } )));
	menu_items.push_back(std::make_unique<MenuButton>(MenuButton(3, 14, "Quit", [] { return true; })));

	auto menu = Menu(m_console, menu_items);
	menu.capture_input();
	
}

void SnakeGame::options()
{
	m_console->reset_screen();

	//std::vector<std::string> head_options {"^", "\x9C", "\x99", "\x9E", "\xE9", "\xFE"};
	//std::vector<std::string> body_options {"", "\xB0", "\xB2"};

	std::vector<std::vector<char>> head_options {
		{ '^',    '>',    'v',    '<'    }, // up, right, down, left
		{ '\x9C', '\x9C', '\x9C', '\x9C' },
		{ '\x99', '\x99', '\x99', '\x99' },
		{ '\x9E', '\x9E', '\x9E', '\x9E' },
		{ '\xE9', '\xE9', '\xE9', '\xE9' },
		{ '\xFE', '\xFE', '\xFE', '\xFE' },
	};

	std::vector<std::vector<char>> body_options {
		{ '\xBA', '\xCD', '\xBC', '\xC8', '\xC9', '\xBB' }, // vertical, horizontal, top left, top right, bottom right, bottom left
		{ '\xB0', '\xB0', '\xB0', '\xB0', '\xB0', '\xB0' },
		{ '\xB3', '\xC4', '\xD9', '\xC0', '\xBF', '\xDA' },
		{ '\xB2', '\xB2', '\xB2', '\xB2', '\xB2', '\xB2' },
	};

	// set up options menu
	std::vector<std::unique_ptr<MenuItem>> menu_items;
	std::vector<char> *head_vector = &(head_options[0]);
	std::vector<char> *body_vector = &(body_options[0]);

	menu_items.push_back(std::make_unique<MultiItemMenuSpinner>(MultiItemMenuSpinner(3, 3, "Head Character", head_options, &head_vector)));
	menu_items.push_back(std::make_unique<MultiItemMenuSpinner>(MultiItemMenuSpinner(3, 5, "Body Character(s)", body_options, &body_vector)));
	menu_items.push_back(std::make_unique<MenuButton>(MenuButton(3, 14, "Return to menu", [&] {
		// save head

		this->menu();
		return true;
	})));

	Menu(m_console, menu_items).capture_input();
}