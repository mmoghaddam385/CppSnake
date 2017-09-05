#pragma once

#include "../Console/Console.h"

#include <string>
#include <memory>
#include <vector>
#include <functional>

#define ENTER_KEY 13

#define LEFT_ARROW_KEY 75
#define RIGHT_ARROW_KEY 77
#define UP_ARROW_KEY 72
#define DOWN_ARROW_KEY 80



typedef std::function<bool ()> MenuCallback;

class MenuItem
{
	public:
		virtual void draw(std::shared_ptr<Console> console) = 0; // this function actually draws the menu item on the screen
		virtual void activate(std::shared_ptr<Console> console) = 0; // called when this menu item becomes selected
		virtual void deactivate(std::shared_ptr<Console> console) = 0; // called when this menu item loses focus
		virtual bool handle_input(std::shared_ptr<Console> console, int input_char) = 0; // handle input when selected; return true to keep going, or false to stop menu input

	protected:
		MenuItem(int x, int y) :  m_x(x), m_y(y) { }

		int m_x, m_y;
};

class MenuButton : public MenuItem
{
	public:
		MenuButton(int x, int y, std::string txt, MenuCallback callback): 
			MenuItem(x, y), m_txt(txt), m_callback(callback) { }

		void draw(std::shared_ptr<Console> console);
		void activate(std::shared_ptr<Console> console);
		void deactivate(std::shared_ptr<Console> console);
		bool handle_input(std::shared_ptr<Console> console, int input_char);

	private:
		std::string m_txt;
		MenuCallback m_callback;
};

class MenuSpinner : public MenuItem
{
	public:
		MenuSpinner(int x, int y, std::string txt, std::vector<std::string>& options):
			MenuItem(x, y), m_txt(txt), m_options(options), m_selected_index(0) { }

		std::string get_selected(); // get the currently selected option

		void draw(std::shared_ptr<Console> console);
		void activate(std::shared_ptr<Console> console);
		void deactivate(std::shared_ptr<Console> console);
		bool handle_input(std::shared_ptr<Console> console, int input_char);

	private:
		std::string m_txt;
		std::vector<std::string>& m_options;
		int m_selected_index;
};

class Menu
{
	public:
		Menu(std::shared_ptr<Console> console, std::vector<std::unique_ptr<MenuItem>>& menu_items) :
			m_console(console), m_menu_items(menu_items), m_active_index(0) { }

		void capture_input(); // take control of the program

	private:
		void init_menu(); // init the menu by drawing all items and activating the first

		std::shared_ptr<Console> m_console;
		std::vector<std::unique_ptr<MenuItem>>& m_menu_items;
		int m_active_index;
};