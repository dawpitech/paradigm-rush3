//
// EPITECH PROJECT, 2025
// SfmlDisplay
// File description:
// implementation of display sfml class functions
//

#include "displayEngine/sfml/SfmlDisplay.hpp"
#include "widgetEngine/IWidget.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <cstdlib>
#include <string>

Krell::SfmlDisplay::SfmlDisplay()
{
    this->_checkEnv();
    this->_init();
}

bool Krell::SfmlDisplay::_checkEnv() const
{
    char *display = std::getenv("DISPLAY");
    /*char *xAuthority = std::getenv("XAUTHORITY");*/

    /*if (display == NULL || xAuthority == NULL)*/
    if (display == NULL)
        throw Error("Env not set");
    return true;
}

bool Krell::SfmlDisplay::_init()
{
    this->_window = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(this->_sizeX, this->_sizeY), "MyGKREEEEEEEEEEEEEEL");
    if (this->_window->isOpen() != true)
        throw Error("Unable to open window");
    this->_window->setFramerateLimit(this->_frameLimit);
    this->_window->display();
    return true;
}

void Krell::SfmlDisplay::useEvent()
{
    auto window = this->_window;
    sf::Event event;

    if (!window)
        throw "Unable to retrieve window for event";
    while (window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::MouseButtonReleased:
                std::cout << "Hello" << std::endl;
                /*this->_useAction(event->);*/
                break;
            default:
                break;
        }
    }
}

void Krell::SfmlDisplay::_displayNumericWidget(const IWidget &widget) const
{
}

void Krell::SfmlDisplay::_displayStringWidget(const IWidget &widget) const
{
    sf::Font font;

    if (!font.loadFromFile("../../../fonts/arial.ttf"))
        throw Error("Unable to load the sfFont");
    sf::Text text(widget.getLegend(), font);
}
