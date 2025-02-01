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

namespace Krell {
    class IDisplay {
       public:
        virtual void displayWidget() = 0;
        virtual void moveWidget() = 0;
        virtual void removeWidget() = 0;
        virtual void minimizeWidget() = 0;

       protected:
        virtual bool _checkEnv() const = 0;
        virtual bool _init() = 0;
        const std::uint32_t _sizeX = 800;
        const std::uint32_t _sizeY = 200;
        std::shared_ptr<sf::RenderWindow> _window;
    };
}  // namespace Krell
