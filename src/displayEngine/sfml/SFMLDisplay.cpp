//
// EPITECH PROJECT, 2025
// SfmlDisplay
// File description:
// implementation of display sfml class functions
//

#include <format>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "displayEngine/sfml/SFMLDisplay.hpp"
#include "widgetEngine/modules/IModule.hpp"

Krell::Displays::SFMLDisplay::SFMLDisplay()
{
    this->_window = std::make_shared<sf::RenderWindow>
        (sf::VideoMode(this->_sizeX, this->_sizeY), "MyKrell");
    this->_font = std::make_unique<sf::Font>();
    if (this->_window->isOpen() != true)
        throw std::exception();
    if (!this->_font->loadFromFile("fonts/JetBrainsMono-Regular.ttf"))
        throw std::exception();
    this->_window->setFramerateLimit(this->_frameLimit);
    this->_window->display();
}

Krell::Displays::SFMLDisplay::~SFMLDisplay()
{
    this->_window->clear();
    this->_window->close();
}

void Krell::Displays::SFMLDisplay::displayModules(
    std::shared_ptr<std::vector<std::shared_ptr<IModule>>> modules) const
{
    this->_window->clear();
    std::uint16_t current_y_pos = SFML_PADDING * 2;
    for (const auto& module : *modules)
    {
        std::uint8_t y_rendering_height = 20;
        for (const auto& widget : module->getWidgets())
            y_rendering_height += widget->getRenderSize() * SML_SIZE_FACTOR;

        sf::RectangleShape box(sf::Vector2f(this->_sizeX - SFML_PADDING * 2, y_rendering_height));

        box.setPosition(SFML_PADDING, current_y_pos);
        box.setOutlineColor(sf::Color::White);
        box.setOutlineThickness(SML_BORDER_THICKNESS);
        box.setFillColor(sf::Color(0, 0, 0));
        this->_window->draw(box);

        sf::Text text;

        text.setFont(*this->_font);
        text.setPosition(25, current_y_pos);
        text.setString(module->getRenderName());
        text.setCharacterSize(15);
        text.setFillColor(sf::Color::White);
        this->_window->draw(text);

        std::uint16_t current_rendering_y = current_y_pos + 5;
        for (const auto& widget : module->getWidgets()) {
            _renderWidget(widget, this->_sizeX / 5, current_rendering_y);
            current_rendering_y += widget->getRenderSize() * SML_SIZE_FACTOR;
        }

        current_y_pos += 3 * SML_SIZE_FACTOR + (current_rendering_y - current_y_pos);
    }
    this->_refresh();
}

void Krell::Displays::SFMLDisplay::_renderWidget(
    const std::shared_ptr<IWidget>& widget,
    const std::uint16_t x,
    const std::uint16_t y) const
{
    if (dynamic_cast<Widgets::StringWidget*>(widget.get()) != nullptr)
        return _renderStringWidget(
            dynamic_cast<Widgets::StringWidget*>(widget.get()), x, y);
    if (dynamic_cast<Widgets::NumericWidget*>(widget.get()) != nullptr)
        return _renderNumericWidget(
            dynamic_cast<Widgets::NumericWidget*>(widget.get()), x, y);
}

void Krell::Displays::SFMLDisplay::_renderStringWidget(
    const Widgets::StringWidget* widget,
    const std::uint16_t x,
    const std::uint16_t y) const
{
    sf::Text text;

    text.setFont(*this->_font);
    text.setPosition(x, y);
    text.setString(std::format("{} {}", widget->getLegend(), widget->getValue()));
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::White);
    this->_window->draw(text);
}

void Krell::Displays::SFMLDisplay::_renderNumericWidget(
    const Widgets::NumericWidget* widget,
    const std::uint16_t x,
    const std::uint16_t y) const
{
    sf::Text text;

    text.setFont(*this->_font);
    text.setPosition(x, y);
    text.setString(std::format("{} {}", widget->getLegend(), widget->getValue()));
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::White);
    this->_window->draw(text);
}

void Krell::Displays::SFMLDisplay::useEvent()
{
    sf::Event event{};
    while (this->_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            throw UserCalledExitException();
    }
}

void Krell::Displays::SFMLDisplay::_refresh() const
{
    this->_window->display();
}
