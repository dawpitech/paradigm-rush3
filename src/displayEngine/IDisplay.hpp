//
// EPITECH PROJECT, 2025
// IDisplay
// File description:
// Interface for display engine
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <cstdint>
#include <memory>

class IDisplay {
   public:
    virtual void displayWidget() = 0;
    virtual void moveWidget() = 0;
    virtual void removeWidget() = 0;
    virtual void minimizeWidget() = 0;

protected:
    virtual bool _checkEnv() const = 0;
    std::uint32_t _sizeX;
    std::uint32_t _sizeY;
    std::shared_ptr<sf::RenderWindow> _window;
};
