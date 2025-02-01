//
// EPITECH PROJECT, 2025
// SfmlDisplay
// File description:
// implementation of display sfml class functions
//

#include "displayEngine/sfml/SfmlDisplay.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>
#include <cstdlib>
#include <string>

SfmlDisplay::SfmlDisplay()
{
    this->_sizeX = 800;
    this->_sizeY = 200;
    this->_checkEnv();
    this->_init();
}

bool SfmlDisplay::_checkEnv() const
{
    char *display = std::getenv("DISPLAY");
    /*char *xAuthority = std::getenv("XAUTHORITY");*/

    /*if (display == NULL || xAuthority == NULL)*/
    if (display == NULL)
        throw Error("Env not set");
    return true;
}

bool SfmlDisplay::_init()
{
    this->_window = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(this->_sizeX, this->_sizeY), "MyGKREEEEEEEEEEEEEEL");
    if (this->_window->isOpen() != true)
        throw Error("Unable to open window");
    this->_window->setFramerateLimit(this->_frameLimit);
    return true;
}
