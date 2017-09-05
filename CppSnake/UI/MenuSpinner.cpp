#include "Menu.h"

#include <iostream>

std::string MenuSpinner::get_selected()
{
    return m_options[m_selected_index];
}

void MenuSpinner::draw(std::shared_ptr<Console> console)
{
    console->gotoxy(m_x, m_y);
    std::cout << "< " << m_options[m_selected_index] << " > " << m_txt;
}

void MenuSpinner::activate(std::shared_ptr<Console> console)
{
    // put the cursor at the front of the current option
    console->gotoxy(m_x + 2, m_y);
}

void MenuSpinner::deactivate(std::shared_ptr<Console> console) { } // do nothing

bool MenuSpinner::handle_input(std::shared_ptr<Console> console, int input_char)
{
    // handle option movement and wrap around
    if (input_char == LEFT_ARROW_KEY)
    {
        m_selected_index--;
        if (m_selected_index < 0)
        {
            m_selected_index = m_options.size() - 1;
        }

        draw(console);
    }
    else if (input_char == RIGHT_ARROW_KEY)
    {
        m_selected_index++;
        if (m_selected_index >= m_options.size())
        {
            m_selected_index = 0;
        }

        draw(console);
    }

    return false;
}
