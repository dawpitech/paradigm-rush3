//
// EPITECH PROJECT, 2025
// SfmlDisplay
// File description:
// implementation of display sfml class functions
//

#include "displayEngine/sfml/SfmlDisplay.hpp"
#include "widgetEngine/modules/IModule.hpp"
#include "widgetEngine/widgets/AWidget.hpp"
#include "widgetEngine/widgets/IWidget.hpp"
#include "widgetEngine/widgets/StringWidget.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
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
        throw Error("Unable to retrieve window for event");
    while (window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::MouseButtonReleased:
                /*this->_useAction(event->);*/
                break;
            default:
                break;
        }
    }
}

void Krell::SfmlDisplay::_displayBaseModule(const IModule &module) const
{
    auto window = this->_window;
    auto moduleName = module.getRenderName();
    auto modulePos = module.getRenderPos();

    auto newPos = (this->_sizeY / this->_nbModules) * (modulePos);
    auto moduleSize = this->_sizeY / this->_nbModules;

    sf::RectangleShape moduleShape;
    moduleShape.setSize(sf::Vector2f(this->_sizeX - 20, moduleSize));
    moduleShape.setOutlineColor(sf::Color::White);
    moduleShape.setOutlineThickness(1);
    moduleShape.setPosition(10, newPos + 10 * (modulePos));
    moduleShape.setFillColor(sf::Color::Transparent);
    window->draw(moduleShape);
}

/*void Krell::SfmlDisplay::_displayNumericWidget(const Widgets::NumericWidget &widget) const*/
/*{*/
/*}*/

void Krell::SfmlDisplay::_displayStringWidget(
    const IWidget &widget, const std::uint8_t pos) const
{
    sf::Font font;
    auto window = this->_window;

    auto stringWidget = dynamic_cast<const Widgets::StringWidget *>(&widget);
    if (stringWidget == nullptr)
        throw Error("Unable to cast String Widget");
    if (!window)
        throw Error("Unable to access window with string widget");
    if (!font.loadFromFile("Space_Mono/SpaceMono-Regular.ttf"))
        throw Error("Unable to load the sfFont");
    std::string strToDisplay =
        stringWidget->getLegend() + stringWidget->getValue();
    sf::Text text(strToDisplay.c_str(), font);
    text.setCharacterSize(10);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, widget.getRenderSize() * 10 + pos);
    window->draw(text);
}

void Krell::SfmlDisplay::_displayProgressBarWidget(
    const IWidget &widget, const std::uint8_t pos) const
{
    /*auto window = this->_window;*/
    /*auto progressbarwidget = dynamic_cast<const Widgets::ProgressBarWidget *>(&widget);*/
    /**/
    /*if (progressbarwidget == nullptr)*/
    /*    throw Error("Unable to cast progress bar widget");*/
}

void Krell::SfmlDisplay::_displayClockModule(const IModule &module) const
{
    auto window = this->_window;
    auto posY = this->_sizeY / this->_nbModules;
    posY *= (module.getRenderPos() + 1);

    sf::Texture clockTexture;
    if (!clockTexture.loadFromFile("sprites/clock.png")) {
        throw Error("Unable to load clock texture");
    }
    sf::Texture needleTexture;
    if (!needleTexture.loadFromFile("sprites/needle.png")) {
        throw Error("Unable to load needle texture");
    }

    sf::Sprite clockSprite(clockTexture);
    sf::Sprite needleSprite(needleTexture);

    clockSprite.setScale(0.5, 0.5);
    needleSprite.setScale(0.5, 0.5);
    clockSprite.setPosition(0, posY);
    needleSprite.setPosition(clockSprite.getScale().x + 50, posY);
    needleSprite.setOrigin(needleSprite.getPosition().x, needleSprite.getPosition().y + 200 );
    needleSprite.rotate(90);
    window->draw(clockSprite);
    window->draw(needleSprite);
}

void Krell::SfmlDisplay::_clear() const
{
    if (!this->_window)
        throw Error("Unable to clear window");
    this->_window->clear();
}

void Krell::SfmlDisplay::_refresh() const
{
    if (!this->_window)
        throw Error("Unable to refresh window");
    this->_window->display();
}
